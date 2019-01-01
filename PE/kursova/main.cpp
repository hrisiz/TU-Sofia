#include <iostream>
#include <fstream>

#include "Addresses.h"

using namespace std;

std::ostream& operator<<(std::ostream& out, Addresses& obj)
{
	for(int counter = 0; counter < obj.getAddressesCount(); counter++)
	{
		out << obj.getAddrAt(counter) << std::endl;
	}
	return out;
}

int main(){
	Addresses* addresses = new Addresses((char*)"Hristiyan Zarkov", (char*)"123456789", (char*)"addr");

//Test
//	cout << "Name: " << addresses->getName() << endl;
//	cout << "EGN: " << addresses->getEGN() << endl;
//	cout << "Address: " << addresses->getAddress() << endl;

	addresses->addAddress((char*)"first address");
	addresses->addAddress((char*)"second address");
	addresses->addAddress((char*)"third address");
	cout << "Is \"first address\" found for Hristiyan Zarkov?: " << addresses->checkAddress((char*)"first address") << endl;
	ofstream file;
  	file.open("addresses.haha");
	cout << (*addresses);
	file << (*addresses);
	file.close();
	return 0;
}