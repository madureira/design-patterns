const Planet = {
  MERCURY: 'MERCURY',
  VENUS: 'VENUS',
  EARTH: 'EARTH',
  MARS: 'MARS',
  JUPITER: 'JUPITER',
  SATURN: 'SATURN',
  URANUS: 'URANUS',
  NEPTUNE: 'NEPTUNE'
};

class PlanetHandler {

  constructor() {
    if (this.constructor === PlanetHandler) {
      throw new TypeError('Cannot construct Abstract instances directly');
    }

    if (this.handleRequest === PlanetHandler.prototype.handleRequest) {
      throw new TypeError('Must override method "handleRequest()"');
    }

    this.successor = null;
  }
  
  setSuccessor(successor) {
    this.successor = successor;
  }

  handleRequest() {
    throw new TypeError('Do not call abstract method "handleRequest()" from child.');
  }

}

class MercuryHandler extends PlanetHandler {

  handleRequest(request) {
    if (request === Planet.MERCURY) {
      console.log("MercuryHandler handles " + request);
      console.log("Mercury is hot.\n");
    } else {
      console.log("MercuryHandler doesn't handle " + request);
      if (this.successor !== null) {
        this.successor.handleRequest(request);
      }
    }
  }

}

class VenusHandler extends PlanetHandler {

  handleRequest(request) {
    if (request === Planet.VENUS) {
      console.log("VenusHandler handles " + request);
      console.log("Venus is poisonous.\n");
    } else {
      console.log("VenusHandler doesn't handle " + request);
      if (this.successor !== null) {
        this.successor.handleRequest(request);
      }
    }
  }

}

class EarthHandler extends PlanetHandler {

  handleRequest(request) {
    if (request === Planet.EARTH) {
      console.log("EarthHandler handles " + request);
      console.log("Earth is comfortable.\n");
    } else {
      console.log("EarthHandler doesn't handle " + request);
      if (this.successor !== null) {
        this.successor.handleRequest(request);
      }
    }
  }

}

function setUpChain() {
  const mercuryHandler = new MercuryHandler();
  const venusHandler = new VenusHandler();
  const earthHandler = new EarthHandler();

  mercuryHandler.setSuccessor(venusHandler);
  venusHandler.setSuccessor(earthHandler);

  return mercuryHandler;
}

console.log(":: Chain of Responsability ::\n");

const chain = setUpChain();
chain.handleRequest(Planet.VENUS);
chain.handleRequest(Planet.MERCURY);
chain.handleRequest(Planet.EARTH);
chain.handleRequest(Planet.JUPITER);