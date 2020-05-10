const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

class GameActor {

  constructor() {
    if (this.constructor === GameActor) {
      throw new TypeError('Cannot construct Abstract instances directly');
    }
  }

  jump() {
    console.log('You jumped in a hole and died :(');
  }

  fire() {
    console.log('You killed the enemy :)');
  }

}

class Player extends GameActor {

}

class Command {

  constructor() {
    if (this.constructor === Command) {
      throw new TypeError('Cannot construct Abstract instances directly');
    }

    if (this.jump === Command.prototype.execute) {
      throw new TypeError('Must override method "execute"');
    }
  }

  execute(actor) {
    throw new TypeError('Do not call abstract method "execute" from child.');
  }

}

class JumpCommand extends Command {

  execute(actor) {
    actor.jump();
  }

}

class FireCommand extends Command {

  execute(actor) {
    actor.fire();
  }

}

class InputHandler {

  constructor() {
    this.keyJ = new JumpCommand();
    this.keyF = new FireCommand();
  }

  handleInput(keyValue) {
    if (keyValue === 'j') {
      return this.keyJ;
    } else if (keyValue === 'f') {
      return this.keyF;
    } else {
      console.log('You need to press "j" or "f".');
    }

    return null;
  }

}


console.log('This is a game, you are in front an enemy.');
console.log('You can press "j" to jump, or you can press "f" to fire your gun.');

const inputHandler = new InputHandler();
const player = new Player();

rl.question('Press the key corresponded to your action and then press "Enter"...\n', pressedKey => {
  const command = inputHandler.handleInput(pressedKey);

  if (command) {
    command.execute(player);
  }

  console.log('Game Over');

  rl.close();
});

