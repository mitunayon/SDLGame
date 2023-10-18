#include "pch.h"
#include "atlas.h"

TEST(AtlasMapCreation, GivenEmptyWorld_WhenCreateMapCalled_ThenMapIsCreated)
{
	WorldSystem WorldSystem;

	Map* map = WorldSystem.CreateMap(10,10);
	EXPECT_TRUE(map != nullptr);
	delete map;

}

TEST(AtlasMapCreation, GivenEmptyWorld_WhenCreateMapCalledWithArguments_ThenMapOfWidthAndHeightIsCreated)
{
	WorldSystem WorldSystem;

	Map* map = WorldSystem.CreateMap(10,10);
	EXPECT_TRUE(map->GetWidth() == 10);
	EXPECT_TRUE(map->GetHeight() == 10);

	delete map;
}
