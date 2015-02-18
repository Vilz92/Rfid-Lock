#ifndef LUKKO_H
#define LUKKO_H
#include <Arduino.h>
#include <AccelStepper.h>

const int pinni1 = 6;
const int pinni2 = 5;
const int pinni3 = 3;
const int pinni4 = 4;
const int moottorin_tyyppi = 8;
const float max_nopeus = 1200.0;
const float kiihtyvyys = 120.0;
const int nopeus = 200;
const int AUKI = 2500; // Suunnilleen 180 astetta
const int KIINNI = 0;

class Lukko
{
  public:
    Lukko();
    ~Lukko();
    void avaa_sulje();
  private:
    AccelStepper* ohjain;
};
#endif
