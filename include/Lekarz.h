#pragma once
#include <string>
#include "Osoba.h"
#include "Date.h"
#include "SlotCzasowy.h"
#include <vector>
#include <memory>

class Lekarz : public Osoba
{
private:
    std::string specjalizacja;
    std::string numerPWZ;
    Date dataZatrudnienia;
    std::vector<std::unique_ptr<SlotCzasowy>> sloty;

public:
    Lekarz(int id, std::string imie, std::string nazwisko, std::string pesel,
           std::string specjalizacja, std::string numerPWZ, Date dataZatrudnienia);

    virtual ~Lekarz() = default;

    std::string getSpecjalizacja() const;
    std::string opisRoli() const override;
    bool dodajSlot(int idSlotu, Date poczatek, int czasMin);
    SlotCzasowy *znajdzSlot(int idSlotu);
    std::vector<SlotCzasowy *> pobierzWolneSloty();
};
