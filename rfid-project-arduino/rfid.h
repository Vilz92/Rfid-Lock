#ifndef RFID_H
#define RFID_H
#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

// Reset-pinniksi 9
const byte RST_PIN = 9;
// SDA(SS)-pinni 10
const byte SS_PIN = 10;

class Rfid
{
  public:
    Rfid();
    ~Rfid();
    
    // Palauttaa true, jos ilmestyy kortti ja luku onnistuu
    bool odota_korttia();
    
    // Tällä haetaan kortista tiedot ja lähetetään serialin kautta pc:lle
    void kortista_tiedot();
  private:
    MFRC522* rfid_rajapinta;
    
};
#endif
