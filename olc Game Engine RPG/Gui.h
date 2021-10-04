#ifndef GUI_H
#define GUI_H

#include "Lifeform.h"
#include "Player.h"

void fight_hud(Lifeform*, Lifeform*);
void display_actions();
void display_inventory(const Player&);
void show_drops(Items[], int);
void display_item(int);
void display_gold(Player&);

#endif 


