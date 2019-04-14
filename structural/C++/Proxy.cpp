#include <iostream>
#include <string>

class Image
{
protected:
	std::string name;

public:
	virtual void display() = 0;
};

class RealImage : public Image
{
public:
	RealImage(std::string imageName)
	{
		this->name = imageName;
		this->loadFromDisk(this->name);
	}

	void display()
	{
		std::cout << "Displaying " << this->name << " from memory.\n" << std::endl;
	}

private:
	void loadFromDisk(std::string imageName)
	{
		std::cout << "Loading image: " << imageName << " from disk." << std::endl;
	}
};

class ProxyImage : public Image
{
private:
	RealImage* realImage;

public:
	ProxyImage(std::string imageName): realImage(nullptr)
	{
		this->name = imageName;
	}

	void display()
	{
		if (this->realImage == nullptr)
		{
			this->realImage = new RealImage(this->name);
		}
		this->realImage->display();
	}
};

int main()
{
	Image* image = new ProxyImage("test_10mb.jpg");

	// image will be loaded from disk.
	image->display();

	// image will not be loaded from disk.
	image->display();

	system("PAUSE");

	return 0;
}