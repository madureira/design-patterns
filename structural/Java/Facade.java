class MD5Encryptor {

	String encrypt(String text) {
		// encrypt text using MD5 algorithm and return the encripted text.
		return "XYZ123";
	}

}

class SHAEncryptor {

	public String encrypt(String text) {
		// encrypt text using SHA algorithm and return the encripted text.
		return "ABC456";	
	}

}

class SHA256Encryptor {

	String encrypt(String text) {
		// encrypt text using SHA256 algorithm and return the encripted text.
		return "WOKDTG45KY012";
	}

}

class EncryptorFacade {

	public String encrypt(String type, String text) {
		if ("MD5".equals(type)) {
			MD5Encryptor encryptor = new MD5Encryptor();
			return encryptor.encrypt(text);
		} else if ("SHA".equals(type)) {
			SHAEncryptor encryptor = new SHAEncryptor();
			return encryptor.encrypt(text);
		} else if ("SHA256".equals(type)) {
			SHA256Encryptor encryptor = new SHA256Encryptor();
			return encryptor.encrypt(text);
		}

		return "";
	}

}

public class Main {

	public static void main(String[] args) {
		System.out.println(":: Facade ::");

		String text = "Text to encrypt";

		EncryptorFacade encryptor = new EncryptorFacade();

		System.out.println("\nMD5 encryption");
		System.out.println(encryptor.encrypt("MD5", text));

		System.out.println("\nSHA encryption");
		System.out.println(encryptor.encrypt("SHA", text));

		System.out.println("\nSHA256 encryption");
		System.out.println(encryptor.encrypt("SHA256", text));
	}

}