#pragma once
#include <iostream>
#include <string>
#include "FavoriteThings.h"
#include <fstream>

using namespace std;

//created my favoriteList class. I Called it favoriteList instead of albums to both keep the naming conventions
//And make it so that if I wanted to I could make another list... such as favoriteThings Cookies[100];
class favoriteList
{
	favoriteThings albums[100];
	int numAlbums;
	int totalAlbums;

public:
	favoriteList();
	void addAlbum();
	void showList();
	int readFile(string filename);
	int saveToFile(string filename);
};
