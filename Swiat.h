#pragma once

#include <vector>
#include <iostream>
#include <String>

using namespace std;

class Organizm;
class Kontroler;

namespace swiatNamespace
{
	class Polozenie;

	class Swiat
	{
	private:
		const char* SAVE_FILE_NAME = "swiat.save";
		int n;
		int m;
		bool koniec = false;
		bool nowySwiat = false;
		vector<vector<Organizm*>> plansza;
		vector<Organizm*> organizmy;
		vector<string> raport;

		void zrobPlansze();
		void wyczyscPlansze();
		void zniszczPlansze();

		void wypiszRaport();
		void wyczyscOrganizmy(bool bezCzlowieka = false);
		Organizm* generujOrganizm(char typ, Kontroler* kontroler);
	public:
		Swiat(int n = 20, int m = 20);

		int getN() const
		{
			return n;
		}

		int getM() const
		{
			return m;
		}

		bool getKoniec() const
		{
			return koniec;
		}

		void setKoniec(const bool value)
		{
			koniec = value;
		}
		
		bool getNowySwiat() const
		{
			return nowySwiat;
		}

		void setNowySwiat(const bool value)
		{
			nowySwiat = value;
		}

		Organizm* getPosPlansza(int i, int j) const;

		void wykonajTure();

		void rysujSwiat();

		bool dodajOrganizm(Organizm* org);

		void przesunOrganizm(Organizm* org, Polozenie* nowe);

		void usunOrganizm(Organizm* org);

		void dodajRaport(string rap);

		void save(Kontroler* kontroler);

		void load(Kontroler* kontroler, Polozenie* pos);

		~Swiat();

		void zapisz(ostream& os)
		{
			os << n << ' ' << m << ' ' << koniec;
		}

		void czytaj(istream& is)
		{
			is >> n >> m >> koniec;
		}
	};
}