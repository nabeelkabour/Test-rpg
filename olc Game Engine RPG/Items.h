#ifndef ITEMS_H
#define ITEMS_H

#include "Lifeform.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <array>

#define NUM_INVENTORY_SLOTS 5
#define UNEQUIPPED -1


enum Items
{
	none,
	sword,
	shield,
	potion,
	bow,
	arrows,
	total_item
};

enum ItemInfo
{
	damage,
	health,
	special,
	price,
	total_info
};

enum PlayerItem
{
	offensive,
	defensive
};

#endif
