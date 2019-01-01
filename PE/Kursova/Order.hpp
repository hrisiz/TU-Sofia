
class Order
{
private:
	std::shared_ptr<ManualDistributor> distributor;
	std::vector<std::shared_ptr<Manual>> manuals;
public:
	Order()
	{

	}

	void addManual(std::shared_ptr<Manual> manual)
	{
		if( this->manuals.end() != std::find_if(this->manuals.begin(), this->manuals.end(), 
			[&] (std::shared_ptr<Manual> const& p)
			{
				return *p == *manual;
			}) 
		  )
		{
			throw std::invalid_argument("This manual is already added for this distributor");
		}
		this->manuals.push_back(manual);
	}

	unsigned int getManualsSum()
	{
		unsigned int sum = 0;
		for( std::vector<std::shared_ptr<Manual>>::iterator it = this->manuals.begin(); it != this->manuals.end(); it++ )
		{
			sum += (*it)->getPrice();
		}
		return sum;
	}

	bool operator==(Order& order)
	{
		return *this->distributor == *order.distributor;
	}

	bool operator!=(Order& order)
	{
		return !(*this == *order);
	}
}