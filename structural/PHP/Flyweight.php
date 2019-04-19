<?php

define('TREES_TO_DRAW', 1000000);
define('TREE_TYPES', 2);

class Color {

    const BLACK = 'BLACK';
    const GREEN = 'GREEN';
    const ORANGE = 'ORANGE';

}

class Graphics {

    public function setColor($color) {
        // sets the current color.
    }

    public function fillRect($x, $y, $w, $h) {
        // draws a rectangle on the screen.
    }

    public function fillOval($x, $y, $w, $h) {
        // draws an ellipse on the screen.
    }

}

class TreeType {

    private $name;
    private $color;

    public function __construct($name, $color) {
        $this->name = $name;
        $this->color = $color;
    }

    public function draw($graphics, $x, $y) {
        // Draws the tree on the screen using the X and Y coordinates.
        $graphics->setColor(Color::BLACK);
        $graphics->fillRect($x - 1, $y, 3, 5);
        $graphics->setColor($this->color);
        $graphics->fillOval($x - 5, $y, 10, 10);
    }

}

class Tree {

    private $x;
    private $y;

    public function __construct($x, $y, $type) {
        $this->x = $x;
        $this->y = $y;
        $this->type = $type;
    }

    public function draw($graphics) {
        $this->type->draw($graphics, $this->x, $this->y);
    }

}

class TreeFactory {

  private static $treeTypes = array();

  public static function getTreeType($name, $color) {
      $treeType = null;

      if (array_key_exists($name, self::$treeTypes)) {
          $treeType = self::$treeTypes[$name];
      } else {
          $treeType = new TreeType($name, $color);
          self::$treeTypes[$name] = &$treeType;
      }

      return $treeType;
  }

}

class Forest {

    private $trees = array();

    public function plantTree($x, $y, $name, $color) {
        $type = TreeFactory::getTreeType($name, $color);
        array_push($this->trees, new Tree($x, $y, $type));
    }

    public function paint($graphics) {
        foreach ($this->trees as &$tree) {
            $tree->draw($graphics);
        }
    }

}

echo ":: Flyweight ::\n\n";

$forest = new Forest();

for ($i = 0; $i < floor(TREES_TO_DRAW / TREE_TYPES); $i++) {
    $forest->plantTree(2 + $i, 2 + $i, 'Summer Oak', Color::GREEN);
    $forest->plantTree(3 + $i, 3 + $i, 'Autumn Oak', Color::ORANGE);
}

$forest->paint(new Graphics());

echo TREES_TO_DRAW . " trees drawn\n";

?>