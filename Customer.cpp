#include"Customer.h"
#include"Publisher.h"
#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;
void Customer::addFunds()
{
	float n;
	cout << "Enter the funds you want to add: ";cin >> n;
	funds += n;
	ofstream f("Client.gsf", ios::out);
	f.seekp(0);
	f.write((char *) this, sizeof(Customer));
	f.close();
}

void Customer::removeFunds(float n)
{
	funds -= n;
	spent += n;
	ofstream f("Client.gsf", ios::out);
	f.seekp(0);
	f.write((char *) this, sizeof(Customer));
	f.close();
}
void Customer::buy()
{
	int flag = 1;
	Publisher pub;
	char gName[15];
	cout << "Enter the name of the game you want to buy: "; cin >> gName;
	
	//Check for purchase
	fstream sales("sales.gsf", ios::in|ios::out);
	sales.seekg(0);
	while (sales.read((char*)&pub, sizeof(Publisher)))
	{
		if (strcmp(pub.gameName, gName) == 0){
			cout << "You already have the game";
			_getch();
			sales.close();
			return;
		}
	}

	//Continue if game is not purchased earlier
	fstream sale("sales.gsf", ios::app);
	fstream gList("gamelist.gsf", ios::in);
	while (gList.read((char*)&pub, sizeof(Publisher)))
	{
		if (strcmp(pub.gameName, gName) == 0)
		{
			float temp = funds - pub.cost;
			if (temp >= 0)
			{
				removeFunds(pub.cost);
				sale.write((char*)&pub, sizeof(Publisher));
				cout << "You Have successfully brought the game!"; _getch();
				flag = 0;
			}
			else{
				cout << "You do not have enough funds!\n"; _getch();
			}
		}

	}
	if (flag)
	{
		cout << "Did not find the game please check the spelling ";
		_getch();
	}
	gList.close();
	sale.close();
}
void Customer::printOrders()
{

}

