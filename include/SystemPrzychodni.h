#pragma once
#include <vector>
#include <string>
#include "Pacjent.h"
#include "Lekarz.h"
#include "Wizyta.h"
#include "SlotCzasowy.h"
using namespace std;

class SystemPrzychodni
{
private:
    vector<unique_ptr<Pacjent>> pacjenci;
    vector<unique_ptr<Lekarz>> lekarze;
    vector<unique_ptr<Wizyta>> wizyty;
    int nastepneIdWizyty = 1;
    int nastepneIdRecepty = 1;

public:
    Pacjent *dodajPacjenta(int id, string imie, string nazwisko, string pesel);
    Pacjent *znajdzPacjenta(int idPacjenta);
    Lekarz *dodajLekarza(int id, string imie, string nazwisko, string pesel, string specjalizacja, string numerPWZ, Date dataZatrudnienia);
    Lekarz *znajdzLekarza(int idLekarza);
    vector<Lekarz *> wyszukajLekarzy(string specjalizacja);
    vector<SlotCzasowy *> pobierzWolneSloty(int idLekarza);
    Wizyta *znajdzWizyte(int idWizyty);
    Wizyta *zarezerwujWizyte(int idPacjenta, int idLekarza, int idSlotu);
    bool odwolajWizyte(int idWizyty);
    bool zakonczWizyte(int idWizyty);
    Recepta *wystawRecepte(int idWizyty, int idLekarza, Date dataWystawienia, Date terminWaznosci);
};
