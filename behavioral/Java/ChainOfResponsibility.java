enum Planet {
	MERCURY,
	VENUS,
	EARTH,
	MARS,
	JUPITER,
	SATURN,
	URANUS,
	NEPTUNE
}

abstract class PlanetHandler {

	protected PlanetHandler successor;

	public void setSuccessor(PlanetHandler successor) {
		this.successor = successor;
	}

	public abstract void handleRequest(Planet request);

}

class MercuryHandler extends PlanetHandler {

	@Override
	public void handleRequest(Planet request) {
		if (request == Planet.MERCURY) {
			System.out.println("MercuryHandler handles " + request);
			System.out.println("Mercury is hot.\n");
		} else {
			System.out.println("MercuryHandler doesn't handle " + request);
			if (this.successor != null) {
				this.successor.handleRequest(request);
			}
		}
	}

}

class VenusHandler extends PlanetHandler {

	@Override
	public void handleRequest(Planet request) {
		if (request == Planet.VENUS) {
			System.out.println("VenusHandler handles " + request);
			System.out.println("Venus is poisonous.\n");
		} else {
			System.out.println("VenusHandler doesn't handle " + request);
			if (this.successor != null) {
				this.successor.handleRequest(request);
			}
		}
	}

}

class EarthHandler extends PlanetHandler {

	@Override
	public void handleRequest(Planet request) {
		if (request == Planet.EARTH) {
			System.out.println("EarthHandler handles " + request);
			System.out.println("Earth is comfortable.\n");
		} else {
			System.out.println("EarthHandler doesn't handle " + request);
			if (this.successor != null) {
				this.successor.handleRequest(request);
			}
		}
	}

}

public class Main {

	public static void main(String[] args) {
		System.out.println(":: Chain of Responsability ::\n");

		PlanetHandler chain = setUpChain();
		chain.handleRequest(Planet.VENUS);
		chain.handleRequest(Planet.MERCURY);
		chain.handleRequest(Planet.EARTH);
		chain.handleRequest(Planet.JUPITER);
	}

	private static PlanetHandler setUpChain() {
		PlanetHandler mercuryHandler = new MercuryHandler();
		PlanetHandler venusHandler = new VenusHandler();
		PlanetHandler earthHandler = new EarthHandler();

		mercuryHandler.setSuccessor(venusHandler);
		venusHandler.setSuccessor(earthHandler);

		return mercuryHandler;
	}

}
