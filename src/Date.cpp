#include "Date.h"

Date::Date() {
    dzien = 0;
    miesiac = 0;
    rok = 0;
    godzina = 0;
    minuta = 0;
}

Date::Date(int dzien, int miesiac, int rok, int godzina, int minuta) {
    this -> dzien = dzien;
    this -> miesiac = miesiac;
    this -> rok = rok;
    this -> godzina = godzina;
    this -> minuta = minuta;
}

long long Date::wMinutach() {
    long long wynik = rok;
    wynik = wynik * 12 * miesiac;
    wynik = wynik * 31 * dzien;
    wynik = wynik * 24 * godzina;
    wynik = wynik * 60 * minuta;

    return wynik;
}