'use strict';

class Car {
  constructor() {
    if (this.constructor === Car) {
      throw new TypeError('Cannot construct Abstract instances directly');
    }

    if (this.engineStart === Car.prototype.engineStart) {
      throw new TypeError('Must override method "engineStart()"');
    }

    if (this.engineStop === Car.prototype.engineStop) {
      throw new TypeError('Must define method "engineStop()"');
    }
  }

  engineStart() {
    throw new TypeError('Do not call abstract method "engineStart()" from child.');
  }

  engineStop() {
    throw new TypeError('Do not call abstract method "engineStop()" from child.');
  }
}

class Porsche extends Car {
  constructor() {
    super();
  }

  engineStart() {
    console.log('Porsche started!');
  }

  engineStop() {
    console.log('Porsche stopped!');
  }
}

class ModelS extends Car {
  constructor() {
    super();
  }

  engineStart() {
    console.log('ModelS started!');
  }

  engineStop() {
    console.log('ModelS stopped!');
  }
}

const Fuel = Object.freeze({
  Electrical: Symbol('Electrical'),
  Gasoline:   Symbol('Gasoline')
});

class CarFactory {
  static getInstance(fuel) {
    if (fuel === Fuel.Gasoline) {
      return new Porsche();
    } else if (fuel === Fuel.Electrical) {
      return new ModelS();
    }
    return null;
  }
}

console.log(':: Factory Method ::\n');

let gasolineCar = CarFactory.getInstance(Fuel.Gasoline);
gasolineCar.engineStart();

let electricalCar = CarFactory.getInstance(Fuel.Electrical);
electricalCar.engineStart();

gasolineCar.engineStop();
electricalCar.engineStop();
