<?php

interface Node {

    public function ls($indentation);

}

class File implements Node {

    private $name;

    public function __construct($name) {
        $this->name = $name;
    }

    public function ls($indentation) {
        $indentation = substr($indentation, 0, strlen($indentation) - 4);

        echo "|     |\n";
        echo "|     +-- " . $this->name . "\n";
    }

}

class Folder implements Node {

    private $name;
    private $nodes;

    public function __construct($name) {
        $this->name = $name;
        $this->nodes = array();
    }

    public function ls($indentation) {
        if ($indentation != "") {
            echo $indentation . "|\n";
        }
        echo $indentation . "+-- " . $this->name . "\n";
        $indentation = $indentation . "   ";
        foreach ($this->nodes as &$node) {
            $node->ls($indentation);
        }
    }

    public function add($node) {
        array_push($this->nodes, $node);
    }

}

echo ":: Composite ::\n";

$folderMusic = new Folder("MUSIC");

$folderRammstein = new Folder("Rammstein");

$track1 = new File("Du Hast.mp3");
$track2 = new File("Sonne.mp3");
$track3 = new File("Amerika.mp3");

$folderSOAD = new Folder("System of a Down");

$track4 = new File("Chop Suey!.mp3");
$track5 = new File("B.Y.O.B.mp3");
$track6 = new File("Toxicity.mp3");

$folderRammstein->add($track1);
$folderRammstein->add($track2);
$folderRammstein->add($track3);

$folderSOAD->add($track4);
$folderSOAD->add($track5);
$folderSOAD->add($track6);

$folderMusic->add($folderRammstein);
$folderMusic->add($folderSOAD);

$folderMusic->ls("");

?>