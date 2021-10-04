#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Lifeform.h"
#include "Player.h"
#include "Pages.h"
#include "olcPixelGameEngine.h"

#define FIGHT_EXIT_PLAYER_WIN 1
#define FIGHT_EXIT_CH1_WIN 1
#define FIGHT_EXIT_CH2_WIN 2
#define FIGHT_EXIT_PLAYER_FLEE 3

void game_loop();
void fight_loop();
int player_fight(Player&, Lifeform&);
int round(Lifeform&, int, Lifeform&, int);
char get_player_input();
void process_player_input(char);
void handle_drops(Player&, Lifeform&);

//Levels
void village(Player&);
void weaponsmith(Player&);
void armory(Player&);
void chemist(Player&);

class PageState;

class Game : public olc::PixelGameEngine
{
	olc::Sprite* player_sprite = nullptr;
	olc::Decal* player_decal = nullptr;

	Player* player1 = nullptr;
	
public:
	PageState* _page_state = nullptr;

	Game();
	bool OnUserCreate() override;
	bool OnUserUpdate(float) override;
};

#endif
