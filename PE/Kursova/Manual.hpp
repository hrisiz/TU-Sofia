#ifndef MANUAL_HPP
#define MANUAL_HPP

#include <string>
#include <ctime>
#include <vector>
#include <memory>

class Manual
{

private:
	std::string title;
	std::string author;
	unsigned int edition;
	std::string ISBN;
	std::tm *release_date;
	std::tm *cert;
	unsigned int price;
	//unsigned int edition;

public:

	Manual( Manual& copy )
	{
		this->title = copy.title;
		this->author = copy.author;
		this->edition = copy.edition;
		this->ISBN = copy.ISBN;
		this->release_date = copy.release_date;
		this->cert = cert;
	}

	Manual( std::string title, std::string author, unsigned int edition, std::string ISBN, std::tm *release_date, unsigned int price )
	:title(title), author(author), edition(edition), ISBN(ISBN), release_date(release_date),cert(NULL), price(price)
	{

	}

	Manual()
	:title(""), author(""), edition(0), ISBN(""), release_date(NULL), cert(NULL), price(0)
	{

	}

	~Manual()
	{
		//delete time
	}

	std::string getTitle()
	{
		return this->title;
	}

	void setTitle( std::string title )
	{
		this->title = title;
	}

	std::string getAuthor()
	{
		return this->author;
	}

	void setAuthor( std::string author )
	{
		this->author = author;
	}

	unsigned int getEdition()
	{
		return this->edition;
	}

	void setEdition( unsigned int edition )
	{
		this->edition = edition;
	}

	std::string getISBN()
	{
		return this->ISBN;
	}

	void setISBN( std::string ISBN )
	{
		this->ISBN = ISBN;
	}

	std::tm *getReleaseDate()
	{
		return this->release_date;
	}

	void setReleaseDate( std::tm* release_date )
	{
		this->release_date = release_date;
	}

	bool isCertificared()
	{
		if(NULL == this->cert)
		{
			return false;
		}
		return true;
	}

	void certificate( std::tm *date = NULL )
	{
		this->cert = date;
	}

	unsigned int getPrice()
	{
		return this->price;
	}

	void setPrice( unsigned int price )
	{
		this->price = price;
	}

	/*unsigned int getEdition()
	{
		return this->edition;
	}*/

	bool operator==(const Manual& manual) const
	{
		return this->title == manual.title;
	}

	bool operator!=(const Manual& manual) const
	{
		return !((*this) == manual);
	}

	bool operator==(const std::string& title) const
	{
		return this->title == title;
	}

	bool operator!=(const std::string& title) const
	{
		return !((*this) == title);
	}

	friend std::ostream& operator<<(std::ostream& os, Manual& manual);

	friend std::istream& operator>>(std::istream& is, Manual& manual);
};

std::tm* stringToTime(std::string time)
{
	std::tm* result = new std::tm;
	size_t delimiter = time.find("/");
	result->tm_mon = std::stoi(time.substr(0, delimiter));
	result->tm_year = std::stoi(time.substr(delimiter+1));
	return result;
}

std::ostream& operator<<(std::ostream& os, Manual& manual)
{
	 //<< "Manual" << ","
	os << manual.title << "," 
	   << manual.author << "," 
	   << manual.edition << "," 
       << manual.ISBN << "," 
       << manual.release_date->tm_mon << "/" << manual.release_date->tm_year << "," 
	   << (manual.isCertificared() ? (manual.cert->tm_mon + "/" + manual.cert->tm_year):"NO") << "," 
       << manual.price
	   << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Manual& manual)
{
	std::string substr;
	is >> substr;
	if(is.fail())
	{
		return is;
	}
	std::stringstream ss( substr );
	
	getline( ss, substr, ',' );
	manual.title = substr;
	
	getline( ss, substr, ',' );
	manual.author = substr;

	getline( ss, substr, ',' );
	manual.edition = std::stoi(substr);

	getline( ss, substr, ',' );
	manual.ISBN = substr;

	getline( ss, substr, ',' );
	manual.release_date = stringToTime(substr);

	getline( ss, substr, ',' );
	if("NO" != substr)
	{
		manual.cert = stringToTime(substr);
	}

	getline( ss, substr );
	manual.price = std::stoi(substr);
	return is;
}
#endif