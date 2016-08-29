/*
 * decrypt.cpp
 *      Author: norris
 */

#include <iostream>
#include <fstream>

#include "ioutils.hpp"
#include "cipher.hpp"
#include "datecipher.hpp"

int main(int argc, const char *argv[]) {

	IOUtils io;
	io.openStream(argc,argv);
	std::string input, encrypted, decrypted;
	input = io.readFromStream();
	std::cout << "Original text:" << input << std::endl;

	// 2. Test various ciphers

	// Simple ROT13 cipher
	DateCipher d;
	encrypted = d.encrypt(input);
	std::cout << "Encrypted text:" << encrypted << std::endl;

	decrypted = d.decrypt(encrypted);
	std::cout << "Decrypted text:" << decrypted << std::endl;

	if (decrypted == input) std::cout << "Decrypted text matches input!" << std::endl;
	else {
		std::cout << "Oops! Decrypted text doesn't match input!" << std::endl;
		return 1;   // Make sure to return a non-zero value to indicate failure
	}

	return 0;
}