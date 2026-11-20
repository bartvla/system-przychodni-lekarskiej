#include "Lekarz.h"

Lekarz::Lekarz(int id, std::string imie, std::string nazwisko, std::string pesel,
               std::string specjalizacja, std::string numerPWZ, Date dataZatrudnienia)
    : Osoba(id, imie, nazwisko, pesel),
      specjalizacja(specjalizacja),
      numerPWZ(numerPWZ),
      dataZatrudnienia(dataZatrudnienia) {}

std::string Lekarz::getSpecjalizacja() const
{
    return specjalizacja;
}

std::string Lekarz::opisRoli() const
{
    return "Lekarz spec. " + specjalizacja;
}

bool Lekarz::dodajSlot(int idSlotu, Date poczatek, int czasMin)
{
    auto nowy = std::make_unique<SlotCzasowy>(idSlotu, poczatek, czasMin);

    for (auto &s : sloty)
    {
        if (s->getId() == idSlotu || s->nakladaSie(nowy.get()))
        {
            return false;
        }
    }

    sloty.push_back(std::move(nowy));
    return true;
}

SlotCzasowy *Lekarz::znajdzSlot(int idSlotu)
{
    for (auto &s : sloty)
    {
        if (s->getId() == idSlotu)
        {
            return s.get();
        }
    }
    return nullptr;
}

std::vector<SlotCzasowy *> Lekarz::pobierzWolneSloty()
{
    std::vector<SlotCzasowy *> wolne;
    for (auto &s : sloty)
    {
        if (s->czyDostepny())
        {
            wolne.push_back(s.get());
        }
    }
    return wolne;
}