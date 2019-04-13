'use strict';

class Logger {
  constructor() {
    if (!Logger.instance) {
      Logger.instance = this;
    }
    return Logger.instance;
  }

  info(message) {
    console.log('INFO: ' + message);
  }

  error(message) {
    console.error('ERROR: ' + message);
  }
}

const loggerOne = new Logger();
const loggerTwo = new Logger();

loggerOne.info('some info message');
loggerTwo.error('some error message');

// Proves that both instances are the same!
console.log(loggerOne === loggerTwo); // true