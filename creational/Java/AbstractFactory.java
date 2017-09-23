import java.util.ArrayList;
import java.util.List;

interface Shape {
	void draw();
}

class Circle implements Shape {

	@Override
	public void draw() {
		System.out.println("Circle: draw");
	}

}

class Ellipse implements Shape {

	@Override
	public void draw() {
		System.out.println("Ellipse: draw");
	}

}

class Square implements Shape {

	@Override
	public void draw() {
		System.out.println("Square: draw");
	}

}

class Rectangle implements Shape {

	@Override
	public void draw() {
		System.out.println("Rectangle: draw");
	}

}

interface ShapeFactory {

	Shape createCurvedInstance();

	Shape createStraightInstance();

}

class SimpleShapeFactory implements ShapeFactory {

	@Override
	public Shape createCurvedInstance() {
		return new Circle();
	}

	@Override
	public Shape createStraightInstance() {
		return new Square();
	}

}

class ComplexShapeFactory implements ShapeFactory {

	@Override
	public Shape createCurvedInstance() {
		return new Ellipse();
	}

	@Override
	public Shape createStraightInstance() {
		return new Rectangle();
	}

}

class Main {

	public static void main(String[] args) {
		System.out.println(":: Abstract Factory ::\n");

		List<Shape> shapes = new ArrayList<Shape>();

		SimpleShapeFactory simpleFactory = new SimpleShapeFactory();
		shapes.add(simpleFactory.createCurvedInstance());
		shapes.add(simpleFactory.createStraightInstance());

		ComplexShapeFactory complexFactory = new ComplexShapeFactory();
		shapes.add(complexFactory.createCurvedInstance());
		shapes.add(complexFactory.createStraightInstance());

		for (Shape shape : shapes) {
			shape.draw();
		}
	}

}
