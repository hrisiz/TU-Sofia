#include <iostream>
class test
{
	private:
		int a;
		int b;
	public:
		test(int a, int b)
		:a(a), b(b)
		{

		}
		friend std::ostream& operator<<(std::ostream& os, test& test);
};

std::ostream& operator<<(std::ostream& os, test& test)
{
	os << test.a << std::endl;
	os << test.b << std::endl;
	return os;
}

template <typename T>
void extendArr(int size, int newSize, T **order){// should be here
	T **order1 = new T*[newSize];
	if (order){
		for (int i = 0; i < size; i++){
			order1[i] = order[i];
			std::cout << "Copy: " << order1[i] << ":" << order[i] << std::endl;
		}
		order = order1;
	}
}

int main()
{
	test** t = new test*[0];
	for(int i = 0; i < 4; i++)
	{
		extendArr<test>(i,i+1,t);
		t[i] = new test(i,i);
	}
	for(int i = 0; i < 4; i++)
	{
		std::cout << *t[i] << std::endl;
	}
}