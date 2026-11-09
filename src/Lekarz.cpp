#include "Lekarz.h"

Lekarz::Lekarz(int id, std::string imie, std::string nazwisko, std::string pesel,
               std::string specjalizacja, std::string numerPWZ, Date dataZatrudnienia)
    : Osoba(id, imie, nazwisko, pesel),
      specjalizacja(specjalizacja),
      numerPWZ(numerPWZ),
      dataZatrudnienia(dataZatrudnienia) {}

std::string Lekarz::getSpecjalizacja() const {
    return specjalizacja;
}

std::string Lekarz::opisRoli() const {
    return "Lekarz spec. " + specjalizacja;
}