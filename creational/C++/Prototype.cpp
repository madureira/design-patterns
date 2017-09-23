#include <iostream>
#include <string>
#include <memory>
#include <map>

// Vehicle is the base Prototype
class Vehicle
{
public:
	virtual ~Vehicle() {};
	virtual void print() = 0;
	virtual std::unique_ptr<Vehicle> clone() = 0;
};

// Motorcycle is a concrete Prototype
class Motorcycle : public Vehicle
{
public:
	Motorcycle(std::string model) : m_Model(model) {}

	void print() override
	{
		std::cout << "Motorcycle" << std::endl << "Model: " << m_Model << "\n\n";
	}

	std::unique_ptr<Vehicle> clone() override
	{
		return std::make_unique<Motorcycle>(*this);
	}

private:
	std::string m_Model;
};

// Bus is a concrete Prototype
class Bus : public Vehicle
{
public:
	Bus(std::string model) : m_Model(model) {}

	void print() override
	{
		std::cout << "Bus" << std::endl << "Model: " << m_Model << "\n\n";
	}

	std::unique_ptr<Vehicle> clone() override
	{
		return std::make_unique<Bus>(*this);
	}

private:
	std::string m_Model;
};

// Car is a concrete Prototype
class Car : public Vehicle
{
public:
	Car(std::string model) : m_Model(model) {}

	void print() override
	{
		std::cout << "Car" << std::endl << "Model: " << m_Model << "\n\n";
	}

	std::unique_ptr<Vehicle> clone() override
	{
		return std::make_unique<Car>(*this);
	}

private:
	std::string m_Model;
};

enum VehicleType
{
	MOTORCYCLE,
	BUS,
	CAR
};

// VehicleFactory is the client
class VehicleFactory
{
public:
	VehicleFactory()
	{
		m_Vehicles[MOTORCYCLE] = std::make_unique<Motorcycle>("Harley-Davidson");
		m_Vehicles[BUS] = std::make_unique<Bus>("Mercedes-Benz");
		m_Vehicles[CAR] = std::make_unique<Car>("Ferrari");
	}

	std::unique_ptr<Vehicle> createVehicle(VehicleType vehicleType)
	{
		return m_Vehicles[vehicleType]->clone();
	}

private:
	std::map<VehicleType, std::unique_ptr<Vehicle>> m_Vehicles;
};

int main()
{
	std::cout << ":: Prototype ::\n" << std::endl;

	VehicleFactory factory;

	auto vehicle = factory.createVehicle(MOTORCYCLE);
	vehicle->print();

	vehicle = factory.createVehicle(BUS);
	vehicle->print();

	vehicle = factory.createVehicle(CAR);
	vehicle->print();

	system("PAUSE");

	return 0;
}
