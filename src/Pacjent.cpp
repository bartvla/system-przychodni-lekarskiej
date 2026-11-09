#include "Pacjent.h"

Pacjent::Pacjent(int id, std::string imie, std::string nazwisko, std::string pesel)
    : Osoba(id, imie, nazwisko, pesel) {}

std::string Pacjent::opisRoli() const {
    return "Pacjent";
}