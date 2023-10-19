#pragma once
#include "Map.h"
#include "Tile.h"

class WorldSystem 
{
public:
	Map* CreateMap(int width, int height);

private:
	int _secretNumber;
};