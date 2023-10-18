#pragma once
#include <GameObject.h>
class Tile
{
public:
	Tile();
	GameObject* GetOccupant();
	bool TrySetOccupant(GameObject* gameObject);

private:
	GameObject* _occupant;
};

