#include "Czlowiek.h"
#include "Roslina.h"

Czlowiek::Czlowiek(Swiat* swiat, Kontroler* kontroler) : Zwierze(swiat)
{
	setPolozenie(new Polozenie(swiat, swiat->getN() / 2, swiat->getM() / 2));
	setSila(5);
	setInicjatywa(4);
	setRuch(true);
	this->kontroler = kontroler;
}

void Czlowiek::akcja()
{
	dodajWiek();

	Polozenie old = Polozenie(getPolozenie());
	kontroler->ruchCzlowieka(&old);
	Organizm* pos = getSwiat()->getPosPlansza(old.getX(), old.getY());

	if (pos != nullptr) pos->kolizja(this);
	if (!getRuch())
	{
		setRuch(true);
		return;
	}
	getSwiat()->przesunOrganizm(this, &old);
}

void Czlowiek::odbicie(Organizm* organizm)
{
	Polozenie nowe = Polozenie(getPolozenie());

	if (nowe.losowyKrok())
	{
		Organizm* prev = getSwiat()->getPosPlansza(nowe.getX(), nowe.getY());
		if (prev == nullptr)
		{
			getSwiat()->przesunOrganizm(organizm, &nowe);
			Zwierze* zw = static_cast<Zwierze*>(organizm);
			zw->setRuch(false);
			return;
		}
	}
	nowe = Polozenie(getPolozenie());
	for (int i = 0; i <= 8; i++)
	{
		if (i == 8)
		{
			getSwiat()->usunOrganizm(organizm);
			return;
		}
		if (nowe.losowyKrok(i))
		{
			Organizm* prev = getSwiat()->getPosPlansza(nowe.getX(), nowe.getY());
			if (prev != nullptr)
			{
				nowe = Polozenie(getPolozenie());
				continue;
			}
			getSwiat()->przesunOrganizm(organizm, &nowe);
			Zwierze* zw = static_cast<Zwierze*>(organizm);
			zw->setRuch(false);
			return;
		}
		nowe = Polozenie(getPolozenie());
	}
}

const char Czlowiek::rysowanie()
{
	return '#';
}

int Czlowiek::getKolor()
{
	return 11;
}

string Czlowiek::wypisanie()
{
	return "czlowiek";
}

bool Czlowiek::czyOdbilAtak()
{
	if (kontroler->getCooldown() > 5)
	{
		return true;
	}
	return false;
}

Organizm* Czlowiek::narodziny()
{
	return nullptr;
}

void Czlowiek::koniecGry()
{
	getSwiat()->setKoniec(true);
}

Czlowiek::~Czlowiek() {}