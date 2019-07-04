#include <iostream>
#include <mylib.h>
#include <windows.h>
#include <conio.h>
#include "Display.h"
using namespace std;


void loginDisplay(){
	
//	for()
	gotoxy(60, 20);
	cout<<"User Name:";
	gotoxy(60, 24);
	cout<<"Password:";
	
}

void resizeConsole(){
	
	HWND console = GetConsoleWindow();
	SetWindowPos(console, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1365, 730, TRUE);
}




int main(){
	hello();
//	
//	resizeConsole();
//	loginDisplay();
//	getch();
}
