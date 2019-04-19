const Color = {
  BLACK: 'BLACK',
  GREEN: 'GREEN',
  ORANGE: 'ORANGE'
};

class Graphics {

  setColor(color) {
    // sets the current color.
  }

  fillRect(x, y, w, h) {
    // draws a rectangle on the screen.
  }

  fillOval(x, y, w, h) {
    // draws an ellipse on the screen.
  }

}

class TreeType {

  constructor(name, color) {
    this.name = name;
    this.color = color;
  }

  draw(graphics, x, y) {
    // Draws the tree on the screen using the X and Y coordinates.
    graphics.setColor(Color.BLACK);
    graphics.fillRect(x - 1, y, 3, 5);
    graphics.setColor(this.color);
    graphics.fillOval(x - 5, y, 10, 10);
  }

}

class Tree {

  constructor(x, y, type) {
    this.x = x;
    this.y = y;
    this.type = type;
  }

  draw(graphics) {
    this.type.draw(graphics, this.x, this.y);
  }

}

class TreeFactory {

  static getTreeType(name, color) {
    let treeType;

    if (TreeFactory.treeTypes[name]) {
      treeType = TreeFactory.treeTypes[name];
    } else {
      treeType = new TreeType(name, color);
      TreeFactory.treeTypes[name] = treeType;
    }

    return treeType;
  }

}
TreeFactory.treeTypes = {};

class Forest {

  constructor() {
    this.trees = [];
  }

  plantTree(x, y, name, color) {
    const type = TreeFactory.getTreeType(name, color);
    this.trees.push(new Tree(x, y, type));
  }

  paint(graphics) {
    this.trees.forEach(tree => {
      tree.draw(graphics);
    });
  }

}

const TREES_TO_DRAW = 1000000;
const TREE_TYPES = 2;

console.log(':: Flyweight ::\n');

const forest = new Forest();

for (let i = 0; i < Math.floor(TREES_TO_DRAW / TREE_TYPES); i++) {
  forest.plantTree(2 + i, 2 + i, 'Summer Oak', Color.GREEN);
  forest.plantTree(3 + i, 3 + i, 'Autumn Oak', Color.ORANGE);
}

forest.paint(new Graphics());

console.log(TREES_TO_DRAW + ' trees drawn');