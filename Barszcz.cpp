#include "Barszcz.h"
#include "Zwierze.h"

Barszcz::Barszcz(Swiat* swiat) : Roslina(swiat)
{
	setSila(10);
}

Barszcz::Barszcz(Barszcz* prev) : Roslina(prev) {}

Organizm* Barszcz::narodziny()
{
	return new Barszcz(this);
}

void Barszcz::usunZwierze(int x, int y)
{
	Swiat* swiat = getSwiat();
	if (x < 0 || x >= swiat->getN()
		|| y < 0 || y >= swiat->getM()) return;

	Organizm* org = swiat->getPosPlansza(x, y);

	if (dynamic_cast<Zwierze*>(org) != nullptr)
	{
		swiat->usunOrganizm(org);
		swiat->dodajRaport(org->wypisanie() + " umarl przez " + wypisanie());
	}
}

void Barszcz::akcja()
{
	Roslina::akcja();

	int x = getPolozenie()->getX();
	int y = getPolozenie()->getY();

	usunZwierze(x - 1, y - 1);
	usunZwierze(x, y - 1);
	usunZwierze(x + 1, y - 1);
	usunZwierze(x - 1, y);
	usunZwierze(x + 1, y);
	usunZwierze(x - 1, y + 1);
	usunZwierze(x, y + 1);
	usunZwierze(x + 1, y + 1);
}

void Barszcz::kolizja(Organizm* org)
{
	Roslina::kolizja(org);
	getSwiat()->usunOrganizm(org);
	getSwiat()->dodajRaport(org->wypisanie() + " zjadl " + wypisanie());
}

const char Barszcz::rysowanie()
{
	return 'b';
}

int Barszcz::getKolor()
{
	return 10;
}

string Barszcz::wypisanie()
{
	return "barszcz";
}

Barszcz::~Barszcz() {}
