#ifndef LEDIT_H
#define LEDIT_H
#include <Arduino.h>

const int punapinni = 7;
const int viherpinni = 2;

class Ledit
{
  public:
    Ledit();
    ~Ledit();
    
    // Tehdään kaksi funktiota, niin mukavampi kutsua "pääohjelmasta"
    void punainen();
    void vihrea();
  private:
    
};
#endif
