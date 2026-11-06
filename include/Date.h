#pragma once

class Date {
public:
    int dzien;
    int miesiac;
    int rok;
    int godzina;
    int minuta;

    Date();
    Date(int dzien, int miesiac, int rok, int godzina, int minuta);
    long long wMinutach();
};
