#include <iostream>
#include <vector>
#include <memory>

using namespace std;

#include "Carrier.hpp"
#include "Files.hpp"

class Program
{
private:
	vector<shared_ptr<Carrier>> carriers;
public:

	void printOptions()
	{
		cout << "Pick Option: " << endl;
		cout << "0. Exit" << std::endl;
		cout << "1. Add Carrier" << std::endl;
		cout << "2. Show Carriers" << std::endl;
		cout << "3. Show Available" << std::endl;
		cout << "4. Show Unavailable" << std::endl;
		cout << "5. Write to file" << std::endl;
		cout << "6. Read from file" << std::endl;
	}

	bool startOption(int option)
	{
		bool result = true;
		switch(option)
		{
			case 0:
			{
				result = false;
				break;
			}
			case 1:
			{
				shared_ptr<Carrier> carrier = make_shared<Carrier>();
				CarrierType type = MAX;
				string author;
				string title;
				string year;
				while(1)
				{
					try
					{
						cout << "Pick type:" << endl;
						cout << "0. BOOK" << endl;
						cout << "1. CDROM" << endl;
						cout << "2. AUDIO" << endl;
						int tmpType;
						cin >> tmpType;
						switch(tmpType)
						{
							case 0:
								type = BOOK;
								break;
							case 1:
								type = CDROM;
								break;
							case 2:
								type = AUDIO;
								break;
							default:
								type = MAX;
						}
						carrier->setCarrierType(type);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}

				while(1)
				{
					try
					{
						cout << "Author: ";
						cin >> author;
						carrier->setAuthor(author);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}

				while(1)
				{
					try
					{
						cout << "Title: ";
						cin >> title;
						carrier->setTitle(title);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}

				while(1)
				{
					cout << "Year: ";
					cin >> year;
					try{
						carrier->setYear(year);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}

				while(1)
				{
					cout << "Is the carrier free?(yes/no) ";
					string tmpFree;
					cin >> tmpFree;
					if("yes" == tmpFree)
					{
						carrier->returnCarrier();
						break;
					}
					else if("no" == tmpFree)
					{
						carrier->takeCarrier();
						break;
					}
					else
					{
						cout << "Incorect input for free field" << endl;
						continue;
					}
				}
				carriers.push_back(carrier);
				break;
			}
			case 2:
			{
				for(vector<shared_ptr<Carrier>>::iterator it = carriers.begin(); it != carriers.end(); it++)
				{
					cout << *(*it) << endl;
				}
				break;
			}
			case 3:
			{
				for(vector<shared_ptr<Carrier>>::iterator it = carriers.begin(); it != carriers.end(); it++)
				{
					if(true == (*it)->isFree())
					{
						cout << *(*it) << endl; 
					}
				}
				break;
			}
			case 4:
			{
				for(vector<shared_ptr<Carrier>>::iterator it = carriers.begin(); it != carriers.end(); it++)
				{
					if(false == (*it)->isFree())
					{
						cout << *(*it) << endl; 
					}
				}
				break;
			}
			case 5:
			{
				string file_name;
				while(1)
				{
					cout << "What is the file name? ";
					cin >> file_name;
					try
					{
						Files::writeToFile(file_name, this->carriers);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}
				break;
			}
			case 6:
			{
				string file_name;
				vector<shared_ptr<Carrier>> carriers_from_file;
				while(1)
				{
					cout << "What is the file name? ";
					cin >> file_name;
					try
					{
						carriers_from_file = Files::readFromFile(file_name);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}
				this->carriers.insert(carriers.begin(), carriers_from_file.begin(), carriers_from_file.end());
				break;
			}
		}
		return result;
	}

};

int main()
{
	Program program;
	int option;
	do
	{
		program.printOptions();
		cin >> option;
	}while(program.startOption(option));
}