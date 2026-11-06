#include "Osoba.h"

Osoba::Osoba(int id, string imie, string nazwisko, string pesel) {
    this -> id = id;
    this -> imie = imie;
    this -> nazwisko = nazwisko;
    this -> pesel = pesel;
}

int Osoba::getId() {
    return id;
}

string Osoba::getPelneNazwisko() {
    return imie + " " + nazwisko;
}
