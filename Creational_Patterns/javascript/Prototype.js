'use strict';

// Vehicle is the base Prototype
class Vehicle {
  constructor() {
    if (this.constructor === Vehicle) {
      throw new TypeError('Cannot construct Abstract instances directly');
    }

    if (this.print === Vehicle.prototype.print) {
      throw new TypeError('Must override method "print()"');
    }

    if (this.clone === Vehicle.prototype.clone) {
      throw new TypeError('Must override method "clone()"');
    }
  }

  print() {
    throw new TypeError('Do not call abstract method "print()" from child.');
  }

  clone() {
    throw new TypeError('Do not call abstract method "clone()" from child.');
  }
}

// Motorcycle is a concrete Prototype
class Motorcycle extends Vehicle {
  constructor(model) {
    super();
    this.model = model;
  }

  print() {
    console.log('Motorcycle');
    console.log('Model: ', this.model, '\n');
  }

  clone() {
    return new Motorcycle(this.model);
  }
}

// Bus is a concrete Prototype
class Bus extends Vehicle {
  constructor(model) {
    super();
    this.model = model;
  }

  print() {
    console.log('Bus');
    console.log('Model: ', this.model, '\n');
  }

  clone() {
    return new Bus(this.model);
  }
}

// Car is a concrete Prototype
class Car extends Vehicle {
  constructor(model) {
    super();
    this.model = model;
  }

  print() {
    console.log('Car');
    console.log('Model: ', this.model, '\n');
  }

  clone() {
    return new Car(this.model);
  }
}

const VehicleType = Object.freeze({
  MOTORCYCLE: Symbol('MOTORCYCLE'),
  BUS:        Symbol('BUS'),
  CAR:        Symbol('CAR')
});

// VehicleFactory is the client
class VehicleFactory {
  constructor() {
    this.vehicles = [];
    this.vehicles[VehicleType.MOTORCYCLE] = new Motorcycle('Harley-Davidson');
    this.vehicles[VehicleType.BUS] = new Motorcycle('Mercedes-Benz');
    this.vehicles[VehicleType.CAR] = new Motorcycle('Ferrari');
  }

  createVehicle(vehicleType) {
    return this.vehicles[vehicleType].clone();
  }
}

console.log(':: Prototype ::\n');

let factory = new VehicleFactory();

let vehicle = factory.createVehicle(VehicleType.MOTORCYCLE);
vehicle.print();

vehicle = factory.createVehicle(VehicleType.BUS);
vehicle.print();

vehicle = factory.createVehicle(VehicleType.CAR);
vehicle.print();
