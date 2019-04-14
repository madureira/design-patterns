#include <iostream>
#include <vector>
#include <map>

enum class Color
{
	BLACK,
	GREEN,
	ORANGE
};

class Graphics
{
public:
	Graphics() {
	}

	void setColor(Color color)
	{
		// sets the current color.
	}

	void fillRect(int x, int y, int w, int h)
	{
		// draws a rectangle on the scrren.
	}

	void fillOval(int x, int y, int w, int h)
	{
		// draws an ellipse on the screen.
	}
};


class TreeType
{
private:
	std::string m_Name;
	Color m_Color;

public:
	TreeType(std::string name, Color color) : m_Name(name), m_Color(color) {
	}

	void draw(Graphics* g, int x, int y)
	{
		// Draws the tree on the screen using the X and Y coordinates.
		g->setColor(Color::BLACK);
		g->fillRect(x - 1, y, 3, 5);
		g->setColor(this->m_Color);
		g->fillOval(x - 5, y - 10, 10, 10);
	}
};

class Tree
{
private:
	int m_X;
	int m_Y;
	TreeType* m_Type;

public:
	Tree(int x, int y, TreeType* type) : m_X(x), m_Y(y), m_Type(type) {
	}

	void draw(Graphics* g)
	{
		this->m_Type->draw(g, this->m_X, this->m_Y);
	}
};

class TreeFactory
{
private:
	static std::map<std::string, TreeType*> m_TreeTypes;

public:
	static TreeType* getTreeType(std::string name, Color color)
	{
		std::map<std::string, TreeType*>::iterator it = m_TreeTypes.find(name);

		TreeType* treeType;

		if (it != m_TreeTypes.end())
		{
			treeType = it->second;
		}
		else
		{
			treeType = new TreeType(name, color);
			m_TreeTypes.insert({ name, treeType });
		}

		return treeType;
	}
};

std::map<std::string, TreeType*> TreeFactory::m_TreeTypes;

class Forest
{
private:
	std::vector<Tree*> m_Trees;

public:
	void plantTree(int x, int y, std::string name, Color color)
	{
		TreeType* type = TreeFactory::getTreeType(name, color);
		m_Trees.push_back(new Tree(x, y, type));
	}

	void paint(Graphics* graphics)
	{
		for (Tree* tree : this->m_Trees) {
			tree->draw(graphics);
		}
	}
};

int main()
{
	static int TREES_TO_DRAW = 1000000;
	static int TREE_TYPES = 2;

	Forest forest;

	for (int i = 0; i < floor(TREES_TO_DRAW / TREE_TYPES); i++) {
		forest.plantTree(2 + i, 2 + i, "Summer Oak", Color::GREEN);
		forest.plantTree(3 + i, 3 + i, "Autumn Oak", Color::ORANGE);
	}

	forest.paint(new Graphics());

	std::cout << TREES_TO_DRAW << " trees drawn" << std::endl;

	system("PAUSE");

	return 0;
}