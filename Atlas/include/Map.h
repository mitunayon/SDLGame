#pragma once
#include "Tile.h"
#include <vector>

class Map
{
public:
	Map(int rows, int columns);
	~Map();

	//Get
	int GetWidth();
	int GetHeight();

	Tile* GetTile(int widthIndex, int heightIndex);

private:
	int _columns;
	int _rows;

	std::vector<std::vector<Tile*>> _tiles;
};

