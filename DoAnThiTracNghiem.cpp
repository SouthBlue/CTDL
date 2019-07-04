#include <iostream>
#include <mylib.h>
#include <windows.h>
using namespace std;


void loginDisplay(){
	gotoxy(300, 200);
	
}

void resizeConsole(){
	
	HWND console = GetConsoleWindow();
	SetWindowPos(console, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1365, 730, TRUE);
}




int main(){
	resizeConsole();
	cout << "jjd";
}
