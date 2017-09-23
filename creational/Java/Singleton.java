class Logger {

	private static final Logger INSTANCE = new Logger();

	private Logger() { } // private constructor

	public static Logger getInstance() {
		return INSTANCE;
	}

	public void info(String message) {
		System.out.println("INFO: " + message);
	}

	public void error(String message) {
		System.out.println("ERROR: " + message);
	}

}

class Main {

	public static void main(String[] args) {
		System.out.println(":: Singleton ::\n");

		//illegal construct
		//Compile Time Error: The constructor Logger() is not visible
		//Logger logger = new Logger();

		Logger log = Logger.getInstance(); // uses the single instance.
		log.info("some info message");
		log.error("some error message");
	}

}
