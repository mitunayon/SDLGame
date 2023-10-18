#pragma once
#include <GameObject.h>
class Tile
{
public:
	Tile();
	GameObject* GetOccupant();

private:
	GameObject* _occupant;
};

