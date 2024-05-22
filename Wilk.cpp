#include "Wilk.h"

Wilk::Wilk(Swiat* swiat) : Zwierze(swiat)
{
	setSila(9);
	setInicjatywa(5);
}

Wilk::Wilk(Wilk* prev) : Zwierze(prev) {}

Organizm* Wilk::narodziny()
{
	return new Wilk(this);
}

bool Wilk::czyOdbilAtak()
{
	return false;
}

const char Wilk::rysowanie()
{
	return 'w';
}

int Wilk::getKolor()
{
	return 8;
}

string Wilk::wypisanie()
{
	return "wilk";
}

Wilk::~Wilk() {}