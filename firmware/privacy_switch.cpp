#include "privacy_switch.h"
#include <Arduino.h>

#define PRIVACY_SWITCH_PIN 2

volatile bool interruptFlag = false;
volatile unsigned long lastInterruptTime = 0;

const unsigned long debounceTime = 50;

bool privacyOff = false;
bool cameraEnabled = false;

void IRAM_ATTR privacySwitchISR()
{
    unsigned long now = millis();

    if (now - lastInterruptTime > debounceTime)
    {
        interruptFlag = true;
        lastInterruptTime = now;
    }
}

void privacySwitchInit()
{
    pinMode(PRIVACY_SWITCH_PIN, INPUT_PULLUP);

    attachInterrupt(
        digitalPinToInterrupt(PRIVACY_SWITCH_PIN),
        privacySwitchISR,
        CHANGE);

    privacySwitchUpdate();
}

void privacySwitchUpdate()
{
    if (!interruptFlag)
        return;

    interruptFlag = false;

    privacyOff = (digitalRead(PRIVACY_SWITCH_PIN) == LOW);

    if (privacyOff)
    {
        cameraEnabled = false;
    }
}

bool isPrivacySwitchOff()
{
    return privacyOff;
}

bool isCameraEnabled()
{
    return cameraEnabled;
}

void requestCameraEnable()
{
    if (privacyOff)
    {
        cameraEnabled = false;
        return;
    }

    cameraEnabled = true;
}

void requestCameraDisable()
{
    cameraEnabled = false;
}
