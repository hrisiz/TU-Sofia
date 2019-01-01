#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <string>
using namespace std;

class Bank{
protected:
	string name;
	double balance;
	double percent;
public:
	Bank(string n, double b, double p);
	~Bank();
	virtual double rate(int months);
	virtual double getPercent();
};

#endif