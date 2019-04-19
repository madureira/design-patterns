interface Widget {

	public void draw();

	public String getDescription();

}

class Window implements Widget {

	@Override
	public void draw() {
		System.out.println("Drawing the Window");
	}

	@Override
	public String getDescription() {
		return "Window";
	}

}

class WindowDecorator extends Window {

	private Widget windowToBeDecorated;

	public WindowDecorator(Widget windowToBeDecorated) {
		this.windowToBeDecorated = windowToBeDecorated;
	}

	@Override
	public void draw() {
		this.windowToBeDecorated.draw(); // Delegation
	}

	public String getDescription() {
		return this.windowToBeDecorated.getDescription(); // Delegation
	}

}

class VerticalScrollBarDecorator extends WindowDecorator {

	public VerticalScrollBarDecorator(Widget windowToBeDecorated) {
		super(windowToBeDecorated);
	}

	@Override
	public void draw() {
		super.draw();
		this.drawVerticalScrollBar();
	}

	@Override
	public String getDescription() {
		return super.getDescription() + ", including vertical scrollbars";
	}

	private void drawVerticalScrollBar() {
		System.out.println("Drawing Vertical ScrollBar");
	}

}

class HorizontalScrollBarDecorator extends WindowDecorator {

	public HorizontalScrollBarDecorator(Widget windowToBeDecorated) {
		super(windowToBeDecorated);
	}

	@Override
	public void draw() {
		super.draw();
		this.drawHorizontalScrollBar();
	}

	@Override
	public String getDescription() {
		return super.getDescription() + ", including horizontal scrollbars";
	}

	private void drawHorizontalScrollBar() {
		System.out.println("Drawing Horizontal ScrollBar");
	}

}

public class Main {

	public static void main(String[] args) {
		System.out.println(":: Decorator ::\n");

		Window decoratedWindow = new HorizontalScrollBarDecorator(new VerticalScrollBarDecorator(new Window()));

		System.out.println(decoratedWindow.getDescription());
	}

}