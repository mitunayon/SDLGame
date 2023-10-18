#include <stdio.h>
#include "pch.h"

int main(int argc, char* args[])
{
	std::cout << "Test run begins" << std::endl;
	testing::InitGoogleTest(&argc, args);
	
	return RUN_ALL_TESTS();
}