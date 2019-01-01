#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

#include "Samolet.hpp"
#include "Destinaciq.hpp"

class Program
{
private:
	std::vector<Samolet> samoleti;
	std::vector<Destinaciq> destinacii;
public:
	void printOptions()
	{
		std::cout << "Pick Option: " << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "1. Dobavi samolet" << std::endl;;
		std::cout << "2. Pokaji samoleti" << std::endl;
		std::cout << "3. Dobavi destinaciq" << std::endl;
		std::cout << "4. Pokaji destinacii" << std::endl;
		std::cout << "5. Samoleti za destinaciq" << std::endl;
		std::cout << "6. Zapazi v fail" << std::endl;
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
				Samolet samolet;
				while(1)
				{
					try
					{
						std::string proizvoditel;
						std::string model;
						int broi_mesta;
						int duljina;
						int broi_personal;
						int razhod_na_gorivo;
						int rezervoar;
						double sredna_skorost;

						std::cout << "Proizvoditel:";
						std::cin >> proizvoditel;
						bool fail = std::cin.fail();
						std::cin.clear();
						if(fail)
						{
							std::cout << "cin failed! Bad input." << std::endl;
							continue;
						}
						samolet.setProizvoditel(proizvoditel);
						std::cout << std::endl;

						std::cout << "Model:";
						std::cin >> model;
						fail = std::cin.fail();
						std::cin.clear();
						if(fail)
						{
							std::cout << "cin failed! Bad input." << std::endl;
							continue;
						}
						samolet.setModel(model);
						std::cout << std::endl;

						std::cout << "Broi Mesta:";
						std::cin >> broi_mesta;
						fail = std::cin.fail();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						if(fail)
						{
							std::cout << "cin failed! Bad input." << std::endl;
							continue;
						}
						samolet.setBroiMesta(broi_mesta);
						std::cout << std::endl;

						std::cout << "Pista Duljina:";
						std::cin >> duljina;
						fail = std::cin.fail();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						if(fail)
						{
							std::cout << "cin failed! Bad input." << std::endl;
							continue;
						}
						samolet.setDuljina(duljina);
						std::cout << std::endl;

						std::cout << "Razhodi:";

						std::cout << "Broi Personal:";
						std::cin >> broi_personal;
						fail = std::cin.fail();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						if(fail)
						{
							std::cout << "cin failed! Bad input." << std::endl;
							continue;
						}
						std::cout << std::endl;

						std::cout << "Razhod na gorivo:";
						std::cin >> razhod_na_gorivo;
						fail = std::cin.fail();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						if(fail)
						{
							std::cout << "cin failed! Bad input." << std::endl;
							continue;
						}
						std::cout << std::endl;

						Razhodi razhodi(broi_personal, razhod_na_gorivo);
						samolet.setRazhodi(razhodi);
						std::cout << std::endl;

						std::cout << "Rezervoar:";
						std::cin >> rezervoar;
						fail = std::cin.fail();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						if(fail)
						{
							std::cout << "cin failed! Bad input." << std::endl;
							continue;
						}
						samolet.setRezervoar(rezervoar);
						std::cout << std::endl;

						std::cout << "Sredna Skorost:";
						std::cin >> sredna_skorost;
						fail = std::cin.fail();
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						if(fail)
						{
							std::cout << "cin failed! Bad input." << std::endl;
							continue;
						}
						samolet.setSrednaSkorost(sredna_skorost);
						break;
					}
					catch(std::exception& e)
					{
						std::cout << e.what() << std::endl;
					}
				}
				this->samoleti.push_back(samolet);
				break;
			}

			case 2:
			{
				for( auto samolet : this->samoleti )
				{
					std::cout << samolet << std::endl;
				}
				break;
			}
			case 3:
			{
				Destinaciq destinaciq;
				while(1)
				{
					try
					{
						std::string ime;
						int razstoqnie;

						std::cout << "Ime:";
						std::cin >> ime;
						bool fail = std::cin.fail();
						std::cin.clear();
						if(fail)
						{
							std::cout << "cin failed! Bad input." << std::endl;
							continue;
						}
						destinaciq.setIme(ime);
						std::cout << std::endl;

						std::cout << "Razstoqnie:";
						std::cin >> razstoqnie;
						fail = std::cin.fail();
						std::cin.clear();
						if(fail)
						{
							std::cout << "cin failed! Bad input." << std::endl;
							continue;
						}
						destinaciq.setRazstoqnie(razstoqnie);
						std::cout << std::endl;
						break;
					}
					catch(std::exception& e)
					{
						std::cout << e.what() << std::endl;
					}
				}
				this->destinacii.push_back(destinaciq);
				break;
			}
			case 4:
			{
				for( auto destianciq : this->destinacii )
				{
					std::cout << destianciq << std::endl;
				}
				break;
			}
			case 5:
			{
				while(1)
				{
					try
					{
						int tekushta_destinaciq;
						int index = 0;
						for( auto destianciq : this->destinacii )
						{
							index++;
							std::cout << index << "): " << std::endl << destianciq << std::endl;
						}

						std::cin >> tekushta_destinaciq;
						bool fail = std::cin.fail();
						std::cin.clear();
						if(fail)
						{
							std::cout << "cin failed! Bad input." << std::endl;
							continue;
						}

						bool flag_za_proverka_dali_e_vlqzlo_v_cikula_za_samoletite = false;
						for( auto samolet: this->samoleti )
						{
							std::cout << samolet.proveriDestinaciq(this->destinacii[tekushta_destinaciq]) << std::endl;
							if(samolet.proveriDestinaciq(this->destinacii[tekushta_destinaciq]))
							{
								std::cout << samolet << std::endl;
								flag_za_proverka_dali_e_vlqzlo_v_cikula_za_samoletite = true;
							}
						}
						if(!flag_za_proverka_dali_e_vlqzlo_v_cikula_za_samoletite)
						{
							std::cout << "Nqma samolet" << std::endl;
						}
						break;
					}
					catch(std::exception& e)
					{
						std::cout << e.what() << std::endl;
					}
				}
				break;
			}
			case 6:
			{
				std::ofstream FILE("samoleti.csv", std::ios::out | std::ofstream::binary);
				std::ofstream FILE1("destinacii.csv", std::ios::out | std::ofstream::binary);
				if(!FILE.is_open())
				{
					std::cout << "Failed to open samoleti.csv" << std::endl;
					break;
				}
				if(!FILE1.is_open())
				{
					FILE.close();
					std::cout << "Failed to open destiancii.csv" << std::endl;
					break;
				}

				for( auto samolet: this->samoleti )
				{
					FILE << samolet;
				}
				for( auto destianciq : this->destinacii )
				{
					FILE1 << destianciq;
				}
				FILE.close();
				FILE1.close();
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
		std::cin >> option;
		bool fail = std::cin.fail();
		std::cin.clear();
		if(fail)
		{
			std::cout << "cin failed! Bad input." << std::endl;
			continue;
		}
	}while(program.startOption(option));
	return 0;
}