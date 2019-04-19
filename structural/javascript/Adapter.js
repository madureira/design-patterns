const RCAPlug = {
  YELLOW: 'YELLOW',
  RED: 'RED',
  WHITE: 'WHITE'
};

// Legacy component
class RCAConnector {

  constructor(yellowPlug, redPlug, whitePlug) {
    this.video = yellowPlug;
    this.rightAudio = redPlug;
    this.leftAudio = whitePlug;
  }

  connectOnRCABoard() {
    if (this.video === RCAPlug.YELLOW && this.rightAudio === RCAPlug.RED && this.leftAudio === RCAPlug.WHITE) {
      console.log('RCAConnector connected correctly!');
      this.isRCAConnected = true;
    } else {
      console.log('ERROR: cable connected in wrong order!');
      this.isRCAConnected = false;
    }
  }

}

// Adapter wrapper
class ConnectorAdapter extends RCAConnector {

  constructor(yellowPlug, redPlug, whitePlug) {
    super(yellowPlug, redPlug, whitePlug);
  }

  connect() {
    this.connectOnRCABoard();
    console.log('HDMI connected to the board through the RCA adapter!');
  }

}

console.log(':: Adapter ::\n');

const hdmi = new ConnectorAdapter(RCAPlug.YELLOW, RCAPlug.RED, RCAPlug.WHITE);
hdmi.connect();