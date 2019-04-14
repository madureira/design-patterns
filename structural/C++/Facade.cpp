#include <iostream>
#include <string>

class MD5Encryptor
{
public:
	MD5Encryptor() {
	}

	std::string encrypt(std::string text)
	{
		// encrypt text using MD5 algorithm and return the encripted text.
		return "XYZ123";
	}
};

class SHAEncryptor
{
public:
	SHAEncryptor() {
	}

	std::string encrypt(std::string text)
	{
		// encrypt text using SHA algorithm and return the encripted text.
		return "ABC456";
	}
};

class SHA256Encryptor {
public:
	SHA256Encryptor() {
	}

	std::string encrypt(std::string text)
	{
		// encrypt text using SHA256 algorithm and return the encripted text.
		return "WOKDTG45KY012";
	}
};

class EncryptorFacade
{
public:
	EncryptorFacade() {
	}

	std::string encrypt(std::string type, std::string text)
	{
		if (type == "MD5")
		{
			MD5Encryptor encryptor;
			return encryptor.encrypt(text);
		}
		else if (type == "SHA")
		{
			SHAEncryptor encryptor;
			return encryptor.encrypt(text);
		}
		else if (type == "SHA256")
		{
			SHA256Encryptor encryptor;
			return encryptor.encrypt(text);
		}

		return "";
	}
};

int main()
{
	std::string text = "Text to encrypt";

	EncryptorFacade encryptor;

	std::cout << "MD5 encryption" << std::endl;
	std::cout << encryptor.encrypt("MD5", text) << std::endl;

	std::cout << "SHA encryption" << std::endl;
	std::cout << encryptor.encrypt("SHA", text) << std::endl;

	std::cout << "SHA256 encryption" << std::endl;
	std::cout << encryptor.encrypt("SHA256", text) << std::endl;

	system("PAUSE");

	return 0;
}