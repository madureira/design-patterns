#include <iostream>
#include <string>

class Fuel
{
public:
	virtual std::string type() = 0;
};

class Diesel : public Fuel
{
public:
	std::string type()
	{
		return "Diesel";
	}
};

class Gasoline : public Fuel
{
public:
	std::string type()
	{
		return "Gasoline";
	}
};

class Car
{
public:
	virtual void info() = 0;
};

class Jeep : public Car
{
public:
	Jeep(Fuel* fuel) : m_Fuel(fuel)
	{
	}

	~Jeep()
	{
		delete m_Fuel;
	}

	void info()
	{
		std::cout << "\nModel: Jeep" << std::endl;
		std::cout << "Fuel: " + m_Fuel->type() << std::endl;
	}

private:
	Fuel* m_Fuel;
};

class Subaru : public Car
{
public:
	Subaru(Fuel* fuel) : m_Fuel(fuel)
	{
	}

	~Subaru()
	{
		delete m_Fuel;
	}

	void info()
	{
		std::cout << "\nModel: Subaru" << std::endl;
		std::cout << "Fuel: " + m_Fuel->type() << std::endl;
	}

private:
	Fuel* m_Fuel;
};

int main()
{
	std::cout << ":: Bridge ::" << std::endl;

	Fuel* diesel = new Diesel();
	Fuel* gasoline = new Gasoline();

	Car* jeep = new Jeep(diesel);
	Car* subaru = new Subaru(gasoline);

	jeep->info();
	subaru->info();

	system("PAUSE");

	delete jeep;
	delete subaru;

	return 0;
}
