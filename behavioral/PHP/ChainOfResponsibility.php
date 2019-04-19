<?php

class Planet {
    const MERCURY = 'MERCURY';
    const VENUS = 'VENUS';
    const EARTH = 'EARTH';
    const MARS = 'MARS';
    const JUPITER = 'JUPITER';
    const SATURN = 'SATURN';
    const URANUS = 'URANUS';
    const NEPTUNE = 'NEPTUNE';
}

abstract class PlanetHandler {

    protected $successor;

    public function setSuccessor($successor) {
        $this->successor = $successor;
    }

    public abstract function handleRequest($request);

}

class MercuryHandler extends PlanetHandler {

    // override
    public function handleRequest($request) {
        if ($request == Planet::MERCURY) {
            echo "MercuryHandler handles " . $request . "\n";
            echo "Mercury is hot.\n\n";
        } else {
            echo "MercuryHandler doesn't handle " . $request . "\n";
            if ($this->successor != null) {
                $this->successor->handleRequest($request);
            }
        }
    }

}

class VenusHandler extends PlanetHandler {

    // override
    public function handleRequest($request) {
        if ($request == Planet::VENUS) {
            echo "VenusHandler handles " . $request . "\n";
            echo "Venus is poisonous.\n\n";
        } else {
            echo "VenusHandler doesn't handle " . $request . "\n";
            if ($this->successor != null) {
                $this->successor->handleRequest($request);
            }
        }
    }

}

class EarthHandler extends PlanetHandler {

    // override
    public function handleRequest($request) {
        if ($request == Planet::EARTH) {
            echo "EarthHandler handles " . $request . "\n";
            echo "Earth is comfortable.\n\n";
        } else {
            echo "EarthHandler doesn't handle " . $request . "\n";
            if ($this->successor != null) {
                $this->successor->handleRequest($request);
            }
        }
    }

}

function setUpChain() {
    $mercuryHandler = new MercuryHandler();
    $venusHandler = new VenusHandler();
    $earthHandler = new EarthHandler();

    $mercuryHandler->setSuccessor($venusHandler);
    $venusHandler->setSuccessor($earthHandler);

    return $mercuryHandler;
}

echo ":: Chain of Responsability ::\n\n";

$chain = setUpChain();
$chain->handleRequest(Planet::VENUS);
$chain->handleRequest(Planet::MERCURY);
$chain->handleRequest(Planet::EARTH);
$chain->handleRequest(Planet::JUPITER);

?>