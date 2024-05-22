#include "Jagody.h"

Jagody::Jagody(Swiat* swiat) : Roslina(swiat)
{
	setSila(99);
}

Jagody::Jagody(Jagody* prev) : Roslina(prev) {}

Organizm* Jagody::narodziny()
{
	return new Jagody(this);
}

void Jagody::kolizja(Organizm* org)
{
	Roslina::kolizja(org);
	getSwiat()->usunOrganizm(org);

	getSwiat()->dodajRaport(org->wypisanie() + " umarl przez " + wypisanie());
}

const char Jagody::rysowanie()
{
	return 'j';
}

int Jagody::getKolor()
{
	return 1;
}

string Jagody::wypisanie()
{
	return "jagody";
}

Jagody::~Jagody() {}
