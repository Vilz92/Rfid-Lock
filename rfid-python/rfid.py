import serial


class Rekisteri:
    def __init__(self, rekisteri):
        self.__rekisteri = rekisteri

    def nayta_kayttajat(self):
        for kayttaja in self.__rekisteri:
            print(kayttaja)

    def lisaa_kayttaja(self):
        pass

    def poista_kayttaja(self):
        pass

    def loytyyko_kayttaja(self, ID):
        return True


def lue_tiedosto():
    rekisteri = []
    try:
        tiedosto = open("tiedot.txt")
        for rivi in tiedosto:
            pass
        return rekisteri
    except IOError:
        print("Tapahtui tiedostonlukuvirhe!")
        return None


def kasittele_data():
    return []


def lukutila(rekisteri):
    # Alustetaan yhteys
    ser = serial.Serial('COM5', 9600)

    # Odotetaan, että kortti ilmaantuu, eli kunnes viestiä tulee
    print("Odotetaan korttia...")
    while ser.readline() == "":
        pass

    # Kun kortti tulee lukijaan, alkaa viestiä tulla. Luetaan se
    kortin_tiedot = []
    RIVEJA = 66
    i = 0
    while i < RIVEJA:
        rivi = ser.readline()
        kortin_tiedot.append(rivi)
        print(rivi)
        i += 1

    # Tarkastetaan, löytyykö kortin tietoja vastaava ID rekisteristä
    ID = kasittele_data()
    loytyy = rekisteri.loytyyko_kayttaja(ID)

    # Palautetaan koneelle 1, jos henkilö löytyy, muuten 0
    loytyy = False
    if loytyy:
        ser.write(b'1')
    else:
        ser.write(b'0')


def kirjoita_kortille(rekisteri):
    # Alustetaan yhteys
    ser = serial.Serial('COM5', 9600)

    kayttaja = input("Anna käyttäjä, jonka haluat kortille lisätä: ")

    # Käsketään arduinoa menemään kirjoitustilaan
    ser.write(b'kirjoita')




def apua():
    print("Näytä rekisterissä olevat henkilöt: nayta")
    print("Lisää käyttäjä rekisteriin: lisaa")
    print("Poista käyttäjä rekisteristä: poista")
    print("Siirry kortin tarkkailutilaan: lue")
    print("Kirjoita henkilötiedot kortille: kirjoita")
    print("Lopeta: q")


def main():
    print("VahtiVillen käyttäjätunnusten hallinta.")
    tiedot = lue_tiedosto()
    rekisteri = Rekisteri(tiedot)

    if rekisteri is None:
        return

    syote = "a"
    while syote != "q":
        syote = input("> ")

        if syote.lower() == "apua":
            apua()
        elif syote.lower() == "nayta":
            rekisteri.nayta_kayttajat()
        elif syote.lower() == "lisaa":
            rekisteri.lisaa_kayttaja()
        elif syote.lower() == "poista":
            rekisteri.poista_kayttaja()
        elif syote.lower() == "lue":
            lukutila(rekisteri)
        elif syote.lower() == "kirjoita":
            kirjoita_kortille(rekisteri)
        elif syote.lower() == "q":
            pass
        else:
            print("Komentoa ei tunnistettu!")

main()