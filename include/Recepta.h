#pragma once
#include <vector>
#include <string>
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
    Date getTerminWaznosci() const { return terminWaznosci; }
    void dodajPozycje(PozycjaRecepty p);
    bool czyWazna(Date dzis);
    std::string opis();
};
