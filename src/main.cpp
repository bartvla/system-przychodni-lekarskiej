#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Date.h"
#include "Pacjent.h"
#include "Lekarz.h"
#include "SlotCzasowy.h"
#include "Recepta.h"
#include "Wizyta.h"
#include "SystemPrzychodni.h"

using namespace std;

void wyczyscBufor() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    SystemPrzychodni przychodnia;

    // Dane poczatkowe (pacjenci i lekarze roznych specjalizacji)
    przychodnia.dodajPacjenta(1, "Jan", "Kowalski", "11111111111");
    przychodnia.dodajPacjenta(2, "Anna", "Nowak", "22222222222");
    przychodnia.dodajPacjenta(3, "Katarzyna", "Wojcik", "33333333333");

    Lekarz* l1 = przychodnia.dodajLekarza(1, "Piotr", "Zielinski", "44444444444", "kardiolog", "1001", Date(1, 1, 2015));
    Lekarz* l2 = przychodnia.dodajLekarza(2, "Ewa", "Wisniewska", "55555555555", "dermatolog", "1002", Date(1, 1, 2018));
    Lekarz* l3 = przychodnia.dodajLekarza(3, "Marek", "Lewandowski", "66666666666", "kardiolog", "1003", Date(1, 1, 2020));
    Lekarz* l4 = przychodnia.dodajLekarza(4, "Magdalena", "Kaminska", "77777777777", "pediatra", "1004", Date(15, 5, 2019));
    Lekarz* l5 = przychodnia.dodajLekarza(5, "Tomasz", "Szymanski", "88888888888", "ortopeda", "1005", Date(10, 9, 2017));

    // Wstepne sloty czasowe w kalendarzach lekarzy
    l1->dodajSlot(101, Date(25, 11, 2026, 9, 0), 30);
    l1->dodajSlot(102, Date(25, 11, 2026, 9, 30), 30);
    l2->dodajSlot(201, Date(25, 11, 2026, 11, 0), 30);
    l2->dodajSlot(202, Date(26, 11, 2026, 12, 15), 30);
    l4->dodajSlot(401, Date(25, 11, 2026, 14, 0), 20);
    l4->dodajSlot(402, Date(25, 11, 2026, 14, 20), 20);
    l5->dodajSlot(501, Date(27, 11, 2026, 8, 30), 45);
    // Lekarz ID 3 (Marek Lewandowski) celowo nie ma slotow do przetestowania przypadku brzegowego

    cout << "=== SYSTEM PRZYCHODNI LEKARSKIEJ ===\n";
    cout << "Pacjenci w bazie: [1] Jan Kowalski, [2] Anna Nowak, [3] Katarzyna Wojcik\n";
    cout << "Lekarze w bazie:  [1] Piotr Zielinski (kardiolog)\n";
    cout << "                  [2] Ewa Wisniewska (dermatolog)\n";
    cout << "                  [3] Marek Lewandowski (kardiolog - brak wolnych terminow)\n";
    cout << "                  [4] Magdalena Kaminska (pediatra)\n";
    cout << "                  [5] Tomasz Szymanski (ortopeda)\n";

    int wybor = -1;
    while (wybor != 0) {
        cout << "\n==================== MENU SYSTEMU ====================\n";
        cout << "1. [US1] Wyszukaj lekarza po specjalizacji i wolne sloty\n";
        cout << "2. [US2] Zarezerwuj wizyte (Pacjent)\n";
        cout << "3. [US3] Odwolaj wizyte (Pacjent)\n";
        cout << "4. [US4] Dodaj nowy slot czasowy do kalendarza (Lekarz)\n";
        cout << "5. [US5] Zakoncz wizyte - oznacz jako ODBYTA (Lekarz)\n";
        cout << "6. [US6] Wystaw recepte z lekiem do wizyty (Lekarz)\n";
        cout << "7. [US7] Przegladaj recepty pacjenta i sprawdz waznosc\n";
        cout << "0. Wyjscie\n";
        cout << "Wybor: ";

        if (!(cin >> wybor)) {
            wyczyscBufor();
            cout << "Niepoprawny wybor! Podaj liczbe.\n";
            continue;
        }

        switch (wybor) {
            case 1: {
                string spec;
                cout << "Podaj specjalizacje (np. kardiolog, dermatolog, pediatra, ortopeda): ";
                cin >> spec;
                vector<Lekarz*> znalezieni = przychodnia.wyszukajLekarzy(spec);
                if (znalezieni.empty()) {
                    cout << "Brak lekarzy o specjalizacji: " << spec << "\n";
                } else {
                    for (Lekarz* l : znalezieni) {
                        vector<SlotCzasowy*> wolne = l->pobierzWolneSloty();
                        cout << " - Lekarz ID " << l->getId() << ": " << l->getPelneNazwisko()
                             << " | Liczba wolnych slotow: " << wolne.size() << "\n";
                        for (SlotCzasowy* s : wolne) {
                            Date start = s->getPoczatek();
                            cout << "     * Slot ID " << s->getId() << ": "
                                 << start.getDzien() << "." << start.getMiesiac() << "." << start.getRok()
                                 << " godz. " << start.getGodzina() << ":"
                                 << (start.getMinuta() < 10 ? "0" : "") << start.getMinuta() << "\n";
                        }
                    }
                }
                break;
            }
            case 2: {
                int idPacjenta, idLekarza, idSlotu;
                cout << "Pacjenci: [1] Jan Kowalski, [2] Anna Nowak, [3] Katarzyna Wojcik\n";
                cout << "Podaj ID pacjenta: "; cin >> idPacjenta;
                if (!przychodnia.znajdzPacjenta(idPacjenta)) {
                    cout << "Nie znaleziono pacjenta o ID: " << idPacjenta << "\n";
                    break;
                }

                cout << "Lekarze:\n";
                for (int id = 1; id <= 5; ++id) {
                    Lekarz* lek = przychodnia.znajdzLekarza(id);
                    if (lek) {
                        cout << "  [" << id << "] " << lek->getPelneNazwisko() << " (" << lek->getSpecjalizacja() << ")\n";
                    }
                }
                cout << "Podaj ID lekarza: "; cin >> idLekarza;
                Lekarz* lekarz = przychodnia.znajdzLekarza(idLekarza);
                if (!lekarz) {
                    cout << "Nie znaleziono lekarza o ID: " << idLekarza << "\n";
                    break;
                }

                vector<SlotCzasowy*> wolne = lekarz->pobierzWolneSloty();
                if (wolne.empty()) {
                    cout << "Lekarz " << lekarz->getPelneNazwisko() << " nie ma obecnie zadnych wolnych slotow!\n";
                    break;
                }

                cout << "Dostepne sloty u lekarza " << lekarz->getPelneNazwisko() << ":\n";
                for (SlotCzasowy* s : wolne) {
                    Date start = s->getPoczatek();
                    cout << "  - Slot ID " << s->getId() << ": "
                         << start.getDzien() << "." << start.getMiesiac() << "." << start.getRok()
                         << " godz. " << start.getGodzina() << ":"
                         << (start.getMinuta() < 10 ? "0" : "") << start.getMinuta() << "\n";
                }

                cout << "Podaj ID slotu do rezerwacji: "; cin >> idSlotu;
                Wizyta* w = przychodnia.zarezerwujWizyte(idPacjenta, idLekarza, idSlotu);
                if (w != nullptr) {
                    cout << "SUKCES! Zarezerwowano wizyte o ID: " << w->getId() << " (Status: ZAPLANOWANA)\n";
                } else {
                    cout << "PORAZKA! Podano bledne ID slotu.\n";
                }
                break;
            }
            case 3: {
                int idWizyty;
                cout << "Podaj ID wizyty do odwolania: "; cin >> idWizyty;
                if (przychodnia.odwolajWizyte(idWizyty)) {
                    cout << "SUKCES! Wizyta odwolana, slot czasowy zostal ponownie zwolniony.\n";
                } else {
                    cout << "PORAZKA! Nie mozna odwolac (nie istnieje, juz odwolana lub odbyta).\n";
                }
                break;
            }
            case 4: {
                int idLekarza, idSlotu, dzien, miesiac, rok, godz, min, czas;
                cout << "Lekarze:\n";
                for (int id = 1; id <= 5; ++id) {
                    Lekarz* lek = przychodnia.znajdzLekarza(id);
                    if (lek) {
                        cout << "  [" << id << "] " << lek->getPelneNazwisko() << " (" << lek->getSpecjalizacja() << ")\n";
                    }
                }
                cout << "Podaj ID lekarza: "; cin >> idLekarza;
                Lekarz* l = przychodnia.znajdzLekarza(idLekarza);
                if (!l) {
                    cout << "Nie znaleziono lekarza!\n";
                    break;
                }
                cout << "Podaj nowe ID slotu: "; cin >> idSlotu;
                cout << "Podaj date (dzien miesiac rok godzina minuta, np. 25 11 2026 9 15): ";
                cin >> dzien >> miesiac >> rok >> godz >> min;
                cout << "Podaj czas trwania w minutach (np. 30): "; cin >> czas;
                if (l->dodajSlot(idSlotu, Date(dzien, miesiac, rok, godz, min), czas)) {
                    cout << "SUKCES! Dodano nowy wolny termin.\n";
                } else {
                    cout << "ODRZUCONO! Termin naklada sie na istniejacy slot lub ID jest zajete.\n";
                }
                break;
            }
            case 5: {
                int idWizyty;
                cout << "Podaj ID wizyty do zakonczenia: "; cin >> idWizyty;
                if (przychodnia.zakonczWizyte(idWizyty)) {
                    cout << "SUKCES! Wizyta oznaczona jako ODBYTA.\n";
                } else {
                    cout << "PORAZKA! Tylko wizyta ZAPLANOWANA moze przejsc w ODBYTA.\n";
                }
                break;
            }
            case 6: {
                int idWizyty, idLekarza;
                string lek, dawkowanie;
                cout << "Podaj ID wizyty: "; cin >> idWizyty;
                cout << "Lekarze:\n";
                for (int id = 1; id <= 5; ++id) {
                    Lekarz* lek = przychodnia.znajdzLekarza(id);
                    if (lek) {
                        cout << "  [" << id << "] " << lek->getPelneNazwisko() << " (" << lek->getSpecjalizacja() << ")\n";
                    }
                }
                cout << "Podaj ID lekarza wystawiajacego: "; cin >> idLekarza;
                Recepta* r = przychodnia.wystawRecepte(idWizyty, idLekarza, Date(21, 11, 2026), Date(21, 12, 2026));
                if (!r) {
                    cout << "PORAZKA! Wizyta nie istnieje, wizyta odwolana, bledny lekarz lub recepta juz istnieje.\n";
                    break;
                }
                wyczyscBufor();
                cout << "Podaj nazwe leku: "; getline(cin, lek);
                cout << "Podaj dawkowanie: "; getline(cin, dawkowanie);
                r->dodajPozycje(PozycjaRecepty(lek, dawkowanie));
                cout << "SUKCES! Wystawiono recepte:\n" << r->opis() << "\n";
                break;
            }
            case 7: {
                int idPacjenta, d, m, r;
                cout << "Pacjenci: [1] Jan Kowalski, [2] Anna Nowak, [3] Katarzyna Wojcik\n";
                cout << "Podaj ID pacjenta: "; cin >> idPacjenta;
                Pacjent* p = przychodnia.znajdzPacjenta(idPacjenta);
                if (!p) {
                    cout << "Nie znaleziono pacjenta!\n";
                    break;
                }
                cout << "Podaj dzisiejsza date do weryfikacji (dzien miesiac rok, np. 1 12 2026): ";
                cin >> d >> m >> r;
                Date dzis(d, m, r);
                vector<Recepta*> recepty = p->pobierzRecepty();
                if (recepty.empty()) {
                    cout << "Brak recept w karcie pacjenta.\n";
                } else {
                    for (Recepta* rec : recepty) {
                        Date termin = rec->getTerminWaznosci();
                        cout << rec->opis() << " -> Status: "
                             << (rec->czyWazna(dzis) ? "WAZNA" : "WYGASLA")
                             << " (do: " << termin.getDzien() << "."
                             << termin.getMiesiac() << "." << termin.getRok() << ")\n";
                    }
                }
                break;
            }
            case 0:
                cout << "Zamykanie systemu...\n";
                break;
            default:
                cout << "Nieznana opcja!\n";
        }
    }

    return 0;
}