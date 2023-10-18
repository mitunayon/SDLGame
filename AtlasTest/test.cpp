#include "pch.h"
#include "atlas.h"

TEST(AtlasTestCase, GivenEmptyWorld_WhenCreateMapCalled_ThenMapIsCreated)
{
	WorldSystem WorldSystem;

	Map* map = WorldSystem.CreateMap();
	EXPECT_TRUE(map != nullptr);

}
