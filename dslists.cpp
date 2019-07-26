#include "dslists.h"

///////////////////////lop//////////
void listLop::insert_Lop()
{
	Nocursortype(1);
	int x = 108, y= 12;
	mauChu(x, y, RED, "-----THEM LOP-----");
	nodesL[slLop] = new Lop;
	gotoxy(x, y + 1);
	cout << "Nhap vao ma lop: ";
	input_check(x + 17, y + 1, 15, 15, nodesL[slLop]->maLop);
	gotoxy(x, y + 2);
	cout << "Nhap vao ten lop: ";
	input_check(x + 18, y + 2, 50, 17, nodesL[slLop]->tenLop);
	slLop++;
	Nocursortype(0);
}
void listLop::output_Lop()
{
	
	int x = 7, y = 15;
	table_LOP();
	gotoxy(x, y - 3);
	cout << "So luong lop: " << slLop <<"/200";
	if(slLop <= 0)
	{
		gotoxy(x + 20, y);
		cout << "Danh sach lop hoc trong!";
		return;
	}
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
void listLop::del_Lop( int vitri)
{
	for(int i = vitri; i < slLop - 1; i++)
	{
		nodesL[i]->maLop = nodesL[i + 1]->maLop;
		nodesL[i]->tenLop = nodesL[i + 1]->tenLop;
	}
	slLop--;
}
void listLop::write_Lop()
{
	ofstream flo("DSlop.txt");
	if(flo.fail()){
		cout << "that bai";
	}
	flo << slLop << "\n";
	for(int i = 0; i < slLop; i++)
	{
		flo << nodesL[i]->maLop <<"@ ";
		flo << nodesL[i]->tenLop <<'@' << "\n";
	}
	flo.close();
}
void listLop::read_Lop()
{
	ifstream fli("DSlop.txt");
	if(fli.fail())
	{
		cout << "that bai";
	}
	fli >> slLop;
	for(int i = 0; i < slLop; i++)
	{
		nodesL[i] = new Lop;
		fli.ignore();
		getline(fli, nodesL[i]->maLop, '@');
		fli.ignore();
		getline(fli, nodesL[i]->tenLop, '@');
	}
}
///////////////////////sinh vien.///////
NODESV *createNode_SV(SinhVien a)
{
	NODESV *p = new NODESV;
	if(p == NULL)
	{
		return NULL;
	}
	p->sv = a;
	p->svnext = NULL;
	return p;	
}
//void listSinhVien::listAddHead_SV(NODESV *p)
//{
//   if (svFirst == NULL) 
//      svFirst  = svLast = p;
//   else
//   {
//      p->svnext = svFirst; 
//      svFirst = p; 
//   }
//}
void listSinhVien::AddTail_SV(SinhVien a)
{
	NODESV *p = new NODESV;
	p->sv = a;
	p->svnext = NULL;
   if (svFirst == NULL) 
    	svFirst  = svLast = p;
   else
   {
      	svLast->svnext = p;
      	svLast = p;
   }
}
bool SinhVien::sexs_SV()
{
	string s[2] = {" nam ", " nu "};
	bool chon = true;
	for(int i = 0; i < 2; i++)
	{
		mauChu(120 + i*10, 14, RED, s[i]);
	}
	HighLight();
	mauChu(120, 14, RED, s[0]);
	char key;
	do{
		key = getch();
		if(key == 0) key= getch();
		switch (key){
			case LEFT: 
				    chon = true;
					Normal();
	              	mauChu(120 + 10, 14, RED, s[1]);	
	              	HighLight();
	              	mauChu(120, 14, RED, s[0]);
				break;
			case RIGHT:
				    chon = false;
					Normal();
	              	mauChu(120, 14, RED, s[0]);
	              	HighLight();
	              	mauChu(120 + 10, 14, RED, s[1]);
				break;
			case ENTER:
				 	SetBGColor(BLACK);
					return chon;
		}
	} while(1);

}
void SinhVien::password_in(int x, int y, int width, string &pass)
 {
 	int a = 0, b = 0;
	char key;
	string result;
	while(1)
	{
		key = getch();
		if (key==0) key = getch();
		switch(key)
		{
			case ENTER :
				pass = result;
				return;
			case SPACE :
				break;
			case BACKSPACE :
				if(result.size() != 0) 
				{
					if(a == 0) 
					{
						b--;
						a = width;
					}
					result.pop_back();
					a--;
					gotoxy(x + a, y + b); 
					cout << " ";
					gotoxy(x + a, y + b); 
				}	
				break;
			default:				
					if(result.length() != width)
					{	
						result.push_back(key);	
						gotoxy(x + a++, y + b);
						cout << key;
						if(a == width){			
							a = 0;
							b++;	
						}
					}
				break;	
		}
	}
 }
 void SinhVien::insert_SV()
{
	
	int x = 108, y = 11; 
	fflush(stdin);
	gotoxy(x, y);
	cout << "Nhap ma sinh vien: ";
	input_check(127, 11, 10, 10, maSV);
	gotoxy(x, y + 1);
	cout << "Nhap Ho: ";
	input_check(117, y + 1, 25, 25, Ho);
	gotoxy(x, y + 2);
	cout << "Nhap Ten: ";
	input_check(118, y + 2, 15, 15, Ten);
	gotoxy(x, y + 3);
	cout << "Phai: ";
	phai = sexs_SV();
	gotoxy(x, y + 4);
	cout << "Password: ";
	password_in(x + 10, y + 4, 16, password);
}
void SinhVien::sex_SV(bool x)
{
	if(x == 1)
	{
		cout << "nam";
	}
	else cout << "nu";
}
void SinhVien::output_SV(int x, int y)
{
	gotoxy(x, y);
	cout << maSV;
	gotoxy(x + 23, y);
	cout << Ho;
	gotoxy(x + 57, y);
	cout << Ten;
	gotoxy(x + 84, y);
	sex_SV(phai);
}
void listSinhVien::insertlist_SV()
{
	clear_screen5();
	SinhVien a;
	a.insert_SV();
	AddTail_SV(a);	
	slsv++;
}
void listSinhVien::outputlist_SV()
{
	clear_screen2();
	SetBGColor(BLACK);
	int x = 9, y = 14;
	if(slsv == 0)
	{
		gotoxy(x + 20, y);
		cout << "Danh sach sinh vien trong!";
		return;
	}
	gotoxy(x, y - 2); 
	cout << "So sinh vien: " << slsv;
	table_SV();
	for(NODESV *p = svFirst; p != NULL; p = p->svnext)
	{
		p->sv.output_SV(x, y);
		y++;
	}
}
void SinhVien::read_SV(ifstream &fsv)
{	
	fsv.ignore();
	getline(fsv, maSV, '@');
	fsv.ignore();
	getline(fsv, Ho, '@');
	fsv.ignore();
	getline(fsv, Ten, '@');
	fsv.ignore();
	getline(fsv, password, ' ');
	fsv >> phai ;
}
void SinhVien::write_SV(ofstream &fsv)
{
	fsv << maSV << "@ ";
	fsv << Ho << "@ ";
	fsv << Ten << "@ ";
	fsv << password << ' ';
	fsv << phai;
}
void listSinhVien::read_listSV()
{
	ifstream fsv("DSsv.txt");
	fsv >> slsv;
	for(int i = 0; i < slsv; i++){
		SinhVien sv;
		sv.read_SV(fsv);
		AddTail_SV(sv);
	}
	fsv.close();
}
void listSinhVien::write_listSV()
{
	ofstream fsv("DSsv.txt");
	fsv << slsv << "\n";
	NODESV *p = svFirst;
	for(int i = 0; i < slsv; i++)
	{
		p->sv.write_SV(fsv);
		fsv << "\n";
		p = p->svnext;
	}
	fsv.close();
}
