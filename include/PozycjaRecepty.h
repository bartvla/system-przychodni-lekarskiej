#pragma once
#include <string>
using namespace std;

class PozycjaRecepty {
private:
    string lek;
    string dawkowanie;

public:
    PozycjaRecepty(string lek, string dawkowanie);
    string opis();
};
