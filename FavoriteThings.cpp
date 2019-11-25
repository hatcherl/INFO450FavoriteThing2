#include <iostream>
#include <string>
#include "FavoriteThings.h"
#include "FavoriteThingsList.h"
using namespace std;

favoriteThings::favoriteThings(int i, string t, string a, int y, string g)
{

};

favoriteThings::favoriteThings()
{
	id = 0;
	title = " ";
	artist = " ";
	year = 0;
	genre = " ";
};


//getters
int  favoriteThings::getID()
{
	return id;
}
string favoriteThings::getTitle()
{
	return title;
}
string favoriteThings::getArtist()
{
	return artist;
}
int favoriteThings::getYear()
{
	return year;
}
string favoriteThings::getGenre()
{
	return genre;
}


//setters
void favoriteThings::setID(int i)
{
	id = i;
}

void favoriteThings::setTitle(string t)
{
	title = t;
}

void favoriteThings::setArtist(string a)
{
	artist = a;
}

void favoriteThings::setYear(int y)
{
	year = y;
}

void favoriteThings::setGenre(string g)
{
	genre = g;
}


void favoriteThings::setAlbumInfo()
{
	cout << "Album ID#: ";
	cin >> id;
	if (cin.fail())
	{
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> id;
		} while (cin.fail());
	}
	cin.ignore();
	cout << "Album Title : ";
	getline(cin, title, '\n');
	cout << "Arist Name: ";
	getline(cin, artist, '\n');
	cout << "Year: ";
	cin >> year;
	cin.ignore();
	cout << "Genre: ";
	getline(cin, genre, '\n');
}

ostream& operator<<(ostream& output, favoriteThings& i)
{
	output << "Album: " << endl << "ID: " << i.id << "| " << i.title << " " << "by " << i.artist << " " << "released in " << i.year << " " << "genre: " << i.genre << endl;
	return output;
}
