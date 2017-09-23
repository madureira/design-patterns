abstract class Car {

	abstract void engineStart();

	abstract void engineStop();

}

class Porsche extends Car {

	public void engineStart() {
		System.out.println("Porsche started!");
	}

	public void engineStop() {
		System.out.println("Porsche stopped!");
	}

}

class ModelS extends Car {

	public void engineStart() {
		System.out.println("ModelS started!");
	}

	public void engineStop() {
		System.out.println("ModelS stopped!");
	}

}

enum Fuel {
	Electrical,
	Gasoline
};

class CarFactory {

	public static Car getInstance(Fuel fuel) {
		if (fuel == Fuel.Gasoline) {
			return new Porsche();
		} else if (fuel == Fuel.Electrical) {
			return new ModelS();
		}

		return null;
	}

}

class Main {

	public static void main(String[] args) {
		System.out.println(":: Factory Method ::\n");

		Car gasolineCar = CarFactory.getInstance(Fuel.Gasoline);
		gasolineCar.engineStart();

		Car electricalCar = CarFactory.getInstance(Fuel.Electrical);
		electricalCar.engineStart();

		gasolineCar.engineStop();
		electricalCar.engineStop();
	}

}
