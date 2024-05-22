#include <conio.h>
#include <stdlib.h>
#include "Kontroler.h"

Kontroler::Kontroler(Swiat* swiat)
{
    cooldown = 0;
    this->swiat = swiat;
}

void Kontroler::ruchCzlowieka(Polozenie* pos)
{
    int pX = pos->getX();
    int pY = pos->getY();
    bool czyDalej = true;

    while (czyDalej)
    {
        switch (int key = _getch())
        {
        case KEY_EXIT:
            swiat->setKoniec(true);
            return;
        case KEY_SHIELD:
            if (cooldown == 0)
            {
                cooldown = 10;
                swiat->dodajRaport("uruchomiono tarcze");
            }
            break;

        case KEY_LEFT:
            if (pY - 1 >= 0)
            {
                pY--;
            }
            czyDalej = false;
            break;

        case KEY_RIGHT:
            if (pY + 1 < swiat->getM())
            {
                pY++;
            }
            czyDalej = false;
            break;

        case KEY_DOWN:
            if (pX + 1 < swiat->getN())
            {
                pX++;
            }
            czyDalej = false;
            break;

        case KEY_UP:
            if (pX - 1 >= 0)
            {
                pX--;
            }
            czyDalej = false;
            break;

        case KEY_SAVE:
            swiat->save(this);
            czyDalej = false;
            break;

        case KEY_LOAD:
            swiat->load(this, pos);
            swiat->setNowySwiat(true);
            pX = pos->getX();
            pY = pos->getY();
            czyDalej = false;
            break;

        default: continue;
        }

    }
    if (cooldown > 0)
    {
        cooldown--;
        if (cooldown == 0) swiat->dodajRaport("tarcza gotowa");
        else if (cooldown == 5) swiat->dodajRaport("tarcza wyladowana");
    }
    pos->setX(pX);
    pos->setY(pY);
}

void Kontroler::clear()
{
    system("CLS");
}

Kontroler::~Kontroler() {}