import java.util.Scanner;

abstract class GameActor {

    public void jump() {
        System.out.println("You jumped in a hole and died :(");
    }

    public void fire() {
        System.out.println("You killed the enemy :)");
    }

}

class Player extends GameActor {
}

interface Command {

    void execute(GameActor actor);

}

class JumpCommand implements Command {

    @Override
    public void execute(GameActor actor) {
        actor.jump();
    }

}

class FireCommand implements Command {

    @Override
    public void execute(GameActor actor) {
        actor.fire();
    }

}

class InputHandler {

    private Command keyJ;
    private Command keyF;

    public InputHandler() {
        this.keyJ = new JumpCommand();
        this.keyF = new FireCommand();
    }

    public Command handleInput(String keyValue) {
        if ("j".equals(keyValue)) {
            return keyJ;
        } else if ("f".equals(keyValue)) {
            return keyF;
        }

        System.out.println("You need to press 'j' or 'f'.");

        return null;
    }

}

public class Main {

    public static void main(String[] args) {
        System.out.println("This is a game, you are in front an enemy.");
        System.out.println("You can press 'j' to jump, or you can press 'f' to fire your gun.");
        System.out.println("Press the key corresponded to your action and then press 'Enter'...");

        InputHandler inputHandler = new InputHandler();
        Player player = new Player();

        Scanner scanner = new Scanner(System.in);

        String pressedKey = scanner.next();

        Command command = inputHandler.handleInput(pressedKey);

        if (command != null) {
            command.execute(player);
        }

        System.out.println("Game Over");
    }

}
