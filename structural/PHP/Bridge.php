<?php

interface Fuel {

    public function getType();

}

class Diesel implements Fuel {

    public function getType() {
        return 'Diesel';
    }

}

class Gasoline implements Fuel {

    public function getType() {
        return 'Gasoline';
    }

}

interface Car {

    public function showInfo();

}

class Jeep implements Car {

    private $fuel;

    public function __construct($fuel) {
        $this->fuel = $fuel;
    }

    public function showInfo() {
        echo "\nModel: Jeep";
        echo "\nFuel: " . $this->fuel->getType() . "\n";
    }

}

class Subaru implements Car {

    private $fuel;

    public function __construct($fuel) {
        $this->fuel = $fuel;
    }

    public function showInfo() {
        echo "\nModel: Subaru";
        echo "\nFuel: " . $this->fuel->getType() . "\n";
    }

}

echo ":: Bridge ::\n";

$diesel = new Diesel();
$gasoline = new Gasoline();

$jeep = new Jeep($diesel);
$subaru = new Subaru($gasoline);

$jeep->showInfo();
$subaru->showInfo();

?>