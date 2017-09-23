<?php

abstract class Car {

    abstract protected function engineStart();

    abstract protected function engineStop();

}

class Porsche extends Car {

    public function engineStart() {
        echo "Porsche started!\n";
    }

    public function engineStop() {
        echo "Porsche stopped!\n";
    }

}

class ModelS extends Car {

    public function engineStart() {
        echo "ModelS started!\n";
    }

    public function engineStop() {
        echo "ModelS stopped!\n";
    }

}

class CarFactory {

    public static function getInstance($fuel) {
        if ($fuel == 'GASOLINE') {
            return new Porsche();
        } else if ($fuel == 'ELECTRICAL') {
            return new ModelS();
        }

        return NULL;
    }

}

echo ":: Factory Method ::\n\n";

$gasolineCar = CarFactory::getInstance('GASOLINE');
$gasolineCar->engineStart();

$electricalCar = CarFactory::getInstance('ELECTRICAL');
$electricalCar->engineStart();

$gasolineCar->engineStop();
$electricalCar->engineStop();

?>
