#include <iostream>
class Shape
{
private:
	int x,y,z;
public:
	Shape()
	{
		this->setTo(0,0,0);
	}
	Shape(int x, int y, int z)
	{
		this->setTo(x,y,z);
	}
	void setTo(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void toCenter()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		// trigger Canves refresh
	}
	int getX()
	{
		return this->x;
	}
	int getY()
	{
		return this->y;
	}
	int getZ()
	{
		return this->z;
	}
};
int main()
{
	Shape object(1,5,1);
	std::cout << "Pos(xyz): " << object.getX() << " " << object.getY() << " " << object.getZ() << std::endl;
	object.toCenter();
	std::cout << "Pos(xyz): " << object.getX() << " " << object.getY() << " " << object.getZ() << std::endl;
}