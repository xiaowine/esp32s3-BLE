#include "BLEServerCallbacks.h"

void MyServerCallbacks::onConnect(BLEServer *pServer)
{
  connectedCount++;
  deviceConnected = true;
  if (connectedCount >= 1)
  {
    pServer->getAdvertising()->stop();
  }
}

void MyServerCallbacks::onDisconnect(BLEServer *pServer)
{
  connectedCount--;
  deviceConnected = false;
  if (connectedCount < 1)
  {
    pServer->getAdvertising()->start();
  }
}