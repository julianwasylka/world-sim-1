#pragma once
#include "Zwierze.h"

class Antylopa :
    public Zwierze
{
private:
    bool czyUciekla;
public:
    Antylopa(Swiat* swiat);

    Antylopa(Antylopa* prev);

    void akcja() override;

    void kolizja(Organizm* org) override;

    void odbicie(Organizm* organizm) override;

    Organizm* narodziny() override;

    bool czyOdbilAtak() override;

    const char rysowanie() override;

    int getKolor() override;

    string wypisanie() override;

    void zapisz(ostream& os) override;

    void czytaj(istream& is) override;

    ~Antylopa();
};

