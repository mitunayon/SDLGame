#include "Map.h"
#include <iostream>


Map::Map(int width, int height)
{
	_width = width;
	_height = height;

}

Map::~Map()
{
	std::cout << "Map is being deleted" << std::endl;
}

int Map::GetWidth()
{
	return _width;
}

int Map::GetHeight()
{
	return _height;
}
