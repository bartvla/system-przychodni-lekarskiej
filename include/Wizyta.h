#pragma once
#include "StatusWizyty.h"

class Pacjent;
class Lekarz;
class SlotCzasowy;
class Recepta;

class Wizyta {
private:
    int id;
    Pacjent* pacjent;
    Lekarz* lekarz;
    SlotCzasowy* slot;
    StatusWizyty status;
    Recepta* recepta;

public:
    Wizyta(int id, Pacjent* pacjent, Lekarz* lekarz, SlotCzasowy* slot);
    ~Wizyta();

    int getId();
    SlotCzasowy* getSlot();
    Recepta* getRecepta();
    bool odwolaj();
    bool zakoncz();
    void przypiszRecepte(Recepta* r);
    StatusWizyty getStatus();
};
