#include <iostream>
#include "Kontroler.h"
#include "Wilk.h"
#include "Owca.h"
#include "Czlowiek.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "Guarana.h"
#include "Jagody.h"
#include "Barszcz.h"
#include "Lis.h"
#include "Antylopa.h"
#include "Zolw.h"

using namespace std;
using namespace swiatNamespace;

int main()
{
	srand(time(NULL));

	Swiat* swiat = new Swiat();

	Kontroler* kontroler = new Kontroler(swiat);

	swiat->dodajOrganizm(new Czlowiek(swiat, kontroler));
	swiat->dodajOrganizm(new Czlowiek(swiat, kontroler));

	swiat->dodajOrganizm(new Mlecz(swiat));

	swiat->dodajOrganizm(new Trawa(swiat));
	swiat->dodajOrganizm(new Trawa(swiat));

	swiat->dodajOrganizm(new Jagody(swiat));
	swiat->dodajOrganizm(new Jagody(swiat));

	swiat->dodajOrganizm(new Guarana(swiat));
	swiat->dodajOrganizm(new Guarana(swiat));

	swiat->dodajOrganizm(new Barszcz(swiat));
	swiat->dodajOrganizm(new Barszcz(swiat));

	swiat->dodajOrganizm(new Wilk(swiat));
	swiat->dodajOrganizm(new Wilk(swiat));

	swiat->dodajOrganizm(new Owca(swiat));
	swiat->dodajOrganizm(new Owca(swiat));

	swiat->dodajOrganizm(new Lis(swiat));
	swiat->dodajOrganizm(new Lis(swiat));

	swiat->dodajOrganizm(new Zolw(swiat));
	swiat->dodajOrganizm(new Zolw(swiat));
	swiat->dodajOrganizm(new Zolw(swiat));

	swiat->dodajOrganizm(new Antylopa(swiat));
	swiat->dodajOrganizm(new Antylopa(swiat));
	swiat->dodajOrganizm(new Antylopa(swiat));

	do
	{
		kontroler->clear();

		swiat->rysujSwiat();

		swiat->wykonajTure();

	} while (!swiat->getKoniec());

	kontroler->clear();

	swiat->rysujSwiat();

	delete swiat;

	return 0;
}