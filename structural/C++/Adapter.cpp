#include <iostream>

enum RCAPlug {
	YELLOW,
	RED,
	WHITE
};

// Legacy component
class RCAConnector
{
public:
	RCAConnector(RCAPlug yellowPlug, RCAPlug redPlug, RCAPlug whitePlug)
		: m_Video(yellowPlug), m_RightAudio(redPlug), m_LeftAudio(whitePlug)
	{
	}

	void connectOnRCABoard()
	{
		if (m_Video == YELLOW && m_RightAudio == RED && m_LeftAudio == WHITE)
		{
			std::cout << "RCAConnector connected correctly!" << std::endl;
			m_RCAConnected = true;
		}
		else
		{
			std::cout << "ERROR: cable connected in wrong order!" << std::endl;
			m_RCAConnected = false;
		}
	}

private:
	bool m_RCAConnected;
	RCAPlug m_Video;
	RCAPlug m_RightAudio;
	RCAPlug m_LeftAudio;
};

// Desired interface
class HDMIConnector
{
public:
	virtual void connect() = 0;
};

// Adapter wrapper
class ConnectorAdapter : public HDMIConnector, private RCAConnector
{
public:
	ConnectorAdapter(RCAPlug yellowPlug, RCAPlug redPlug, RCAPlug whitePlug)
		: RCAConnector(yellowPlug, redPlug, whitePlug)
	{
	}

	virtual void connect()
	{
		connectOnRCABoard();
		std::cout << "HDMI connected to the board through the RCA adapter!" << std::endl;
	}
};

int main()
{
	std::cout << ":: Adapter ::\n" << std::endl;

	HDMIConnector* hdmi = new ConnectorAdapter(RCAPlug::YELLOW, RCAPlug::RED, RCAPlug::WHITE);
	hdmi->connect();

	system("PAUSE");

	return 0;
}
