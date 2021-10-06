#include "crypt.h"
#include "serial.h"

/* Arduino Nano ATMega2560*/

#define LED_PIN 6

bool fKeyReceived = false;

uint16_t uiSharedKey = 0;
uint16_t uiPrivateKey = 1; //genPrivateKey();
uint16_t uiPublicKeyPC = 0;
uint16_t uiPublicKeyArduino = 0;

void setup() {
  Serial.begin(9600);
  delay(250);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
 // initRand();
}

void loop() {

    if(fKeyReceived)
    {
      //Obradi podatke
      uint16_t cipher = receiveData();
      delay(500);
      uint16_t data = cipher^uiSharedKey;

      analogWrite(LED_PIN, (uint8_t)data);
    }
    else
    {
      //Razmijeni kljuc
      uiPublicKeyPC = receiveData();
      uiSharedKey = genSharedKey(uiPublicKeyPC, uiPrivateKey);
      uiPublicKeyArduino = genPublicKey(uiPrivateKey);
      sendData(&uiPublicKeyArduino);
      delay(500);
      if(uiPublicKeyPC)
        fKeyReceived = true;
      }
  }


