#include "PozycjaRecepty.h"
using namespace std;

PozycjaRecepty::PozycjaRecepty(string lek, string dawkowanie)
    : lek(lek), dawkowanie(dawkowanie) {}

string PozycjaRecepty::opis() const{
    return lek + " - " + dawkowanie;
}