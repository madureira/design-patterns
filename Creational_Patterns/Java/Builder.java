// computer parts
class Processor {

	private String model;

	public Processor(String model) {
		this.model = model;
	}

	String getModel() {
		return this.model;
	}

}

class MemoryRAM {

	private Integer capacity;

	public MemoryRAM(Integer capacity) {
		this.capacity = capacity;
	}

	Integer getCapacity() {
		return this.capacity;
	}

}

class HardDrive {

	private Integer space;

	public HardDrive(Integer space) {
		this.space = space;
	}

	public Integer getSpace() {
		return this.space;
	}

}

// Final product
class Computer {

	private String description;
	private Processor processor;
	private MemoryRAM memoryRAM;
	private HardDrive hardDrive;

	public Computer(String description) {
		this.description = description;
	}

	public void setProcessor(Processor processor) {
		this.processor = processor;
	}

	public void setMemoryRAM(MemoryRAM memoryRAM) {
		this.memoryRAM = memoryRAM;
	}

	public void setHardDrive(HardDrive hardDrive) {
		this.hardDrive = hardDrive;
	}

	public void show() {
		System.out.println("\n--------------------------------");
		System.out.println("Description: " + description);
		System.out.println("Processor model: " + processor.getModel());
		System.out.println("Memory RAM capacity: " + memoryRAM.getCapacity());
		System.out.println("Hard Drive space: " + hardDrive.getSpace());
	}

}

// Create an abstract 'Builder' class
abstract class ComputerBuilder {

	protected Computer computer;

	public Computer getComputer() {
		return this.computer;
	}

	protected abstract void buildProcessor();
	protected abstract void buildMemoryRAM();
	protected abstract void buildHardDrive();

}

class DellBuilder extends ComputerBuilder {

	public DellBuilder() {
		this.computer = new Computer("DELL Inspiron");
	}

	@Override
	public void buildProcessor() {
		this.computer.setProcessor(new Processor("i7"));
	}

	@Override
	public void buildMemoryRAM() {
		this.computer.setMemoryRAM(new MemoryRAM(16));
	}

	@Override
	public void buildHardDrive() {
		this.computer.setHardDrive(new HardDrive(500));
	}

}

class AppleBuilder extends ComputerBuilder {

	public AppleBuilder() {
		this.computer = new Computer("Apple iMac");
	}

	@Override
	public void buildProcessor() {
		this.computer.setProcessor(new Processor("i5"));
	}

	@Override
	public void buildMemoryRAM() {
		this.computer.setMemoryRAM(new MemoryRAM(8));
	}

	@Override
	public void buildHardDrive() {
		this.computer.setHardDrive(new HardDrive(256));
	}

}

// Director is responsible for the whole process
class Director {

	private ComputerBuilder builder;

	public void setBuilder(ComputerBuilder builder) {
		this.builder = builder;
	}

	public Computer contruct() {
		this.builder.buildProcessor();
		this.builder.buildMemoryRAM();
		this.builder.buildHardDrive();

		return this.builder.getComputer();
	}

}

class Main {

	public static void main(String[] args) {
		System.out.println(":: Builder ::\n");

		Director director = new Director(); // A director who controls the process

		// Concrete builders
		ComputerBuilder dellBuilder = new DellBuilder();
		ComputerBuilder appleBuilder = new AppleBuilder();

		// building a DELL Inspiron computer
		director.setBuilder(dellBuilder);
		Computer inspiron = director.contruct(); // Final product

		// building a Apple Mac computer
		director.setBuilder(appleBuilder);
		Computer mac = director.contruct();  // Final product

		// Show specifications
		inspiron.show();
		mac.show();
	}

}
