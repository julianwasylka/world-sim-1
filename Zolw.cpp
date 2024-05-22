#include "Zolw.h"

Zolw::Zolw(Swiat* swiat) : Zwierze(swiat)
{
	setSila(2);
	setInicjatywa(1);
}

Zolw::Zolw(Zolw* prev) : Zwierze(prev) {}

void Zolw::akcja()
{
	int ruch = rand() % 4;
	if (ruch == 0) Zwierze::akcja();
}

void Zolw::kolizja(Organizm* org)
{
	if (org->getSila() < 5 && typeid(*this) != typeid(*org))
	{
		if (dynamic_cast<Zwierze*>(org) != nullptr)
		{
			Zwierze* zw = static_cast<Zwierze*>(org);
			zw->setRuch(false);
		}
	}
	else Zwierze::kolizja(org);
}

Organizm* Zolw::narodziny()
{
	return new Zolw(this);
}

bool Zolw::czyOdbilAtak()
{
	return false;
}

const char Zolw::rysowanie()
{
	return 'z';
}

int Zolw::getKolor()
{
	return 13;
}

string Zolw::wypisanie()
{
	return "zolw";
}

Zolw::~Zolw() {}
