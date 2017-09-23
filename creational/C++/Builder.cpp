#include <iostream>
#include <string>

// computer parts
class Processor
{
public:
	Processor(std::string model) : m_Model(model) {}
	~Processor() {}

	std::string model()
	{
		return m_Model;
	}

private:
	std::string m_Model;
};

class MemoryRAM
{
public:
	MemoryRAM(int capacity) : m_Capacity(capacity) {}
	~MemoryRAM() {}

	int capacity()
	{
		return m_Capacity;
	}

private:
	int m_Capacity;
};

class HardDrive
{
public:
	HardDrive(int space) : m_Space(space) {}

	int space()
	{
		return m_Space;
	}

private:
	int m_Space;
};

// Final product
class Computer
{
public:
	Computer(std::string description) : m_Description(description) {}

	void setProcessor(Processor* processor)
	{
		m_Processor = processor;
	}

	void setMemoryRAM(MemoryRAM* memoryRAM)
	{
		m_MemoryRAM = memoryRAM;
	}

	void setHardDrive(HardDrive* hardDrive)
	{
		m_HardDrive = hardDrive;
	}

	void show()
	{
		std::cout << "\n--------------------------------" << std::endl;
		std::cout << "Description: " << m_Description << std::endl;
		std::cout << "Processor model: " << m_Processor->model() << std::endl;
		std::cout << "Memory RAM capacity: " << m_MemoryRAM->capacity() << std::endl;
		std::cout << "Hard Drive space: " << m_HardDrive->space() << std::endl;
	}

private:
	std::string m_Description;
	Processor* m_Processor;
	MemoryRAM* m_MemoryRAM;
	HardDrive* m_HardDrive;
};

// Create an abstract 'Builder' class
class ComputerBuilder
{
public:
	const Computer& getComputer()
	{
		return *m_Computer;
	}

	virtual void buildProcessor() = 0;
	virtual void buildMemoryRAM() = 0;
	virtual void buildHardDrive() = 0;

protected:
	Computer* m_Computer;
};

class DellBuilder : public ComputerBuilder
{
public:
	DellBuilder()
	{
		m_Computer = new Computer("DELL Inspiron");
	}

	void buildProcessor()
	{
		m_Computer->setProcessor(new Processor("i7"));
	}

	void buildMemoryRAM()
	{
		m_Computer->setMemoryRAM(new MemoryRAM(16));
	}

	void buildHardDrive()
	{
		m_Computer->setHardDrive(new HardDrive(500));
	}
};

class AppleBuilder : public ComputerBuilder
{
public:
	AppleBuilder()
	{
		m_Computer = new Computer("Apple iMac");
	}

	void buildProcessor()
	{
		m_Computer->setProcessor(new Processor("i5"));
	}

	void buildMemoryRAM()
	{
		m_Computer->setMemoryRAM(new MemoryRAM(8));
	}

	void buildHardDrive()
	{
		m_Computer->setHardDrive(new HardDrive(256));
	}
};

// Director is responsible for the whole process
class Director
{
public:
	void setBuilder(ComputerBuilder* newBuilder)
	{
		m_Builder = newBuilder;
	}

	const Computer& construct()
	{
		m_Builder->buildProcessor();
		m_Builder->buildMemoryRAM();
		m_Builder->buildHardDrive();
		return m_Builder->getComputer();
	}

protected:
	ComputerBuilder* m_Builder;
};

int main()
{
	std::cout << ":: Builder ::\n" << std::endl;

	Director director; // A director who controls the process

	// Concrete builders
	DellBuilder dellBuilder;
	AppleBuilder appleBuilder;

	// building a DELL Inspiron computer
	director.setBuilder(&dellBuilder);
	Computer inspiron = director.construct(); // Final product

	// building a Apple Mac computer
	director.setBuilder(&appleBuilder);
	Computer mac = director.construct();  // Final product

	// Show specifications
	inspiron.show();
	mac.show();

	system("PAUSE");

	return 0;
}
