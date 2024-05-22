#pragma once

#include <time.h>
#include "Roslina.h"

Roslina::Roslina(Swiat* swiat) : Organizm(swiat)
{
	setInicjatywa(0);
}

Roslina::Roslina(Roslina* poprzednia) : Roslina(poprzednia->getSwiat())
{
	setPolozenie(poprzednia->getPolozenie());
	setSila(poprzednia->getSila());
}

void Roslina::akcja()
{
	dodajWiek();

	int czyRozsiac = rand() % FREQ;

	if (czyRozsiac == 0)
	{
		Polozenie nowePolozenie = Polozenie(getPolozenie());

		nowePolozenie.losowyKrok();

		if (getSwiat()->getPosPlansza(nowePolozenie.getX(), nowePolozenie.getY()) != nullptr) return;

		Organizm* nowa = narodziny();

		if (nowa == nullptr) return;

		nowa->setPolozenie(&nowePolozenie);

		getSwiat()->dodajOrganizm(nowa);
	}
}

void Roslina::kolizja(Organizm* org)
{
	if (getSila() <= org->getSila())
	{
		getSwiat()->usunOrganizm(this);
		getSwiat()->dodajRaport(org->wypisanie() + " zjadl " + wypisanie());
	}
}

bool Roslina::czyOdbilAtak()
{
	return false;
}

Roslina::~Roslina() {}