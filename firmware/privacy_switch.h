#ifndef PRIVACY_SWITCH_H
#define PRIVACY_SWITCH_H

#include <stdbool.h>

void privacySwitchInit();
void privacySwitchISR();
void privacySwitchUpdate();

bool isPrivacySwitchOff();
bool isCameraEnabled();

void requestCameraEnable();
void requestCameraDisable();

#endif
