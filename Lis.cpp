#include "Lis.h"

Lis::Lis(Swiat* swiat) : Zwierze(swiat)
{
	setSila(3);
	setInicjatywa(7);
}

Lis::Lis(Lis* prev) : Zwierze(prev) {}

void Lis::akcja()
{
	dodajWiek();

	if (!getRuch())
	{
		setRuch(true);
		return;
	}

	Polozenie ruch = Polozenie(getPolozenie());
	ruch.losowyKrok();
	Organizm* pos = getSwiat()->getPosPlansza(ruch.getX(), ruch.getY());

	if (pos != nullptr && pos != this)
	{
		if (pos->getSila() > getSila())
		{
			getSwiat()->dodajRaport(wypisanie() + " wyczul " + pos->wypisanie());
			return;
		}
		else pos->kolizja(this);
	}
	if (getRuch()) getSwiat()->przesunOrganizm(this, &ruch);
	else setRuch(true);
}

Organizm* Lis::narodziny()
{
	return new Lis(this);
}

bool Lis::czyOdbilAtak()
{
	return false;
}

const char Lis::rysowanie()
{
	return 'l';
}

int Lis::getKolor()
{
	return 12;
}

string Lis::wypisanie()
{
	return "lis";
}

Lis::~Lis() {}
