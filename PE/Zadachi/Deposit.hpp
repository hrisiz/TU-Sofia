#include <iostream>
#include <string>
#include "Bank.hpp"

using namespace std;

class Deposit : public Bank{

	public:
	Deposit(string n, double b, double p);
	~Deposit();
};