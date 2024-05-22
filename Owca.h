#pragma once
#include "Zwierze.h"

class Owca :
    public Zwierze
{
public:
    Owca(Swiat* swiat);

    Owca(Owca* prev);

    Organizm* narodziny() override;

    bool czyOdbilAtak() override;

    const char rysowanie() override;

    int getKolor() override;

    string wypisanie() override;

    ~Owca();
};

