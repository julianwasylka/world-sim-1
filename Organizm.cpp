#include <iostream>
#include "Organizm.h"

Organizm::Organizm(Swiat* swiat, int inicjatywa, int sila)
{
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->swiat = swiat;
	polozenie = Polozenie(swiat);
	wiek = 0;
}

void Organizm::dodajWiek()
{
	wiek++;
}

void Organizm::zmniejszWiek()
{
	wiek--;
}

void Organizm::koniecGry() {}

bool Organizm::porownaj(Organizm* pierwszy, Organizm* drugi)
{
	if (pierwszy->inicjatywa == drugi->inicjatywa) return pierwszy->wiek > drugi->wiek;
	return pierwszy->inicjatywa > drugi->inicjatywa;
}

void Organizm::czytaj(istream& is)
{
	is >> sila >> inicjatywa >> wiek;
	polozenie.czytaj(is);
}

void Organizm::zapisz(ostream& os)
{
	os << rysowanie() << ' ' << sila << ' ' << inicjatywa << ' ' << wiek << ' ';
	polozenie.zapisz(os);
}

Organizm::~Organizm() {}