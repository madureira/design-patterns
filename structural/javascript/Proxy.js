// abstract class
class Image {

  constructor() {
    if (this.constructor === Image) {
      throw new TypeError('Cannot construct Abstract instances directly');
    }

    if (this.display === Image.prototype.display) {
      throw new TypeError('Must override method "display()"');
    }

    this.name = '';
  }

  display() {
    throw new TypeError('Do not call abstract method "display()" from child.');
  }

}

class RealImage extends Image {

  constructor(imageName) {
    super();
    this.name = imageName;
    this.loadFromDisk(this.name);
  }

  // Implements the abstract parent method
  display() {
    console.log('Displaying ' + this.name + ' from memory.\n');
  }

  loadFromDisk(imageName) {
    console.log('Loading image: ' + imageName + ' from disk.');
  }

}

class ProxyImage extends Image {

  constructor(imageName) {
    super();
    this.realImage = null;
    this.name = imageName;
  }

  // override
  display() {
    if (!this.realImage) {
      this.realImage = new RealImage(this.name);
    }
    this.realImage.display();
  }

}

console.log(':: Proxy ::\n');

const image = new ProxyImage('test_10mb.jpg');

// image will be loaded from disk.
image.display();

// image will not be loaded from disk.
image.display();