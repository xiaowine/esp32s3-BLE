#include "BLETool.h"
#include <Arduino.h>

extern bool deviceConnected;

BLETool::BLETool()
    : pServer(nullptr), lyricCharacteristic(nullptr), authorCharacteristic(nullptr), titleCharacteristic(nullptr)
{
}

void BLETool::createCharacteristic(BLEService *pService, BLECharacteristic **characteristic, const char *uuid, BLECharacteristicCallbacks *callbacks)
{
  *characteristic = pService->createCharacteristic(
      uuid,
      BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_WRITE);

  // 设置特征的初始值
  (*characteristic)->setValue("");

  // 设置特征回调
  (*characteristic)->setCallbacks(callbacks);
}

void BLETool::initBLE()
{
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  // 初始化BLE设备
  BLEDevice::init("ESP32S3_BLE_Server");

  // 创建BLE服务器
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // 创建BLE服务
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // 创建和初始化特征
  createCharacteristic(pService, &lyricCharacteristic, LYRIC_CHARACTERISTIC_UUID, new LyricCallbacks());
  createCharacteristic(pService, &authorCharacteristic, AUTHOR_CHARACTERISTIC_UUID, new AuthorCallbacks());
  createCharacteristic(pService, &titleCharacteristic, TITLE_CHARACTERISTIC_UUID, new TitleCallbacks());
  createCharacteristic(pService, &stateCharacteristic, TITLE_CHARACTERISTIC_UUID, new StateCallbacks());
  createCharacteristic(pService, &durationCharacteristic, TITLE_CHARACTERISTIC_UUID, new DurationCallbacks());

  // 启动服务
  pService->start();
}

void BLETool::startAdvertising()
{
  // 开始广告
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
}