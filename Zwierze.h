#pragma once
#include "Organizm.h"

class Zwierze :
    public Organizm
{
private:
    bool czyRuch;

    void rozmnazanie(Zwierze* organizm);
public:
    Zwierze(Swiat* swiat);

    Zwierze(Zwierze* poprzednie);

    bool getRuch();

    void setRuch(bool perm);

    virtual void odbicie(Organizm* organizm);

    virtual void akcja() override;

    virtual void kolizja(Organizm* org) override;

    virtual void zapisz(ostream& os) override;

    virtual void czytaj(istream& is) override;

    virtual ~Zwierze();
};

