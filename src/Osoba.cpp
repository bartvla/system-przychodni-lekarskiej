#include "Osoba.h"

using namespace std;

Osoba::Osoba(int id, string imie, string nazwisko, string pesel)
    : id(id), imie(imie), nazwisko(nazwisko), pesel(pesel) {}

int Osoba::getId() const {
    return id;
}

string Osoba::getPelneNazwisko() const {
    return imie + " " + nazwisko;
}