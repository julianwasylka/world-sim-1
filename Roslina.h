#pragma once
#include <iostream>
#include "Organizm.h"
#include "Swiat.h"
#include "Polozenie.h"

using namespace std;

class Roslina :
    public Organizm
{
private:
    static const int FREQ = 10;
public:
    Roslina(Swiat* swiat);

    Roslina(Roslina* poprzednia);

    bool czyOdbilAtak() override;

    virtual void akcja() override;

    virtual void kolizja(Organizm* org) override;

    virtual ~Roslina();
};

