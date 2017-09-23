import java.util.HashMap;
import java.util.Map;

// Vehicle is the base Prototype
interface Vehicle {

	void print();

	Vehicle clone();

}

// Motorcycle is a concrete Prototype
class Motorcycle implements Vehicle {

	private String model;

	public Motorcycle(String model) {
		this.model = model;
	}

	@Override
	public void print() {
		System.out.println("Motorcycle");
		System.out.println("Model: " + this.model + "\n");
	}

	@Override
	public Vehicle clone() {
		return new Motorcycle(this.model);
	}

}

// Bus is a concrete Prototype
class Bus implements Vehicle {

	private String model;

	public Bus(String model) {
		this.model = model;
	}

	@Override
	public void print() {
		System.out.println("Bus");
		System.out.println("Model: " + this.model + "\n");
	}

	@Override
	public Vehicle clone() {
		return new Bus(this.model);
	}

}

// Car is a concrete Prototype
class Car implements Vehicle {

	private String model;

	public Car(String model) {
		this.model = model;
	}

	@Override
	public void print() {
		System.out.println("Car");
		System.out.println("Model: " + this.model + "\n");
	}

	@Override
	public Vehicle clone() {
		return new Car(this.model);
	}

}

enum VehicleType
{
	MOTORCYCLE,
	BUS,
	CAR
};

// VehicleFactory is the client
class VehicleFactory {

	private Map<VehicleType, Vehicle> vehicles;

	public VehicleFactory() {
		this.vehicles = new HashMap<VehicleType, Vehicle>();
		this.vehicles.put(VehicleType.MOTORCYCLE, new Motorcycle("Harley-Davidson"));
		this.vehicles.put(VehicleType.BUS, new Bus("Mercedes-Benz"));
		this.vehicles.put(VehicleType.CAR, new Car("Ferrari"));
	}

	public Vehicle createVehicle(VehicleType vehicleType) {
		return vehicles.get(vehicleType).clone();
	}

}

class Main {

	public static void main(String[] args) {
		System.out.println(":: Prototype ::\n");

		VehicleFactory factory = new VehicleFactory();

		Vehicle vehicle = factory.createVehicle(VehicleType.MOTORCYCLE);
		vehicle.print();

		vehicle = factory.createVehicle(VehicleType.BUS);
		vehicle.print();

		vehicle = factory.createVehicle(VehicleType.CAR);
		vehicle.print();
	}

}
