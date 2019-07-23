#include "khaibao.h"

void listLop::insert_Lop()
{
	int x = 108, y= 10;
	
	nodesL[slLop] = new Lop;
	gotoxy(x, y + 1);
	cout << "Nhap vao ma lop: ";
	input_check(x + 17, y + 1, 15, 15, nodesL[slLop]->maLop);
	gotoxy(x, y + 2);
	cout << "Nhap vao ten lop: ";
	input_check(x + 18, y + 2, 50, 17, nodesL[slLop]->tenLop);
	slLop++;
}
void listLop::output_Lop()
{
	
	int x = 7, y = 15;
	if(slLop == 0)
	{
		gotoxy(x + 20, y);
		cout << "Danh sach lop hoc trong!";
		return;
	}
	table_LOP();
	gotoxy(x, y - 3);
	cout << "So luong lop: " << slLop <<"/200";
	for (int i = 0; i < slLop; i ++)
	{
		 gotoxy(x, y);	
		 cout << nodesL[i]->maLop;
		 gotoxy(x + 30, y );
		 cout << nodesL[i]->tenLop;
		x = 7;
		y++; 
	}
}

