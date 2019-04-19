class MD5Encryptor {

  encrypt(text) {
    // encrypt text using MD5 algorithm and return the encripted text.
    return "XYZ123";
  }

}

class SHAEncryptor {

  encrypt(text) {
    // encrypt text using SHA algorithm and return the encripted text.
    return "ABC456";
  }

}

class SHA256Encryptor {

  encrypt(text) {
    // encrypt text using SHA256 algorithm and return the encripted text.
    return "WOKDTG45KY012";
  }

}

class EncryptorFacade {

  encrypt(type, text) {
    let encryptor;

    if (type === 'MD5') {
      encryptor = new MD5Encryptor();
    } else if (type === 'SHA') {
      encryptor = new SHAEncryptor();
    } else if (type === 'SHA256') {
      encryptor = new SHA256Encryptor();
    } else {
      return '';
    }

    return encryptor.encrypt(text);;
  }

}

console.log(':: Facede ::\n');

const text = 'Text to enscrypt';

const encryptor = new EncryptorFacade();

console.log('\nMD5 encryption');
console.log(encryptor.encrypt('MD5', text));

console.log('\nSHA encryption');
console.log(encryptor.encrypt('SHA', text));

console.log('\nSHA256 encryption');
console.log(encryptor.encrypt('SHA256', text));