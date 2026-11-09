#include "Recepta.h"

Recepta::Recepta(int id, Date dataWystawienia, Date terminWaznosci)
    : id(id), dataWystawienia(dataWystawienia), terminWaznosci(terminWaznosci) {}

void Recepta::dodajPozycje(PozycjaRecepty p) {
    pozycje.push_back(p);
}

bool Recepta::czyWazna(Date dzis) {
    return dzis.wMinutach() <= terminWaznosci.wMinutach();
}