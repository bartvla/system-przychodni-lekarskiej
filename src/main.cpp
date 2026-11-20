#include <iostream>
#include "Date.h"
#include "Pacjent.h"
#include "Lekarz.h"
#include "SlotCzasowy.h"
#include "Recepta.h"
#include "Wizyta.h"
#include "SystemPrzychodni.h"

using namespace std;

int main() {
    cout << "=== TEST KLASY DATE ===" << endl;
    Date d(17, 2, 2026, 17, 30);
    cout << "dzien: " << d.getDzien() << endl;
    cout << "miesiac: " << d.getMiesiac() << endl;
    cout << "rok: " << d.getRok() << endl;
    cout << "godzina: " << d.getGodzina() << endl;
    cout << "minuta: " << d.getMinuta() << endl;
    cout << "Czas w minutach: " << d.wMinutach() << endl << endl;

    cout << "=== TEST KLASY PACJENT ===" << endl;
    Pacjent p1(1, "Bartosz", "Prosianowski", "12345678901");
    cout << "Imie i nazwisko: " << p1.getPelneNazwisko() << endl;
    cout << "Opis roli: " << p1.opisRoli() << endl << endl;

    cout << "=== TEST KLASY LEKARZ ===" << endl;
    Lekarz l1(1, "Tomasz", "Nowak", "98765432109", "kardiolog", "123456", d);
    cout << "Imie i nazwisko: " << l1.getPelneNazwisko() << endl;
    cout << "Opis roli: " << l1.opisRoli() << endl;
    cout << "Specjalizacja: " << l1.getSpecjalizacja() << endl << endl;

    cout << "=== TEST LOGIKI BIZNESOWEJ (SLOT CZASOWY) ===" << endl;
    SlotCzasowy slot1(101, d, 30);
    cout << "Czy slot wolny przed zablokowaniem: " << (slot1.czyDostepny() ? "TAK" : "NIE") << endl;
    bool zablokowano = slot1.zablokuj();
    cout << "Wynik blokowania: " << (zablokowano ? "SUKCES" : "PORAŻKA") << endl;
    cout << "Czy slot wolny po zablokowaniu: " << (slot1.czyDostepny() ? "TAK" : "NIE") << endl << endl;

    cout << "=== TEST LOGIKI BIZNESOWEJ (RECEPTA) ===" << endl;
    Date dataWystawienia(1, 10, 2026, 10, 0);
    Date terminWaznosci(31, 10, 2026, 23, 59);
    Recepta r1(1, dataWystawienia, terminWaznosci);
    
    Date dzisiaj(15, 10, 2026, 12, 0);
    Date zaMiesiac(15, 11, 2026, 12, 0);

    cout << "Czy recepta jest wazna dzisiaj (15.10.2026): " << (r1.czyWazna(dzisiaj) ? "TAK" : "NIE") << endl;
    cout << "Czy recepta jest wazna 15.11.2026: " << (r1.czyWazna(zaMiesiac) ? "TAK" : "NIE") << endl << endl;

    cout << "=== TEST KLASY RECEPTA (POZYCJE I OPIS) ===" << endl;
    r1.dodajPozycje(PozycjaRecepty("Aspiryna", "1 tabletka dziennie"));
    r1.dodajPozycje(PozycjaRecepty("Witamina D", "2 krople rano"));
    cout << "Id recepty: " << r1.getId() << endl;
    cout << r1.opis() << endl << endl;

    cout << "=== TEST LOGIKI BIZNESOWEJ (SLOTY LEKARZA) ===" << endl;
    bool dodano1 = l1.dodajSlot(101, Date(20, 11, 2026, 9, 0), 30);
    bool dodano2 = l1.dodajSlot(102, Date(20, 11, 2026, 9, 30), 30);
    bool dodano3 = l1.dodajSlot(103, Date(20, 11, 2026, 9, 15), 30);
    bool dodano4 = l1.dodajSlot(101, Date(21, 11, 2026, 9, 0), 30);
    cout << "Slot 101 (9:00-9:30): " << (dodano1 ? "DODANY" : "ODRZUCONY") << endl;
    cout << "Slot 102 (9:30-10:00): " << (dodano2 ? "DODANY" : "ODRZUCONY") << endl;
    cout << "Slot 103 (9:15-9:45, naklada sie): " << (dodano3 ? "DODANY" : "ODRZUCONY") << endl;
    cout << "Slot 101 drugi raz (to samo id): " << (dodano4 ? "DODANY" : "ODRZUCONY") << endl;
    cout << "Liczba wolnych slotow: " << l1.pobierzWolneSloty().size() << endl;
    cout << "Czy znaleziono slot 101: " << (l1.znajdzSlot(101) != nullptr ? "TAK" : "NIE") << endl;
    cout << "Czy znaleziono slot 999: " << (l1.znajdzSlot(999) != nullptr ? "TAK" : "NIE") << endl << endl;

    cout << "=== TEST KLASY WIZYTA (ODWOLANIE) ===" << endl;
    SlotCzasowy* slotA = l1.znajdzSlot(101);
    slotA->zablokuj();
    Wizyta w1(1, &p1, &l1, slotA);
    cout << "Status ZAPLANOWANA: " << (w1.getStatus() == ZAPLANOWANA ? "TAK" : "NIE") << endl;
    cout << "Wolne sloty po zajeciu 101: " << l1.pobierzWolneSloty().size() << endl;
    cout << "Odwolanie wizyty: " << (w1.odwolaj() ? "SUKCES" : "PORAZKA") << endl;
    cout << "Status ODWOLANA: " << (w1.getStatus() == ODWOLANA ? "TAK" : "NIE") << endl;
    cout << "Czy slot 101 znow wolny: " << (slotA->czyDostepny() ? "TAK" : "NIE") << endl;
    cout << "Ponowne odwolanie: " << (w1.odwolaj() ? "SUKCES" : "PORAZKA") << endl;
    cout << "Zakonczenie odwolanej wizyty: " << (w1.zakoncz() ? "SUKCES" : "PORAZKA") << endl;

    Recepta* receptaDoOdwolanej = new Recepta(2, Date(20, 11, 2026), Date(20, 12, 2026));
    bool przypisano = w1.przypiszRecepte(receptaDoOdwolanej);
    cout << "Recepta do odwolanej wizyty: " << (przypisano ? "SUKCES" : "PORAZKA") << endl << endl;
    if (!przypisano) {
        delete receptaDoOdwolanej;
    }

    cout << "=== TEST KLASY WIZYTA (RECEPTA I ZAKONCZENIE) ===" << endl;
    SlotCzasowy* slotB = l1.znajdzSlot(102);
    slotB->zablokuj();
    Wizyta w2(2, &p1, &l1, slotB);

    Recepta* recepta = new Recepta(3, Date(20, 11, 2026), Date(20, 12, 2026));
    recepta->dodajPozycje(PozycjaRecepty("Ibuprom", "2 razy dziennie"));
    cout << "Przypisanie recepty: " << (w2.przypiszRecepte(recepta) ? "SUKCES" : "PORAZKA") << endl;

    Recepta* drugaRecepta = new Recepta(4, Date(20, 11, 2026), Date(20, 12, 2026));
    bool przypisanoDruga = w2.przypiszRecepte(drugaRecepta);
    cout << "Przypisanie drugiej recepty: " << (przypisanoDruga ? "SUKCES" : "PORAZKA") << endl;
    if (!przypisanoDruga) {
        delete drugaRecepta;
    }

    cout << "Zakonczenie wizyty: " << (w2.zakoncz() ? "SUKCES" : "PORAZKA") << endl;
    cout << "Status ODBYTA: " << (w2.getStatus() == ODBYTA ? "TAK" : "NIE") << endl;
    cout << "Lekarz wizyty: " << w2.getLekarz()->getPelneNazwisko() << endl << endl;

    cout << "=== TEST KARTY PACJENTA ===" << endl;
    p1.getKarta().dodajWizyte(&w1);
    p1.getKarta().dodajWizyte(&w2);
    p1.getKarta().dodajWizyte(nullptr);
    vector<Recepta*> receptyPacjenta = p1.pobierzRecepty();
    cout << "Liczba recept pacjenta: " << receptyPacjenta.size() << endl;
    for (Recepta* r : receptyPacjenta) {
        cout << r->opis() << endl;
        cout << "Czy wazna 01.12.2026: " << (r->czyWazna(Date(1, 12, 2026)) ? "TAK" : "NIE") << endl;
        cout << "Czy wazna 01.01.2027: " << (r->czyWazna(Date(1, 1, 2027)) ? "TAK" : "NIE") << endl;
    }
    cout << endl;

    cout << "=== TEST SYSTEMU: DODAWANIE I WYSZUKIWANIE OSOB ===" << endl;
    SystemPrzychodni przychodnia;
    Pacjent* pacjent1 = przychodnia.dodajPacjenta(1, "Jan", "Kowalski", "11111111111");
    Pacjent* pacjent2 = przychodnia.dodajPacjenta(2, "Anna", "Nowak", "22222222222");
    Lekarz* kardiolog1 = przychodnia.dodajLekarza(1, "Piotr", "Zielinski", "33333333333", "kardiolog", "1001", Date(1, 1, 2015));
    przychodnia.dodajLekarza(2, "Ewa", "Wisniewska", "44444444444", "dermatolog", "1002", Date(1, 1, 2018));
    przychodnia.dodajLekarza(3, "Marek", "Lewandowski", "55555555555", "kardiolog", "1003", Date(1, 1, 2020));
    cout << "Znaleziony pacjent nr 2: " << przychodnia.znajdzPacjenta(2)->getPelneNazwisko() << endl;
    cout << "Czy znaleziono pacjenta nr 99: " << (przychodnia.znajdzPacjenta(99) != nullptr ? "TAK" : "NIE") << endl;
    cout << "Znaleziony lekarz nr 2: " << przychodnia.znajdzLekarza(2)->opisRoli() << endl;

    vector<Lekarz*> kardiolodzy = przychodnia.wyszukajLekarzy("kardiolog");
    cout << "Liczba kardiologow: " << kardiolodzy.size() << endl;
    for (Lekarz* l : kardiolodzy) {
        cout << " - " << l->getPelneNazwisko() << endl;
    }
    cout << "Liczba neurologow: " << przychodnia.wyszukajLekarzy("neurolog").size() << endl << endl;

    cout << "=== TEST SYSTEMU: WOLNE SLOTY ===" << endl;
    kardiolog1->dodajSlot(201, Date(25, 11, 2026, 10, 0), 30);
    kardiolog1->dodajSlot(202, Date(25, 11, 2026, 10, 30), 30);
    cout << "Wolne sloty lekarza nr 1: " << przychodnia.pobierzWolneSloty(1).size() << endl;
    cout << "Wolne sloty lekarza nr 3 (brak slotow): " << przychodnia.pobierzWolneSloty(3).size() << endl;
    cout << "Wolne sloty lekarza nr 99 (nie istnieje): " << przychodnia.pobierzWolneSloty(99).size() << endl << endl;

    cout << "=== TEST SYSTEMU: REZERWACJA WIZYTY ===" << endl;
    Wizyta* rezerwacja1 = przychodnia.zarezerwujWizyte(1, 1, 201);
    cout << "Rezerwacja slotu 201 przez pacjenta 1: " << (rezerwacja1 != nullptr ? "SUKCES" : "PORAZKA") << endl;
    cout << "Id wizyty: " << rezerwacja1->getId() << endl;
    cout << "Status ZAPLANOWANA: " << (rezerwacja1->getStatus() == ZAPLANOWANA ? "TAK" : "NIE") << endl;
    cout << "Wolne sloty lekarza nr 1 po rezerwacji: " << przychodnia.pobierzWolneSloty(1).size() << endl;
    cout << "Czy znajdzWizyte zwraca te sama wizyte: " << (przychodnia.znajdzWizyte(rezerwacja1->getId()) == rezerwacja1 ? "TAK" : "NIE") << endl;
    cout << "Rezerwacja zajetego slotu 201 przez pacjenta 2: " << (przychodnia.zarezerwujWizyte(2, 1, 201) != nullptr ? "SUKCES" : "PORAZKA") << endl;
    cout << "Rezerwacja przez nieistniejacego pacjenta: " << (przychodnia.zarezerwujWizyte(99, 1, 202) != nullptr ? "SUKCES" : "PORAZKA") << endl;
    cout << "Rezerwacja u nieistniejacego lekarza: " << (przychodnia.zarezerwujWizyte(1, 99, 202) != nullptr ? "SUKCES" : "PORAZKA") << endl;
    cout << "Rezerwacja nieistniejacego slotu: " << (przychodnia.zarezerwujWizyte(1, 1, 999) != nullptr ? "SUKCES" : "PORAZKA") << endl;
    cout << "Rezerwacja slotu innego lekarza (201 u lekarza 3): " << (przychodnia.zarezerwujWizyte(1, 3, 201) != nullptr ? "SUKCES" : "PORAZKA") << endl << endl;

    cout << "=== TEST SYSTEMU: ODWOLANIE WIZYTY ===" << endl;
    cout << "Odwolanie wizyty: " << (przychodnia.odwolajWizyte(rezerwacja1->getId()) ? "SUKCES" : "PORAZKA") << endl;
    cout << "Status ODWOLANA: " << (rezerwacja1->getStatus() == ODWOLANA ? "TAK" : "NIE") << endl;
    cout << "Wolne sloty lekarza nr 1 po odwolaniu: " << przychodnia.pobierzWolneSloty(1).size() << endl;
    cout << "Ponowne odwolanie: " << (przychodnia.odwolajWizyte(rezerwacja1->getId()) ? "SUKCES" : "PORAZKA") << endl;
    cout << "Odwolanie nieistniejacej wizyty: " << (przychodnia.odwolajWizyte(99) ? "SUKCES" : "PORAZKA") << endl;
    Wizyta* rezerwacja2 = przychodnia.zarezerwujWizyte(2, 1, 201);
    cout << "Rezerwacja zwolnionego slotu 201 przez pacjenta 2: " << (rezerwacja2 != nullptr ? "SUKCES" : "PORAZKA") << endl;
    cout << "Id nowej wizyty: " << rezerwacja2->getId() << endl << endl;

    cout << "=== TEST SYSTEMU: WYSTAWIENIE RECEPTY ===" << endl;
    Recepta* odObcegoLekarza = przychodnia.wystawRecepte(rezerwacja2->getId(), 3, Date(25, 11, 2026), Date(25, 12, 2026));
    cout << "Recepta od lekarza, ktory nie prowadzi wizyty: " << (odObcegoLekarza != nullptr ? "SUKCES" : "PORAZKA") << endl;
    Recepta* doOdwolanej = przychodnia.wystawRecepte(rezerwacja1->getId(), 1, Date(25, 11, 2026), Date(25, 12, 2026));
    cout << "Recepta do odwolanej wizyty: " << (doOdwolanej != nullptr ? "SUKCES" : "PORAZKA") << endl;
    Recepta* receptaSystemu = przychodnia.wystawRecepte(rezerwacja2->getId(), 1, Date(25, 11, 2026), Date(25, 12, 2026));
    cout << "Recepta od lekarza prowadzacego: " << (receptaSystemu != nullptr ? "SUKCES" : "PORAZKA") << endl;
    receptaSystemu->dodajPozycje(PozycjaRecepty("Bisoprolol", "1 tabletka rano"));
    receptaSystemu->dodajPozycje(PozycjaRecepty("Polocard", "1 tabletka wieczorem"));
    cout << receptaSystemu->opis() << endl;
    Recepta* drugaReceptaSystemu = przychodnia.wystawRecepte(rezerwacja2->getId(), 1, Date(25, 11, 2026), Date(25, 12, 2026));
    cout << "Druga recepta do tej samej wizyty: " << (drugaReceptaSystemu != nullptr ? "SUKCES" : "PORAZKA") << endl << endl;

    cout << "=== TEST SYSTEMU: ZAKONCZENIE WIZYTY ===" << endl;
    cout << "Zakonczenie wizyty: " << (przychodnia.zakonczWizyte(rezerwacja2->getId()) ? "SUKCES" : "PORAZKA") << endl;
    cout << "Status ODBYTA: " << (rezerwacja2->getStatus() == ODBYTA ? "TAK" : "NIE") << endl;
    cout << "Ponowne zakonczenie: " << (przychodnia.zakonczWizyte(rezerwacja2->getId()) ? "SUKCES" : "PORAZKA") << endl;
    cout << "Zakonczenie odwolanej wizyty: " << (przychodnia.zakonczWizyte(rezerwacja1->getId()) ? "SUKCES" : "PORAZKA") << endl << endl;

    cout << "=== TEST SYSTEMU: RECEPTY W KARCIE PACJENTA ===" << endl;
    cout << "Liczba recept pacjenta 1 (wizyta odwolana): " << pacjent1->pobierzRecepty().size() << endl;
    cout << "Liczba recept pacjenta 2: " << pacjent2->pobierzRecepty().size() << endl;
    for (Recepta* r : pacjent2->pobierzRecepty()) {
        cout << r->opis() << endl;
        cout << "Czy wazna 20.12.2026: " << (r->czyWazna(Date(20, 12, 2026)) ? "TAK" : "NIE") << endl;
        cout << "Czy wazna 30.12.2026: " << (r->czyWazna(Date(30, 12, 2026)) ? "TAK" : "NIE") << endl;
    }

    return 0;
}