#include "atlas.h"
#include <iostream>

Map* WorldSystem::CreateMap(int width, int height)
{
	Map* mapPtr = new Map(width, height);
	return mapPtr;
}


