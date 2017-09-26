#include <iostream>
#include <string>

class Widget
{
public:
	virtual void draw() = 0;
	virtual std::string description() = 0;
};

class Window : public Widget
{
public:
	void draw() override
	{
		std::cout << "Drawing the Window" << std::endl;
	}

	std::string description() override
	{
		return "Window";
	}
};

class WindowDecorator : public Window
{
public:
	WindowDecorator(Widget* windowToBeDecorated)
		: m_WindowToBeDecorated(windowToBeDecorated)
	{
	}

	void draw()
	{
		m_WindowToBeDecorated->draw(); // Delegation
	}

	std::string description()
	{
		return m_WindowToBeDecorated->description(); // Delegation
	}

private:
	Widget* m_WindowToBeDecorated;
};

class VerticalScrollBarDecorator : public WindowDecorator
{
public:
	VerticalScrollBarDecorator(Widget* windowToDecorate)
		: WindowDecorator(windowToDecorate)
	{
	}

	void draw() override
	{
		WindowDecorator::draw();
		drawVerticalScrollBar();
	}

	std::string description() override
	{
		return WindowDecorator::description() + ", including vertical scrollbars";
	}

private:
	void drawVerticalScrollBar()
	{
		std::cout << "Drawing Vertical ScrollBar" << std::endl;
	}
};

class HorizontalScrollBarDecorator : public WindowDecorator
{
public:
	HorizontalScrollBarDecorator(Widget* windowToDecorate)
		: WindowDecorator(windowToDecorate)
	{
	}

	void draw() override
	{
		WindowDecorator::draw();
		drawHorizontalScrollBar();
	}

	std::string description() override
	{
		return WindowDecorator::description() + ", including horizontal scrollbars";
	}

private:
	void drawHorizontalScrollBar()
	{
		std::cout << "Drawing Horizontal ScrollBar" << std::endl;
	}
};

int main()
{
	std::cout << ":: Decorator ::\n" << std::endl;

	Window* decoratedWindow = new HorizontalScrollBarDecorator(new VerticalScrollBarDecorator(new Window()));

	std::cout << decoratedWindow->description() << std::endl;

	system("PAUSE");

	delete decoratedWindow;

	return 0;
}
