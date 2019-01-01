#ifndef DESTIANCIQ_H
#define DESTIANCIQ_H

#include <iostream>
#include <string>

class Destinaciq
{
private:
	std::string ime;
	int razstoqnie;
public:

	Destinaciq()
	{

	}
	Destinaciq( std::string ime, int razstoqnie )
	:ime(ime), razstoqnie(razstoqnie)
	{

	}

	void setIme( std::string ime )
	{
		this->ime = ime;
	}

	void setRazstoqnie( int razstoqnie )
	{
		this->razstoqnie = razstoqnie;
	}

	std::string getIme()
	{
		return this->ime;
	}

	int getRazstoqnie()
	{
		return this->razstoqnie;
	}
	friend std::ostream& operator<<(std::ostream& out, Destinaciq& razhodi);
};

std::ostream& operator<<(std::ostream& out, Destinaciq& razhodi)
{
	out << razhodi.ime << ","
		<< razhodi.razstoqnie
		<< std::endl;
}
#endif