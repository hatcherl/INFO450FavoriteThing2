#pragma once
#include <iostream>
#include <string>

using namespace std;

class favoriteThings {
	// Variables for my class
private:
	int id;
	string title;
	string artist;
	int year;
	string genre;

public:

	//getters
	favoriteThings();
	favoriteThings(int i, string t, string a, int y, string g);
	int getID();
	string getTitle();
	string getArtist();
	int getYear();
	string getGenre();

	//setters
	void setID(int i);
	void setTitle(string t);
	void setArtist(string a);
	void setYear(int i);
	void setGenre(string g);

	void setAlbumInfo();

	//friend function to overload the << operator
	friend ostream& operator<<(ostream& output, favoriteThings& i);


};