#include "ledit.h"

Ledit::Ledit()
{
  pinMode(viherpinni, OUTPUT);
  pinMode(punapinni, OUTPUT);
}

Ledit::~Ledit()
{
  
}

void Ledit::punainen()
{
  digitalWrite(punapinni, HIGH);
  delay(1000);
  digitalWrite(punapinni, LOW);
}

void Ledit::vihrea()
{
  digitalWrite(viherpinni, HIGH);
  delay(1000);
  digitalWrite(viherpinni, LOW);
}
