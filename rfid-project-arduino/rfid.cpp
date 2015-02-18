#include "rfid.h"

Rfid::Rfid()
{
  // Rfidin ohjaukseen käytettävä olio
  rfid_rajapinta = new MFRC522(SS_PIN, RST_PIN);
  
  // Spi-väylä auki
  SPI.begin();
  
  // Alustetaan rfid-komponentti
  rfid_rajapinta->PCD_Init();
}

Rfid::~Rfid()
{
  delete rfid_rajapinta;
  rfid_rajapinta = 0;
}

bool Rfid::odota_korttia()
{
  // Jos ei uutta korttia, palataan
  if (!rfid_rajapinta->PICC_IsNewCardPresent())
  {
    return false;
  }

  // Jos korttia ei voida lukea, palataan
  if (!rfid_rajapinta->PICC_ReadCardSerial())
  {
    return false;
  }
  
  // Jos päästään tähän, on kortin luku onnistunut
  return true;
}

void Rfid::kortista_tiedot()
{
  rfid_rajapinta->PICC_DumpToSerial(&(rfid_rajapinta->uid));
}
