#pragma once
#include <string>
#include <vector>
#include "Osoba.h"
// #include "KartaPacjenta.h"

class Recepta;

class Pacjent : public Osoba {
private:
    // KartaPacjenta karta;

public:
    Pacjent(int id, std::string imie, std::string nazwisko, std::string pesel);
    virtual ~Pacjent() = default;

    // KartaPacjenta& getKarta();
    std::string opisRoli() const override;
    // std::vector<Recepta*> pobierzRecepty();
};