#pragma once

class Date {
private:
    int dzien;
    int miesiac;
    int rok;
    int godzina;
    int minuta;

public:
    Date();
    Date(int d, int m, int r, int g = 0, int min = 0);

    int getDzien() const;
    int getMiesiac() const;
    int getRok() const;
    int getGodzina() const;
    int getMinuta() const;

    long long wMinutach() const;
};