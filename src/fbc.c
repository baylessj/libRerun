/**
 * @file Team BLRS Feedback Controller Library (FBCL)
 * @brief Provides components to implement feedback controllers with
 *        pre-made templates for PID, TBH, Hysteresis, and Master-Slave.
 *
 * @author Jonathan Bayless, Elliot Berman, Brian Hanford
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "fbc.h"

static void _fbcTask(void* param) {
  fbc_t* fbc = (fbc_t*)param;
  unsigned long now = millis();
  while(true) {
    fbcRunContinuous(fbc);
    taskDelayUntil(&now, FBC_LOOP_INTERVAL);
  }
}

void fbcInit(fbc_t* fbc, void (*move)(int), int (*sense)(void), void (*resetSense)(void),
            int neg_deadband, int pos_deadband, int acceptableTolerance, unsigned int acceptableConfidence) {
  fbc->move = move;
  fbc->sense = sense;
  fbc->resetSense = resetSense;
  fbc->acceptableTolerance = acceptableTolerance;
  fbc->acceptableConfidence = acceptableConfidence;
  fbc->neg_deadband = neg_deadband;
  fbc->pos_deadband = pos_deadband;
  fbc->goal = 0;
}

void fbcReset(fbc_t* fbc) {
	fbc->_confidence = 0;
  if(fbc->resetSense) fbc->resetSense();
  if(fbc->resetController) fbc->resetController(fbc);
  fbc->goal = 0;
}

bool fbcSetGoal(fbc_t* fbc, int new_goal) {
  if(!fbc) return false;
  if(fbc->goal == new_goal) return true;
  fbc->goal = new_goal;
  fbc->_prevExecution = CUR_TIME();
  return true;
}

bool fbcIsConfident(fbc_t* fbc) {
  return fbc->_confidence >= fbc->acceptableConfidence;
}

bool fbcRunContinuous(fbc_t* fbc) {
  int error = fbc->goal - fbc->sense();
  int out = fbc->compute(fbc, error);
  if (out < fbc->pos_deadband && out > 0)
    out = fbc->pos_deadband;
  else if (out > fbc->neg_deadband && out < 0)
    out = fbc->neg_deadband;
	fbc->move(out);

  if((unsigned int)abs(error) < fbc->acceptableTolerance)
    fbc->_confidence++;
  else
    fbc->_confidence = 0;
	fbc->_prevExecution = CUR_TIME();
  return fbc->_confidence >= fbc->acceptableConfidence;
}

bool fbcRunCompletion(fbc_t* fbc, unsigned long timeout) {
  unsigned long int now = CUR_TIME();
  unsigned long start = millis();
#define HAS_TIMED_OUT   (timeout == 0 || (start + timeout) >= now)
  while(!fbcRunContinuous(fbc) && HAS_TIMED_OUT)
    taskDelayUntil(&now, FBC_LOOP_INTERVAL);
  return HAS_TIMED_OUT;
#undef HAS_TIMED_OUT
}

TaskHandle fbcRunParallel(fbc_t* fbc) {
  return taskCreate(_fbcTask, TASK_DEFAULT_STACK_SIZE, fbc, TASK_PRIORITY_DEFAULT);
}
