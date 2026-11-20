#include "Wizyta.h"
#include "SlotCzasowy.h"
#include "Recepta.h"

Wizyta::Wizyta(int id, Pacjent *pacjent, Lekarz *lekarz, SlotCzasowy *slot)
    : id(id), pacjent(pacjent), lekarz(lekarz), slot(slot),
      status(ZAPLANOWANA), recepta(nullptr) {}

Wizyta::~Wizyta()
{
    delete recepta;
}

int Wizyta::getId() { return id; }
Lekarz *Wizyta::getLekarz() { return lekarz; }
SlotCzasowy *Wizyta::getSlot() { return slot; }
Recepta *Wizyta::getRecepta() { return recepta; }
StatusWizyty Wizyta::getStatus() { return status; }

bool Wizyta::odwolaj()
{
    if (status != ZAPLANOWANA)
    {
        return false;
    }
    status = ODWOLANA;
    slot->zwolnij();
    return true;
}

bool Wizyta::zakoncz()
{
    if (status != ZAPLANOWANA)
    {
        return false;
    }
    status = ODBYTA;
    return true;
}

bool Wizyta::przypiszRecepte(Recepta *r)
{
    if (status == ODWOLANA || recepta != nullptr)
    {
        return false;
    }
    recepta = r;
    return true;
}