#pragma once
#include "Zwierze.h"

class Lis :
    public Zwierze
{
public:
    Lis(Swiat* swiat);

    Lis(Lis* prev);

    virtual void akcja() override;

    Organizm* narodziny() override;

    bool czyOdbilAtak() override;

    const char rysowanie() override;

    int getKolor() override;

    string wypisanie() override;

    ~Lis();
};