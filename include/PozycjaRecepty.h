#pragma once
#include <string>

class PozycjaRecepty {
private:
    std::string lek;
    std::string dawkowanie;

public:
    PozycjaRecepty(std::string lek, std::string dawkowanie);
    std::string opis() const;
};