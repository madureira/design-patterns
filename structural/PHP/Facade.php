<?php

class MD5Encryptor {

    public function encrypt($text) {
        // encrypt text using MD5 algorithm and return the encripted text.
        return 'XYZ123';
    }

}

class SHAEncryptor {

    public function encrypt($text) {
        // encrypt text using SHA algorithm and return the encripted text.
        return 'ABC456';
    }

}

class SHA256Encryptor {

    public function encrypt($text) {
        // encrypt text using SHA256 algorithm and return the encripted text.
        return 'WOKDTG45KY012';
    }

}

class EncryptorFacade {

    public function encrypt($type, $text) {
        $encryptor = null;

        if ($type == 'MD5') {
            $encryptor = new MD5Encryptor();
        } else if ($type == 'SHA') {
            $encryptor = new SHAEncryptor();
        } else if ($type == 'SHA256') {
            $encryptor = new SHA256Encryptor();
        } else {
            return '';
        }

        return $encryptor->encrypt($text);
    }

}

echo ":: Facade ::\n";

$text = 'Text to encrypt';

$encryptor = new EncryptorFacade();

echo "\nMD5 encryption\n";
echo $encryptor->encrypt('MD5', $text) . "\n";

echo "\nSHA encryption\n";
echo $encryptor->encrypt('SHA', $text) . "\n";

echo "\nSHA256 encryption\n";
echo $encryptor->encrypt('SHA256', $text) . "\n";
?>