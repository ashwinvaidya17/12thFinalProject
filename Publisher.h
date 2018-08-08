#ifndef PUBLISHER_H
#define PUBLISHER_H
class Publisher
{
public:
	char pubName[15];
	char gameName[15];
	float cost ;
	void printSales();
	void addGame();
	void removeGame();
};
#endif