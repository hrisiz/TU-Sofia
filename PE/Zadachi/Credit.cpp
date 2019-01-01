#include "Credit.hpp"

Credit::Credit(string n, double b, double p):Bank(n,b,p)
{
	cout << "Credit()" << endl;
}

Credit::~Credit()
{
	cout << "~Credit()" << endl;
}

void Credit::addMoney(double income)
{
	this->balance = this->balance + income;
	cout << "Your current balance after the transaction is: " << balance << endl;

}

void Credit::getMoney(double money)
{
	this->balance -= money;
	cout << "getMoney()" << endl;
}