#pragma once
#include <vector>

class Wizyta;
class Recepta;

class KartaPacjenta {
private:
    int numerKarty;
    std::vector<Wizyta*> historiaWizyt;

public:
    KartaPacjenta(int numerKarty);
    void dodajWizyte(Wizyta* w);
    std::vector<Recepta*> pobierzRecepty();
};