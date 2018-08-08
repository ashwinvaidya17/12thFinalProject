#ifndef DRAW_H
#define DRAW_H
#include <windows.h>
#include <string>
#include "Customer.h"
#include "Publisher.h"
class Draw
{
	
	
public:
	void gotoxy(int,int);
	void clear();
	void loginScreen();
	void pubDash();
	void clientDash();
private:
	void listGames();
	void dispPubSales();
	void dispCustSales();

};

#endif