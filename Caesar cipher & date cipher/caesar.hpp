#ifndef CAESARCIPHER_HPP_
#define CAESARCIPHER_HPP_

#include "cipher.hpp"

class CaesarCipher : public Cipher {
public:
	CaesarCipher();
	CaesarCipher(int key);
	virtual ~CaesarCipher();
	virtual std::string encrypt(std::string &text);
	virtual std::string decrypt(std::string &text);
private:
	int rotation;
	std::string alph;
};

#endif /* CAESARCIPHER_HPP_ */