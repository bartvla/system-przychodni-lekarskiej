#include "Pacjent.h"
// #include "KartaPacjenta.h"
using namespace std;

Pacjent::Pacjent(int id, string imie, string nazwisko, string pesel) 
    : Osoba(id, imie, nazwisko, pesel) {}

// KartaPacjenta& Pacjent::getKarta() {
//     return karta;
// }

string Pacjent::opisRoli() const {
    return "Pacjent";
}

// vector<Recepta*> Pacjent::pobierzRecepty() {
//     return karta.pobierzRecepty();
// }