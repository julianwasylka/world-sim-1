#pragma once
#include "Zwierze.h"

class Wilk :
    public Zwierze
{
public:
    Wilk(Swiat* swiat);

    Wilk(Wilk* prev);

    Organizm* narodziny() override;

    bool czyOdbilAtak() override;

    const char rysowanie() override;

    int getKolor() override;

    string wypisanie() override;

    ~Wilk();
};

