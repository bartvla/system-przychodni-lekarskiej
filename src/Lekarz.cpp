#include "Lekarz.h"
using namespace std;

Lekarz::Lekarz(int id, string imie, string nazwisko, string pesel, 
               string specjalizacja, string numerPWZ, Date dataZatrudnienia) 
    : Osoba(id, imie, nazwisko, pesel),
      specjalizacja(specjalizacja),
      numerPWZ(numerPWZ),
      dataZatrudnienia(dataZatrudnienia) {}

string Lekarz::getSpecjalizacja() const {
    return specjalizacja;
}

string Lekarz::opisRoli() const {
    return "Lekarz spec. " + specjalizacja;
}