#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>

class Files
{
public:
	static vector<shared_ptr<Carrier>> readFromFile(string fileName)
	{
		vector<shared_ptr<Carrier>> result;

		std::ifstream FILE(fileName, std::ios::in | std::ifstream::binary);
		if(!FILE.is_open())
		{
			throw std::runtime_error("Failed to open " + fileName);
		}

		string line;
		FILE >> line;
		if(!FILE.fail())
		{
			shared_ptr<Carrier> carrier = make_shared<Carrier>();
			CarrierType type = MAX;
			string author;
			string title;
			string year;

			std::string tmpType;
			stringstream ss( line );
			getline( ss, tmpType, ',' );

			if("0" == tmpType)
			{
				type = BOOK;
			}
			else if("1" == tmpType)	
			{
				type = CDROM;
			}
			else if("2" == tmpType)
			{
				type = AUDIO;
			}
			else
			{
				type = MAX;
			}
			carrier->setCarrierType(type);

			getline( ss, author, ',' );
			carrier->setAuthor(author);

			getline( ss, title, ',' );
			carrier->setTitle(title);

			getline( ss, year, ',' );
			carrier->setYear(year);

			string tmpFree;
			getline( ss, tmpFree, ',' );
			if("1" == tmpFree)
			{
				carrier->returnCarrier();
			}
			else
			{
				carrier->takeCarrier();
			}
			result.push_back(carrier);
		}
		return result;
	}

	static void writeToFile(string fileName, vector<shared_ptr<Carrier>> carriers)
	{
		std::ofstream FILE(fileName, std::ios::out | std::ofstream::binary);
		if(!FILE.is_open())
		{
			throw std::runtime_error("Failed to open " + fileName);
		}
		for( typename vector<shared_ptr<Carrier>>::iterator it = carriers.begin(); it != carriers.end(); it++ )
		{
			FILE << *(*it);
		}
	}
};