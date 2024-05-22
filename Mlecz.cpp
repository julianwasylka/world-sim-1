#include "Mlecz.h"

Mlecz::Mlecz(Swiat* swiat) : Roslina(swiat) {}

Mlecz::Mlecz(Mlecz* prev) : Roslina(prev) {}

Organizm* Mlecz::narodziny()
{
	return new Mlecz(this);
}

void Mlecz::akcja()
{
	dodajWiek();
	int counter = 0;
	while (counter < 3)
	{
		Roslina::akcja();
		counter++;
		zmniejszWiek();
	}
}

const char Mlecz::rysowanie()
{
	return 'm';
}

int Mlecz::getKolor()
{
	return 14;
}

string Mlecz::wypisanie()
{
	return "mlecz";
}

Mlecz::~Mlecz() {}
