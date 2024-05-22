#pragma once
#include "Roslina.h"

class Mlecz :
    public Roslina
{
public:
    Mlecz(Swiat* swiat);

    Mlecz(Mlecz* prev);

    void akcja() override;

    Organizm* narodziny() override;

    const char rysowanie() override;

    int getKolor() override;

    string wypisanie() override;

    ~Mlecz();
};

