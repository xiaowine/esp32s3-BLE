#include "BLECharacteristicCallbacks.h"
#include <Arduino.h>

void LyricCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  std::string value = pCharacteristic->getValue();
  Serial.print("Lyric Characteristic value written: ");
  Serial.println(value.c_str());
}

void AuthorCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  std::string value = pCharacteristic->getValue();
  Serial.print("Author Characteristic value written: ");
  Serial.println(value.c_str());
}

void TitleCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  std::string value = pCharacteristic->getValue();
  Serial.print("Title Characteristic value written: ");
  Serial.println(value.c_str());
}

void StateCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  std::string value = pCharacteristic->getValue();
  Serial.print("State Characteristic value written: ");
  Serial.println(value.c_str());
}
void DurationCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
  std::string value = pCharacteristic->getValue();
  Serial.print("State Characteristic value written: ");
  Serial.println(value.c_str());
}