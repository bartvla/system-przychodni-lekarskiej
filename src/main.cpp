#include <iostream>
#include "Date.h"
#include "Pacjent.h"
#include "Lekarz.h"
#include "SlotCzasowy.h"
#include "Recepta.h"

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
    cout << "Czy recepta jest wazna 15.11.2026: " << (r1.czyWazna(zaMiesiac) ? "TAK" : "NIE") << endl;

    return 0;
}