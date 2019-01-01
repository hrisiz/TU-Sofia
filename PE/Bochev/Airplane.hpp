#include <string>
#include "Flight.hpp"
#include <regex>


using namespace std;

class Airplane
{
private:
	string producer;
	string model;
	unsigned int space;
	unsigned int needed_track;
	unsigned int needed_staff;
	unsigned int fuel_usage;
	unsigned int fuel_liters;
	unsigned int avarage_speed;

public:
	Airplane(string producer="", string model="", unsigned int space=0, unsigned int needed_track=0, unsigned int needed_staff=0, unsigned int fuel_usage=0) 
	:producer(producer), model(model), space(space),
	needed_track(needed_track), needed_staff(needed_staff), fuel_usage(fuel_usage)
	{

	}

	Airplane(Airplane& airplane) 
	{

	}

	bool isFlightPossible(Flight& flight)
	{
		bool result = true;
		if(this->needed_track > flight.getTrack())
		{
			result = false;
		}

		if(this->fuel_usage == 0 || (this->fuel_liters/this->fuel_usage) > flight.getLength() )
		{
			result = false;
		}

		return result;
	}

	string getProducer()
	{
		return this->producer;
	}

	string getModel()
	{
		return this->model;
	}

	unsigned int getSpace()
	{
		return this->space;
	}

	unsigned int getNeededTrack()
	{
		return this->needed_track;
	}

	unsigned int getNeededStaff()
	{
		return this->needed_staff;
	}

	unsigned int getFuelUsage()
	{
		return this->fuel_usage;
	}

	unsigned int getFuelLiters()
	{
		return this->fuel_liters;
	}

	unsigned int getAvarageSpeed()
	{
		return this->avarage_speed;
	}

	void setProducer(string producer)
	{
		if( !std::regex_match(producer, std::regex("[a-zA-Z ]+")) )
		{
			throw std::invalid_argument("Incorect producer name.");
		}
		this->producer = producer;
	}

	void setModel(string model)
	{
		if( !std::regex_match(model, std::regex("[a-zA-Z ]+")) )
		{
			throw std::invalid_argument("Incorect model name.");
		}
		this->model = model;
	}

	void setSpace(unsigned int space)
	{
		this->space = space;
	}

	void setNeededTrack(unsigned int needed_track)
	{
		this->needed_track = needed_track;
	}

	void setNeededStaff(unsigned int needed_staff)
	{
		this->needed_staff = needed_staff;
	}

	void setFuelUsage(unsigned int fuel_usage)
	{
		this->fuel_usage = fuel_usage;
	}

	void setFuelLiters(unsigned int fuel_liters)
	{
		this->fuel_liters = fuel_liters;
	}

	void setAvarageSpeed(unsigned int avarage_speed)
	{
		this->avarage_speed = avarage_speed;
	}

	friend ostream& operator<<(ostream& out, Airplane& airplane);
};

ostream& operator<<(ostream& out, Airplane& airplane)
{
	out << airplane.producer << "," << airplane.model << "," << airplane.space << "," << airplane.needed_track << "," 
	<< airplane.needed_staff << "," << airplane.fuel_usage << "," 
	<< airplane.fuel_liters << "," << airplane.avarage_speed << endl;
}