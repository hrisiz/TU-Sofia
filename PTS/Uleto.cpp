#include <iostream>
class CanvesObject
{
private:
	int priority;
public:
	int getPriority()
	{
		return this->priority;
	}
	void hide()
	{
		this->priority = -1;
	}
	void show(int priority=0)
	{
		this->priority = priority;
	}
};

class Axes: public CanvesObject
{
private:
	int size;
};

class Canves
{
private:
	Axes axes;
public:
	void hideAxes()
	{
		this->axes.hide();
	}
	bool axesStatus()
	{
		return (this->axes.getPriority() >= 0);
	}
};

int main()
{
	Canves canves;
	std::cout << "Axes status: " << (canves.axesStatus() ? "Visible":"Hidden") << std::endl;
	canves.hideAxes();
	std::cout << "Axes status: " << (canves.axesStatus() ? "Visible":"Hidden") << std::endl;
}