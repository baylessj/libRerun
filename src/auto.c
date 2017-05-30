/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost,  the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */
void autonomous() {
  playbackInit();

  //example script
  playback(0, -10, -127, 0, 0, 1, 0);
  playback(0, -30, -127, 0, 0, 1, 0);
  playback(20, -50, -127, 0, 3, 1, 0);
  playback(40, -70, -127, 0, 13, 1, 0);
  playback(60, -90, -127, 12, 41, 1, 0);
  playback(80, -100, -127, 44, 56, 1, 0);
  playback(100, -100, -127, 90, 93, 1, 0);
  playback(100, -100, -127, 147, 151, 1, 0);
  playback(100, -100, -127, 215, 219, 1, 0);
  playback(100, -100, -127, 296, 300, 1, 0);
  playback(100, -100, -127, 384, 389, 1, 0);
  playback(100, -100, -127, 481, 463, 1, 0);
  playback(100, -100, -127, 585, 567, 1, 0);
  playback(100, -100, -127, 695, 678, 1, 0);
  playback(100, -100, -127, 808, 767, 1, 0);
  playback(100, -100, -127, 924, 886, 1, 0);
  playback(100, -100, -127, 1045, 1006, 1, 0);
  playback(100, -100, -127, 1168, 1101, 1, 0);
  playback(100, -100, -127, 1293, 1231, 1, 0);
  playback(100, -100, -127, 1421, 1360, 1, 0);
  playback(100, -90, -127, 1551, 1469, 1, 0);
  playback(100, -70, -127, 1683, 1601, 1, 0);
  playback(80, -50, -127, 1817, 1715, 1, 0);
  playback(60, -30, -127, 1949, 1819, 1, 0);
  playback(40, -10, -127, 2075, 1932, 1, 0);
  playback(20, 0, -127, 2193, 2042, 1, 0);
  playback(0, 0, -127, 2303, 2119, 1, 0);
  playback(0, 0, -127, 2404, 2217, 1, 0);
  playback(0, 20, -127, 2496, 2290, 1, 0);
  playback(-20, 40, -127, 2576, 2318, 1, 0);
  playback(-40, 60, -127, 2604, 2318, 1, 0);
  playback(-60, 80, -127, 2604, 2301, 1, 0);
  playback(-80, 100, -127, 2598, 2274, 1, 0);
  playback(-100, 100, -127, 2564, 2231, 1, 0);
  playback(-100, 100, -127, 2497, 2173, 1, 0);
  playback(-100, 100, -127, 2417, 2097, 1, 0);
  playback(-100, 100, -127, 2331, 2041, 1, 0);
  playback(-100, 100, -127, 2236, 1951, 1, 0);
  playback(-100, 100, -127, 2135, 1847, 1, 0);
  playback(-100, 100, -127, 2027, 1737, 1, 0);
  playback(-100, 100, -127, 1913, 1648, 1, 0);
  playback(-100, 100, -127, 1799, 1525, 1, 0);
  playback(-100, 100, -127, 1680, 1401, 1, 0);
  playback(-100, 100, -127, 1557, 1304, 1, 0);
  playback(-100, 100, -127, 1436, 1178, 1, 0);
  playback(-100, 100, -127, 1309, 1055, 1, 0);
  playback(-100, 90, -127, 1184, 945, 1, 0);
  playback(-100, 70, -127, 1059, 817, 1, 0);
  playback(-100, 50, -127, 933, 721, 1, 0);
  playback(-100, 30, -127, 809, 617, 1, 0);
  playback(-100, 10, -127, 681, 513, 1, 0);
  playback(-100, 0, -127, 555, 423, 1, 0);
  playback(-100, 0, -127, 430, 364, 1, 0);
  playback(-80, 0, -127, 308, 288, 1, 0);
  playback(-60, 0, -127, 188, 224, 1, 0);
  playback(-40, 0, -127, 81, 160, 1, 0);
  playback(-20, 0, -127, -11, 103, 1, 0);
  playback(0, 0, -127, -88, 56, 1, 0);
  playback(0, 0, -127, -151, 27, 1, 0);
  playback(0, 0, -127, -199, -17, 1, 0);
  playback(0, 0, -127, -233, -52, 1, 0);
  playback(0, 0, -127, -259, -80, 1, 0);
  playback(0, 0, -127, -277, -97, 1, 0);
  playback(0, 0, -127, -286, -105, 1, 0);
  playback(0, 0, -127, -287, -107, 1, 0);
  playback(0, 0, -127, -287, -105, 1, 0);
  playback(0, 0, -127, -285, -101, 1, 0);
  playback(0, 0, -127, -284, -101, 1, 0);
  playback(0, 0, -127, -284, -101, 1, 0);
  playback(0, 0, -127, -284, -101, 1, 0);
  playback(0, 0, -127, -284, -101, 1, 0);
  playback(0, 0, -127, -284, -101, 1, 0);
  playback(0, 0, -127, -284, -101, 1, 0);
  playback(20, 0, -127, -284, -101, 1, 0);
  playback(40, 0, -127, -284, -101, 1, 0);
  playback(60, 0, -127, -271, -101, 1, 0);
  playback(80, 0, -127, -247, -100, 1, 0);
  playback(100, 0, -127, -204, -96, 1, 0);
  playback(80, 0, -127, -149, -89, 1, 0);
  playback(60, 0, -127, -90, -84, 1, 0);
  playback(40, 0, -127, -35, -79, 1, 0);
  playback(20, 0, -127, 9, -68, 1, 0);
  playback(0, 0, -127, 43, -60, 1, 0);
  playback(0, 0, -127, 61, -49, 1, 0);
  playback(0, 0, -127, 67, -41, 1, 0);
  playback(0, 0, -127, 67, -40, 1, 0);
  playback(0, 0, -127, 66, -40, 1, 0);
  playback(0, 0, -127, 65, -43, 1, 0);
  playback(0, 0, -127, 65, -43, 1, 0);
  playback(0, 0, -127, 65, -43, 1, 0);
  playback(0, 0, -127, 65, -43, 1, 0);
  playback(0, 0, -127, 65, -43, 1, 0);
  playback(0, 0, -127, 65, -43, 1, 0);
  playback(-20, 0, -127, 65, -43, 1, 0);
  playback(-40, 0, -127, 65, -43, 1, 0);
  playback(-60, 0, -127, 50, -43, 1, 0);
  playback(-80, 0, -127, 21, -44, 1, 0);
  playback(-80, 0, -127, -13, -47, 1, 0);
  playback(-60, 0, -127, -72, -57, 1, 0);
  playback(-40, 0, -127, -120, -72, 1, 0);
  playback(-20, 0, -127, -153, -83, 1, 0);
  playback(0, 0, -127, -176, -95, 1, 0);
  playback(0, 0, -127, -187, -107, 1, 0);
  playback(0, 0, -127, -188, -112, 1, 0);
  playback(0, 0, -127, -188, -112, 1, 0);
  playback(0, 0, -127, -188, -111, 1, 0);
  playback(0, 0, -127, -188, -109, 1, 0);
  playback(0, -10, -127, -188, -109, 1, 0);
  playback(0, -30, -127, -188, -109, 1, 0);
  playback(0, -50, -127, -188, -99, 1, 0);
  playback(0, -70, -127, -188, -81, 1, 0);
  playback(0, -90, -127, -188, -52, 1, 0);
  playback(0, -100, -127, -185, -1, 1, 0);
  playback(0, -90, -127, -184, 56, 1, 0);
  playback(0, -70, -127, -183, 101, 1, 0);
  playback(0, -50, -127, -181, 176, 1, 0);
  playback(0, -30, -127, -180, 237, 1, 0);
  playback(0, -10, -127, -178, 287, 1, 0);
  playback(0, 0, -127, -173, 321, 1, 0);
  playback(0, 0, -127, -167, 337, 1, 0);
  playback(0, 0, -127, -163, 341, 1, 0);
  playback(0, 0, -127, -163, 341, 1, 0);
  playback(0, 10, -127, -163, 340, 1, 0);
  playback(0, 30, -127, -163, 337, 1, 0);
  playback(0, 50, -127, -163, 337, 1, 0);
  playback(0, 70, -127, -163, 308, 1, 0);
  playback(0, 90, -127, -163, 267, 1, 0);
  playback(0, 100, -127, -164, 213, 1, 0);
  playback(0, 100, -127, -173, 140, 1, 0);
  playback(0, 100, -127, -185, 56, 1, 0);
  playback(0, 100, -127, -193, -7, 1, 0);
  playback(0, 100, -127, -202, -105, 1, 0);
  playback(0, 90, -127, -211, -212, 1, 0);
  playback(0, 70, -127, -220, -288, 1, 0);
  playback(0, 50, -127, -229, -383, 1, 0);
  playback(0, 30, -127, -239, -464, 1, 0);
  playback(0, 10, -127, -249, -528, 1, 0);
  playback(0, 0, -127, -259, -571, 1, 0);
  playback(0, 0, -127, -267, -593, 1, 0);
  playback(0, 0, -127, -272, -600, 1, 0);
  playback(-10, 0, -127, -272, -600, 1, 0);
  playback(-30, 0, -127, -272, -599, 1, 0);
  playback(-50, 0, -127, -276, -597, 1, 0);
  playback(-70, 0, -127, -299, -597, 1, 0);
  playback(-90, 0, -127, -329, -597, 1, 0);
  playback(-90, 0, -127, -382, -603, 1, 0);
  playback(-70, 0, -127, -441, -608, 1, 0);
  playback(-50, 0, -127, -501, -608, 1, 0);
  playback(-30, 0, -127, -551, -608, 1, 0);
  playback(-10, 0, -127, -587, -619, 1, 0);
  playback(0, 0, -127, -608, -627, 1, 0);
  playback(0, 0, -127, -616, -631, 1, 0);
  playback(0, 0, -127, -615, -631, 1, 0);
  playback(0, 0, -127, -615, -631, 1, 0);
  playback(0, 0, -127, -615, -629, 1, 0);
  playback(0, 0, -127, -615, -629, 1, 0);
  playback(0, 0, -127, -615, -629, 1, 0);
}
