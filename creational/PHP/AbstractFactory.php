<?php

interface Shape {
  public function draw();
}

class Circle implements Shape {

  public function draw() {
    echo "Circle: draw\n";
  }

}

class Ellipse implements Shape {

  public function draw() {
    echo "Ellipse: draw\n";
  }

}

class Square implements Shape {

  public function draw() {
    echo "Square: draw\n";
  }

}

class Rectangle implements Shape {

  public function draw() {
    echo "Rectangle: draw\n";
  }

}

interface ShapeFactory {

  public function createCurvedInstance();

  public function createStraightInstance();

}

class SimpleShapeFactory implements ShapeFactory {

  public function createCurvedInstance() {
    return new Circle();
  }

  public function createStraightInstance() {
    return new Square();
  }

}

class ComplexShapeFactory implements ShapeFactory {

  public function createCurvedInstance() {
    return new Ellipse();
  }

  public function createStraightInstance() {
    return new Rectangle();
  }

}

echo ":: Abstract Factory ::\n\n";

$shapes = [];

$simpleFactory = new SimpleShapeFactory();
array_push($shapes, $simpleFactory->createCurvedInstance());
array_push($shapes, $simpleFactory->createStraightInstance());

$complexFactory = new ComplexShapeFactory();
array_push($shapes, $complexFactory->createCurvedInstance());
array_push($shapes, $complexFactory->createStraightInstance());

foreach ($shapes as $shape) {
  $shape->draw();
}

?>
