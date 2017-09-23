#include <iostream>
#include <string>

class Logger
{
public:
	Logger(Logger const&) = delete;
	Logger& operator=(Logger const&) = delete;
	// Note: Scott Meyers mentions in his Effective Modern
	//       C++ book, that deleted functions should generally
	//       be public as it results in better error messages
	//       due to the compilers behavior to check accessibility
	//       before deleted status

	static Logger& getInstance()
	{
		static Logger instance; // Guaranteed to be destroyed.
								// Instantiated on first use.
		return instance;
	}

	void info(std::string message)
	{
		std::cout << "INFO: " << message << std::endl;
	}

	void error(std::string message)
	{
		std::cout << "ERROR: " << message << std::endl;
	}

private:
	Logger() {}
};

int main()
{
	std::cout << ":: Singleton ::\n" << std::endl;

	Logger::getInstance().info("some info message"); // creates an instance for Logger and use it to log the message
	Logger::getInstance().error("some error message"); // uses the instance already created.

	system("PAUSE");

	return 0;
}
