#include "Polozenie.h"

using namespace swiatNamespace;

Polozenie::Polozenie(Swiat* swiat) : swiat(swiat)
{
	if (swiat == nullptr)
	{
		x = 0;
		y = 0;
		return;
	}
	int a = rand() % swiat->getN();
	int b = rand() % swiat->getM();

	while (a == (swiat->getN() / 2)) a = rand() % swiat->getN();
	while (b == (swiat->getM() / 2)) b = rand() % swiat->getM();

	x = a;
	y = b;
}

Polozenie::Polozenie(Swiat* swiat, int x, int y)
	: x(x), y(y), swiat(swiat) {}

Polozenie::Polozenie(Polozenie* prev)
	: x(prev->x), y(prev->y), swiat(prev->swiat) {}

void Polozenie::setXY(Polozenie* pos)
{
    x = pos->x;
    y = pos->y;
}

bool Polozenie::przesun(int x, int y)
{
	if (this->x + x < swiat->getN() && this->x + x >= 0
		&& this->y + y < swiat->getM() && this->y + y >= 0)
	{
		this->x += x;
		this->y += y;
		return true;
	}
	return false;
}

bool Polozenie::losowyKrok(int gdzie, int krok)
{
	if (gdzie == -1) gdzie = rand() % 8;

	// 0 1 2
	// 3 X 4
	// 5 6 7

	switch (gdzie)
	{
	case 0:
		return przesun(-1 * krok, -1 * krok);
	case 1:
		return przesun(0, -1 * krok);
	case 2:
		return przesun(krok, -1 * krok);
	case 3:
		return przesun(-1 * krok, 0);
	case 4:
		return przesun(krok, 0);
	case 5:
		return przesun(-1 * krok, krok);
	case 6:
		return przesun(0, krok);
	case 7:
		return przesun(krok, krok);
	}
	return false;
}

bool Polozenie::operator==(Polozenie* other)
{
	return other->getX() == x && other->getY() == y;
}

void Polozenie::czytaj(istream& is)
{
	is >> x >> y;
}

void Polozenie::zapisz(ostream& os)
{
	os << x << ' ' << y;
}

Polozenie::~Polozenie() {}