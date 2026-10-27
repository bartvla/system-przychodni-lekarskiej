#pragma once
#include <vector>
#include "Osoba.h"
#include "Date.h"
#include "SlotCzasowy.h"
#include "PozycjaRecepty.h"
using namespace std;

class Wizyta;
class Recepta;

class Lekarz : public Osoba {
private:
    string specjalizacja;
    string numerPWZ;
    Date dataZatrudnienia;
    vector<SlotCzasowy*> kalendarz;

public:
    Lekarz(int id, string imie, string nazwisko, string pesel,
           string specjalizacja, string numerPWZ, Date dataZatrudnienia);
    ~Lekarz();

    string getSpecjalizacja();
    string opisRoli() override;
    bool dodajSlot(Date poczatek, int czasMin);
    vector<SlotCzasowy*> pobierzWolneSloty();
    Recepta* wystawRecepte(Wizyta* w, vector<PozycjaRecepty> leki);
};
