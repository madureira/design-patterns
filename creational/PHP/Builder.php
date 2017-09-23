<?php

// computer parts
class Processor {

    private $model;

    public function __construct($model) {
        $this->model = $model;
    }

    public function getModel() {
        return $this->model;
    }

}

class MemoryRAM {

    private $capacity;

    public function __construct($capacity) {
        $this->capacity = $capacity;
    }

    public function getCapacity() {
        return $this->capacity;
    }

}

class HardDrive {

    private $space;

    public function __construct($space) {
        $this->space = $space;
    }

    public function getSpace() {
        return $this->space;
    }

}

// Final product
class Computer {

    private $description;
    private $processor;
    private $memoryRAM;
    private $hardDrive;

    public function __construct($description) {
        $this->description = $description;
    }

    public function setProcessor(Processor $processor) {
        $this->processor = $processor;
    }

    public function setMemoryRAM(MemoryRAM $memoryRAM) {
        $this->memoryRAM = $memoryRAM;
    }

    public function setHardDrive(HardDrive $hardDrive) {
        $this->hardDrive = $hardDrive;
    }

    public function show() {
        echo "\n--------------------------------\n";
        echo "Description: " . $this->description . "\n";
        echo "Processor model: " . $this->processor->getModel() . "\n";
        echo "Memory RAM capacity: " . $this->memoryRAM->getCapacity() . "\n";
        echo "Hard Drive space: " . $this->hardDrive->getSpace() . "\n";
    }

}

// Create an abstract 'Builder' class
abstract class ComputerBuilder {

    protected $computer;

    public function getComputer() {
        return $this->computer;
    }

    abstract protected function buildProcessor();
    abstract protected function buildMemoryRAM();
    abstract protected function buildHardDrive();

}

class DellBuilder extends ComputerBuilder {

    public function __construct() {
        $this->computer = new Computer('DELL Inspiron');
    }

    public function buildProcessor() {
        $this->computer->setProcessor(new Processor('i7'));
    }

    public function buildMemoryRAM() {
        $this->computer->setMemoryRAM(new MemoryRAM(16));
    }

    public function buildHardDrive() {
        $this->computer->setHardDrive(new HardDrive(500));
    }

}

class AppleBuilder extends ComputerBuilder {

    public function __construct() {
        $this->computer = new Computer('Apple iMac');
    }

    public function buildProcessor() {
        $this->computer->setProcessor(new Processor('i7'));
    }

    public function buildMemoryRAM() {
        $this->computer->setMemoryRAM(new MemoryRAM(16));
    }

    public function buildHardDrive() {
        $this->computer->setHardDrive(new HardDrive(256));
    }

}

// Director is responsible for the whole process
class Director {

    private $builder;

    public function setBuilder(ComputerBuilder $builder) {
        $this->builder = $builder;
    }

    public function mount() {
        $this->builder->buildProcessor();
        $this->builder->buildMemoryRAM();
        $this->builder->buildHardDrive();

        return $this->builder->getComputer();
    }

}

echo ":: Builder ::\n\n";

$director = new Director(); // A director who controls the process

// Concrete builders
$dellBuilder = new DellBuilder();
$appleBuilder = new AppleBuilder();

// building a DELL Inspiron computer
$director->setBuilder($dellBuilder);
$inspiron = $director->mount(); // Final product

// building a Apple Mac computer
$director->setBuilder($appleBuilder);
$mac = $director->mount();  // Final product

// Show specifications
$inspiron->show();
$mac->show();

?>
