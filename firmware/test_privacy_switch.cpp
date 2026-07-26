#include "privacy_switch.h"

void setup()
{
    Serial.begin(115200);

    privacySwitchInit();
}

void loop()
{
    privacySwitchUpdate();

    requestCameraEnable();

    if (isPrivacySwitchOff())
    {
        if (isCameraEnabled())
        {
            Serial.println("TEST FAILED");
        }
        else
        {
            Serial.println("PASS: Hardware override active");
        }
    }
    else
    {
        Serial.println("Privacy switch ON");
    }

    delay(1000);
}
