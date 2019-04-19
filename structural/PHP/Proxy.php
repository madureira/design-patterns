<?php

abstract class Image {

    protected $name;

    public abstract function display();

}

class RealImage extends Image {

    public function __construct($imageName) {
        $this->name = $imageName;
        $this->loadFromDisk($this->name);
    }

    // override
    public function display() {
        echo "Displaying " . $this->name . "from memory.\n\n";
    }

    public function loadFromDisk($imageName) {
        echo "Loading image: " . $imageName . " from disk.\n";
    }

}

class ProxyImage extends Image {

    private $realImage;

    public function __construct($imageName) {
        $this->name = $imageName;
    }

    // override
    public function display() {
        if ($this->realImage == null) {
            $this->realImage = new RealImage($this->name);
        }
        $this->realImage->display();
    }

}

echo ":: Proxy ::\n\n";

$image = new ProxyImage('test_10mb.jpg');

// image will be loaded from disk.
$image->display();

// image will not be loaded from disk.
$image->display();

?>