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
int listCauHoi::select_DA()
{
	int x = 20, y = 8;
	string da[4] = {"  A  ", "  B  ", "  C  ", "  D  "};
	int chon = 0;
 	int i;
 	for ( i = 0; i < 4 ; i++){
	 	mauChu(x + 10*i, y, RED,da[i]);
 	}
	  	HighLight();
	  	mauChu(x + 10*chon, y, RED, da[chon]);
	  	char kytu;
	do {
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {
	    case LEFT :if (chon+1 >1)
	  			  {
	  		        Normal();
	              	mauChu(x + chon*10, y, RED, da[chon]);
	              	chon --;
	              	HighLight();
	              	mauChu(x + chon*10, y, RED, da[chon]);	
	  			  }
	  			  break;
	  	case RIGHT :if (chon+1 < 4)
	  			  {
	  		        Normal();
	              	mauChu(x + chon*10, y, RED, da[chon]);
	              	chon ++;
	              	HighLight();
	              	mauChu(x + chon*10, y, RED, da[chon]);
	  			  }
	  			  break;
	  	case ENTER : 
	  				SetBGColor(BLACK);
	  				//cout << chon;
	  				return chon;
	  } 
	  } while (1);

}
void listCauHoi::DA_CauHoi(int x)
{
	if(x == 0)
	{
		cout << "A";
	}
	else if(x == 1)
	{
		cout << "B";
	}
	else if(x == 2)
	{
		cout << "C";
	}
	else
	{
		cout << "D";
	}
}
void listCauHoi::insert_CH()
{
	clear_screen1();
	int x = 3, y = 1;
	int i = 0;
	nodesCH[slCauHoi] = new CauHoi;
	gotoxy(x, y);
	cout << "Nhap cau hoi: ";
	input_check(x + 14, y, 250, 86, nodesCH[slCauHoi]->noiDung);
	gotoxy(x, y + 3);
	cout << "A: ";
	input_check(x + 2, y + 3, 80, 80, nodesCH[slCauHoi]->A);
	gotoxy(x, y + 4);
	cout << "B: ";
	input_check(x + 2, y + 4, 80, 80, nodesCH[slCauHoi]->B);
	gotoxy(x, y + 5);
	cout << "C: ";
	input_check(x + 2, y + 5, 80, 80, nodesCH[slCauHoi]->C);
	gotoxy(x, y + 6);
	cout << "D: ";
	input_check(x + 2, y + 6, 80, 80, nodesCH[slCauHoi]->D);
	gotoxy(x, y + 7);
	cout << "Dap An: ";
	nodesCH[slCauHoi]->dapAn = select_DA();
	//cout << nodesCH[slCauHoi]->dapAn;
	slCauHoi++;
}
void listCauHoi::output_CH()
{
	SetBGColor(BLACK);
	int x = 7, y = 15;
	if(slCauHoi == 0)
	{
		gotoxy(x + 20, y);
		cout << "Danh cau hoi trong!";
		return;
	}
	table_CH();
	for (int i = 0; i < slCauHoi; i++)
	{
		 gotoxy(x, y);	
		 cout << nodesCH[i]->noiDung;
		 gotoxy(x + 54, y);
		 DA_CauHoi(nodesCH[i]->dapAn);
		x = 7;
		y++; 
	}
}
void listCauHoi::output1_CH(int chon)
{
	int x = 3, y = 1;
	gotoxy(x,y);
	cout << "Noi dung cau hoi: " <<nodesCH[chon]->noiDung;
	gotoxy(x, y + 3);
	cout << "A:    " << nodesCH[chon]->A;
	gotoxy(x, y + 4);
	cout << "B:    " << nodesCH[chon]->B;
	gotoxy(x, y + 5);
	cout << "C:    " << nodesCH[chon]->C;
	gotoxy(x, y + 6);
	cout << "D:    " << nodesCH[chon]->D;
	if(nodesCH[chon]->dapAn == 0)
	{
		gotoxy(x+3,y+3);
		cout << "*";
	}
		else if(nodesCH[chon]->dapAn == 1)
		{
			gotoxy(x+3,y+4);
			cout << "*";
		}
			else if(nodesCH[chon]->dapAn == 2)
			{
				gotoxy(x+3,y+5);
				cout << "*";
			}
				else if(nodesCH[chon]->dapAn == 3)
				{
					gotoxy(x+3,y+6);
					cout << "*";
				}
}
void listCauHoi::write_CauHoi()
{
	ofstream flo("DScauhoi.txt");
	if(flo.fail()){
		cout << "that bai";
	}
	flo << slCauHoi << "\n";
	for(int i = 0; i < slCauHoi; i++)
	{
		flo << nodesCH[i]->noiDung <<"@ ";
		flo << nodesCH[i]->A <<"@ ";
		flo << nodesCH[i]->B <<"@ ";
		flo << nodesCH[i]->C <<"@ ";
		flo << nodesCH[i]->D <<" ";
		flo << nodesCH[i]->dapAn <<"\n" ;
		
	}
	flo.close();
}
void listCauHoi::read_CauHoi()
{
	ifstream fli("DScauhoi.txt");
	if(fli.fail())
	{
		cout << "that bai";
	}
	fli >> slCauHoi;
	for(int i = 0; i < slCauHoi; i++)
	{
		nodesCH[i] = new CauHoi;
		fli.ignore();
		getline(fli, nodesCH[i]->noiDung, '@');
		fli.ignore();
		getline(fli, nodesCH[i]->A, '@');
		fli.ignore();
		getline(fli, nodesCH[i]->B, '@');
		fli.ignore();
		getline(fli, nodesCH[i]->C, '@');
		fli.ignore();
		getline(fli, nodesCH[i]->D, ' ');
		//fli.ignore();
		fli >> nodesCH[i]->dapAn;
	}
}
void listCauHoi::del_CauHoi( int vitri)
{
	for(int i = vitri; i < slCauHoi - 1; i++)
	{
		nodesCH[i]->noiDung = nodesCH[i + 1]->noiDung;
		nodesCH[i]->A = nodesCH[i + 1]->A;
		nodesCH[i]->B = nodesCH[i + 1]->B;
		nodesCH[i]->C = nodesCH[i + 1]->C;
		nodesCH[i]->D = nodesCH[i + 1]->D;
		nodesCH[i]->dapAn = nodesCH[i + 1]->dapAn;
		
	}
	slCauHoi--;
}
