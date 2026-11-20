#pragma once
#include <vector>
#include "Date.h"
#include "PozycjaRecepty.h"

class Recepta
{
private:
    int id;
    Date dataWystawienia;
    Date terminWaznosci;
    std::vector<PozycjaRecepty> pozycje;

public:
    Recepta(int id, Date dataWystawienia, Date terminWaznosci);
    int getId();
    void dodajPozycje(PozycjaRecepty p);
    bool czyWazna(Date dzis);
    std::string opis();
};
