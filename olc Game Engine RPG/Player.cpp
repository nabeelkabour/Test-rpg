#include "Player.h"

int item_index[Items::total_item][ItemInfo::total_info] = {
	/*Items::none*/ {0, 0, 0, 0},
	/*Items::sword*/{2, 0, 0, 2},
	/*Items::shield*/{0, 2, 0, 3},
	/*Items::potion*/{0, 0, 5, 1},
	/*Items::bow*/   {1, 0, 1, 3}
};

Player::Player(int _max_hp, int _level, int _damage) : Lifeform{ _max_hp, _level, _damage }
{
	inventory[0] = Items::sword;
	inventory[1] = Items::shield;
	inventory[2] = Items::potion;

	for (int i = 3; i < NUM_INVENTORY_SLOTS; ++i)
	{
		inventory[i] = Items::none;
	}

	items_equipped[offensive] = UNEQUIPPED;
	items_equipped[defensive] = UNEQUIPPED;

	/*for (unsigned i = 1; i < NUM_INVENTORY_SLOTS; ++i)
	{
		equipped_array[i] = false;
		inventory[i] = "Empty";
	}*/
}

void Player::select_item(unsigned slot_val)
{
	int slot_item = inventory.at(slot_val);

	switch (slot_item)
	{
	case Items::sword:
	case Items::bow:
		if (items_equipped[offensive] == slot_val)
		{
			items_equipped[offensive] = UNEQUIPPED;
		}
		else
		{
			items_equipped[offensive] = slot_val;
		}
		break;

	case Items::shield:
		if (items_equipped[defensive] == slot_val)
		{
			items_equipped[defensive] = UNEQUIPPED;
		}
		else
		{
			items_equipped[defensive] = slot_val;
		}
		break;

	case Items::potion:
		//gain hp
		increase_hp(item_index[Items::potion][ItemInfo::special]);

		inventory[slot_val] = Items::none;
		break;
	}
}

int Player::get_damage()
{
	//return damage plus item_damage
	if (items_equipped[offensive] != UNEQUIPPED)
	{
		return Lifeform::get_damage() + item_index[inventory[items_equipped[offensive]]][ItemInfo::damage];
	}

	return Lifeform::get_damage();
}

int Player::get_max_hp()
{
	if (items_equipped[defensive] != UNEQUIPPED)
	{
		return Lifeform::get_max_hp() + item_index[inventory[items_equipped[defensive]]][ItemInfo::health];
	}

	return Lifeform::get_max_hp();

	//return 200;
}

bool Player::inventory_gain_item(int _item)
{
	for (int i = 0; i < NUM_INVENTORY_SLOTS; ++i)
	{
		if (inventory[i] == Items::none)
		{
			inventory[i] = _item;
			return true;
		}
	}

	return false;
}

int Player::get_gold()
{
	return gold;
}

bool Player::reduce_gold(int _amount)
{
	gold -= _amount;

	if (gold < 0)
	{
		//cout << "NEGATIVE GOLD" << endl;
		return false;
	}

	return true;
}

//void Player::set_name(string _name)
//{
//	name = _name;
//}
//
//string Player::get_name()
//{
//	return name;
//}
//
//int Player::get_hp()
//{
//	return hp;
//}
//
//int Player::get_max_hp()
//{
//	return max_hp;
//}