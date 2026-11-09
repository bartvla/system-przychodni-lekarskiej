#pragma once
#include <string>
#include "Osoba.h"
#include "Date.h"

class Lekarz : public Osoba {
private:
    std::string specjalizacja;
    std::string numerPWZ;
    Date dataZatrudnienia;

public:
    Lekarz(int id, std::string imie, std::string nazwisko, std::string pesel,
           std::string specjalizacja, std::string numerPWZ, Date dataZatrudnienia);
    
    virtual ~Lekarz() = default; 

    std::string getSpecjalizacja() const;
    std::string opisRoli() const override;
};
