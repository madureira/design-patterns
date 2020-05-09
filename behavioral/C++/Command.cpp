#include <iostream>

class GameActor
{
public:
    virtual ~GameActor()
    {
    }

    virtual void Jump()
    {
        std::cout << "You jumped in a hole and died :(" << std::endl;
    }

    virtual void Fire()
    {
        std::cout << "You killed the enemy :)" << std::endl;
    }
};

class Player final : public GameActor
{
};

class Command
{
public:
    virtual ~Command()
    {
    }

    virtual void Execute(GameActor& actor) = 0;
};

class JumpCommand final : public Command
{
public:
    virtual void Execute(GameActor& actor)
    {
        actor.Jump();
    }
};

class FireCommand final : public Command
{
public:
    virtual void Execute(GameActor& actor)
    {
        actor.Fire();
    }
};

class InputHandler final
{
private:
    Command* m_KeyJ;
    Command* m_KeyF;

public:
    InputHandler()
    {
        this->m_KeyJ = new JumpCommand;
        this->m_KeyF = new FireCommand;
    }

    Command* HandleInput(std::string keyValue)
    {
        if (keyValue == "j")
        {
            return m_KeyJ;
        }
        else if (keyValue == "f")
        {
            return m_KeyF;
        }
        else
        {
            std::cout << "You need to press 'j' or 'f'." << std::endl;
        }

        return nullptr;
    }
};

int main()
{
    std::cout << "This is a game, you are in front an enemy." << std::endl;
    std::cout << "You can press 'j' to jump, or you can press 'f' to fire your gun." << std::endl;
    std::cout << "Press the key corresponded to your action and then press 'Enter'..." << std::endl;

    InputHandler inputHandler;
    Player player;

    std::string pressedKey;
    std::cin >> pressedKey;

    Command* command = inputHandler.HandleInput(pressedKey);

    command->Execute(player);

    std::cout << "Game Over" << std::endl;

    return 0;
}
