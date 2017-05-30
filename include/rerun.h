/**
 * @file ReRun
 * @brief a library for recording driver input and playing it back in autonomous
 */
#ifndef _RERUN_H_
#define _RERUN_H_

#include "main.h"

// void startRecording(unsigned long duration, unsigned int dt, unsigned int id_num);
// void stopRecording();
// void playback(int script_num);
// void stopPlayback();

#define RESOLUTION 40 //time between frames in millis
#define RERUN_DRIVE_KP 0.4f
#define RERUN_DRIVE_KI 0.05f
#define RERUN_DRIVE_KD 0.0f
#define RERUN_DRIVE_MAX_INTEGRAL 10000

void startRecording(button_t killswitch);
void playback(char left_set, char right_set, char lift_set, long left_pos, long right_pos, long lift_pos, bool status);
void playbackInit();

#endif
