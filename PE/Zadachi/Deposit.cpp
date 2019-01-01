#include "Deposit.hpp"

 Deposit::Deposit(string n, double b, double p): Bank(n, b,p)
 {
 	cout << "Constructing Deposit" << endl;
 }

Deposit::~Deposit()
{
	cout << "Destructing Deposit" << endl;
}

 


