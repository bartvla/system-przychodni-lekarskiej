#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Pacjent.h"
#include "Lekarz.h"
#include "Wizyta.h"
#include "SlotCzasowy.h"

class SystemPrzychodni
{
private:
    std::vector<std::unique_ptr<Pacjent>> pacjenci;
    std::vector<std::unique_ptr<Lekarz>> lekarze;
    std::vector<std::unique_ptr<Wizyta>> wizyty;
    int nastepneIdWizyty = 1;
    int nastepneIdRecepty = 1;

public:
    Pacjent *dodajPacjenta(int id, std::string imie, std::string nazwisko, std::string pesel);
    Pacjent *znajdzPacjenta(int idPacjenta);
    Lekarz *dodajLekarza(int id, std::string imie, std::string nazwisko, std::string pesel, std::string specjalizacja, std::string numerPWZ, Date dataZatrudnienia);
    Lekarz *znajdzLekarza(int idLekarza);
    std::vector<Lekarz *> wyszukajLekarzy(std::string specjalizacja);
    std::vector<SlotCzasowy *> pobierzWolneSloty(int idLekarza);
    Wizyta *znajdzWizyte(int idWizyty);
    Wizyta *zarezerwujWizyte(int idPacjenta, int idLekarza, int idSlotu);
    bool odwolajWizyte(int idWizyty);
    bool zakonczWizyte(int idWizyty);
    Recepta *wystawRecepte(int idWizyty, int idLekarza, Date dataWystawienia, Date terminWaznosci);
};