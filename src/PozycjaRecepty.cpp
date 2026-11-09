#include "PozycjaRecepty.h"

PozycjaRecepty::PozycjaRecepty(string lek, string dawkowanie)
    : lek(lek), dawkowanie(dawkowanie) {}

string PozycjaRecepty::opis() {
    return lek + " - " + dawkowanie;
}