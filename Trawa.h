#pragma once
#include "Roslina.h"

class Trawa :
    public Roslina
{
public:
    Trawa(Swiat* swiat);

    Trawa(Trawa* prev);

    Organizm* narodziny() override;

    const char rysowanie() override;

    int getKolor() override;

    string wypisanie() override;

    ~Trawa();
};

