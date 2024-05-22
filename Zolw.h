#pragma once
#include "Zwierze.h"

class Zolw :
    public Zwierze
{
public:
    Zolw(Swiat* swiat);

    Zolw(Zolw* prev);

    void akcja() override;

    void kolizja(Organizm* org) override;

    Organizm* narodziny() override;

    bool czyOdbilAtak() override;

    const char rysowanie() override;

    int getKolor() override;

    string wypisanie() override;

    ~Zolw();
};

