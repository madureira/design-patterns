

interface Fuel {

	public String getType();

}

class Diesel implements Fuel {

	@Override
	public String getType() {
		return "Diesel";
	}

}

class Gasoline implements Fuel {

	@Override
	public String getType() {
		return "Gasoline";
	}

}

interface Car {

	public void showInfo();

}

class Jeep implements Car {

	private Fuel fuel;

	public Jeep(Fuel fuel) {
		this.fuel = fuel;
	}

	@Override
	public void showInfo() {
		System.out.println("\nModel: Jeep");
		System.out.println("Fuel: " + fuel.getType());
	}
}

class Subaru implements Car {

	private Fuel fuel;

	public Subaru(Fuel fuel) {
		this.fuel = fuel;
	}

	@Override
	public void showInfo() {
		System.out.println("\nModel: Subaru");
		System.out.println("Fuel: " + fuel.getType());
	}

}

public class Main {

	public static void main(String[] args) {
		System.out.println(":: Bridge ::\n");

		Fuel diesel = new Diesel();
		Fuel gasoline = new Gasoline();

		Car jeep = new Jeep(diesel);
		Car subaru = new Subaru(gasoline);

		jeep.showInfo();
		subaru.showInfo();
	}

}