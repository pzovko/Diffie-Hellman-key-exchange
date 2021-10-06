#include <math.h>
#include <Arduino.h>

#define BASE 2
#define PRIME 19
#define KEY_MIN 0
#define KEY_MAX 4

#define CALC_PUBLIC(private_key) (uint16_t)pow(BASE,private_key) % PRIME
#define CALC_SHARED(public_key, private_key) pow16(public_key,private_key) % PRIME

void initRand(void);
uint16_t genSharedKey(uint16_t,uint16_t);
uint16_t genPrivateKey(void);
uint16_t genPublicKey(uint16_t);
uint16_t pow16(uint16_t x, uint16_t y);