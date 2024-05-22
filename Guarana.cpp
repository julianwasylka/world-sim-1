#include "Guarana.h"

Guarana::Guarana(Swiat* swiat) : Roslina(swiat) {}

Guarana::Guarana(Guarana* prev) : Roslina(prev) {}

Organizm* Guarana::narodziny()
{
	return new Guarana(this);
}

void Guarana::kolizja(Organizm* org)
{
	Roslina::kolizja(org);
	org->setSila(org->getSila() + 3);

	getSwiat()->dodajRaport("sila " + org->wypisanie() + " urosla");
}

const char Guarana::rysowanie()
{
	return 'g';
}

int Guarana::getKolor()
{
	return 4;
}

string Guarana::wypisanie()
{
	return "guarana";
}

Guarana::~Guarana() {}
