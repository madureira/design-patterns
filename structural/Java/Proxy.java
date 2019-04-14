abstract class Image {

	protected String name;

	public abstract void display();

}

class RealImage extends Image {

	public RealImage(String imageName) {
		this.name = imageName;
		this.loadFromDisk(this.name);
	}

	@Override
	public void display() {
		System.out.println("Displaying " + this.name + " from memory.\n");
	}

	private void loadFromDisk(String imageName) {
		System.out.println("Laoding image: " + imageName + " from disk.");
	}

}

class ProxyImage extends Image {

	private RealImage realImage;

	public ProxyImage(String imageName) {
		this.name = imageName;
	}

	@Override
	public void display() {
		if (this.realImage == null) {
			this.realImage = new RealImage(this.name);
		}
		this.realImage.display();
	}

}

public class Main {

	public static void main(String[] args) {
		System.out.println(":: Proxy ::\n");
		
		Image image = new ProxyImage("test_10mb.jpg");
		
		// image will be loaded from disk.
		image.display();
		
		// image will not be loaded from disk.
		image.display();
	}

}