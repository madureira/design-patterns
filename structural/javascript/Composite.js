// Interface
class Node {

  constructor() {
    if (this.constructor === Node) {
      throw new TypeError('Cannot construct Abstract instances directly');
    }

    if (this.ls === Node.prototype.ls) {
      throw new TypeError('Must override method "ls(string indentation)"');
    }
  }

  ls(indentation) {
    throw new TypeError('Do not call abstract method "ls(string indentation)" from child.');
  }

}

class File extends Node {

  constructor(name) {
    super();
    this.name = name;
  }

  // Implements abstract parent method
  ls(indentation) {
    indentation = indentation.sub(0, indentation.length - 4);

    console.log('|     |');
    console.log('|     +-- ' + this.name);
  }

}

class Directory extends Node {

  constructor(name) {
    super();
    this.name = name;
    this.nodes = [];
  }

  // Implements abstract parent method
  ls(indentation) {
    if (!indentation) {
      console.log(indentation + '|');
    }
    console.log(indentation + '+-- ' + this.name);
    indentation = indentation + '   ';

    this.nodes.forEach(node => {
      node.ls(indentation);
    }); 
  }

  add(node) {
    this.nodes.push(node);
  }

}

console.log(':: Composite ::\n');

const folderMusic = new Directory('MUSIC');
const folderRammstein = new Directory('Rammstein');

const track1 = new File('Du Hast.mp3');
const track2 = new File('Sonne.mp3');
const track3 = new File('Amerika.mp3');

const folderSOAD = new Directory('System of a Down');

const track4 = new File('Chop Suey!.mp3');
const track5 = new File('B.Y.O.B.mp3');
const track6 = new File('Toxicity.mp3');

folderRammstein.add(track1);
folderRammstein.add(track2);
folderRammstein.add(track3);

folderSOAD.add(track4);
folderSOAD.add(track5);
folderSOAD.add(track6);

folderMusic.add(folderRammstein);
folderMusic.add(folderSOAD);

folderMusic.ls('');