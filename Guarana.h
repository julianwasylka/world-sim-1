#pragma once
#include "Roslina.h"

class Guarana :
    public Roslina
{
public:
    Guarana(Swiat* swiat);

    Guarana(Guarana* prev);

    Organizm* narodziny() override;

    void kolizja(Organizm* org) override;

    const char rysowanie() override;

    int getKolor() override;

    string wypisanie() override;

    ~Guarana();
};

