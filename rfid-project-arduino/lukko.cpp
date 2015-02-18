#include "lukko.h"

Lukko::Lukko()
{
  // Pinnijärjestys tällä moottorilla pitää olla 1,3,2,4
  ohjain = new AccelStepper(moottorin_tyyppi, pinni1, pinni3, pinni2, pinni4); 
  ohjain->setMaxSpeed(max_nopeus);
  ohjain->setAcceleration(kiihtyvyys);
  ohjain->setSpeed(nopeus);
}

Lukko::~Lukko()
{
  delete ohjain;
  ohjain = 0;
}


void Lukko::avaa_sulje()
{
  ohjain->moveTo(AUKI);
  while(ohjain->distanceToGo() != 0)
  {
    ohjain->run();
  }
  
  // Lukko auki 3 sekuntia
  delay(3000);
  
  ohjain->moveTo(KIINNI);
  while(ohjain->distanceToGo() != 0)
  {
    ohjain->run();
  }
}
