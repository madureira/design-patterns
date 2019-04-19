<?php

interface Widget {

    public function draw();

    public function getDescription();

}

class Window implements Widget {

    // override
    public function draw() {
        echo "Drawing the Window\n";
    }

    // override
    public function getDescription() {
        return 'Window';
    }

}

class WindowDecorator extends Window {

    private $windowToBeDecorated;

    public function __construct($windowToBeDecorated) {
        $this->windowToBeDecorated = $windowToBeDecorated;
    }

    // override
    public function draw() {
        $this->windowToBeDecorated->draw(); // Delegation
    }

    // override
    public function getDescription() {
        return $this->windowToBeDecorated->getDescription(); // Delegation
    }

}

class VerticalScrollBarDecorator extends WindowDecorator {

    public function __construct($windowToBeDecorated) {
        parent::__construct($windowToBeDecorated);
    }

    // override
    public function draw() {
        parent::draw();
        $this->drawVerticalScrollBar();
    }

    // override
    public function getDescription() {
        return parent::getDescription() . ', including vertical scrollbar';
    }

}

class HorizontalScrollBarDecorator extends WindowDecorator {

    public function __construct($windowToBeDecorated) {
        parent::__construct($windowToBeDecorated);
    }

    // override
    public function draw() {
        parent::draw();
        $this->drawHorizontalScrollBar();
    }

    // override
    public function getDescription() {
        return parent::getDescription() . ', including horizontal scrollbars';
    }

    private function drawHorizontalScrollBar() {
        echo "Drawing Horizontal ScrollBar\n";
    }

}

echo ":: Decorator ::\n";

$decoratedWindow = new HorizontalScrollBarDecorator(new VerticalScrollBarDecorator(new Window()));

echo $decoratedWindow->getDescription() . "\n";

?>