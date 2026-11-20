#include "Pacjent.h"

Pacjent::Pacjent(int id, std::string imie, std::string nazwisko, std::string pesel)
    : Osoba(id, imie, nazwisko, pesel), karta(id) {}

KartaPacjenta &Pacjent::getKarta()
{
    return karta;
}

std::string Pacjent::opisRoli() const
{
    return "Pacjent";
}

std::vector<Recepta *> Pacjent::pobierzRecepty()
{
    return karta.pobierzRecepty();
}