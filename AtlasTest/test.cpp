#include "pch.h"
#include "atlas.h"

TEST(MapCreation, CanCreateMap)
{
	EXPECT_EQ(1, 1);
	WorldSystem WorldSystem;
	bool result = false;
	result = WorldSystem.TestFunction();
	EXPECT_TRUE(result);
}