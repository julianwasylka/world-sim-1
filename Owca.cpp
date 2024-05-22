#include "Owca.h"

Owca::Owca(Swiat* swiat) : Zwierze(swiat)
{
	setSila(4);
	setInicjatywa(4);
}

Owca::Owca(Owca* prev) : Zwierze(prev) {}

Organizm* Owca::narodziny()
{
	return new Owca(this);
}

bool Owca::czyOdbilAtak()
{
	return false;
}

const char Owca::rysowanie()
{
	return 'o';
}

int Owca::getKolor()
{
	return 15;
}

string Owca::wypisanie()
{
	return "owca";
}

Owca::~Owca() {}