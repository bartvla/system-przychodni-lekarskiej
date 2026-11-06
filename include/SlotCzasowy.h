#pragma once
#include "Date.h"

class SlotCzasowy {
private:
    int id;
    Date poczatek;
    int czasMin;
    bool dostepny;

public:
    SlotCzasowy(int id, Date poczatek, int czasMin);

    int getId();
    Date getPoczatek();
    bool czyDostepny();
    bool zablokuj();
    void zwolnij();
    bool nakladaSie(SlotCzasowy* inny);
};
