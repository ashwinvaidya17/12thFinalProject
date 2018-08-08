#include "Draw.h"
#include<conio.h>
#include <iostream>
#include<iomanip>
#include<fstream>

using namespace std;

void Draw::gotoxy(int y, int x)
{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Draw::loginScreen()
{
	system("cls");
	for (int i = 0; i < 50; i++)
		cout << (char)219;
	cout << "\n";
	for (int i = 0; i < 50; i++)
		cout << (char)177;
	cout << "\n";
	cout << (char)177 << "                    Select Option\n";
	cout << (char)177 << " 1. Developer Dashboard\n";
	cout << (char)177 << " 2. Customer Dashboard\n";
	cout << (char)177 << " 3. Exit\n";
	for (int i = 0; i < 50; i++)
		cout << (char)177;
	cout << "\n";
	for (int i = 0; i < 50; i++)
		cout << (char)219;
	cout << "\n";
	for (int i = 2; i < 6; i++){
		gotoxy(i, 49); cout << (char)177;
	}
	gotoxy(8, 0);
	int inp = 0; cout << "Select Option: ";
	cin >> inp;
	switch (inp)
	{
	case 1:
		pubDash();
		break;
	case 2:
		clientDash();
		break;
	case 3:
		exit(0);
			break;
	default:
		loginScreen();
		break;
	}
	
}

void Draw::clientDash()
{
	while (true){
		system("cls");
		Customer cust;
		fstream f("Client.gsf", ios::in|ios::out);
			f.seekg(0);
			if (f.read((char *)&cust, sizeof(Customer)))
				f.close();
			else{
				cust.funds = 0;
				cust.spent = 0;
				f.seekp(0);
				f.write((char *)&cust, sizeof(cust));
				f.close();
			}

		for (int i = 0; i < 50; i++)
			cout << (char)219;
		cout << "\n";
		for (int i = 0; i < 50; i++)
			cout << (char)177;
		cout << "\n";
		cout << (char)177 << "              Customer Zone\n";
		cout << (char)177 << "                  Select Option\n";
		cout << (char)177 << "Wallet: " << cust.funds << "    Total Spent: " << cust.spent << "\n";
		cout << (char)177 << " 1. Marketplace\n";
		cout << (char)177 << " 2. Add Funds\n";
		cout << (char)177 << " 3. View Orders\n";
		cout << (char)177 << " 4. Back\n";
		for (int i = 0; i < 50; i++)
			cout << (char)177;
		cout << "\n";
		for (int i = 0; i < 50; i++)
			cout << (char)219;
		cout << "\n";
		for (int i = 2; i < 9; i++){
			gotoxy(i, 49); cout << (char)177;
		}
		gotoxy(11, 0);


		int inp = 0; cout << "Select Option: ";
		cin >> inp;
		switch (inp)
		{
		case 1:
			system("cls");
			listGames();
			cust.buy();
			break;
		case 2:
			cust.addFunds();
			break;
		case 3:
			dispCustSales();
			break;
		case 4:
			loginScreen();
			break;
		default:
			clientDash();
			break;
		}
	}
}

void Draw::pubDash()
{
	Publisher pub;
	while (true){
		system("cls");
		for (int i = 0; i < 50; i++)
			cout << (char)219;
		cout << "\n";
		for (int i = 0; i < 50; i++)
			cout << (char)177;
		cout << "\n";
		cout << (char)177 << "              Publisher Zone\n";
		cout << (char)177 << "                  Select Option\n";
		cout << (char)177 << " 1. View Games\n";
		cout << (char)177 << " 2. Add Games\n";
		cout << (char)177 << " 3. Remove Games\n";
		cout << (char)177 << " 4. View Sales\n";
		cout << (char)177 << " 5. Back\n";
		for (int i = 0; i < 50; i++)
			cout << (char)177;
		cout << "\n";
		for (int i = 0; i < 50; i++)
			cout << (char)219;
		cout << "\n";
		for (int i = 2; i < 9; i++){
			gotoxy(i, 49); cout << (char)177;
		}
		gotoxy(11, 0);


		int inp = 0; cout << "Select Option: ";
		cin >> inp;
		switch (inp)
		{
		case 1:
			listGames();
			break;
		case 2:
			pub.addGame();
			break;
		case 3:
			pub.removeGame();
			break;
		case 4:
			dispPubSales();
			break;
		case 5:
			loginScreen();
		default:
			pubDash();
			break;
		}
	}
}

void Draw::listGames()
{
	fstream f;
	f.open("gamelist.gsf", ios::in);
	Publisher pub;
	if (f){
		int i = 1;
		cout << "No.           Publisher           Game       Cost(Rs.)\n";
		while (f.read((char *)&pub, sizeof(Publisher)))
		{
			cout << i<< setw(20)<< pub.pubName<< setw(20) << pub.gameName<<setw(10)<< pub.cost << endl;
			i++;
		}
		f.close();
	}
	else
		cout << "Sorry! No games available now :(\n";
		_getch();
	
	
}
void Draw::dispPubSales()
{
	system("cls");
	fstream f;
	f.open("sales.gsf", ios::in);
	Publisher pub;
	if (f){
		int i = 1;
		float TotalSale = 0;
		cout << endl;
		cout << "No.           Publisher           Game       Cost(Rs.)\n";
		while (f.read((char *)&pub, sizeof(Publisher)))
		{
			cout << i <<setw(60) << pub.pubName << setw(100)<< pub.gameName <<setw(30) << pub.cost << endl;
			i++;

			TotalSale += pub.cost;
		}
		f.close();
		cout << "\nTotal Sale: " << TotalSale << endl<<endl;
		cout << "Press P to print your orders, press any key to continue ";
		char n;
		cin >> n;
		switch (n){
		case 'P':
			pub.printSales();
			break;
		case 'p':
			pub.printSales();
			break;
		default:
			pubDash();
		}
	}

	else{
		cout << "You have not sold anything\n";
		_getch();
	}
}

void Draw::dispCustSales()
{
	system("cls");
	fstream f;
	f.open("sales.gsf", ios::in);
	Publisher pub;
	if (f){
		int i = 1;
		cout << "-------------------------------------------------------------\n";
		cout << "                  Bought On GAMESTORE                       \n";
		cout << "                  YOUR ORDER SUMMARY\n";
		cout << "No.           Publisher           Game       Cost(Rs.)\n";
		while (f.read((char *)&pub, sizeof(Publisher)))
		{
			cout << i << "        " << pub.pubName << "            " << pub.gameName << "        " << pub.cost << endl;
			i++;
		}
		f.close();
		cout << "-------------------------------------------------------------\n";
		cout << "Press P to print your orders, press any key to continue shopping ";
		char n;
		cin >> n;
		if (n == 'p' || n == 'P'){
			Customer cust; cust.printOrders();
		}
	}

	else{
		cout << "You have not made any purchases\n"; _getch();
	}

}