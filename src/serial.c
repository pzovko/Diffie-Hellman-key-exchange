#include "serial.h"

bool sendData(uint16_t *data)
{
     byte buff[sizeof(DATASIZE)];

     for(int i = 0; i < sizeof(DATASIZE); i++)
         buff[i] = (byte)((*data >> (i*8)) & 255);

    for(;;)
    {
        if(Serial.availableForWrite() >= sizeof(DATASIZE))
        {  
            Serial.write(buff, sizeof(buff));
            delay(500);
            return 0;
        }
    }
}

uint16_t receiveData()
{
    byte buf[sizeof(DATASIZE)];
    uint16_t data;
    byte i = 0;

    for(;i<sizeof(DATASIZE);)
    {
        if(Serial.available() > 0)
        {
            buf[i] = Serial.read();
            i++;
        }
    }
        data = (uint16_t)COMBINE_DATA(buf);
        delay(500);
      return data;    
}