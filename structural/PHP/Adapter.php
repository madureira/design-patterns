<?php

class RCAPlug {
    const YELLOW = 'YELLOW';
    const RED = 'RED';
    const WHITE = 'WHITE';
}

// Legacy component
class RCAConnector {

    private $isRCAConnected;
    private $video;
    private $rightAudio;
    private $leftAudio;

    public function __construct($yellowPlug, $redPlug, $whitePlug) {
        $this->video = $yellowPlug;
        $this->rightAudio = $redPlug;
        $this->leftAudio = $whitePlug;
    }

    public function connectOnRCABoard() {
        if ($this->video == RCAPlug::YELLOW && $this->rightAudio == RCAPlug::RED && $this->leftAudio == RCAPlug::WHITE) {
            echo "RCAConnector connected correctly!\n";
            $this->isRCAConnected = true;
        } else {
            echo "ERROR: cable connected in wrong order!\n";
            $this->isRCAConnected = false;
        }
    }

}

// Desired interface
interface HDMIConnector {

    public function connect();

}

// Adapter wrapper
class ConnectorAdapter extends RCAConnector implements HDMIConnector {

    public function __construct($yellowPlug, $redPlug, $whitePlug) {
        parent::__construct($yellowPlug, $redPlug, $whitePlug);
    }

    public function connect() {
        $this->connectOnRCABoard();
        echo "HDMI connected to the board through the RCA adapter!\n";
    }

}

echo ":: Adapter ::\n\n";

$hdmi = new ConnectorAdapter(RCAPlug::YELLOW, RCAPlug::RED, RCAPlug::WHITE);
$hdmi->connect();

?>