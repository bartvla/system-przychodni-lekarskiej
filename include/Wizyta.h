#pragma once
#include "StatusWizyty.h"

class Pacjent;
class Lekarz;
class SlotCzasowy;
class Recepta;

class Wizyta
{
private:
    int id;
    Pacjent *pacjent;
    Lekarz *lekarz;
    SlotCzasowy *slot;
    StatusWizyty status;
    Recepta *recepta;

public:
    Wizyta(int id, Pacjent *pacjent, Lekarz *lekarz, SlotCzasowy *slot);
    ~Wizyta();

    int getId();
    Lekarz *getLekarz();
    SlotCzasowy *getSlot();
    Recepta *getRecepta();
    StatusWizyty getStatus();

    bool przypiszRecepte(Recepta *r);
    bool odwolaj();
    bool zakoncz();
};
