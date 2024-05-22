#pragma once
#include "Roslina.h"

class Jagody :
    public Roslina
{
public:
    Jagody(Swiat* swiat);

    Jagody(Jagody* prev);

    Organizm* narodziny() override;

    void kolizja(Organizm* org) override;

    const char rysowanie() override;

    int getKolor() override;

    string wypisanie() override;

    ~Jagody();
};

