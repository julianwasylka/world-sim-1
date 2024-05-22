#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "Swiat.h"
#include "Organizm.h"
#include "Czlowiek.h"
#include "Antylopa.h"
#include "Barszcz.h"
#include "Guarana.h"
#include "Jagody.h"
#include "Lis.h"
#include "Mlecz.h"
#include "Owca.h"
#include "Trawa.h"
#include "Wilk.h"
#include "Zolw.h"


using namespace swiatNamespace;

Swiat::Swiat(int n, int m)
	: n(n), m(m)
{
	zrobPlansze();
}

void Swiat::wykonajTure()
{
	size_t size = organizmy.size();

	std::sort(organizmy.begin(), organizmy.end(), Organizm::porownaj);

	for (int i = 0; i < size; i++)
	{
		if (nowySwiat)
		{
			nowySwiat = false;
			break;
		}
		if (i >= organizmy.size()) break;
		organizmy[i]->akcja();
	}
}

void Swiat::wyczyscPlansze()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			plansza[i][j] = nullptr;
		}
	}
}

void Swiat::rysujSwiat()
{
	wyczyscPlansze();

	cout << "Julian Wasylka 193223" << endl;

	for (int i = 0; i < organizmy.size(); i++)
	{
		Polozenie* pos = organizmy[i]->getPolozenie();
		plansza[pos->getX()][pos->getY()] = organizmy[i];
	}

	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Organizm* pos = plansza[i][j];
			if (pos == nullptr) cout << ". ";
			else
			{
				SetConsoleTextAttribute(hConsole, pos->getKolor());
				cout << pos->rysowanie() << ' ';
				SetConsoleTextAttribute(hConsole, 7);
			}
		}
		cout << endl;
	}

	for (int i = 0; i < raport.size(); i++)
	{
		cout << raport[i];
		if (i < raport.size() - 1) cout << ", ";
	}
	cout << endl;

	raport.clear();
}

Organizm* Swiat::getPosPlansza(int i, int j) const
{
	return plansza[i][j];
}

bool Swiat::dodajOrganizm(Organizm* org)
{
	if (plansza[org->getPolozenie()->getX()][org->getPolozenie()->getY()] != nullptr)
	{
		delete org;
		return false;
	}
	organizmy.push_back(org);
	plansza[org->getPolozenie()->getX()][org->getPolozenie()->getY()] = org;
	return true;
}

void Swiat::usunOrganizm(Organizm* org)
{
	org->koniecGry();
	plansza[org->getPolozenie()->getX()][org->getPolozenie()->getY()] = nullptr;
	organizmy.erase(remove(organizmy.begin(), organizmy.end(), org), organizmy.end());
}

void Swiat::przesunOrganizm(Organizm* org, Polozenie* nowe)
{
	plansza[org->getPolozenie()->getX()][org->getPolozenie()->getY()] = nullptr;
	plansza[nowe->getX()][nowe->getY()] = org;
	org->setPolozenie(nowe);
}

void Swiat::dodajRaport(string rap)
{
	raport.push_back(rap);
}

void Swiat::wypiszRaport()
{
	for (int i = 0; i < raport.size(); i++)
	{
		cout << raport[i];
		if (i < raport.size() - 1) cout << ", ";
	}
	cout << endl;

	raport.clear();
}

void Swiat::save(Kontroler* kontroler)
{
    ofstream fp;
    fp.open(SAVE_FILE_NAME, ios::out);

    if(!fp.is_open()) return;

    fp << kontroler->getCooldown() << endl;

    zapisz(fp);
	fp << endl;

    fp << organizmy.size() << endl;
    for (Organizm* org : organizmy)
    {
		org->zapisz(fp);
		fp << endl;
    }

    fp << raport.size() << endl;
    for (string info : raport)
    {
        fp << info << endl;
    }

    fp.close();
}

void Swiat::load(Kontroler* kontroler, Polozenie* pos)
{
	ifstream fp;
	fp.open(SAVE_FILE_NAME, ios::in);

	if (!fp.is_open()) return;

	wyczyscOrganizmy(true);
	zniszczPlansze();

	int tmp = 0;
	fp >> tmp;
	kontroler->setCooldown(tmp);

	czytaj(fp);
	zrobPlansze();

	char typ = ' ';
	fp >> tmp;
	for (int i = 0; i < tmp; i++)
	{
		Organizm* org = nullptr;
		fp >> typ;
		if (typ == '#') org = organizmy.at(0);
		else org = generujOrganizm(typ, kontroler);

		org->czytaj(fp);
		if (typ == '#') 
		{
			pos->setXY(org->getPolozenie());
		}
		else dodajOrganizm(org);
	}

	fp >> tmp;
	for (int i = 0; i < tmp; i++)
	{
		string info;
		getline(fp, info);
		raport.push_back(info);
	}

	fp.close();

	kontroler->clear();
	rysujSwiat();
}

Organizm* Swiat::generujOrganizm(char typ, Kontroler* kontroler)
{
	Organizm* org = nullptr;
	switch (typ)
	{
	case 'a':
		org = new Antylopa(this);
		break;
	case 'b':
		org = new Barszcz(this);
		break;
	case '#':
		org = new Czlowiek(this, kontroler);
		break;
	case 'g':
		org = new Guarana(this);
		break;
	case 'j':
		org = new Jagody(this);
		break;
	case 'l':
		org = new Lis(this);
		break;
	case 'm':
		org = new Mlecz(this);
		break;
	case 'o':
		org = new Owca(this);
		break;
	case 't':
		org = new Trawa(this);
		break;
	case 'w':
		org = new Wilk(this);
		break;
	case 'z':
    	org = new Zolw(this);
    	break;

	default:
		break;

	}
	return org;
}

void Swiat::zrobPlansze()
{
	plansza = vector<vector<Organizm*>>(n);
	for (int i = 0; i < n; i++)
	{
		plansza[i] = vector<Organizm*>(m);
		for (int j = 0; j < m; j++)
		{
			plansza[i][j] = nullptr;
		}
	}
}

void Swiat::zniszczPlansze()
{
	for (vector<Organizm*> cols : plansza) cols.clear();
	plansza.clear();
}

void Swiat::wyczyscOrganizmy(bool bezCzlowieka)
{
	if (bezCzlowieka)
	{
		vector<Organizm*>::iterator iter = organizmy.begin();
		while (iter != organizmy.end())
		{
			if ((*iter)->rysowanie() != '#')
			{
				delete (*iter);
				iter = organizmy.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
	else
	{
		for (Organizm* org : organizmy)
		{
			delete org;
		}
		organizmy.clear();
	}
}

Swiat::~Swiat()
{
    wyczyscOrganizmy();
	raport.clear();
	zniszczPlansze();
}