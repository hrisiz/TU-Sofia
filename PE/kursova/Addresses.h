#ifndef ADDRESSES_H
#define ADDRESSES_H

#include <iostream>
#include "string.h"
#include "Person.h"

class AddressesException{};

class Addresses:public Person
{
	private:
		char* addr[5];
		int addresses_count;
	public:
		Addresses(char* name, char* EGN, char* address);
		void addAddress(char* address);
		bool checkAddress(char* address);
		char* getAddrAt(int index);
		int getAddressesCount();
};

#endif