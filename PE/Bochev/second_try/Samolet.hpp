#ifndef SAMOLETI_H
#define SAMOLETI_H
#include <iostream>
#include <string>

#include "Razhodi.hpp"
#include "Destinaciq.hpp"

class Samolet
{
private:
	std::string proizvoditel;
	std::string model;
	int broi_mesta;
	int duljina; // v metri
	Razhodi razhodi;
	int rezervoar;
	double sredna_skorost;
public:

	Samolet()
	{

	}

	Samolet(std::string proizvoditel, std::string model, int broi_mesta, int duljina, Razhodi razhodi, int rezervoar, double sredna_skorost)
	:proizvoditel(proizvoditel), model(model), broi_mesta(broi_mesta), duljina(duljina), razhodi(razhodi), rezervoar(rezervoar), sredna_skorost(sredna_skorost)
	{

	}

	std::string getProizvoditel()
	{
		return this->proizvoditel;
	}
	std::string getModel()
	{
		return this->model;
	}
	int getBroiMesta()
	{
		return this->broi_mesta;
	}
	int getDuljina()
	{
		return this->duljina;
	}
	Razhodi getRazhodi()
	{
		return this->razhodi;
	}
	int getRezervoar()
	{
		return this->rezervoar;
	}
	double getSrednaSkorost()
	{
		return this->sredna_skorost;
	}

	void setProizvoditel(std::string proizvoditel)
	{
		this->proizvoditel = proizvoditel;
	}
	void setModel(std::string model)
	{
		this->model = model;
	}
	void setBroiMesta(int broi_mesta)
	{
		this->broi_mesta = broi_mesta;
	}
	void setDuljina(int duljina)
	{
		this->duljina = duljina;
	}
	void setRazhodi(Razhodi razhodi)
	{
		this->razhodi = razhodi;
	}
	void setRezervoar(int rezervoar)
	{
		this->rezervoar = rezervoar;
	}
	void setSrednaSkorost(double sredna_skorost)
	{
		this->sredna_skorost = sredna_skorost;
	}

	bool proveriDestinaciq(Destinaciq destinaciq)
	{
		return ( this->broi_mesta * this->razhodi.getRazhodNaGorivoZaChovek() ) * (destinaciq.getRazstoqnie() + 200 ) < this->rezervoar; // 200 km dopulnitelni
	}

	friend std::ostream& operator<<(std::ostream& out, Samolet& nomer5);
};

std::ostream& operator<<(std::ostream& out, Samolet& nomer5)
{
	out << nomer5.proizvoditel << ","
		<< nomer5.model << ","
		<< nomer5.broi_mesta << ","
		<< nomer5.duljina << ","
		<< nomer5.razhodi << ","
		<< nomer5.rezervoar << ","
		<< nomer5.sredna_skorost
		<< std::endl;
}
#endif