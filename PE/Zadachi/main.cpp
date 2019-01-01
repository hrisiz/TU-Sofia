#include <iostream>
#include "Credit.hpp"
#include "Deposit.hpp"
#include <vector>

using namespace std;


int main()
{
	vector<Bank*> accounts;

	accounts.push_back(new Credit("name1", 50.5, 50.1));
	accounts.push_back(new Deposit("name2", 100, 20.1));
	accounts.push_back(new Deposit("name3", 51.5, 4.4));	
	accounts.push_back(new Deposit("name4", 101, 2.2));

	int i = 0;
	double temp = accounts[i]->getPercent();
	for(i = 1; i < accounts.size(); i++)
	{
		if(temp < accounts[i]->getPercent())
		{
			temp = accounts[i]->getPercent();
		}
	}
	cout << "Result: " << temp << endl;
	return 0;
}

