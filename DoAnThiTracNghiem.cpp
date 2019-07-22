//#include <iostream>
#include <iomanip>
//#include "mylib.h"
//#include <string>
#include <vector>
#include <fstream>
//#include "hienthi.h"
//#include "nhapxuat.h"
#include "khaibao.h"

using namespace std;

const int so_item1 = 4;

const int so_item3 = 5;
const int dong = 4;
const int cot = 10;
int xmh = 7, ymh = 15;



///////////////////////////

string menu1 [so_item1]= {"    Lop    ", " Cau Hoi Thi", "  Mon Hoc  ", " Bang Diem "};					   	 
string menuLop [so_item3] = {"Esc: Quay lai", "F1: Menu chinh", "Enter: Chon lop", "Delete: Xoa lop", "Insert: Them lop"};
const int so_item2 = 3;
const char menu2 [so_item2][50] = {"<-  ->: Di chuyen", "      Enter: Chon", "       Esc: Thoat"};


int MenuGV(string td[so_item1]){
	system("cls");
	GiaoDienGV();
	rectangle(8, 3, 15, 3, BLUE);
	rectangle(34, 3, 15, 3, BLUE);
	rectangle(58, 3, 15, 3, BLUE);
	rectangle(83, 3, 15, 3, BLUE);
	press_key();
	int chon =0;
 	int i;
 	for ( i=0; i< so_item1 ; i++){
	 	mauChu(cot + 25*i, dong, BLUE, td[i]);
 	}
	  	HighLight();
	  	mauChu(cot + 25*chon, dong, BLUE, td[chon]);
		Nocursortype();
	  	char kytu;
	do {
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {
	    case LEFT :if (chon+1 >1)
	  			  {
					Normal();
					mauChu(cot + chon*25, dong, BLUE, td[chon]);
					chon --;
					HighLight();
					mauChu(cot + chon*25, dong, BLUE, td[chon]);
					Nocursortype();		
	  			  }
	  			  break;
	  	case RIGHT :if (chon+1 <so_item1)
	  			  {
	  		        Normal();
	              	mauChu(cot + chon*25, dong, BLUE, td[chon]);
	              	chon ++;
	              	HighLight();
	              	mauChu(cot + chon*25, dong, BLUE, td[chon]);
					Nocursortype();	
	  			  }
	  			  break;
	  	case ENTER : return chon+1;
	  } 
	  } while (1);

}	
						   


void ThongBaoDN(){
	rectangle(40, 31, 60, 6, GREEN);
// mauChu(50, 32, GREEN, "Tai khoan hoac mat khau khong chinh xac!");
	mauChu(52, 32, GREEN, "Ban chua nhap tai khoan hoac mat khau!");
	mauChu(60, 33, GREEN, "vui long nhap lai!");
	mauChu(50, 35, RED, "~~~~~~~~~~~~~~~~~ENTER~~~~~~~~~~~~~~~~");
}

///////////////////Code doi voi cac danh sach//////////////////


int empty_Lop(LISTLOP l)
{
	return l.slLop == 0;
}
int full_Lop(LISTLOP l)
{
	return l.slLop == MAXLOP;
}
void create_Lop(LISTLOP &l)
{
	l.slLop = 0;
}
// int search_Lop(LISTLOP &l, string* ma)
// {
// 	for(int i = 0; i < l.slLop; i++)
// 	{
// 		if(l.nodesL[i].maLop == ma)
// 		return i;
// 	}
// 	return -1;
// }






//------------------ DOC GHI FILE LOP ---------------
void write_Lop(LISTLOP l)
{
	ofstream flo("DSlop.txt", ios::in);
	if(flo.fail()){
		cout << "that bai";
	}
	flo << l.slLop << endl;

	for(int i=0; i < l.slLop; i++)
	{

		flo << l.nodesL[i]->maLop <<"@ ";
		flo << l.nodesL[i]->tenLop <<'@' <<"\n";
	}
	flo.close();
}
void read_Lop(LISTLOP &l)
{
	ifstream fli("DSlop.txt");
	if(fli.fail())
	{
		cout << "that bai";
	}
	fli >> l.slLop;
	for(int i = 0; i < l.slLop; i++)
	{
		l.nodesL[i] = new Lop;
//		// fli >> l.nodesL[i]->maLop;
//		// fli >> l.nodesL[i]->tenLop;
		fli.ignore();
		getline(fli, l.nodesL[i]->maLop, '@');
		fli.ignore();
		getline(fli, l.nodesL[i]->tenLop, '@');
	}
}

/////////////////////////////////////////
/////////////////////////MonHocKhoiTao////////////

int compare_MH(MonHoc a, MonHoc b)
{
	return (a.maMonHoc.compare(b.maMonHoc));
}
MonHoc input_MH()
{ 
	int x = 108, y = 11;
	MonHoc a;
	gotoxy(x,y);
	cout << "Nhap ma mon hoc: ";
	input_check(x + 17, y, 15, 15, a.maMonHoc);
	gotoxy(x, y + 1);
	cout << "Nhap ten mon hoc: ";
	input_check(x + 18, y + 1, 50, 17, a.tenMonHoc);
	return a;
}
void output_MH(int xmh, int &ymh, MonHoc a)
{
	gotoxy(xmh, ymh);
	cout << a.maMonHoc;
	gotoxy(xmh + 34, ymh);
	cout<< a.tenMonHoc;
	ymh++;
}

int insert_MH(TREEMH &t, MonHoc a){
	if(t != NULL){
		if(compare_MH(t->MH, a) == 0)
			return -1;				// node da co
		if(compare_MH(t->MH, a) > 0)
			return insert_MH(t->left, a); // chen trai
		else if(compare_MH(t->MH, a) < 0)
			return insert_MH(t->right, a); // chen phai
	}
	t = new NODEMH;
	if (t == NULL)
		return 0;
	t->MH = a;
	t->left = t->right = NULL;
	return 1;
}
void createtree_MH(TREEMH &t){
	MonHoc a;
	int n = 3;
	while(n > 0){
		a = input_MH();
		int check = insert_MH(t, a);
		if(check == -1){
			gotoxy(108, 6);
			cout << "Ma mon hoc da co!";
		}
		if(check == 0)
			cout<<"Bo nho day";
		n--;
	}
}

void LNR(TREEMH &t)
{
	table_MH();
	gotoxy(7, 13);
	cout << "So mon hoc: ";
	if(t != NULL)
	{
		LNR(t->left);
		output_MH(xmh, ymh, t->MH);
		LNR(t->right);
	}
}
// NODEMH* search_MH(TREEMH t, char* data)    
// {
//     if (t != NULL) {
//         if (strcmp(t->MH.maMonHoc, data) < ) {
//             Node *P = T;
//             return P;
//         }
//         if (T->key.scores >= scores) {
//             Node *node = searchScores(T->Left, scores);
//             if (node != NULL)
//                 return node;
//             else {
//                 return searchScores(T->Right, scores);
//             }
//         }
//     }
//     return NULL;
// }
int del_MH(TREEMH &t, string ma)
{
	if(t == NULL)
	{
		return 0;
	}
	else if((t->MH.maMonHoc.compare(ma)) > 0)
		return del_MH(t->left, ma);
	else if((t->MH.maMonHoc.compare(ma)) < 0)
		return del_MH(t->right, ma);
	else
	{
		NODEMH *p = t;
		if(t->left == NULL)
			t = t->right;
		else if(t->right == NULL)
			t = t->left;
		else
		{
			NODEMH *s = t, *q = s->left;
			while(q->right != NULL)
			{
				s = q;
				q = q->right;
			}
			p->MH= q->MH;
			s->right = q->right;
			delete q;
		}
		return 1;
	}
	
}
//////////////////////////////////SINH VIEN/////////////
void create_ListSV(LISTSV &l)
{
	l.svFirst = l.svLast = NULL;
}
NODESV* createNode_SV(SinhVien a)
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
void AddHead_SV(LISTSV &l, NODESV *p)
{
   if (l.svFirst == NULL) 
      l.svFirst  = l.svLast = p;
   else
   {
      p->svnext = l.svFirst; 
      l.svFirst = p; 
   }
}
 
void AddTail_SV(LISTSV &l, NODESV *p)
{
   if (l.svFirst == NULL) 
    	l.svFirst  = l.svLast = p;
   else
   {
      	l.svLast->svnext = p;
      	l.svLast = p;
   }
}
bool sex_SV()
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
// vector<char> password_in(int x, int y, int max)
// {
// 	int a = 0;
// 	char key;
// 	vector<char> pass;
// 	while(1)
// 	{
// 		key = getch();
// 		if (key==0) key = getch();
// 		switch(key)
// 		{
// 			case ENTER :
// 				pass.push_back('\0');
// 				return pass;
// 			case BACKSPACE :
// 				if(pass.size() != 0) 
// 				{
// 					pass.pop_back();
// 					a--;
// 					gotoxy(x + a, y); 
// 					cout << " ";
// 					gotoxy(x + a, y); 
// 				}	
// 				break;
// 			case SPACE :	
// 				break;
// 			default:				
// 					if(pass.size() != max)
// 					{	
// 						pass.push_back(key);	
// 						gotoxy(x + a++, y);
// 						cout << "*";
// 					}
// 				break;	
// 		}
// 	}
// }
// void passord_out(int x, int y, int max, char *data)
// {
// 	vector<char> ans = password_in(x, y, max);	
// 	for(int i = 0; i < ans.size(); i++) data[i] = ans[i];	
// }
void input_SV(SinhVien &sv)
{
	
	int x = 108, y = 11; 
	fflush(stdin);
	gotoxy(x, y);
	cout << "Nhap ma sinh vien: ";
	input_check(127, 11, 10, 10, sv.maSV);
	gotoxy(x, y + 1);
	cout << "Nhap Ho: ";
	input_check(117, y + 1, 25, 25, sv.Ho);
	gotoxy(x, y + 2);
	cout << "Nhap Ten: ";
	input_check(118, y + 2, 15, 15, sv.Ten);
	gotoxy(x, y + 3);
	cout << "Phai: ";
	sv.phai = sex_SV();
	gotoxy(x, y + 4);
	cout << "Password: ";
	input_check(x + 10, y + 4, 16, 16, sv.password);
}


void sex_SV(bool x)
{
	if(x == 1)
	{
		cout << "nam";
	}
	else cout << "nu";
}
void output_SV(int x, int y, SinhVien sv)
{
	gotoxy(x, y);
	cout << sv.maSV;
	gotoxy(x + 23, y);
	cout << sv.Ho;
	gotoxy(x + 57, y);
	cout << sv.Ten;
	gotoxy(x + 84, y);
	sex_SV(sv.phai);
}

void inputlist_SV(LISTSV &l)
{
	gotoxy(108, 10);
	cout << "so luong: ";
	int n;
	cin >> n;
	create_ListSV(l);
	SinhVien x;
	for(int i = 0; i < n; i++ )
	{
		input_SV(x);
		NODESV *p = createNode_SV(x);
		AddTail_SV(l, p);	
	}
}
void outputlist_SV(LISTSV l)
{

	SetBGColor(BLACK);

	int x = 9, y = 14;
	NODESV *p;
	p = l.svFirst;
	if(p == NULL)
	{
		gotoxy(x + 20, y);
		cout << "Danh sach sinh vien trong!";
		return;
	}
	gotoxy(x, y - 2); 
	cout << "So sinh vien: ";
	table_SV();
	while(p != NULL)
	{
		output_SV(x, y, p->sv);
		p = p->svnext;
		y++;
	}
}
///////////////////CauHoi//////////
int select_DA(){
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
	  	case RIGHT :if (chon+1 <so_item1)
	  			  {
	  		        Normal();
	              	mauChu(x + chon*10, y, RED, da[chon]);
	              	chon ++;
	              	HighLight();
	              	mauChu(x + chon*10, y, RED, da[chon]);
	  			  }
	  			  break;
	  	case 13 : return chon+1;
	  } 
	  } while (1);

}
void insert_CH()
{
//	clear_screen1();
//	int x = 3, y = 1;
//	int i = 0;
//	LISTCH.nodesCH[i] = new CauHoi;
//	gotoxy(x, y);
//	cout << "Nhap cau hoi: ";
//	input_check(x + 14, y, 250, 86, LISTCH.nodesCH[i]->noiDung);
//	gotoxy(x, y + 3);
//	cout << "A: ";
//	input_check(x + 2, y + 3, 80, 80, LISTCH.nodesCH[i]->A);
//	gotoxy(x, y + 4);
//	cout << "B: ";
//	input_check(x + 2, y + 4, 80, 80, LISTCH.nodesCH[i]->B);
//	gotoxy(x, y + 5);
//	cout << "C: ";
//	input_check(x + 2, y + 5, 80, 80, LISTCH.nodesCH[i]->C);
//	gotoxy(x, y + 6);
//	cout << "D: ";
//	input_check(x + 2, y + 6, 80, 80, LISTCH.nodesCH[i]->D);
//	gotoxy(x, y + 7);
//	cout << "Dap An: ";
//	LISTCH.nodesCH[i]->dapAn = select_DA(); 
//	LISTCH.slCauHoi++;
}

void dapan(int a)
{
	if(a == 1)
	{
		cout << "A";
	}else
	{
		if(a == 2)
		cout << "B";
		else
		{
			if(a == 3)
			cout << "C";
			else
			{
				cout << "D";
			}
			
		}
		
	}
	
}
void output_CH()
{
//	SetBGColor(BLACK);
//	int x = 7, y = 15;
//	if(LISTCH.slCauHoi == 0)
//	{
//		gotoxy(x + 20, y);
//		cout << "Danh cau hoi trong!";
//		return;
//	}
//	table_CH();
//	for (int i = 0; i < LISTCH.slCauHoi; i++)
//	{
//		 gotoxy(x, y + i);	
//		 cout << LISTCH.nodesCH[i]->noiDung;
//		 gotoxy(x + 54, y + i);
//		 dapan(LISTCH.nodesCH[i]->dapAn);
//		x = 7;
//		y++; 
//	}
}
////////////////Diem//////

////////////////////////
void menu();         //////////////////???
int select_Lop(LISTLOP &l)
{
	int x = 1, y = 15;
	int chon = 0;
	read_Lop(l);
	l.output_Lop();
	HighLight();
	mauChu(x, y, BLACK, " -> ");
	char kytu;
	do {
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {
	    case UP :if (chon+1 >1)
	  			  {
	  		        Normal();
	              	mauChu(x, y + chon, BLACK, " -> ");
	              	chon --;
	              	HighLight();
	              	mauChu(x, y + chon, BLACK, " -> ");
					Nocursortype();	
	  			  }
	  			  break;
	  	case DOWN :if (chon + 1 <l.slLop)
	  			  {
	  		        Normal();
	              	mauChu(x, y + chon, BLACK, " -> ");
	              	chon ++;
	              	HighLight();
	              	mauChu(x, y + chon, BLACK, " -> ");
					Nocursortype();
	  			  }
	  			  break;
		case ESC :	system("cls");
					SetBGColor(BLACK);
					menu();
					break;
		case INSERT : 	clear_screen4();
						Normalw();
						l.insert_Lop();
						write_Lop(l);
						select_Lop(l);
						break;
	  	case ENTER : return chon + 1;
	  } 
	  } while (1);
}
void menu()
{
	int chon =  MenuGV(menu1);
	switch (chon)
	{
		case 1:
			SetBGColor(BLACK);
			clear_screen3();
			guide_Lop();
			LISTLOP l;
			select_Lop(l);
			break;
		// case 2:
		// 	SetBGColor(BLACK);

	}
}
void resizeConsole(){	
	HWND console = GetConsoleWindow();
	SetWindowPos(console, 0, 50, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1200, 700, TRUE);
}

int main(){
	
 //	ios::sync_with_stdio(0);
 //	cin.tie(0);
 	resizeConsole();
// 	 DangNhap();
 	// getch();
 	// ThongBaoDN();
 	// MenuGV(menu1);
 	// SetBGColor(BLACK);
	// TREEMH t;
	// t=NULL;
	// createtree_MH(t);
	// LNR(t);
 	// getch();
	// char c[16];
	// gotoxy(108, 17);
	// cout<<"nhap mh can xoa:";
	// cin>>c;
	// del_MH(t, c);
	// LISTSV l;
 	// inputlist_SV(l);
 	// outputlist_SV(l);
	menu();
	// LNR(t);
//	insert_CH();
//	output_CH();
 	getch();

	return 0;
}
