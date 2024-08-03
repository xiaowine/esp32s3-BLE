#ifndef BLE_SERVER_CALLBACKS_H
#define BLE_SERVER_CALLBACKS_H

#include <BLEServer.h>

class MyServerCallbacks : public BLEServerCallbacks
{
public:
  bool deviceConnected = false;
  void onConnect(BLEServer *pServer);
  void onDisconnect(BLEServer *pServer);

private:
  int connectedCount = 0;
};

#endif // BLE_SERVER_CALLBACKS_H