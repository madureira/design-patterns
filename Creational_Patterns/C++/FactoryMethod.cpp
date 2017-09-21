#include <iostream>
#include <string>
#include <memory>

// abstract class
class Car
{
public:
	virtual ~Car() {};
	virtual void engineStart() = 0;
	virtual void engineStop() = 0;
};

class Porsche : public Car
{
public:
	virtual ~Porsche() {}

	void engineStart() override
	{
		std::cout << "Porsche started!" << std::endl;
	}

	void engineStop() override
	{
		std::cout << "Porsche stopped!" << std::endl;
	}

};

class ModelS : public Car
{
public:
	virtual ~ModelS() {};

	void engineStart() override
	{
		std::cout << "ModelS started!" << std::endl;
	}

	void engineStop() override
	{
		std::cout << "ModelS stopped!" << std::endl;
	}
};

enum Fuel {
	Electrical,
	Gasoline
};

class CarFactory
{
public:
	static std::unique_ptr<Car> getInstance(Fuel fuel)
	{
		if (fuel == Fuel::Gasoline)
		{
			return std::make_unique<Porsche>();
		}
		else if (fuel == Fuel::Electrical)
		{
			return std::make_unique<ModelS>();
		}
		else
		{
			return nullptr;
		}
	}
};


int main()
{
	std::cout << ":: Factory Method ::\n" << std::endl;

	std::unique_ptr<Car>  gasolineCar = CarFactory::getInstance(Fuel::Gasoline);
	gasolineCar->engineStart();

	std::unique_ptr<Car> electricalCar = CarFactory::getInstance(Fuel::Electrical);
	electricalCar->engineStart();

	gasolineCar->engineStop();
	electricalCar->engineStop();

	system("PAUSE");

	return 0;
}
