#include "Date.h"

Date::Date() 
    : dzien(1), miesiac(1), rok(2000), godzina(0), minuta(0) {}

Date::Date(int d, int m, int r, int g, int min) 
    : dzien(d), miesiac(m), rok(r), godzina(g), minuta(min) {}

int Date::getDzien() const {
    return dzien;
}

int Date::getMiesiac() const {
    return miesiac;
}

int Date::getRok() const {
    return rok;
}

int Date::getGodzina() const {
    return godzina;
}

int Date::getMinuta() const {
    return minuta;
}

long long Date::wMinutach() const {
    long long sumaMinut = 0;
    sumaMinut += (long long)rok * 525600;
    sumaMinut += (long long)miesiac * 43200;
    sumaMinut += (long long)dzien * 1440;
    sumaMinut += godzina * 60;
    sumaMinut += minuta;

    return sumaMinut;
}