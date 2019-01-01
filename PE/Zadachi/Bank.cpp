#include "Bank.hpp"

Bank::Bank(string n, double b, double p):name(n), balance(b), percent(p)
{
	cout << "Bank()" << endl;
}

Bank::~Bank()
{
	cout << "~Bank()" << endl;
}

double Bank::rate(int months)
{
	return this->percent * months;
}

double Bank::getPercent()
{
	return this->percent;
}