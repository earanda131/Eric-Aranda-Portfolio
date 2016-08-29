#include "cipher.hpp"
#include "datecipher.hpp"
#include <algorithm>
#include <iterator>

DateCipher::DateCipher() : Cipher() {
	ws_date = "01/31/90";
	std::remove_copy(ws_date.begin(), ws_date.end(), std::back_inserter(date), '/');
	alph = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

// Destructor
DateCipher::~DateCipher() {
}

std::string
DateCipher::encrypt(std::string &inputText) {
	std::string text = inputText;
	std::string date_text = text;
	std::string::size_type len = text.length();
	int alph_l = alph.length();
	int date_ctr = 0;
	for (int i = 0; i != len; ++i) {
		if(text[i] == 32) {
			continue;
		}
		date_text[i] = date[date_ctr % 6] - '0';
		date_ctr++;
		int pos = alph.find(text[i]);
		text[i] = alph[(pos + date_text[i]) % alph_l];
	}
	date_ctr = 0;
	return text;
}

std::string
DateCipher::decrypt(std::string &inputText) {
	std::string text = inputText;
	std::string date_text = text;
	std::string::size_type len = text.length();
	int alph_l = alph.length();
	int date_ctr = 0;
	for (int i = 0; i != len; ++i) {
		if(text[i] == 32) {
			continue;
		}
		date_text[i] = date[date_ctr % 6] - '0';
		date_ctr++;
		int pos = alph.find(text[i]);
		text[i] = alph[(pos - date_text[i]) % alph_l];
	}
	date_ctr = 0;
	return text;
}
