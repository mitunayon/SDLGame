#include "pch.h"
#include "atlas.h"
#include "test.h"

TEST(AtlasMapCreation, GivenEmptyWorld_WhenCreateMap_ThenMapIsCreated)
{
	WorldSystem WorldSystem;

	Map* map = WorldSystem.CreateMap(10,10);
	EXPECT_TRUE(map != nullptr);
	delete map;

}

TEST(AtlasMapCreation, GivenEmptyWorld_WhenCreateMap_ThenMapOfWidthAndHeightIsCreated)
{
	WorldSystem WorldSystem;

	Map* map = WorldSystem.CreateMap(10,10);
	EXPECT_TRUE(map->GetWidth() == 10);
	EXPECT_TRUE(map->GetHeight() == 10);

	delete map;
}

TEST(AtlasMapCreation, GivenEmptyWorld_WhenCreateMap_ThenMapTilesAreNotNull)
{
	WorldSystem WorldSystem;

	Map* map = WorldSystem.CreateMap(10, 10);
	Tile* Tile = map->GetTile(5, 5);

	EXPECT_TRUE(Tile != nullptr);

	delete map;
}

TEST(AtlasTiles, GivenNewTile_WhenGetOccupants_ThenReturnNullGameObject)
{
	Tile Tile;
	GameObject* Occupant = Tile.GetOccupant();

	EXPECT_TRUE(Occupant == nullptr);
}

TEST(AtlasTiles, GivenNewTile_WhenSetOccupantAndGetOccupant_ThenReturnGameObjectPtr)
{
	Tile Tile;
	GameObject* TestGameObject = new GameObject;
	Tile.TrySetOccupant(TestGameObject);
	GameObject* Occupant = Tile.GetOccupant();

	EXPECT_TRUE(Occupant == TestGameObject);
}
