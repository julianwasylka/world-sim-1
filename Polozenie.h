#pragma once
#include <iostream>
#include <time.h>
#include "Swiat.h"

namespace swiatNamespace
{
	class Polozenie
	{
	private:
		int x;
		int y;
		Swiat* swiat;
	public:
		Polozenie(Swiat* swiat = nullptr);

		Polozenie(Swiat* swiat, int x, int y);

		Polozenie(Polozenie* prev);

		int getX() const
		{
			return x;
		}

		void setX(const int x)
		{
			this->x = x;
		}

		int getY() const
		{
			return y;
		}

		void setY(const int y)
		{
			this->y = y;
		}

        void setXY(Polozenie* pos);

		bool przesun(int x, int y);

		bool losowyKrok(int gdzie = -1, int krok = 1);

		bool operator==(Polozenie* other);

		void czytaj(istream& is);

		void zapisz(ostream& os);

		~Polozenie();
	};
}