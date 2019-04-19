#include <iostream>
#include <string>
#include <type_traits>

enum class Planet {
	MERCURY,
	VENUS,
	EARTH,
	MARS,
	JUPITER,
	SATURN,
	URANUS,
	NEPTUNE
};

// Not part of the pattern.
std::string enumToString(Planet planet);

class PlanetHandler
{
protected:
	PlanetHandler* m_Successor = nullptr;

public:
	void setSuccessor(PlanetHandler* successor)
	{
		this->m_Successor = successor;
	}

	virtual void handleRequest(Planet request) = 0;
};

class MercuryHandler : public PlanetHandler
{
public:
	void handleRequest(Planet request) override
	{
		if (request == Planet::MERCURY)
		{
			std::cout << "MercuryHandler handles " << enumToString(request) << std::endl;
			std::cout << "Mercury is hot.\n" << std::endl;
		}
		else
		{
			std::cout << "MercuryHandler doesn't handle " << enumToString(request) << std::endl;
			if (this->m_Successor != nullptr) {
				this->m_Successor->handleRequest(request);
			}
		}
	}
};

class VenusHandler : public PlanetHandler
{
public:
	void handleRequest(Planet request) override
	{
		if (request == Planet::VENUS)
		{
			std::cout << "VenusHandler handles " << enumToString(request) << std::endl;
			std::cout << "Venus is poisonous.\n" << std::endl;
		}
		else
		{
			std::cout << "VenusHandler doesn't handle " << enumToString(request) << std::endl;
			if (this->m_Successor != nullptr) {
				this->m_Successor->handleRequest(request);
			}
		}
	}
};

class EarthHandler : public PlanetHandler
{
public:
	void handleRequest(Planet request) override
	{
		if (request == Planet::EARTH)
		{
			std::cout << "EarthHandler handles " << enumToString(request) << std::endl;
			std::cout << "Earth is comfortable.\n" << std::endl;
		}
		else
		{
			std::cout << "EarthHandler doesn't handle " << enumToString(request) << std::endl;
			if (this->m_Successor != nullptr) {
				this->m_Successor->handleRequest(request);
			}
		}
	}
};

PlanetHandler* setUpChain() {
	PlanetHandler* mercuryHandler = new MercuryHandler();
	PlanetHandler* venusHandler = new VenusHandler();
	PlanetHandler* earthHandler = new EarthHandler();

	mercuryHandler->setSuccessor(venusHandler);
	venusHandler->setSuccessor(earthHandler);

	return mercuryHandler;
}

// Not part of the pattern.
template<typename T>
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
{
	return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

int main()
{
	std::cout << ":: Chain of Responsability ::\n" << std::endl;

	PlanetHandler* chain = setUpChain();
	chain->handleRequest(Planet::VENUS);
	chain->handleRequest(Planet::MERCURY);
	chain->handleRequest(Planet::EARTH);
	chain->handleRequest(Planet::JUPITER);

	system("PAUSE");

	return 0;
}

// Not part of the pattern.
std::string enumToString(Planet planet)
{
	int index = int(planet);

	std::string temp = "";

	switch (index)
	{
	case 0:
		temp = "MERCURY";
		break;
	case 1:
		temp = "VENUS";
		break;
	case 2:
		temp = "EARTH";
		break;
	case 3:
		temp = "MARS";
		break;
	case 4:
		temp = "JUPITER";
		break;
	case 5:
		temp = "SATURN";
		break;
	case 6:
		temp = "URANUS";
		break;
	case 7:
		temp = "NEPTUNE";
		break;
	default:
		break;
	}

	return temp;
}