// Interface
class Fuel {

  constructor() {
    if (this.constructor === Fuel) {
      throw new TypeError('Cannot construct Abstract instances directly');
    }

    if (this.type === Fuel.prototype.type) {
      throw new TypeError('Must override method "type()"');
    }
  }

  type() {
    throw new TypeError('Do not call abstract method "type()" from child.');
  }

}

class Diesel extends Fuel {

  // Implements abstract parent method
  type() {
    return "Diesel";
  }

}

class Gasoline extends Fuel {

  // Implements abstract parent method
  type() {
    return "Gasoline";
  }

}

// Interface
class Car {

  constructor() {
    if (this.constructor === Car) {
      throw new TypeError('Cannot construct Abstract instances directly');
    }

    if (this.showInfo === Car.prototype.showInfo) {
      throw new TypeError('Must override method "showInfo()"');
    }
  }

  showInfo() {
    throw new TypeError('Do not call abstract method "showInfo()" from child.');
  }

}

class Jeep extends Car {

  constructor(fuel) {
    super();
    this.fuel = fuel;
  }

  // Implements abstract parent method
  showInfo() {
    console.log("\nModel: Jeep");
    console.log("Fuel: " + this.fuel.type());
  }

}

class Subaru extends Car {

  constructor(fuel) {
    super();
    this.fuel = fuel;
  }

  showInfo() {
    console.log("\nModel: Subaru");
    console.log("Fuel: " + this.fuel.type());
  }

}

console.log(":: Bridge ::\n");

const diesel = new Diesel();
const gasoline = new Gasoline();

const jeep = new Jeep(diesel);
const subaru = new Subaru(gasoline);

jeep.showInfo();
subaru.showInfo();