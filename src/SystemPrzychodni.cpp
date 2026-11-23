#include "SystemPrzychodni.h"
#include "Recepta.h"
using namespace std;

Pacjent *SystemPrzychodni::dodajPacjenta(int id, string imie, string nazwisko, string pesel)
{
    pacjenci.push_back(make_unique<Pacjent>(id, imie, nazwisko, pesel));
    return pacjenci.back().get();
}

Lekarz *SystemPrzychodni::dodajLekarza(int id, string imie, string nazwisko, string pesel, string specjalizacja, string numerPWZ, Date dataZatrudnienia)
{
    lekarze.push_back(make_unique<Lekarz>(id, imie, nazwisko, pesel, specjalizacja, numerPWZ, dataZatrudnienia));
    return lekarze.back().get();
}

Pacjent *SystemPrzychodni::znajdzPacjenta(int idPacjenta)
{
    for (auto &p : pacjenci)
    {
        if (p->getId() == idPacjenta)
        {
            return p.get();
        }
    }
    return nullptr;
}

Lekarz *SystemPrzychodni::znajdzLekarza(int idLekarza)
{
    for (auto &l : lekarze)
    {
        if (l->getId() == idLekarza)
        {
            return l.get();
        }
    }
    return nullptr;
}

Wizyta *SystemPrzychodni::znajdzWizyte(int idWizyty)
{
    for (auto &w : wizyty)
    {
        if (w->getId() == idWizyty)
        {
            return w.get();
        }
    }
    return nullptr;
}

vector<Lekarz *> SystemPrzychodni::wyszukajLekarzy(string specjalizacja)
{
    vector<Lekarz *> wynik;
    for (auto &l : lekarze)
    {
        if (l->getSpecjalizacja() == specjalizacja)
        {
            wynik.push_back(l.get());
        }
    }
    return wynik;
}

vector<SlotCzasowy *> SystemPrzychodni::pobierzWolneSloty(int idLekarza)
{
    Lekarz *lekarz = znajdzLekarza(idLekarza);
    if (lekarz == nullptr)
    {
        return {};
    }
    return lekarz->pobierzWolneSloty();
}

Wizyta *SystemPrzychodni::zarezerwujWizyte(int idPacjenta, int idLekarza, int idSlotu)
{
    Pacjent *pacjent = znajdzPacjenta(idPacjenta);
    Lekarz *lekarz = znajdzLekarza(idLekarza);
    if (pacjent == nullptr || lekarz == nullptr)
    {
        return nullptr;
    }

    SlotCzasowy *slot = lekarz->znajdzSlot(idSlotu);
    if (slot == nullptr)
    {
        return nullptr;
    }

    if (!slot->zablokuj())
    {
        return nullptr;
    }

    wizyty.push_back(make_unique<Wizyta>(nastepneIdWizyty, pacjent, lekarz, slot));
    ++nastepneIdWizyty;

    Wizyta *nowaWizyta = wizyty.back().get();
    pacjent->getKarta().dodajWizyte(nowaWizyta);
    return nowaWizyta;
}

bool SystemPrzychodni::odwolajWizyte(int idWizyty)
{
    Wizyta *wizyta = znajdzWizyte(idWizyty);
    if (wizyta == nullptr)
    {
        return false;
    }
    return wizyta->odwolaj();
}

bool SystemPrzychodni::zakonczWizyte(int idWizyty)
{
    Wizyta *wizyta = znajdzWizyte(idWizyty);
    if (wizyta == nullptr)
    {
        return false;
    }
    return wizyta->zakoncz();
}

Recepta *SystemPrzychodni::wystawRecepte(int idWizyty, int idLekarza, Date dataWystawienia, Date terminWaznosci)
{
    Wizyta *wizyta = znajdzWizyte(idWizyty);
    if (wizyta == nullptr)
    {
        return nullptr;
    }

    if (wizyta->getLekarz()->getId() != idLekarza)
    {
        return nullptr;
    }

    Recepta *recepta = new Recepta(nastepneIdRecepty, dataWystawienia, terminWaznosci);
    if (!wizyta->przypiszRecepte(recepta))
    {
        delete recepta;
        return nullptr;
    }

    ++nastepneIdRecepty;
    return recepta;
}