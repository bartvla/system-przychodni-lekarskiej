#pragma once
#include <vector>
using namespace std;

class Wizyta;
class Recepta;

class KartaPacjenta {
private:
    int numerKarty;
    vector<Wizyta*> historiaWizyt;

public:
    KartaPacjenta(int numerKarty);
    void dodajWizyte(Wizyta* w);
    vector<Recepta*> pobierzRecepty();
};
