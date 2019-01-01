#include <iostream>
#include <vector>
#include <memory>
#include <regex>
#include <fstream>	


using namespace std;

#include "Airplane.hpp"

class Program
{
private:
	vector<shared_ptr<Airplane>> airplanes;

	void writeToFile(string fileName, vector<shared_ptr<Airplane>> airplanes)
	{
		std::ofstream FILE(fileName, std::ios::out | std::ofstream::binary);
		if(!FILE.is_open())
		{
			throw std::runtime_error("Failed to open " + fileName);
		}
		for( vector<shared_ptr<Airplane>>::iterator it = airplanes.begin(); it != airplanes.end(); it++ )
		{
			FILE << *(*it);
		}
	}
public:


	void printOptions()
	{
		cout << "Pick Option: " << endl;
		cout << "0. Exit" << std::endl;
		cout << "1. Add Airplane" << std::endl;
		cout << "2. Check for destination" << std::endl;
		cout << "3. Write to file" << std::endl;
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
				shared_ptr<Airplane> airplane = make_shared<Airplane>();
				string producer;
				string model;
				unsigned int space;
				unsigned int needed_track;
				unsigned int needed_staff;
				unsigned int fuel_usage;
				unsigned int fuel_liters;
				unsigned int avarage_speed;
				while(1)
				{
					try
					{
						cout << "Producer:" << endl;
						cin >> producer;
						airplane->setProducer(producer);
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
						cout << "Model: ";
						cin >> model;
						airplane->setModel(model);
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
						cout << "Space: ";
						cin >> space;
						bool fail = std::cin.fail();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						if(fail)
						{
							std::cout << "cin failed! Bad input." << std::endl;
							continue;
						}
						airplane->setSpace(space);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}

				while(1)
				{
					cout << "Track: ";
					cin >> needed_track;
					bool fail = std::cin.fail();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if(fail)
					{
						std::cout << "cin failed! Bad input." << std::endl;
						continue;
					}
					try{
						airplane->setNeededTrack(needed_track);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}

				while(1)
				{
					cout << "Staff: ";
					cin >> needed_staff;
					bool fail = std::cin.fail();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if(fail)
					{
						std::cout << "cin failed! Bad input." << std::endl;
						continue;
					}
					try{
						airplane->setNeededStaff(needed_staff);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}

				while(1)
				{
					cout << "Fuel usage: ";
					cin >> fuel_usage;
					bool fail = std::cin.fail();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if(fail)
					{
						std::cout << "cin failed! Bad input." << std::endl;
						continue;
					}
					try{
						airplane->setFuelUsage(fuel_usage);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}

				while(1)
				{
					cout << "Fuel liters: ";
					cin >> fuel_liters;
					bool fail = std::cin.fail();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if(fail)
					{
						std::cout << "cin failed! Bad input." << std::endl;
						continue;
					}
					try{
						airplane->setFuelLiters(fuel_liters);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}

				while(1)
				{
					cout << "Avarage speed: ";
					cin >> avarage_speed;
					bool fail = std::cin.fail();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if(fail)
					{
						std::cout << "cin failed! Bad input." << std::endl;
						continue;
					}
					try{
						airplane->setAvarageSpeed(avarage_speed);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}
				airplanes.push_back(airplane);
				break;
			}
			case 2:
			{
				cout << "Pick destination." << endl;
				Flight flight;
				string name;
				unsigned int length;
				unsigned int track;
				while(1)
				{
					cout << "Name: ";
					cin >> name;
					try{
						flight.setName(name);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}
				
				while(1)
				{
					cout << "Length: ";
					cin >> length;
					bool fail = std::cin.fail();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if(fail)
					{
						std::cout << "cin failed! Bad input." << std::endl;
						continue;
					}
					try{
						flight.setLength(length);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}

				while(1)
				{
					cout << "Track: ";
					cin >> track;
					bool fail = std::cin.fail();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if(fail)
					{
						std::cout << "cin failed! Bad input." << std::endl;
						continue;
					}
					try{
						flight.setTrack(track);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}

				for(vector<shared_ptr<Airplane>>::iterator it = airplanes.begin(); it != airplanes.end(); it++)
				{
					if((*it)->isFlightPossible(flight))
					{
						cout << *(*it) << endl;
					}
				}
				break;
			}
			case 3:
			{
				string file_name;
				while(1)
				{
					cout << "What is the file name? ";
					cin >> file_name;
					try
					{
						this->writeToFile(file_name, this->airplanes);
						break;
					}
					catch(exception& e)
					{
						cout << e.what() << endl;
					}
				}
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