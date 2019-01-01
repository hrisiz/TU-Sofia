#ifndef RAZHODI_H
#define RAZHODI_H
#include <iostream>


class Razhodi
{
private:
	int broi_personal;
	int razhod_na_gorivo_za_chovek;

public:

	Razhodi()
	{

	}

	Razhodi( int broi_personal, int razhod_na_gorivo_za_chovek )
	:broi_personal(broi_personal), razhod_na_gorivo_za_chovek(razhod_na_gorivo_za_chovek)
	{

	}

	int getbroiPersonal()
	{
		return this->broi_personal;
	}
	int getRazhodNaGorivoZaChovek()
	{
		return this->razhod_na_gorivo_za_chovek;
	}

	void setBroiPersonal( int broi_personal )
	{
		this->broi_personal = broi_personal;
	}

	void setRazhodNaGorivoZaChovek( int razhod_na_gorivo_za_chovek )
	{
		this->razhod_na_gorivo_za_chovek = razhod_na_gorivo_za_chovek;
	}
	friend std::ostream& operator<<(std::ostream& out, Razhodi& razhodi);
};

std::ostream& operator<<(std::ostream& out, Razhodi& razhodi)
{
	out << razhodi.broi_personal << ","
		<< razhodi.razhod_na_gorivo_za_chovek;
}
#endif