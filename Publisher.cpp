#include "Publisher.h"
#include <fstream>
#include<conio.h>
#include<iostream>
using namespace std;

void Publisher::addGame()
{
	char gName[15];
	cout << "\nEnter game name: "; cin >> gName;
	fstream sales("gamelist.gsf", ios::in | ios::out);
	sales.seekg(0);
	while (sales.read((char*)this, sizeof(Publisher)))
	{
		if (strcmp(gameName, gName) == 0){
			cout << "There is already a game with this name in store!";
			_getch();
			sales.close();
			return;
		}
	}
	ofstream f("gamelist.gsf", ios::app);
	strcpy_s(gameName, gName);
	cout << "\nEnter publisher name: "; cin>>pubName;
	cout << "\nEnter cost: "; cin >> cost;
	f.write((char *)this, sizeof(Publisher));
	f.close();
}
void Publisher::removeGame()
{
	char gName[15];
	int flag = 1;
	cout << "Enter the name of the game you want to remove: ";
	cin >> gName;
	ifstream f("gamelist.gsf");
	ofstream o("temp.gsf");
	while (f.read((char*)this, sizeof(Publisher)))
	{
		if (strcmp(gameName, gName)!=0)
		{
			o.write((char*)this, sizeof(Publisher));
			flag = 0;
		}
	}

	f.close();
	o.close();
	remove("gamelist.gsf");
	rename("temp.gsf", "gamelist.gsf");
	if (flag){
		cout << "\nDidn't Find The Game Please Check The Spelling.";
		_getch();
	}
	}
void Publisher::printSales()
{

}
