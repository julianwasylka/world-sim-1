#pragma once
#include <iostream>
#include "Polozenie.h"
#include "Swiat.h"

using namespace swiatNamespace;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SHIELD 32
#define KEY_EXIT 'q'
#define KEY_LOAD 'l'
#define KEY_SAVE 's'

class Kontroler
{
private:
	int cooldown;
	Swiat* swiat;
public:
	Kontroler(Swiat* swiat);

	void ruchCzlowieka(Polozenie* pos);

	void clear();

	int getCooldown() const
	{
		return cooldown;
	}

	void setCooldown(const int newCd)
	{
		cooldown = newCd;
	}

	~Kontroler();
};

