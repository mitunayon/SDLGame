#pragma once
class Map
{
public:
	Map(int width, int height);
	~Map();

	//Get
	int GetWidth();
	int GetHeight();

private:
	int _width;
	int _height;
};

