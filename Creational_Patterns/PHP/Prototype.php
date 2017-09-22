<?php

// Vehicle is the base Prototype
interface Vehicle {

    public function show();

    public function clonePrototype();

}

// Motorcycle is a concrete Prototype
class Motorcycle implements Vehicle {

    private $model;

    public function __construct($model) {
        $this->model = $model;
    }

    public function show() {
        echo "Motorcycle\n";
        echo "Model: ". $this->model ."\n\n";
    }

    public function clonePrototype() {
        return new Motorcycle($this->model);
    }

}

// Bus is a concrete Prototype
class Bus implements Vehicle {

    private $model;

    public function __construct($model) {
        $this->model = $model;
    }

    public function show() {
        echo "Bus\n";
        echo "Model: ". $this->model ."\n\n";
    }

    public function clonePrototype() {
        return new Bus($this->model);
    }

}

// Car is a concrete Prototype
class Car implements Vehicle {

    private $model;

    public function __construct($model) {
        $this->model = $model;
    }

    public function show() {
        echo "Car\n";
        echo "Model: ". $this->model ."\n\n";
    }

    public function clonePrototype() {
        return new Car($this->model);
    }

}

// VehicleFactory is the client
class VehicleFactory {

    private $vehicles;

    public function __construct() {
        $this->vehicles = array();
        $this->vehicles['MOTORCYCLE'] = new Motorcycle('Harley-Davidson');
        $this->vehicles['BUS'] = new Bus('Mercedes-Benz');
        $this->vehicles['CAR'] = new Bus('Ferrari');
    }

    public function createVehicle($vehicleType) {
        return $this->vehicles[$vehicleType]->clonePrototype();
    }

}

echo ":: Prototype ::\n\n";

$factory = new VehicleFactory();

$vehicle = $factory->createVehicle('MOTORCYCLE');
$vehicle->show();

$vehicle = $factory->createVehicle('BUS');
$vehicle->show();

$vehicle = $factory->createVehicle('CAR');
$vehicle->show();

?>
