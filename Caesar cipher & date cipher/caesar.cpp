#include "cipher.hpp"
#include "caesar.hpp"

// Single-argument constructor
CaesarCipher::CaesarCipher(int text) : Cipher(), rotation(text) {
	alph = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

// Destructor
CaesarCipher::~CaesarCipher() {
}

std::string
CaesarCipher::encrypt(std::string &inputText) {
	std::string text = inputText;
	std::string::size_type len = text.length();
	for (int i = 0; i != len; ++i) {
		int pos = alph.find(text[i]);
		text[i] = alph[(pos + rotation) % 53];
    }    
	return text;
}

std::string
CaesarCipher::decrypt(std::string &inputText) {
	std::string text = inputText;
	std::string::size_type len = text.length();
	for (int i = 0; i != len; ++i) {
		int pos = alph.find(text[i]);
		text[i] = alph[(pos - rotation) % 53];
	}
	return text;
}