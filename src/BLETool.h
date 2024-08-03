#ifndef BLE_TOOL_H
#define BLE_TOOL_H

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include "BLEServerCallbacks.h"
#include "BLECharacteristicCallbacks.h"

class BLETool
{
#define SERVICE_UUID "e591a226-81a2-4326-9ee8-f7df05cdce9c"
#define LYRIC_CHARACTERISTIC_UUID "e2fd7ec9-fc39-46e2-af28-7fbf5dcedaeb"
#define AUTHOR_CHARACTERISTIC_UUID "c51d530e-8afa-4de4-95d2-2e6323729cf3"
#define TITLE_CHARACTERISTIC_UUID "ec7450a3-7c19-4eac-a54a-1c635784fb7e"

public:
  BLETool();
  void initBLE();
  void startAdvertising();
  void setMaxConnections(uint8_t maxConnections);

private:
  BLEServer *pServer;
  BLECharacteristic *lyricCharacteristic;
  BLECharacteristic *authorCharacteristic;
  BLECharacteristic *titleCharacteristic;

  void createCharacteristic(BLEService *pService, BLECharacteristic **characteristic, const char *uuid, BLECharacteristicCallbacks *callbacks);
};

#endif // BLE_TOOL_H