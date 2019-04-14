import java.util.ArrayList;
import java.util.List;

interface Node {

	public void ls(String indentation);
 
}

class File implements Node {

	private String name;

	public File(String name) {
		this.name = name;
	}

	@Override
	public void ls(String indentation) {
		indentation = indentation.substring(0, indentation.length() - 4);

		System.out.println("|     |");
		System.out.println("|     +-- " + this.name);
	}
}

class Directory implements Node {
	
	private String name;
	private List<Node> nodes;

	public Directory(String name) {
		this.name = name;
		this.nodes = new ArrayList<>();
	}

	@Override
	public void ls(String indentation) {
		if (!"".equals(indentation)) {
			System.out.println(indentation + "|");
		}
		System.out.println(indentation + "+-- " + this.name);
		indentation = indentation + "   ";
		for (Node node : this.nodes) {
			node.ls(indentation);
		}
	}

	public void add(Node node) {
		this.nodes.add(node);
	}

}

public class Main {

	public static void main(String[] args) {
		System.out.println(":: Composite ::\n");
		
		Directory folderMusic = new Directory("MUSIC");
		Directory folderRammstein = new Directory("Rammstein");
		
		File track1 = new File("Du Hast.mp3");
		File track2 = new File("Sonne.mp3");
		File track3 = new File("Amerika.mp3");
		
		Directory folderSOAD = new Directory("System of a Down");

		File track4 = new File("Chop Suey!.mp3");
		File track5 = new File("B.Y.O.B.mp3");
		File track6 = new File("Toxicity.mp3");
		
		folderRammstein.add(track1);
		folderRammstein.add(track2);
		folderRammstein.add(track3);

		folderSOAD.add(track4);
		folderSOAD.add(track5);
		folderSOAD.add(track6);

		folderMusic.add(folderRammstein);
		folderMusic.add(folderSOAD);

		folderMusic.ls("");
	}

}