'use strict';

// computer parts
class Processor {
  constructor(model) {
    this.model = model;
  }

  getModel() {
    return this.model;
  }
}

class MemoryRAM {
  constructor(capacity) {
    this.capacity = capacity;
  }

  getCapacity() {
    return this.capacity;
  }
}

class HardDrive {
  constructor(space) {
    this.space = space;
  }

  getSpace() {
    return this.space;
  }
}

// Final product
class Computer {
  constructor(description) {
    this.description = description;
    this.processor = {};
    this.memoryRAM = {};
    this.hardDrive = {};
  }

  setProcessor(processor) {
    this.processor = processor;
  }

  setMemoryRAM(memoryRAM) {
    this.memoryRAM = memoryRAM;
  }

  setHardDrive(hardDrive) {
    this.hardDrive = hardDrive;
  }

  show() {
    console.log('\n--------------------------------');
    console.log('Description: ', this.description);
    console.log('Processor model: ', this.processor.getModel());
    console.log('Memory RAM capacity: ', this.memoryRAM.getCapacity());
    console.log('Hard Drive space: ', this.hardDrive.getSpace());
  }
}

// Create an abstract 'Builder' class
class ComputerBuilder {
  constructor() {
    if (this.constructor === ComputerBuilder) {
      throw new TypeError('Cannot construct Abstract instances directly');
    }

    if (this.buildProcessor === ComputerBuilder.prototype.buildProcessor) {
      throw new TypeError('Must override method "buildProcessor()"');
    }

    if (this.buildMemoryRAM === ComputerBuilder.prototype.buildMemoryRAM) {
      throw new TypeError('Must override method "buildMemoryRAM()"');
    }

    if (this.buildHardDrive === ComputerBuilder.prototype.buildHardDrive) {
      throw new TypeError('Must override method "buildHardDrive()"');
    }

    this.computer = {};
  }

  getComputer() {
    return this.computer;
  }

  buildProcessor() {
    throw new TypeError('Do not call abstract method "buildProcessor()" from child.');
  }

  buildMemoryRAM() {
    throw new TypeError('Do not call abstract method "buildMemoryRAM()" from child.');
  }

  buildHardDrive() {
    throw new TypeError('Do not call abstract method "buildHardDrive()" from child.');
  }
}

class DellBuilder extends ComputerBuilder {
  constructor() {
    super();
    this.computer = new Computer('DELL Inspiron');
  }

  buildProcessor() {
    this.computer.setProcessor(new Processor('i7'));
  }

  buildMemoryRAM() {
    this.computer.setMemoryRAM(new MemoryRAM(16));
  }

  buildHardDrive() {
    this.computer.setHardDrive(new HardDrive(500));
  }
}

class AppleBuilder extends ComputerBuilder {
  constructor() {
    super();
    this.computer = new Computer('Apple iMac');
  }

  buildProcessor() {
    this.computer.setProcessor(new Processor('i5'));
  }

  buildMemoryRAM() {
    this.computer.setMemoryRAM(new MemoryRAM(8));
  }

  buildHardDrive() {
    this.computer.setHardDrive(new HardDrive(256));
  }
}

// Director is responsible for the whole process
class Director {
  constructor() {
    this.builder = {};
  }

  setBuilder(builder) {
    this.builder = builder;
  }

  contruct() {
    this.builder.buildProcessor();
    this.builder.buildMemoryRAM();
    this.builder.buildHardDrive();

    return this.builder.getComputer();
  }
}

console.log(':: Builder ::\n');

let director = new Director(); // A director who controls the process

// Concrete builders
let dellBuilder = new DellBuilder();
let appleBuilder = new AppleBuilder();

// building a DELL Inspiron computer
director.setBuilder(dellBuilder);
let inspiron = director.contruct(); // Final product

// building a Apple Mac computer
director.setBuilder(appleBuilder);
let mac = director.contruct(); // Final product

// Show specifications
inspiron.show();
mac.show();
