'use strict';

class Shape {
  constructor() {
  }

  draw() {
  }
}

class Circle extends Shape {
  constructor() {
    super();
  }

  draw() {
    console.log('Circle: draw');
  }
}

class Ellipse extends Shape {
  constructor() {
    super();
  }

  draw() {
    console.log('Ellipse: draw');
  }
}

class Square extends Shape {
  constructor() {
    super();
  }

  draw() {
    console.log('Square: draw');
  }
}

class Rectangle extends Shape {
  constructor() {
    super();
  }

  draw() {
    console.log('Rectangle: draw');
  }
}

class ShapeFactory {
  contructor() {
  }

  createCurvedInstance() {
  }

  createStraightInstance() {
  }
}

class SimpleShapeFactory extends ShapeFactory {
  constructor() {
    super();
  }

  createCurvedInstance() {
    return new Circle();
  }

  createStraightInstance() {
    return new Square();
  }
}

class ComplexShapeFactory extends ShapeFactory {
  constructor() {
    super();
  }

  createCurvedInstance() {
    return new Ellipse();
  }

  createStraightInstance() {
    return new Rectangle();
  }
}

console.log(':: Abstract Factory ::\n');

let shapes = [];

let simpleFactory = new SimpleShapeFactory();
shapes.push(simpleFactory.createCurvedInstance());
shapes.push(simpleFactory.createStraightInstance());

let complexFactory = new ComplexShapeFactory();
shapes.push(complexFactory.createCurvedInstance());
shapes.push(complexFactory.createStraightInstance());

shapes.forEach((shape) => {
  shape.draw();
});
