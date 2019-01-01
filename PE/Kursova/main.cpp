#include <iostream>
#include <memory>
#include <functional>
#include <regex>

#include "Manual.hpp"
#include "ManualDistributor.hpp"
#include "File.hpp"

class Program
{
private:

	FileSystem filesys;
	std::vector<std::shared_ptr<ManualDistributor>> distributors;
	std::vector<std::shared_ptr<Manual>> manuals;
	std::vector<std::shared_ptr<Order>> orders;

	void printMenu()
	{
		std::cout << std::endl << std::endl;
		std::cout << "Menu:" << std::endl;
		std::cout << "0. Menu" << std::endl;
		std::cout << "1. Add distributor" << std::endl;
		std::cout << "2. Add manual" << std::endl;
		std::cout << "3. Cetificate manual" << std::endl;
		std::cout << "4. Buy manual for distributor" << std::endl;
		std::cout << "5. Show manual" << std::endl;
		std::cout << "6. Show distributor" << std::endl;
		std::cout << "7. Show distributor's cart" << std::endl;

		std::cout << "10. Save manuals to file" << std::endl;
		std::cout << "11. Save distributors to file" << std::endl;
		std::cout << "12. Load manuals from file" << std::endl;
		std::cout << "13. Load distributors to file" << std::endl;
		std::cout << "100. EXIT" << std::endl << std::endl;
	}

	template<typename T>
	T getData(std::string print, std::function<void(T value)> validator = nullptr)
	{
		T result;
		while(1)
		{
			std::cout << print << ": ";
			std::cin >> result;
			bool fail = std::cin.fail();
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if(fail)
			{
				std::cout << "cin failed! Bad input." << std::endl;
				continue;
			}
			try
			{

				if(nullptr != validator)
				{
					validator(result);
				}
				break;
			}
			catch(std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		return result;
	}

	std::shared_ptr<ManualDistributor> generateManualDistributor()
	{
		std::string name, phone, address;

		name = this->getData<std::string>("Distributor name", [] (std::string title)
		{
			if( !std::regex_match(title, std::regex("[a-zA-Z ]+")) )
			{
				throw std::invalid_argument("Incorect name. ");
			}
		});

		phone = this->getData<std::string>("Distributor phone", [] (std::string phone)
		{
			if( !std::regex_match(phone, std::regex("^(0|\\+359)[[:digit:]]{9}")) )
			{
				throw std::invalid_argument("Incorect phone.");
			}
		});

		address = this->getData<std::string>("Distributor address");

		return std::make_shared<ManualDistributor>(name, phone, address);
	}

	void addManualDistributor(std::shared_ptr<ManualDistributor> distributor)
	{
		this->distributors.push_back(distributor);
	}

	std::shared_ptr<Manual> generateManual()
	{
		std::string title;
		std::string author;
		unsigned int edition = 0;
		std::string ISBN;
		std::tm *release_date;
		unsigned int price = 0;

		title = this->getData<std::string>("Manual title", [] (std::string title)
		{
			if( !std::regex_match(title, std::regex("[a-zA-Z ]+")) )
			{
				throw std::invalid_argument("Incorect title.");
			}
		});

		author = this->getData<std::string>("Manual author", [] (std::string title)
		{
			if( !std::regex_match(title, std::regex("[a-zA-Z ]+")) )
			{
				throw std::invalid_argument("Incorect author.");
			}
		});
		
		edition = this->getData<unsigned int>("Manual edition");
		
		ISBN = this->getData<std::string>("Manual ISBN", [] (std::string ISBN)
		{
			if( !std::regex_match(ISBN, std::regex("[[:digit:]]+")) )
			{
				throw std::invalid_argument("Incorect ISBN.");
			}
		});
		
		release_date = new std::tm;
		std::cout << "Manual release date: " << std::endl;
		release_date->tm_mon = this->getData<int>("Month", [] (int month)
		{
			if(12 < month || 0 > month)
			{
				throw std::invalid_argument("Bad month input");
			}
		});
		release_date->tm_year = this->getData<int>("Year", [] (int year)
		{
			if(0 > year)
			{
				throw std::invalid_argument("Bad year input");
			}
		});
		
		price = this->getData<unsigned int>("Manual's price");

		std::shared_ptr<Manual> ptr = std::make_shared<Manual>(title, author, edition, ISBN, release_date, price);
		return ptr;
	}

	void addManual(std::shared_ptr<Manual> manual)
	{
		std::cout << "Title:" << manual->getTitle() << std::endl;
		this->manuals.push_back(manual);
	}

	void printManuals()
	{
		std::cout << "Manuals: " << std::endl;
		for( std::vector<std::shared_ptr<Manual>>::iterator it = this->manuals.begin(); it != this->manuals.end(); it++ )
		{
			std::cout << (it - this->manuals.begin()) << ". " << (*it)->getTitle() << std::endl;
		}
	}

	std::shared_ptr<Manual> pickManual()
	{
		if(this->manuals.size() <= 0)
		{
			throw std::invalid_argument("No manuals");
		}
		this->printManuals();
		unsigned int number = this->getData<unsigned int>("Number of the manual", [&] (unsigned int number)
		{
			if(this->manuals.size() < number)
			{
				throw std::invalid_argument("Bad manual number!");
			}
		});
		return this->manuals[number];
	}

	std::tm* generateCetificateDate()
	{
		std::tm* cert_date = new std::tm;
		std::cout << "Certificate Date: " << std::endl;
		cert_date->tm_mon = this->getData<int>("Month", [] (int month)
		{
			if(12 < month || 0 > month)
			{
				throw std::invalid_argument("Bad month input");
			}
		});
		cert_date->tm_year = this->getData<int>("Year", [] (int year)
		{
			if(0 > year)
			{
				throw std::invalid_argument("Bad year input");
			}
		});
		return cert_date;
	}

	void printManualDistributors()
	{
		std::cout << "Manual Distributors: " << std::endl;
		for( std::vector<std::shared_ptr<ManualDistributor>>::iterator it = this->distributors.begin(); it != this->distributors.end(); it++ )
		{
			std::cout << (it - this->distributors.begin()) << ". " << (*it)->getName() << std::endl;
		}
	}

	std::shared_ptr<ManualDistributor> pickManualDistributor()
	{
		if(this->distributors.size() <= 0)
		{
			throw std::invalid_argument("No distributors");
		}

		this->printManualDistributors();
		unsigned int number = this->getData<unsigned int>("Pick number of manual distributor", [&] (unsigned int number)
		{
			if(this->distributors.size() <= number)
			{
				throw std::invalid_argument("Bad manual number!");
			}
		});

		return this->distributors[number];
	}

	void showDistributor(std::shared_ptr<ManualDistributor> distributor)
	{
		std::cout << *distributor << std::endl;
	}

	void showManual(std::shared_ptr<Manual> manual)
	{
		std::cout << *manual << std::endl;
	}

	std::string pickFile()
	{
		return this->getData<std::string>("File name", [] (std::string file_name)
				{
					if( !std::regex_match(file_name, std::regex("[a-zA-Z0-9\\-]+\\.data")) )
					{	
						throw std::invalid_argument("Incorect file name. ");
					}
				});
	}
public:

	unsigned int getOption()
	{
		unsigned int option;
		option = this->getData<unsigned int>("Pick Option");
		return option;
	}

	void executeOption(int option)
	{
		switch(option)
		{
			case 0:
				this->printMenu();
				break;
			case 1:
				this->addManualDistributor(this->generateManualDistributor());
				break;
			case 2:
				this->addManual(this->generateManual());
				break;
			case 3:
				try
				{
					std::shared_ptr<Manual> picked_manual = this->pickManual();
					picked_manual->certificate(this->generateCetificateDate());
				}
				catch(std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
				break;
			case 4:
				try
				{
					std::shared_ptr<ManualDistributor> picked_distributor = this->pickManualDistributor();
					/*std::find_if(this->orders.begin(), this->orders.end(), 
									[&] (std::shared_ptr<Manual> const& p)
									{
										return *p == *manual;
									}) 
								  )*/
					picked_distributor->addManual(this->pickManual());
				}
				catch(std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
				break;
			case 5:
				try
				{
					std::shared_ptr<Manual> picked_manual = this->pickManual();
					this->showManual(picked_manual);
				}
				catch(std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
				break;
			case 6:
				try
				{
					std::shared_ptr<ManualDistributor> picked_distributor = this->pickManualDistributor();
					this->showDistributor(picked_distributor);
				}
				catch(std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
				break;
			case 7:
				{
					std::shared_ptr<ManualDistributor> picked_distributor = this->pickManualDistributor();
					std::cout << picked_distributor->getManualsSum() << std::endl;
				}
			case 10:
				try
				{
					std::string picked_file = this->pickFile();
					this->filesys.saveToFile<Manual>( picked_file, this->manuals );
				}
				catch(std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
				break;
			case 11:
				try
				{
					std::string picked_file = this->pickFile();
					this->filesys.saveToFile<ManualDistributor>( picked_file, this->distributors );
				}
				catch(std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
				break;
			case 12:
				try
				{
					std::string picked_file = this->pickFile();
					auto result_vector = this->filesys.readFromFile<Manual>( picked_file );
					this->manuals.insert(this->manuals.begin(), result_vector.begin(), result_vector.end());
				}
				catch(std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
				break;
			case 13:
				try
				{
					std::string picked_file = this->pickFile();
					auto result_vector = this->filesys.readFromFile<ManualDistributor>( picked_file );
					this->distributors.insert(this->distributors.begin(), result_vector.begin(), result_vector.end());	
				}
				catch(std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
				break;
		}
	}
};

int main()
{
	Program program;
	while(1)
	{
		unsigned int option = 0;
		program.executeOption(option);
		option = program.getOption();
		if(option == 0)
		{
			continue;
		}
		if(option == 100)
		{
			break;
		}
		program.executeOption(option);
	}
}