#include "Lekarz.h"
#include "Date.h"

Lekarz::Lekarz(int id, string imie, string nazwisko, string pesel, string specjalizacja, string numerPWZ, Date dataZatrudnienia) 
: Osoba(id, imie, nazwisko, pesel) {
    this -> specjalizacja = specjalizacja;
    this -> numerPWZ = numerPWZ;
    this -> dataZatrudnienia = dataZatrudnienia;
}

string Lekarz::getSpecjalizacja() {
    return specjalizacja;
}

string Lekarz::opisRoli() {
    return "Lekarz";
}