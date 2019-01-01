#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string.h>

class PersonException{};

class Person{
	private:
		char* name;
		char* EGN;
		char* address;
		void setName(char* name);
		void setEGN(char EGN[10]);
		void setAddress(char* address);
	public:
		Person(char* name, char EGN[10], char* address);
		char* getName();
		char* getEGN();
		char* getAddress();
};

#endif