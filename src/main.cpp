#include <Arduino.h>
#include "BLETool.h"

BLETool bleUtils;

void setup()
{
  Serial.begin(115200);
  bleUtils.initBLE();
  bleUtils.startAdvertising();
}

void loop()
{
  delay(2000);
}