#include "main.h"

static Encoder leftenc, rightenc;

void tankInit() {
  leftenc = encoderInit(DIG_DRIVE_ENC_LEFT_1, DIG_DRIVE_ENC_LEFT_2, false);
  rightenc = encoderInit(DIG_DRIVE_ENC_RIGHT_1, DIG_DRIVE_ENC_RIGHT_2, false);
  blrsMotorInit(MTR_TANK_FRONT_LEFT, false, DRIVE_SLEW, NULL);
  blrsMotorInit(MTR_TANK_FRONT_RIGHT, true, DRIVE_SLEW, NULL);
}

int32_t tankGetLeftEncoder() {
  return encoderGet(leftenc);
}

int32_t tankGetRightEncoder() {
  return encoderGet(rightenc);
}

int liftGetHeight() {
  return 1;
}

void liftSet(int cmd) {
  blrsMotorSet(MTR_LIFT_1, cmd, false);
}

void tankSet(int left, int right, bool immediate) {
  blrsMotorSet(MTR_TANK_FRONT_LEFT, left, immediate);
  blrsMotorSet(MTR_TANK_FRONT_RIGHT, right, immediate);
}

void tankResetSensors() {
  encoderReset(leftenc);
  encoderReset(rightenc);
}

int clamp(int in, int max) {
  if (in > 0 && in > max)
    return max;
  else if (in < 0 && in < -max)
    return -max;
  else
    return 0;
}
