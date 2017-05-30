/**
 * @file hdrive.h
 * @author Jonathan Bayless, Brian Hanford, Alex Van de Sandt
 *
 * @brief provides functionality for interacting with a standard HDrive in op control and auton.
 */
#ifndef _HDRIVE_H_
#define _HDRIVE_H_

#include "main.h"

Gyro gyroscope;
int prevRight;
int prevLeft;
int prevStrafe;
//CONSTRUCTOR//

/**
 * Initializes the controllers, sensors, and motors in the drive.
 */
bool hdriveInit();

//OP CONTROL FUNCTIONS//

/**
 * @brief Manually sets the speeds of all motors in the drive.
 *
 * @param left
 *          The speed of the left side
 * @param right
 *          The speed of the right side
 * @param central
 *          The speed of the strafe motors. Positive is right, negative is left.
 */
void opSetDrive(int left, int right, int central);

/**
 * @brief provides arcade joystick style driver control
 *
 * Channel 3 moves the robot forwards and backwards. Channel 1 moves the robot
 * left and right. Channel 4 turns the robot left and right.
 *
 * @param cubic
 *          Cubic or linear scaling on the joystick
 */
void hdriveArcade(bool cubic);

/**
 * @brief Joe's preferred style of driver control, a slight modification to
 *          traditional arcade control
 *
 * Channel 2 moves the robot forward backward. Channel 4 moves the robot left
 * and right. Channel 1 turns the robot left and right.
 *
 * @param cubic
 *          Cubic or linear scaling on the joystick
 */
void hdriveJoe(bool cubic);

/**
 * @brief implements a deadband control for the joystick's analog controls
 *
 * @param in
 *        the input from the joystick controller
 * @param cubic
 *        true if cubic scaling, false if linear
 *
 * @returns the scaled output value
 */
int scaleJoystick(int in, bool cubic);

/**
 * @brief implements a deadband control for the HDrive's strafe module
 *
 * @param in
 *          the value to set the strafe module to
 * @returns the scaled output value
 */
int scaleStrafe(int in);

/**
 * Set the speeds of the left, right, and center motors individually.
 */
void setLeft(int speed);
void setRight(int speed);
void setTankStrafe(int speed);
/**
 * Sets the speed of the left and right opposite each other to turn.
 */
void setTankTurn(int speed);

/**
 * Return the encoder values of the left, right, and strafe motors.
 */
int getLeftTicks();
int getRightTicks();
int getStrafeTicks();
/**
 * Returns a combination of the left and right encoders and the gyro.
 */
int getTurnTicks();

/**
 * Reset the encoder values of the left, right, and strafe motors.
 */
void resetLeftTicks();
void resetRightTicks();
void resetStrafeTicks();
/**
 * Resets the values of the left and right encoders and the gyro.
 */
void resetTurnTicks();

/**
 * Changes the tolerance of the left and right controllers.
 */
void editDriveTolerance(int new_tolerance);

/**
 * Return pointers to the left, right, strafe, and turn PID Controller
 * configurations.
 */
fbc_t * getRightCon();
fbc_t * getLeftCon();
fbc_t * getStrafeCon();
fbc_t * getTurnCon();

/**
 * Returns pointer to the left, right, strafe, and turn PID Controller tasks.
 */
TaskHandle getLeftTask();
TaskHandle getRightTask();
TaskHandle getTurnTask();

/**
 * Sets the goals o fthe Drive, turn, and strafe PID controllers.
 */
void setDrive(int goal);
void setTurn(int goal);
void setFrontTurn(int goal);
void setBackTurn(int goal);
void setStrafe(int goal);

/**
 * Returns an int representing the state of the drive PID tasks.
 * Either TASK_SUSPENDED or TASK_RUNNING
 */
unsigned int hdriveTaskGetState();
/**
 * Stops or resumes the hdrive PID controllers.
 */
void hdriveStopPID();
void hdriveResumePID();
/**
 * Swites the PID controller to either turn or drive forward.
 */
void switchToDrivePID();
void switchToTurnPID();

#endif
