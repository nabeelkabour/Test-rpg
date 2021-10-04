#include "Gui.h"
#include <iostream>
#include "Player.h"

void fight_hud(Lifeform* char1, Lifeform* char2)
{
	/*cout << char1->get_name() << ": " << char1->get_hp() << "/" << char1->get_max_hp() << "hp lvl: " << char1->get_level();
	cout << " " << "Dmg: " << char1->get_damage();
	cout << "  vs  ";
	cout << char2->get_name() << ": " << char2->get_hp() << "/" << char2->get_max_hp() << "hp lvl: " << char2->get_level();
	cout << " " << "Dmg: " << char2->get_damage();
	cout << endl;*/
}

void display_actions()
{
	//cout << "-Attack [x]  " << "-Flee [z]" << endl;
}

void display_inventory(const Player& player)
{
	//cout << endl;
	//cout << "Inv: ";

	for (unsigned i = 0; i < NUM_INVENTORY_SLOTS; ++i)
	{
		if (player.items_equipped[offensive] == i or player.items_equipped[defensive] == i)
		{
			//cout << "*";
		}

		//cout << "[" << i + 1 << "]";

		//use this to display items on cout

		display_item(player.inventory.at(i));

		//cout << " ";
		//cout << player.inventory.at(i) << " ";
	}

	//cout << endl << endl;
}

void show_drops(Items _arr[], int _size)
{
	//cout << "Drops: " << endl;
	for (int i = 0; i < _size; ++i)
	{
		//cout << "[" << i + 1 << "]";
		display_item(_arr[i]);
		//cout << " ";
	}
	//cout << "  " << "[x]Done" << endl;
}


void display_item(int _item)
{
	switch (_item)
	{
	case none:
		//cout << "empty";
		break;

	case sword:
		//cout << "sword";
		break;

	case shield:
		//cout << "shield";
		break;

	case potion:
		//cout << "potion";
		break;

	case bow:
		//cout << "bow";
		break;

	case arrows:
		//cout << "arrows";
		break;
	}
}

void display_gold(Player& _player)
{
	//cout << "gold: " << _player.get_gold();
}
