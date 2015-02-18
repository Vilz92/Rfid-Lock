# Rfid-Lock
Yksinkertainen rfid-tunnisteella toimiva sähkölukko. Kun lukijaan tuodaan rfid-kortti, lukee
laite sen tiedot, lähettää sarjaportin (USB) kautta tietokoneelle, jossa pyörii python-ohjelma,
joka sisältää tietokannan käyttäjistä. Ohjelma tarkastaa, löytyykö kortin tiedot rekisteristä. 

Jos löytyy, ohjelma lähettää Arduinolle 1:n, muutoin 0:n. Arduino käskee vihreän ledin välkähtää
ja moottorin kääntyä 180 asteen kulmaan 3:ksi sekunniksi, jonka jälkeen se palaa lähtökulmaan.
Jos taas käyttäjää ei löydy, väläytetään punaista lediä.

Ohjelma käyttää AccelStepper (http://www.airspayce.com/mikem/arduino/AccelStepper/) ja
MFRC522 (https://github.com/miguelbalboa/rfid) -kirjastoja.

TODO:
Python-ohjelmassa käyttäjänhallinta kuntoon ja kortin ohjelmointitila (rfid-tagiin voi lisätä käyttäjätietoja
ja poistaa niitä).

Käytetyt osat:

- Arduino Uno
- Punainen ja vihreä ledi
- 2 x 220 ohmin vastus
- MFRC522 rfid-kortinlukija
- 28BYJ48 Stepperimoottori ja driver
- Hyppylankoja x kpl
- USB-kaapeli
- PC

<hr>

Johdotukset:

MFRC522 <---> Arduino:
<ul style="list-style-type:none">
 <li> RST <---> pin 9 </li>
 <li> SDA <---> pin 10 </li>
 <li> MOSI <--> pin 11 </li>
 <li> MISO <--> pin 12 </li>
 <li> SCK <---> 13 </li>
</ul>
  
Ledit <---> Arduino

- Punaisen katodi <---> pin 7
- Vihreän katodi <----> pin 2

Stepperin driver <---> Arduino
- pin 1 <---> pin 6
- pin 2 <---> pin 5
- pin 3 <---> pin 3
- pin 3 <---> pin 4

Lisäksi virtajohdot, 5 volttia moottoriin ja 3.3 volttia kortinlukijaan ja ledeihin.

<img src="https://github.com/Vilz92/Rfid-Lock/blob/master/rfid_suunnitelma_bb.png?raw=true" width="500" height="400">
<p>Kuva 1. Suunnitelma laitteistosta</p>

