#include <string>

using namespace std;

class Flight
{
private:
	string name;
	unsigned int length;
	unsigned int track;

public:
	Flight(string name, unsigned int length)
	:name(name), length(length)
	{

	}
	Flight(Flight& flight)
	{
		this->name = flight.name;
		this->length = flight.length;
	}
	Flight()
	:name(""), length(0), track(0)
	{

	}

	string getName()
	{
		return this->name;
	}

	unsigned int getLength()
	{
		return this->length;
	}

	unsigned int getTrack()
	{
		return this->track;
	}

	void setName(string name)
	{
		this->name = name;
	}

	void setLength(unsigned int length)
	{
		this->length = length;
	}

	void setTrack(unsigned int track)
	{
		this->track = track;
	}

};