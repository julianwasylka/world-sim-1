#pragma once
#include "Organizm.h"
#include "Zwierze.h"
#include "Kontroler.h"

class Czlowiek :
    public Zwierze
{
private:
    Kontroler* kontroler;
public:
    Czlowiek(Swiat* swiat, Kontroler* kontroler);

    void akcja() override;

    void odbicie(Organizm* organizm) override;

    const char rysowanie() override;

    int getKolor() override;

    string wypisanie() override;

    Organizm* narodziny() override;

    bool czyOdbilAtak() override;

    void koniecGry() override;

    ~Czlowiek();
};

