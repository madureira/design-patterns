#include <iostream>
#include <vector>

class Shape
{
public:
	Shape() {}
	virtual void draw() = 0;
};

class Circle : public Shape
{
public:
	void draw()
	{
		std::cout << "Circle " << ": draw" << std::endl;
	}
};

class Ellipse : public Shape
{
public:
	void draw()
	{
		std::cout << "Ellipse " << ": draw" << std::endl;
	}
};

class Square : public Shape
{
public:
	void draw()
	{
		std::cout << "Square " << ": draw" << std::endl;
	}
};

class Rectangle : public Shape
{
public:
	void draw()
	{
		std::cout << "Rectangle " << ": draw" << std::endl;
	}
};

class ShapeFactory
{
public:
	virtual Shape* createCurvedInstance() = 0;
	virtual Shape* createStraightInstance() = 0;
};

class SimpleShapeFactory : public ShapeFactory
{
	Shape* createCurvedInstance()
	{
		return new Circle;
	}

	Shape* createStraightInstance()
	{
		return new Square;
	}
};

class ComplexShapeFactory : public ShapeFactory
{
public:
	Shape* createCurvedInstance()
	{
		return new Ellipse;
	}

	Shape* createStraightInstance()
	{
		return new Rectangle;
	}
};

int main()
{
	std::cout << ":: Abstract Factory ::\n" << std::endl;

	std::vector<Shape*> shapes;

	ShapeFactory* simpleFactory = new SimpleShapeFactory;
	shapes.push_back(simpleFactory->createCurvedInstance());    // new Circle;
	shapes.push_back(simpleFactory->createStraightInstance());  // new Square;

	ShapeFactory* complexFactory = new ComplexShapeFactory;
	shapes.push_back(complexFactory->createCurvedInstance());   // new Ellipse;
	shapes.push_back(complexFactory->createStraightInstance()); // new Rectangle;

	for (auto& shape : shapes)
	{
		shape->draw();
	}

	system("PAUSE");

	return 0;
}
