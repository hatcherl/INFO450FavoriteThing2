#include <iostream>
#include <string>
#include "FavoriteThings.h"
#include "FavoriteThingsList.h"
#include <stdlib.h>
#include <fstream>

using namespace std;

int main()
{
	//response so the user can choose if they want to continue or not
	char response;
	
	favoriteList myAlbums;

	do {

		cout << "Hello! Please select one of these options" << endl;
		cout << "A: Read " << "B: Add " << "C: Show " << "D: Save " << "E: Exit" << endl;
		//response so the user can choose if they want to continue or not
		cin >> response;
		cin.ignore();

		//Read
		if (response == 'A' || response == 'a') //Read
		{
			//Read
			//Current Error in trying to read...Won't read beyond the 2nd entry's ID#
			cout << "Enter file path" << endl;
			string fileInput;
			getline(cin, fileInput);
			cin.ignore();
			myAlbums.readFile(fileInput);
			system("pause");
		};

		//Add
		if (response == 'B' || response == 'b')
		{
			//created a myAlbums list
			char response1;
			do {
				myAlbums.addAlbum();
				cout << "Would you like to make another? Select Y/y to continue. Select any other character to continue." << endl;
				cin >> response1;
			} while (response1 == 'y' || response1 == 'Y');
			
			system("pause");
		}

		//Show
		if (response == 'C' || response == 'c')
		{
			//Show
			//Calling on the showList function
			myAlbums.showList();

			system("pause");
		};

		//Save
		if (response == 'D' || response == 'd')
		{
			//Save
			cout << "Enter file path" << endl;
			string fileInput;
			getline(cin, fileInput);
			cin.ignore();
			myAlbums.saveToFile(fileInput);

			system("pause");
		};

		//Exit
		if (response == 'E' || response == 'e')
		{
			exit(0);
			//I chose to use the exit(0) function b/c I understood it as a "successful" exit rather than unsuccessful"
			//I thought this was redundant with my system(pause) + return 0 below but because of the do-while loop
			//it'll execute at least once so it needs to have an option that will exit the program
			//I guess I can argue that the bottom lines of code are safeguards?
		}
		
	} while (response != 'E' || response != 'e');
	system("pause");
	return 0;
};