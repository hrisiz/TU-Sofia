#ifndef MANUAL_DISTRIBUTOR_HPP
#define MANUAL_DISTRIBUTOR_HPP

#include <string>
#include <algorithm>

#include "Manual.hpp"

class ManualDistributor
{
private:
	std::string name;
	std::string phone;
	std::string address;

public:
	ManualDistributor()
	:name(""),phone(""),address("")
	{
	}

	ManualDistributor(std::string name, std::string phone, std::string address)
	:name(name), phone(phone), address(address)
	{

	}

	void setName(std::string name)
	{
		this->name = name;
	}

	void setPhone(std::string phone)
	{
		this->phone = phone;
	}

	void setAddress(std::string address)
	{
		this->address = address;
	}

	std::string getName()
	{
		return this->name;
	}

	std::string getPhone()
	{
		return this->phone;
	}

	std::string getAddress()
	{
		return this->address;
	}

	bool operator==(const ManualDistributor& manualdist) const
	{
		return this->name == manualdist.name;
	}

	bool operator!=(const ManualDistributor& manualdist) const
	{
		return !((*this) == manualdist);
	}

	bool operator==(const std::string& name) const
	{
		return this->name == name;
	}

	bool operator!=(const std::string& name) const
	{
		return !((*this) == name);
	}

	friend std::ostream& operator<<(std::ostream& os, ManualDistributor& distributor);
	friend std::istream& operator>>(std::istream& is, ManualDistributor& distributor);
};

std::ostream& operator<<(std::ostream& os, ManualDistributor& distributor)
{
	os  << distributor.name << ","
		<< distributor.phone << ","
		<< distributor.address 
		<< std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, ManualDistributor& distributor)
{
	std::string substr;
	is >> substr;
	if(is.fail())
	{
		return is;
	}
	std::stringstream ss( substr );

	getline( ss, substr, ',' );
	distributor.name = substr;

	getline( ss, substr, ',' );
	distributor.phone = substr;

	getline( ss, substr );
	distributor.address = substr;

	return is;
}
#endif