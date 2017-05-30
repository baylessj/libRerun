/**
 * just here to serve as an example of normal functions to use with rerun
 */
#ifndef SAMPLE_FUNCTIONS_H
#define SAMPLE_FUNCTIONS_H

#include "main.h"

#define RECORD_DRIVE_MAX_INPUT 100
int clamp(int in, int max);

void tankInit();

int32_t tankGetLeftEncoder();
int32_t tankGetRightEncoder();
int liftGetHeight();
int clawGetPos();

void tankSet(int in, int right, bool immediate);
void liftSet(int in);
void clawSet(int in);

void tankResetSensors();
void liftResetSensors();
void tankFBCTurnTaskSuspend();
void tankFBCDriveTaskSuspend();
void liftFBCTaskSuspend();
void clawFBCTaskSuspend();

#define MTR_TANK_FRONT_LEFT 2
#define MTR_TANK_FRONT_RIGHT 9
#define MTR_TANK_REAR_LEFT 0
#define MTR_TANK_REAR_RIGHT 0
#define MTR_LIFT_1 0
#define DIG_DRIVE_ENC_LEFT_1 2
#define DIG_DRIVE_ENC_LEFT_2 1
#define DIG_DRIVE_ENC_RIGHT_1 3
#define DIG_DRIVE_ENC_RIGHT_2 4

#define DRIVE_KP 0.1f
#define DRIVE_KI 0.1f
#define DRIVE_KD 0.1f
#define CLAW_KP 0.1f
#define CLAW_KI 0.1f
#define CLAW_KD 0.1f
#define LIFT_KP 0.1f
#define LIFT_KI 0.1f
#define LIFT_KD 0.1f

#define DRIVE_SLEW 0.5f

#endif
