#include <typeinfo>
#include "Zwierze.h"
#include "Polozenie.h"

Zwierze::Zwierze(Swiat* swiat) : Organizm(swiat)
{
	czyRuch = true;
}

Zwierze::Zwierze(Zwierze* poprzednie) : Zwierze(poprzednie->getSwiat())
{
	czyRuch = false;
    setPolozenie(poprzednie->getPolozenie());
    setSila(poprzednie->getSila());
}

bool Zwierze::getRuch()
{
	return czyRuch;
}

void Zwierze::setRuch(bool perm)
{
	czyRuch = perm;
}

void Zwierze::akcja()
{
	dodajWiek();

	if (!czyRuch)
	{
		czyRuch = true;
		return;
	}

	Polozenie ruch = Polozenie(getPolozenie());
	ruch.losowyKrok();
	Organizm* pos = getSwiat()->getPosPlansza(ruch.getX(), ruch.getY());

	if (pos != nullptr && pos != this) pos->kolizja(this);
	if (czyRuch) getSwiat()->przesunOrganizm(this, &ruch);
	else czyRuch = true;
}

void Zwierze::odbicie(Organizm* organizm) {}

void Zwierze::kolizja(Organizm* organizm)
{
	if (organizm == nullptr) return;
	if (dynamic_cast<Zwierze*> (organizm) != nullptr)
	{
		Zwierze* org = static_cast<Zwierze*> (organizm);
		if (typeid(*this) == typeid(*org))
		{
			rozmnazanie(org);
			return;
		}
		else if (org->czyOdbilAtak())
		{
			org->odbicie(this);
			getSwiat()->dodajRaport(org->wypisanie() + " uniknal ataku " + wypisanie());
			return;
		}
		else if (czyOdbilAtak())
		{
			odbicie(org);
			getSwiat()->dodajRaport(wypisanie() + " uniknal ataku " + org->wypisanie());
			return;
		}
	}

	if (getSila() < organizm->getSila())
	{
		getSwiat()->dodajRaport(organizm->wypisanie() + " pokonal " + wypisanie());
		getSwiat()->usunOrganizm(this);
	}
	else
	{
		getSwiat()->dodajRaport(wypisanie() + " pokonal " + organizm->wypisanie());
		getSwiat()->usunOrganizm(organizm);
		czyRuch = false;
	}
}

void Zwierze::rozmnazanie(Zwierze* other)
{
	czyRuch = false;
	other->czyRuch = false;

	int counter = 0;
	while (counter < 8)
	{
		Polozenie parent = Polozenie(getPolozenie());
		parent.losowyKrok();
		Organizm* pos = getSwiat()->getPosPlansza(parent.getX(), parent.getY());

		if (pos == nullptr)
		{
			Organizm* nowe = narodziny();
			if (nowe == nullptr) return;
			nowe->setPolozenie(&parent);
			getSwiat()->dodajOrganizm(nowe);
			getSwiat()->dodajRaport("narodzil sie " + wypisanie());
			return;
		}
		else
		{
			counter++;
		}
	}
}

void Zwierze::zapisz(ostream& os)
{
	Organizm::zapisz(os);
	os << ' ' << czyRuch;
}

void Zwierze::czytaj(istream& is)
{
	Organizm::czytaj(is);
	is >> czyRuch;
}

Zwierze::~Zwierze() {}