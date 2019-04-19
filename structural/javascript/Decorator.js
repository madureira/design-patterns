// Interface
class Widget {

  constructor() {
    if (this.constructor === Widget) {
      throw new TypeError('Cannot construct Abstract instances directly');
    }

    if (this.draw === Widget.prototype.draw) {
      throw new TypeError('Must override method "draw()"');
    }

    if (this.getDescription === Widget.prototype.getDescription) {
      throw new TypeError('Must override method "getDescription()"');
    }
  }

  draw() {
    throw new TypeError('Do not call abstract method "draw()" from child.');
  }

  getDescription() {
    throw new TypeError('Do not call abstract method "getDescription()" from child.');
  }

}

class Window extends Widget {

  // Implements abstract parent's method
  draw() {
    console.log('Drawing the Window');
  }

  // Implements abstract parent's method
  getDescription() {
    return 'Window';
  }

}

class WindowDecorator extends Window {

  constructor(windowToBeDecorated) {
    super();
    this.windowToBeDecorated = windowToBeDecorated;
  }

  // override
  draw() {
    this.windowToBeDecorated.draw(); // Delegation
  }

  // override
  getDescription() {
    return this.windowToBeDecorated.getDescription(); // Delegation
  }

}

class VerticalScrollBarDecorator extends WindowDecorator {

  constructor(windowToBeDecorated) {
    super(windowToBeDecorated);
  }

  // override
  draw() {
    super.draw();
    this.drawVerticalScrollBar();
  }

  // override
  getDescription() {
    return super.getDescription() + ', including vertical scrollbars';
  }

  drawVerticalScollBar() {
    console.log('Drawing Vertical ScrollBar');
  }

}

class HorizontalScrollBarDecorator extends WindowDecorator {

  constructor(windowToBeDecorated) {
    super(windowToBeDecorated);
  }

  // override
  draw() {
    super.draw();
    this.drawHorizontalScrollBar();
  }

  // override
  getDescription() {
    return super.getDescription() + ', including horizontal scrollbar';
  }

  drawHorizontalScrollBar() {
    console.log('Drawing Horizontal ScrollBar');
  }

}

console.log(':: Decorator ::\n');

const decoratedWindow = new HorizontalScrollBarDecorator(new VerticalScrollBarDecorator(new Window()));

console.log(decoratedWindow.getDescription());