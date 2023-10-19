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

bool Tile::TrySetOccupant(GameObject* gameObject)
{
    if (_occupant == nullptr)
    {
        _occupant = gameObject;
        return true;
    }
    else 
    {
        return false;
    }
}
