import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

enum Color {
	BLACK,
	GREEN,
	ORANGE
}

class Graphics {

	public void setColor(Color color) {
		// sets the current color.
	}

	void fillRect(int x, int y, int w, int h) {
		// draws a rectangle on the screen.
	}

	void fillOval(int x, int y, int w, int h) {
		// draws an ellipse on the screen.
	}

}

class TreeType {
	
	private String name;
	private Color color;

	public TreeType(String name, Color color) {
		this.name = name;
		this.color = color;
	}
	
	public void draw(Graphics g, int x, int y) {
		// Draws the tree on the screen using the X and Y coordinates.
		g.setColor(Color.BLACK);
		g.fillRect(x - 1, y, 3, 5);
		g.setColor(color);
		g.fillOval(x - 5, y, 10, 10);
	}

}

class Tree {

	private int x;
	private int y;
	TreeType type;

	Tree(int x, int y, TreeType type) {
		this.x = x;
		this.y = y;
		this.type = type;
	}

	public void draw(Graphics g) {
		this.type.draw(g, this.x, this.y);
	}

}

class TreeFactory {

	private static Map<String, TreeType> treeTypes = new HashMap<>();

	public static TreeType getTreeType(String name, Color color) {
		TreeType treeType;

		if (treeTypes.containsKey(name)) {
			treeType = treeTypes.get(name);
		} else {
			treeType = new TreeType(name, color);
			treeTypes.put(name, treeType);
		}

		return treeType;
	}

}

class Forest {

	private List<Tree> trees = new ArrayList<>();

	public void plantTree(int x, int y, String name, Color color) {
		TreeType type = TreeFactory.getTreeType(name, color);
		trees.add(new Tree(x, y, type));
	}

	public void paint(Graphics graphics) {
		for (Tree tree : this.trees) {
			tree.draw(graphics);
		}
	}

}

public class Main {

	private static int TREES_TO_DRAW = 1000000;
	private static int TREE_TYPES = 2;

	public static void main(String[] args) {
		System.out.println(":: Flyweight ::\n");

		Forest forest = new Forest();

		for (int i = 0; i < Math.floor(TREES_TO_DRAW / TREE_TYPES); i++) {
			forest.plantTree(2 + i, 2 + i, "Summer Oak", Color.GREEN);
			forest.plantTree(3 + i, 3 + i, "Autumn Oak", Color.ORANGE);
		}

		forest.paint(new Graphics());

		System.out.println(TREES_TO_DRAW + " trees drawn");
	}

}