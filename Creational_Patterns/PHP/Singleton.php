<?php

class Logger {

    private static $instance;

    private function __construct() { } // implements a private default constructor

    public static function getInstance() {
        if (!isset(self::$instance)) {
            self::$instance = new Logger();
        }

        return self::$instance;
    }

    public function info($message) {
        echo "INFO: ". $message ."\n";
    }

    public function error($message) {
        echo "ERROR: ". $message ."\n";
    }

}

echo ":: Singleton ::\n\n";

$log = Logger::getInstance(); // uses the single instance.
$log->info("some info message");
$log->error("some error message");

?>
