#include "Recepta.h"
using namespace std;

Recepta::Recepta(int id, Date dataWystawienia, Date terminWaznosci)
    : id(id), dataWystawienia(dataWystawienia), terminWaznosci(terminWaznosci) {}

void Recepta::dodajPozycje(PozycjaRecepty p)
{
    pozycje.push_back(p);
}

bool Recepta::czyWazna(Date dzis)
{
    return dzis.wMinutach() <= terminWaznosci.wMinutach();
}

int Recepta::getId()
{
    return id;
}

string Recepta::opis()
{
    string wynik = "Recepta nr " + to_string(id) + ":";
    for (PozycjaRecepty &p : pozycje)
    {
        wynik += "\n - " + p.opis();
    }
    return wynik;
}