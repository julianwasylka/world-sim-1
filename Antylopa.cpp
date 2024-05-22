#include "Antylopa.h"

Antylopa::Antylopa(Swiat* swiat) : Zwierze(swiat)
{
	setSila(4);
	setInicjatywa(4);
	czyUciekla = false;
}

Antylopa::Antylopa(Antylopa* prev) : Zwierze(prev)
{
	czyUciekla = false;
}

void Antylopa::akcja()
{
	dodajWiek();

	if (!getRuch())
	{
		setRuch(true);
		return;
	}

	Polozenie ruch = Polozenie(getPolozenie());
	ruch.losowyKrok(-1, 2);
	Organizm* pos = getSwiat()->getPosPlansza(ruch.getX(), ruch.getY());

	if (pos != nullptr && pos != this) pos->kolizja(this);
	if (getRuch()) getSwiat()->przesunOrganizm(this, &ruch);
	else setRuch(true);
}

void Antylopa::kolizja(Organizm* org)
{
	int ucieczka = rand() % 2;

	if (ucieczka == 0)
	{
		czyUciekla = true;
	}
	else czyUciekla = false;

	Zwierze::kolizja(org);
}

void Antylopa::odbicie(Organizm* organizm)
{
	Polozenie nowe = Polozenie(getPolozenie());

	if (nowe.losowyKrok())
	{
		Organizm* prev = getSwiat()->getPosPlansza(nowe.getX(), nowe.getY());
		if (prev == nullptr)
		{
			getSwiat()->przesunOrganizm(this, &nowe);
			setRuch(false);
			return;
		}
	}
	nowe = Polozenie(getPolozenie());

	for (int i = 0; i <= 8; i++)
	{
		if (i == 8)
		{
			getSwiat()->usunOrganizm(this);
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
			getSwiat()->przesunOrganizm(this, &nowe);
			setRuch(false);
			return;
		}
		nowe = Polozenie(getPolozenie());
	}
}

Organizm* Antylopa::narodziny()
{
	return new Antylopa(this);
}

bool Antylopa::czyOdbilAtak()
{
	return czyUciekla;
}

const char Antylopa::rysowanie()
{
	return 'a';
}

int Antylopa::getKolor()
{
	return 6;
}

string Antylopa::wypisanie()
{
	return "antylopa";
}

void Antylopa::zapisz(ostream& os)
{
	Zwierze::zapisz(os);
	os << ' ' << czyUciekla;
}

void Antylopa::czytaj(istream& is)
{
	Zwierze::czytaj(is);
	is >> czyUciekla;
}

Antylopa::~Antylopa() {}
