#pragma once
#include <vector>
#include <string>
#include "Pacjent.h"
#include "Lekarz.h"
#include "Wizyta.h"
#include "SlotCzasowy.h"
using namespace std;

class SystemPrzychodni {
private:
    vector<Pacjent*> pacjenci;
    vector<Lekarz*> lekarze;
    vector<Wizyta*> wizyty;

public:
    ~SystemPrzychodni();

    void dodajPacjenta(Pacjent* p);
    void dodajLekarza(Lekarz* l);
    Pacjent* znajdzPacjenta(int idPacjenta);
    Lekarz* znajdzLekarza(int idLekarza);
    Wizyta* znajdzWizyte(int idWizyty);
    vector<Lekarz*> wyszukajLekarzy(string specjalizacja);
    vector<SlotCzasowy*> pobierzWolneSloty(int idLekarza);
    Wizyta* zarezerwujWizyte(int idPacjenta, int idLekarza, int idSlotu);
    bool odwolajWizyte(int idWizyty);
};
