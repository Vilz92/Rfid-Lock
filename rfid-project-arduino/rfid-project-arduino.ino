#include "rfid.h"
#include "lukko.h"
#include "ledit.h"
#include <AccelStepper.h> // Stepperimoottorin ohjauskirjasto
#include <SPI.h> // Rfid-komponentin kanssa puhutaan SPI-väylän kautta
#include <MFRC522.h> // Rfid-komponentin käyttökirjasto

// Olioista yms. pitää tehdä globaaleja, että loop-funktio näkee ne
Ledit* ledit;
Lukko* lukko;
Rfid* rfid;
int vastaus = 0; // PC:ltä tuleva vastaus

// Alustusfunktio, jossa tehdään luokista oliot jne.
void setup() {
  ledit = new Ledit();
  lukko = new Lukko();
  rfid = new Rfid();
  
  // Avataan yhteys tietokoneeseen
  Serial.begin(9600);
  
  // Jos yhteys ei toimi, välkytetään punaista lediä
  while(!Serial)
  {
     ledit->punainen();
     delay(200);
  }
}

void loop() {
  
  // Tarkkaillaan, ilmaantuuko rfid-kortti lukijaan
  if(rfid->odota_korttia())
  {
    // Lähetetään tiedot PC:lle
    rfid->kortista_tiedot();
    
    // Odotetaan vastausta ja väläytetään lamppua ja ohjataan lukkoa vastauksen mukaan
    // Odotetaan niin kauan, että vastaus tulee
    //while(!(Serial.available() > 0)){}
    
    vastaus = Serial.parseInt();

    if(vastaus == 1)
    {
      // Väläytetään vihreää valoa
      ledit->vihrea();
      // Ja avataan lukko
      lukko->avaa_sulje();
    }
    else
    {
      // Ei sisäänpääsyä, väläytetään punaista valoa
      ledit->punainen();
    }
  }
}
