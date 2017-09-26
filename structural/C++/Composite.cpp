#include <iostream>
#include <string>
#include <vector>

class Node
{
public:
	virtual void ls(std::string indentation = "") = 0;
};

class File : public Node
{
public:
	File(std::string name) : m_Name(name)
	{
	}

	void ls(std::string indentation = "") override
	{
		indentation = indentation.substr(0, indentation.length() - 3);

		std::cout << indentation << "|   |" << std::endl;
		std::cout << indentation << "|   +-- " << m_Name << std::endl;
	}

private:
	std::string m_Name;
};

class Directory : public Node
{
public:
	Directory(std::string name) : m_Name(name)
	{
	}

	~Directory()
	{
		for (auto &it : m_Nodes)
			delete it;

		m_Nodes.clear();
	}

	void add(Node* node) {
		m_Nodes.push_back(node);
	}

	void ls(std::string indentation = "") override
	{
		if (!indentation.empty()) {
			std::cout << indentation << "|" << std::endl;
		}
		std::cout << indentation << "+-- " << m_Name << std::endl;
		indentation.append("   ");
		for (auto node : m_Nodes) {
			node->ls(indentation);
		}
	}

private:
	std::string m_Name;
	std::vector<Node*> m_Nodes;
};

int main()
{
	std::cout << ":: Composite ::\n" << std::endl;

	Directory* folderMusic = new Directory("MUSIC");

	Directory* folderRammstein = new Directory("Rammstein");

	File* track1 = new File("Du Hast.mp3");
	File* track2 = new File("Sonne.mp3");
	File* track3 = new File("Amerika.mp3");

	Directory* folderSOAD = new Directory("System of a Down");

	File* track4 = new File("Chop Suey!.mp3");
	File* track5 = new File("B.Y.O.B.mp3");
	File* track6 = new File("Toxicity.mp3");

	folderRammstein->add(track1);
	folderRammstein->add(track2);
	folderRammstein->add(track3);

	folderSOAD->add(track4);
	folderSOAD->add(track5);
	folderSOAD->add(track6);

	folderMusic->add(folderRammstein);
	folderMusic->add(folderSOAD);

	folderMusic->ls();

	system("PAUSE");

	delete folderMusic;

	return 0;
}
