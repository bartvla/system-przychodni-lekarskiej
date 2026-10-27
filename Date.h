#pragma once

class Date {
public:
    int rok;
    int miesiac;
    int dzien;
    int godzina;
    int minuta;

    Date();
    Date(int rok, int miesiac, int dzien, int godzina, int minuta);
    long long wMinutach();
};
