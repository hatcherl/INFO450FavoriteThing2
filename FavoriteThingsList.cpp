#include <iostream>
#include <string>
#include "FavoriteThings.h"
#include "FavoriteThingsList.h"
#include <fstream>
using namespace std;

favoriteList::favoriteList()
{
	numAlbums = 0;
}

void favoriteList::addAlbum()
{
	//Need to ask the user for input, then validate information, and THEN set it.
	//albums[numAlbums].setAlbumInfo();
	//Created variables to send to the set functions
	int i, y;
	string t, a, g;
	bool validated = true; //Bool variable to validate album/object
	cout << "Album ID#: ";
	cin >> i; //Below is my cin.fail loop to make sure the user can only put in a valid value to continue. 
			  //Year variable has the same loop.
	if (cin.fail())
	{
		cout << "Please select a valid number!" << endl;
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> i;
		} while (cin.fail());
	}
	cin.ignore(); //cin.ignore to make sure the input stream is prepped for new input. This is repeated down below
	cout << "Album Title : ";
	getline(cin, t, '\n');
	cout << "Arist Name: ";
	getline(cin, a, '\n');
	cout << "Year: ";
	cin >> y;
	if (cin.fail())
	{
		cout << "Please select a valid number!" << endl;
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> i;
		} while (cin.fail());
	}
	cin.ignore();
	cout << "Genre: ";
	getline(cin, g, '\n');


	//Using d b/c i is already a variable outside this loop.
	//This loop and nested loop(s) will be used to check for duplication
	for (int d = 0; d < numAlbums; d++)
	{
		if (albums[d].getID() == i)
		{
			validated = false;
			cout << "Please select a valid ID #" << endl;
		}
		if (albums[d].getTitle() == t && albums[d].getArtist() == a)
		{
			validated = false;
			cout << "This album already exists. An artist can't have an album with the same exact title." << endl;
		}
		if (validated == false)
		{
			break;
		}

	};

	//sets the values into the variables
	if (validated == true)
	{
		albums[numAlbums].setID(i);
		albums[numAlbums].setTitle(t);
		albums[numAlbums].setArtist(a);
		albums[numAlbums].setYear(y);
		albums[numAlbums].setGenre(g);

		numAlbums++;
	}
}

//Shows the list of albums
void favoriteList::showList()
{
	for (int i = 0; i < numAlbums; i++)
	{
		cout << albums[i] << endl;
		totalAlbums = i;
	}
}

int favoriteList::readFile(string filename)
{
	//I'd like to note right here that I used .c_string() because the string type doesn't have a null character at the end
	//Which gives me an error. .cstring() will return it with a null-termination. 
	//I don't understand this 100% but I do know it's because if I try to pass without .cstring, it'll give erros b/c
	//of the null.
	ifstream inputFile;
	inputFile.open(filename.c_str());
	if (!inputFile)
	{
		cout << "File couldn't be Read!" << endl;
		return -1;
	}

	//Temp Variables

	int Tempid;
	string Temptitle;
	string Tempartist;
	int Tempyear;
	string Tempgenre;

	string inputstring;

	while (!inputFile.eof())
	{
		getline(inputFile, inputstring, '|');
		if (inputstring.length() >= 1)
		{
			Tempid = stoi(inputstring);
			getline(inputFile, Temptitle, '|');
			getline(inputFile, Tempartist, '|');
			getline(inputFile, inputstring, '|');
			Tempyear = stoi(inputstring);
			getline(inputFile, Tempgenre, '|');
			getline(inputFile, inputstring, '\n');


			//Adding Data to objects/Albums from list

			albums[numAlbums].setID(Tempid);
			albums[numAlbums].setTitle(Temptitle);
			albums[numAlbums].setArtist(Tempartist);
			albums[numAlbums].setYear(Tempyear);
			albums[numAlbums].setGenre(Tempgenre);
			numAlbums++;
		}
	}

	inputFile.close();
	return 0;
}

int favoriteList::saveToFile(string filename)
{
	int i;

	ofstream outputFile;
	outputFile.open(filename.c_str());
	
	if (!outputFile)
	{
		cout << "ERROR - file open failed!" << endl;
		return -3;
	}

	for (i = 0; i < numAlbums; i++)
	{
		outputFile << albums[i].getID() << "|";
		outputFile << albums[i].getTitle() << "|";
		outputFile << albums[i].getArtist() << "|";
		outputFile << albums[i].getYear() << "|";
		outputFile << albums[i].getGenre() << endl;
	}
	outputFile.close();
	return 0;

}