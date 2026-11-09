#pragma once
#include <string>

class Osoba {
private:
    int id;
    std::string imie;
    std::string nazwisko;
    std::string pesel;

public:
    Osoba(int id, std::string imie, std::string nazwisko, std::string pesel);
    virtual ~Osoba() = default;

    int getId() const;
    std::string getPelneNazwisko() const;
    virtual std::string opisRoli() const = 0; 
};