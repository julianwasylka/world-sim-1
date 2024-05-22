#include "Trawa.h"

Trawa::Trawa(Swiat* swiat) : Roslina(swiat) {}

Trawa::Trawa(Trawa* prev) : Roslina(prev) {}

Organizm* Trawa::narodziny()
{
	return new Trawa(this);
}

const char Trawa::rysowanie()
{
	return 't';
}

int Trawa::getKolor()
{
	return 2;
}

string Trawa::wypisanie()
{
	return "trawa";
}

Trawa::~Trawa() {}
