#pragma once
#include <vector>
#include "Osoba.h"
#include "KartaPacjenta.h"
using namespace std;

class Recepta;

class Pacjent : public Osoba {
private:
    KartaPacjenta karta;

public:
    Pacjent(int id, string imie, string nazwisko, string pesel);

    KartaPacjenta& getKarta();
    string opisRoli() override;
    vector<Recepta*> pobierzRecepty();
};
