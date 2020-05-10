<?php

abstract class GameActor {

    public function jump() {
        echo "You jumped in a hole and died :(\n";
    }

    public function fire() {
        echo "You killed the enemy :)\n";
    }

}

class Player extends GameActor {
}

interface Command {

    public function execute($actor);

}

class JumpCommand implements Command {

    // override
    public function execute($actor) {
        $actor->jump();
    }

}

class FireCommand implements Command {

    // override
    public function execute($actor) {
        $actor->fire();
    }

}

class InputHandler {

    private $keyJ;
    private $keyF;

    public function __construct() {
        $this->keyJ = new JumpCommand();
        $this->keyF = new FireCommand();
    }

    public function handleInput($keyValue) {
        if ($keyValue == 'j') {
            return $this->keyJ;
        } else if ($keyValue == 'f') {
            return $this->keyF;
        }

        echo "You need to press 'j' or 'f'.\n";

        return null;
    }

}

echo ":: Command ::\n\n";

echo "This is a game, you are in front an enemy.\n";
echo "You can press 'j' to jump, or you can press 'f' to fire your gun.\n";

$inputHandler = new InputHandler();
$player = new Player();

$stdin = fopen('php://stdin', 'r');
echo "Press the key correspondend to your action and then press 'Enter'...\n";
$pressedKey = stream_get_contents($stdin, 1);

$command = $inputHandler->handleInput($pressedKey);

if ($command != null) {
    $command->execute($player);
}

echo "Game Over\n";

?>
