// main.cpp
#include <iostream>
#include "Date.h"
#include "Pacjent.h"
#include "Lekarz.h"
using namespace::std;

int main() {
    cout << "Date.cpp - test" << endl;
    cout << "=============================" << endl;
    Date d(17, 2, 2026, 17, 30);
    cout << "dzien: " << d.dzien << endl;
    cout << "miesiac: " << d.miesiac << endl;
    cout << "rok: " << d.rok << endl;
    cout << "godzina: " << d.godzina << endl;
    cout << "minuta: " << d.minuta << endl;
    cout << endl;

    cout << "Pacjent.cpp - test" << endl;
    cout << "=============================" << endl;
    Pacjent p1(1, "Bartosz", "Prosianowski", "pesel");
    cout << "Imie i nazwisko: " << p1.getPelneNazwisko() << endl;
    cout << "Opis roli: " << p1.opisRoli() << endl;
    cout << endl;

    cout << "Lekarz.cpp - test" << endl;
    cout << "=============================" << endl;
    Lekarz l1(1, "tomak", "nowak", "psl", "kardiolog", "123456", d);
    cout << "Imie i nazwisko: " << l1.getPelneNazwisko() << endl;
    cout << "Opis roli: " << l1.opisRoli() << endl;
    cout << "Specjalizacja: " << l1.getSpecjalizacja() << endl;
    cout << endl;

}