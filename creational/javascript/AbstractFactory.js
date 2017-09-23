'use strict';

class Shape {
  constructor() {
    if (this.constructor === Shape) {
      throw new TypeError('Cannot construct Abstract instances directly');
    }

    if (this.draw === Shape.prototype.draw) {
      throw new TypeError('Must override method "draw()"');
    }
  }

  draw() {
    throw new TypeError('Do not call abstract method "draw()" from child.');
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
    if (this.constructor === ShapeFactory) {
      throw new TypeError('Cannot construct Abstract instances directly');
    }

    if (this.createCurvedInstance === ShapeFactory.prototype.createCurvedInstance) {
      throw new TypeError('Must override method "createCurvedInstance()"');
    }

    if (this.createStraightInstance === ShapeFactory.prototype.createStraightInstance) {
      throw new TypeError('Must define method "createStraightInstance()"');
    }
  }

  createCurvedInstance() {
    throw new TypeError('Do not call abstract method "createCurvedInstance()" from child.');
  }

  createStraightInstance() {
    throw new TypeError('Do not call abstract method "createStraightInstance()" from child.');
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
