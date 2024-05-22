#pragma once
#include "Roslina.h"

class Barszcz :
    public Roslina
{
public:
    Barszcz(Swiat* swiat);

    Barszcz(Barszcz* prev);

    Organizm* narodziny() override;

    void akcja() override;

    void usunZwierze(int x, int y);

    void kolizja(Organizm* org) override;

    const char rysowanie() override;

    int getKolor() override;

    string wypisanie() override;

    ~Barszcz();
};

