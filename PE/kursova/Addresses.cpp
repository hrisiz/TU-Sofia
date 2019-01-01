#include "Addresses.h"

Addresses::Addresses(char* name, char* EGN, char* address): Person(name, EGN, address), addresses_count(0)
{

}

void Addresses::addAddress(char* address)
{
	if(5 <= this->addresses_count)
	{
		throw AddressesException();
	}
	this->addr[this->addresses_count] = address;
	this->addresses_count++;
}

bool Addresses::checkAddress(char* address)
{
	bool result = false;
	for(int counter = 0; counter < this->addresses_count; counter++)
	{
		if(0 == strcmp(this->addr[counter], address))
		{
			result = true;
		}
	}
	return result;
}

char* Addresses::getAddrAt(int index)
{
	return this->addr[index];
}

int Addresses::getAddressesCount()
{
	return this->addresses_count;
}