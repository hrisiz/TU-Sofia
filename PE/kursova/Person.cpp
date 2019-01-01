#include "Person.h"

Person::Person(char* name, char* EGN, char* address){
	this->setName(name);
	this->setEGN(EGN);
	this->setAddress(address);
}

char* Person::getName()
{
	return this->name;
}

char* Person::getEGN()
{
	return this->EGN;
}

char* Person::getAddress()
{
	return this->address;
}

void Person::setName(char* name)
{
	this->name = name;
}

void Person::setEGN(char* EGN)
{
	if(10 <= strlen(EGN))
	{
		throw PersonException();
	}
	this->EGN = EGN;
}

void Person::setAddress(char* address)
{
	this->address = address;
}