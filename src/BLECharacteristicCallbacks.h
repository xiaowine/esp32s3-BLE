#ifndef BLE_CHARACTERISTIC_CALLBACKS_H
#define BLE_CHARACTERISTIC_CALLBACKS_H

#include <BLECharacteristic.h>

class LyricCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic);
};

class AuthorCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic);
};

class TitleCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic);
};
class StateCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic);
};
class DurationCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic);
};

#endif // BLE_CHARACTERISTIC_CALLBACKS_H