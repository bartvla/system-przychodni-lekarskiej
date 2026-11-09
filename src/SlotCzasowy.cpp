#include "SlotCzasowy.h"

SlotCzasowy::SlotCzasowy(int id, Date poczatek, int czasMin)
    : id(id), poczatek(poczatek), czasMin(czasMin), dostepny(true) {}

int SlotCzasowy::getId() { return id; }
Date SlotCzasowy::getPoczatek() { return poczatek; }
bool SlotCzasowy::czyDostepny() { return dostepny; }

bool SlotCzasowy::zablokuj() {
    if (!dostepny) {
        return false;
    }
    dostepny = false;
    return true;
}

void SlotCzasowy::zwolnij() {
    dostepny = true;
}

bool SlotCzasowy::nakladaSie(SlotCzasowy* inny) {
    if (inny == nullptr) return false;
    
    long long t1_start = poczatek.wMinutach();
    long long t1_end = t1_start + czasMin;
    
    long long t2_start = inny->getPoczatek().wMinutach();
    long long t2_end = t2_start + inny->czasMin;

    return (t1_start < t2_end) && (t2_start < t1_end);
}