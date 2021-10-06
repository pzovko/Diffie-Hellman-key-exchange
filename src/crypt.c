#include "crypt.h"

bool fRand = false;

void initRand(void)
{
    randomSeed(analogRead(0)); // promijenit
    fRand = true;
}
uint16_t genSharedKey(uint16_t uiPublicKey, uint16_t uiPrivateKey)
{
    return CALC_SHARED(uiPublicKey, uiPrivateKey);
}

uint16_t genPrivateKey(void)
{
    if(fRand)
        return (uint16_t)random(KEY_MIN, KEY_MAX);
    else
        return 0;
}

uint16_t genPublicKey(uint16_t uiPrivateKey)
{
    return CALC_PUBLIC(uiPrivateKey);
}

uint16_t pow16(uint16_t x, uint16_t y)
{
    uint16_t a = 1;
    for(uint16_t i = 1; i<= y; i++)
        a*=x;
     
     return a;
}

