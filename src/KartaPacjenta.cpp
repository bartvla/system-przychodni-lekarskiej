#include "KartaPacjenta.h"
#include "Wizyta.h"
using namespace std;

KartaPacjenta::KartaPacjenta(int numerKarty)
    : numerKarty(numerKarty) {}

void KartaPacjenta::dodajWizyte(Wizyta *w)
{
    if (w != nullptr)
    {
        historiaWizyt.push_back(w);
    }
}

vector<Recepta *> KartaPacjenta::pobierzRecepty()
{
    vector<Recepta *> recepty;
    for (Wizyta *w : historiaWizyt)
    {
        if (w->getRecepta() != nullptr)
        {
            recepty.push_back(w->getRecepta());
        }
    }
    return recepty;
}