#pragma once
#include <vector>
#include "Date.h"
#include "PozycjaRecepty.h"
using namespace std;

class Recepta {
private:
    int id;
    Date dataWystawienia;
    Date terminWaznosci;
    vector<PozycjaRecepty> pozycje;

public:
    Recepta(int id, Date dataWystawienia, Date terminWaznosci);
    void dodajPozycje(PozycjaRecepty p);
    bool czyWazna(Date dzis);
};
