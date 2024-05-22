#pragma once
#include "Polozenie.h"
#include "Swiat.h"
#include <iostream>

using namespace swiatNamespace;

class Organizm
{
private:
	int sila;
	int inicjatywa;
	int wiek;
	Polozenie polozenie;
	Swiat* swiat;

public:
	Organizm(Swiat* swiat, int inicjatywa = 0, int sila = 0);

	int getSila() const
	{
		return sila;
	}

	void setSila(const int sila)
	{
		this->sila = sila;
	}

	Polozenie* getPolozenie()
	{
		return &polozenie;
	}

	void setPolozenie(Polozenie* pos)
	{
		polozenie = Polozenie(pos);
	}

	int getInicjatywa() const
	{
		return inicjatywa;
	}

	void setInicjatywa(const int inicjatywa)
	{
		this->inicjatywa = inicjatywa;
	}

	int getWiek() const
	{
		return wiek;
	}

	Swiat* getSwiat() const
	{
		return swiat;
	}

	void dodajWiek();

	void zmniejszWiek();

	virtual void koniecGry();

	virtual void akcja() = 0;

	virtual void kolizja(Organizm* org) = 0;

	virtual bool czyOdbilAtak() = 0;

	virtual Organizm* narodziny() = 0;

	virtual const char rysowanie() = 0;

	virtual int getKolor() = 0;

	virtual string wypisanie() = 0;

	static bool porownaj(Organizm* pierwszy, Organizm* drugi);

    virtual void czytaj(istream& is);

    virtual void zapisz(ostream& os);

	virtual ~Organizm();

};

