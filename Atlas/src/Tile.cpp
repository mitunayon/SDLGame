#include "Tile.h"
#include <vector>

Tile::Tile()
{
    _occupant = nullptr;
    //_occupant = new std::vector<GameObject>(0);
}

GameObject* Tile::GetOccupant()
{
    return _occupant;
}
