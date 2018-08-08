#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer
{
public:
	void addFunds();
	void removeFunds(float);
	void printOrders();
	void buy();
	float funds;
	float spent;
};
#endif