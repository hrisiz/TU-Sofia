#include <string>
#include <regex>

using namespace std;

enum CarrierType
{
	BOOK = 0,
	CDROM,
	AUDIO,
	MAX
};

class Carrier
{
private:
	CarrierType type;
	string author;
	string title;
	string year;
	bool free;
public:

	Carrier()
	:free(false)
	{

	}

	Carrier(Carrier& carrier)
	{
		this->type = carrier.type;
		this->author = carrier.author;
		this->title = carrier.title;
		this->year = carrier.year;
		this->free = carrier.free;
	}

	CarrierType getType()
	{
		return this->type;
	}

	void setCarrierType(CarrierType type)
	{
		if(MAX == type)
		{
			throw invalid_argument("Bad Carrier Type");
		}
		this->type = type;
	}

	string getAuthor()
	{
		return this->author;
	}

	void setAuthor(string author)
	{
		if( !std::regex_match(author, std::regex("[a-zA-Z ]+")) )
		{
			throw std::invalid_argument("Incorect author name.");
		}
		this->author = author;
	}
	
	string getTitle()
	{
		return this->title;
	}

	void setTitle(string title)
	{
		if( !std::regex_match(title, std::regex("[a-zA-Z0-9 ]+")) )
		{
			throw std::invalid_argument("Incorect title.");
		}
		this->title = title;
	}

	string getYear()
	{		
		return this->year;
	}

	void setYear(string year)
	{
		if( !std::regex_match(year, std::regex("[0-9]{4}")) )
		{
			throw std::invalid_argument("Incorect year.");
		}
		this->year = year;
	}

	bool isFree()
	{
		return this->free;
	}

	void takeCarrier()
	{
		this->free = false;
	}

	void returnCarrier()
	{
		this->free = true;
	}

	friend ostream& operator<<(ostream& out, Carrier carrier);
};

ostream& operator<<(ostream& out, Carrier carrier)
{
	out << carrier.type << "," << carrier.author << "," << carrier.title << "," << carrier.year << "," << carrier.free << endl;
}