#include"Screen.h"

void main() {
	char* str = new char[] {"Hello world"};
	Screen scr(6, 11, str);
	scr.showCurrent();
	scr.move();
	scr.showCurrent();
	scr.back();
	scr.showCurrent();
	scr.move(0, 4);
	scr.set('0');
	scr.show();
}