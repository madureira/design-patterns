'use strict';

class Logger {
  constructor() {
    if (!Logger.instance) {
      Logger.instance = this;
    }
    return Logger.instance;
  }

  info(message) {
    console.log(message);
  }

  error(message) {
    console.error(message);
  }
}

const loggerOne = new Logger();
const loggerTwo = new Logger();

loggerOne.info('Success message');
loggerTwo.error('Failure message');

// Proves that both instances are the same!
loggerOne.info(loggerOne === loggerTwo);