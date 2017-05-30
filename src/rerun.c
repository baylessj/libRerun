#include "main.h"

#define RECORDING_ACTIVE 0
#define RECORDING_DONE 1
#define MAX_RECORDING_LENGTH (45000 / RESOLUTION)

static void _record(void* param) {
  button_t* button = (button_t*)(param);
  char status;
  /**
   * NOTE: RESET ALL SENSORS HERE
   */
  tankResetSensors();
  /**
   * NOTE: END SENSOR RESET
   */
  unsigned long now = millis();
  for (int i = 0; i < MAX_RECORDING_LENGTH; i++) {
    int num_inputs;
    long input[num_inputs];

    /**
     * NOTE: RECORDED INPUT
     */
    num_inputs = 6;
    input[0] = motorGet(MTR_TANK_FRONT_LEFT);
    input[1] = motorGet(MTR_TANK_FRONT_RIGHT);
    input[2] = motorGet(MTR_LIFT_1);
    input[3] = tankGetLeftEncoder();
    input[4] = tankGetRightEncoder();
    input[5] = liftGetHeight();
    /**
     * NOTE: END RECORDED INPUT
     */

    status = RECORDING_ACTIVE;
    if (buttonIsNewPress(*button)) status = RECORDING_DONE;
    print("playback(");
    for (int i = 0; i < num_inputs; i++) printf("%ld, ", input[i]);
    printf("%d);\n", status);
    taskDelayUntil(&now, RESOLUTION);
    if (status == RECORDING_DONE) {
      print("\n\n\n\n//**RECORDING DONE**//\n\n");
      break;
    }
  }
}

static int sgn(int in) {
  if (in > 0) return 1;
  else if (in < 0) return -1;
  else return 0;
}

static int _pidCompute(fbc_pid_t *data, int error) {
  data->_integral += error;
  if(data->_integral < data->minI)
    data->_integral = data->minI;
  else if(data->_integral > data->maxI)
    data->_integral = data->maxI;
  if (sgn(data->_prevError) != sgn(error))
    data->_integral = 0;
  double derivative = ((double)(error - data->_prevError) / RESOLUTION);
  data->_prevError = error;
  return (data->kP * error) + (data->kI * data->_integral) + (data->kD * derivative);
}

/**
 * NOTE: EDIT PLAYBACK FUNCTION AS NEEDED
 */
long prev_left, prev_right, prev_lift; //previous values
long prev_rec_left, prev_rec_right, prev_rec_lift;
fbc_pid_t left_vel_pid, right_vel_pid, lift_vel_pid;

void playbackInit() {
  fbcPIDInitializeData(&left_vel_pid, RERUN_DRIVE_KP, RERUN_DRIVE_KI, RERUN_DRIVE_KD, -RERUN_DRIVE_MAX_INTEGRAL, RERUN_DRIVE_MAX_INTEGRAL);
  fbcPIDInitializeData(&right_vel_pid, RERUN_DRIVE_KP, RERUN_DRIVE_KI, RERUN_DRIVE_KD, -RERUN_DRIVE_MAX_INTEGRAL, RERUN_DRIVE_MAX_INTEGRAL);
  fbcPIDInitializeData(&lift_vel_pid, RERUN_DRIVE_KP, RERUN_DRIVE_KI, RERUN_DRIVE_KD, -RERUN_DRIVE_MAX_INTEGRAL, RERUN_DRIVE_MAX_INTEGRAL);
  tankResetSensors();
}

void playback(char left_set, char right_set, char lift_set, long left_pos, long right_pos, long lift_pos, bool status) {
  //Compute Errors
  right_set = -right_set;
  int left_vel_error = (left_pos - prev_rec_left) - (tankGetLeftEncoder() - prev_left);
  int right_vel_error = (right_pos - prev_rec_right) - (tankGetRightEncoder() - prev_right);
  int lift_vel_error = (lift_pos - prev_rec_lift) - (liftGetHeight() - prev_lift);
  left_set += _pidCompute(&left_vel_pid, left_vel_error);
  right_set += _pidCompute(&right_vel_pid, right_vel_error);
  lift_set += _pidCompute(&lift_vel_pid, lift_vel_error);

  if (status) {
    motorStopAll();
    return;
  }
  else {
    tankSet(left_set, right_set, true);
    liftSet(lift_set);
  }

  prev_left = tankGetLeftEncoder();
  prev_right = tankGetRightEncoder();
  prev_rec_left = left_pos;
  prev_rec_right = right_pos;
  delay(RESOLUTION);
}
/**
 * NOTE: END PLAYBACK FUNCTION
 */

static button_t record_stop;
void startRecording(button_t killswitch) {
  record_stop = killswitch;
  taskCreate(_record, TASK_DEFAULT_STACK_SIZE, (void*)(&record_stop), TASK_PRIORITY_DEFAULT);
}
