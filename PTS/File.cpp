#include <iostream>
#include <fstream>
#include <sys/stat.h>

static void message(std::string message)
{
	std::cout << message << std::endl;
}

static bool ask_user(std::string message, std::string possitive, std::string negative)
{
	while(1)
	{
		std::cout << message << std::endl;
		std::cout << possitive << " or " << negative << std::endl;
		std::string str;
		std::cin >> str;
		if(str == "Yes")
		{
			return true;
		}
		else if(str == "No")
		{
			return false;
		}
		else
		{
			std::cout << "Bad input!" << std::endl;
		}
	}
}

class File
{
private:
	std::fstream file;
	bool unsaved_change;
	std::string file_name;

	void CheckForChange()
	{
		// compare current state with file state and if they are different set false
		this->unsaved_change = true;
	}
public:
	File()
	:unsaved_change(false)
	{

	}

	File(std::string file_name) // Misheto's story
	:unsaved_change(false)
	{
		this->Open(file_name);
	}

	~File()
	{
		if(this->file.is_open())
		{
			this->Close();
		}
	}

	void Save()
	{
	}; // Dummy

	void Open(std::string file_name) // Misheto's story
	{
		this->file_name = file_name;
		struct stat statbuff;
		std::ios_base::openmode mode = std::fstream::out | std::fstream::in;
		if(stat(file_name.c_str(),&statbuff) == -1)
		{
			if(!ask_user("File do not exist. Do you want to create it?", "Yes", "No")) // Pepi's story
			{
				return;
			}
			else
			{
				mode |= std::fstream::trunc;
			}
		}
		this->file.open((file_name ).c_str(), mode);
	}

	void Close() // Zarkov's story
	{
		if(!this->file.is_open())
		{
			message("No file was opened.");
		}
		else
		{
			this->CheckForChange();
			if(unsaved_change)
			{
				if(ask_user("Your changes are not saved. Do you want to save them ?", "Yes", "No"))
				{
					this->Save();
				}
			}
			this->file.close();
		}
	}
};

int main()
{
	File test_file("./mySuperUltraDuperFile.haha");
	test_file.Close();
}

