#pragma once
#include <string>
using namespace std;

class Osoba {
private:
    int id;
    string imie;
    string nazwisko;
    string pesel;

public:
    Osoba(int id, string imie, string nazwisko, string pesel);
    virtual ~Osoba() {}

    int getId();
    string getPelneNazwisko();
    virtual string opisRoli() = 0;
};
