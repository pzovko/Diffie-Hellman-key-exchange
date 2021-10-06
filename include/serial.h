#include <Arduino.h>

#define COMBINE_DATA(data) (data[0]|(data[1]<<8))
#define DATASIZE  uint16_t // 2bytes


bool sendData(uint16_t *data);
uint16_t receiveData();
