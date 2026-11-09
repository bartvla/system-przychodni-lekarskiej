#include "KartaPacjenta.h"
#include "Wizyta.h"

KartaPacjenta::KartaPacjenta(int numerKarty) 
    : numerKarty(numerKarty) {}

void KartaPacjenta::dodajWizyte(Wizyta* w) {
    if (w != nullptr) {
        historiaWizyt.push_back(w);
    }
}

vector<Recepta*> KartaPacjenta::pobierzRecepty() {
    vector<Recepta*> recepty;
    return recepty;
}