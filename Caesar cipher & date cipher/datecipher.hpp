#ifndef DATECIPHER_HPP_
#define DATECIPHER_HPP_

#include "cipher.hpp"

class DateCipher : public Cipher {
public:
	DateCipher();
	virtual ~DateCipher();
	virtual std::string encrypt(std::string &text);
	virtual std::string decrypt(std::string &text);
private:
	std::string date;
	std::string ws_date;
	std::string alph;
};

#endif /* DATECIPHER_HPP_ */