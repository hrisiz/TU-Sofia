#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Date{
protected: 
           int day;
           int month;
           int year;
public:
	Date(const Date& d);
	Date(int d, int m, int y);
	~Date(){cout << "Destructing";}
             
};
      
Date::Date(int d, int m, int y)
{
	day=d;
	month =m;
	year = y;
}

Date::Date(const Date& d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
}

class Student{
protected:   
	string name;
	string facNum;
	Date *dateOfB;
	double avScore;
public:
	Student(string n, string facNum, Date *dOB, double avSc);
	~Student(){cout << "destructing student";}
	bool isAvgSmaller(const Student student )
	{
		if(this->avScore < student.avScore)
		{
			return true;
		}
		return false;
	}
};
      
Student :: Student(string n, string facN, Date *dOB, double avSc){
	name = name;
	facNum = facN;
	this->dateOfB = dOB;
	this->avScore = avSc;
	}

int main(int argc, char *argv[])
{
	vector<Student*> students;
	Date date(1,2,3);
	students.push_back(new Student("az", "50", &date, 10));
	students.push_back(new Student("az", "50", &date, 12));
	students.push_back(new Student("az", "50", &date, 9));
	cout << students.at(0)->isAvgSmaller(*students.at(1)) << endl;
	//system("PAUSE");
	return EXIT_SUCCESS;
}