#include "Map.h"
#include <iostream>


Map::Map(int rows, int columns)
{
	_rows = rows;
	_columns = columns;

	_tiles.resize(rows);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			_tiles[i].push_back(new Tile());
		}
	}
}

Map::~Map()
{
	std::cout << "Map is being deleted" << std::endl;

	for (int i = 0; i < _tiles.size(); i++)
	{
		for (int j = 0; j < _tiles[0].size(); j++)
		{
			delete _tiles[i][j];
		}
	}

	_tiles.clear();
}

int Map::GetWidth()
{
	return _columns;
}

int Map::GetHeight()
{
	return _rows;
}

Tile* Map::GetTile(const int row, const int column)
{
	Tile* Tile = _tiles[row][column];
	return Tile;
}
