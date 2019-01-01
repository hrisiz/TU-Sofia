#include <iostream>
#include <string>
#include "Bank.hpp"

using namespace std;

class Credit : public Bank{

public:
	Credit(string n, double b, double p);
	~Credit();
	void addMoney(double income);
	void getMoney(double money);
};