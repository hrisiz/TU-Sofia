#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

class FileSystem
{
private:

public:
	template<typename InputType, typename SharedType = std::shared_ptr<InputType>>
	void saveToFile(std::string path, std::vector<SharedType> input_vector)
	{
		std::ofstream FILE(path, std::ios::out | std::ofstream::binary);
		if(!FILE.is_open())
		{
			throw std::runtime_error("Failed to open " + path);
		}
		for( typename std::vector<SharedType>::iterator it = input_vector.begin(); it != input_vector.end(); it++ )
		{
			FILE << *(*it);
		}
	}

	template<typename InputType, typename SharedType = std::shared_ptr<InputType>>
	std::vector<SharedType> readFromFile(std::string path)
	{
		std::vector<SharedType> result;
		std::ifstream FILE(path, std::ios::in | std::ifstream::binary);
		if(!FILE.is_open())
		{
			throw std::runtime_error("Failed to open " + path);
		}
		while(1)
		{
			InputType man;
			FILE >> man;
			if(FILE.eof())
			{
				break;
			}
			if(FILE.fail())
			{
				continue;
			}
			result.push_back(std::make_shared<InputType>(man));
		}
		return result;
	}
};