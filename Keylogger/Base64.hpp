#ifndef BASE64_H
#define BASE64_H

#include <vector>
#include <string>

using namespace std;

namespace Base64{
	string base64_encode(const string &);

	const string &SALT1 = "LM::TB::BB";
	const string &SALT2 = "_:/_77";
	const string &SALT3 = "line=boostedC++";

	string EncryptB64(string s){
		s = SALT1 + s + SALT2 + SALT3;
		s = base64_encode(s);
		s.insert(7, SALT3);
		s += SALT1;
		s = base64_encode(s);
		s = SALT2 + SALT3 + s + SALT1;
		s = base64_encode(s);
		s.insert(1, "Ls");
		s.insert(7, "A");
		return s;
	}

	const string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	string base64_encode(const string &s){
		string ret;
		int val = 0;
		int bits = -6;
		const unsigned int b63 = 0x3F;

		for (const auto &c : s){
			val = (val << 8) + c;
			bits += 8;
			while (bits >= 0){
				ret.push_back(BASE64_CODES[(val >> bits) & b63]);
				bits -= 6;
			}
		}

		if (bits > -6)
			ret.push_back(BASE64_CODES[((val << 8) >> (bits + 8)) & b63]);

		while (ret.size() % 4)
			ret.push_back('=');

		return ret;
	}
}

#endif // BASE64_H
