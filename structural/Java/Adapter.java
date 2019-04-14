enum RCAPlug {
	YELLOW,
	RED,
	WHITE
};

// Legacy component
class RCAConnector {

	private boolean isRCAConnected;
	private RCAPlug video;
	private RCAPlug rightAudio;
	private RCAPlug leftAudio;

	public RCAConnector(RCAPlug yellowPlug, RCAPlug redPlug, RCAPlug whitePlug) {
		this.video = yellowPlug;
		this.rightAudio = redPlug;
		this.leftAudio = whitePlug;
	}

	public void connectOnRCABoard() {
		if (video == RCAPlug.YELLOW && rightAudio == RCAPlug.RED && leftAudio == RCAPlug.WHITE) {
			System.out.println("RCAConnector connected correctly!");
			this.isRCAConnected = true;
		} else {
			System.out.println("ERROR: cable connected in wrong order!");
			this.isRCAConnected = false;
		}
	}

}

// Desired interface
interface HDMIConnector {

	public void connect();

}

// Adapter wrapper
class ConnectorAdapter extends RCAConnector implements HDMIConnector {

	ConnectorAdapter(RCAPlug yellowPlug, RCAPlug redPlug, RCAPlug whitePlug) {
		super(yellowPlug, redPlug, whitePlug);
	}

	@Override
	public void connect() {
		this.connectOnRCABoard();
		System.out.println("HDMI connected to the board through the RCA adapter!");
	}

}

public class Main {

	public static void main(String[] args) {
		System.out.println(":: Adapter ::\n");

		HDMIConnector hdmi = new ConnectorAdapter(RCAPlug.YELLOW, RCAPlug.RED, RCAPlug.WHITE);
		hdmi.connect();
	}

}