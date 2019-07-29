#include <iostream>
#include <iomanip>
#include "mylib.h"
#include <string>
#include <vector>
#include <fstream>
#include "hienthi.h"
#include "nhapxuat.h"
#include "dslists.h"

#include "giaovien.h"
//using namespace std;

const int so_item1 = 4;
const int so_item3 = 5;




///////////////////////////

void ThongBaoDN(){
	rectangle(40, 31, 60, 6, GREEN);
// mauChu(50, 32, GREEN, "Tai khoan hoac mat khau khong chinh xac!");
	mauChu(52, 32, GREEN, "Ban chua nhap tai khoan hoac mat khau!");
	mauChu(60, 33, GREEN, "vui long nhap lai!");
	mauChu(50, 35, RED, "~~~~~~~~~~~~~~~~~ENTER~~~~~~~~~~~~~~~~");
}

///////////////////Code doi voi cac danh sach//////////////////


<<<<<<< HEAD
//void output_MH(int x, int &y, MonHoc a)
//{
//	gotoxy(xmh, ymh);
//	cout << a.maMonHoc;
//	gotoxy(xmh + 34, ymh);
//	cout<< a.tenMonHoc;
//	ymh++;
//}
//
//void insert_MH(TREEMH &t, MonHoc a){
//	if(t != NULL){
//		if((t->MH.maMonHoc.compare(a.maMonHoc)) == 0){
//			mauChu(108, 6, YELLOW, "Ma mon hoc da ton tai!");
//			return;
//		}
//		if(t->MH.maMonHoc.compare(a.maMonHoc) > 0)
//			return insert_MH(t->left, a); // chen trai
//		else if(t->MH.maMonHoc.compare(a.maMonHoc) < 0)
//			return insert_MH(t->right, a); // chen phai
//	}
//	t = new NODEMH;
////	if (t == NULL)
////		return 0;
//	t->MH = a;
//	t->left = t->right = NULL;
//	return;
//}
//void add_MH(TREEMH &t){
//	MonHoc a;
//	a = input_MH(a);
//	insert_MH(t, a);
//}
//
//void LNR(TREEMH &t)
//{
//	table_MH();
//	gotoxy(7, 13);
//	cout << "So mon hoc: ";
//
//	if(t != NULL)
//	{
//		LNR(t->left);
//		output_MH(xmh, ymh, t->MH);
//		LNR(t->right);
//	}
//}
=======
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






/////////////////////////////////////////


/////////////////////////////////////////CauHoi///////////
void insert_cauhoi(LISTCH &l)
{
	int i;
	cout << "So Cau Hoi muon them: ";
	cin >> i;
	for (int j = 0; j < i; j ++)
	{
		l.nodesCH[j] = new CauHoi;
//		cout << "Nhap ma mon hoc: ";
//		cin >> l.nodesCH[j]->
		cout << "Nhap vao cau hoi:  ";
		cin >> l.nodesCH[j]->noiDung;
		cout << "Nhap dap an: ";
		cin >> l.nodesCH[j]->dapAn;
		l.slCauHoi ++;

	}
}
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
>>>>>>> parent of 2f7b472... update 29/7
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
<<<<<<< HEAD
//int del_MH(TREEMH &t, string ma)
//{
//	if(t == NULL)
//	{
//		return 0;
//	}
//	else if((t->MH.maMonHoc.compare(ma)) > 0)
//		return del_MH(t->left, ma);
//	else if((t->MH.maMonHoc.compare(ma)) < 0)
//		return del_MH(t->right, ma);
//	else
//	{
//		NODEMH *p = t;
//		if(t->left == NULL)
//			t = t->right;
//		else if(t->right == NULL)
//			t = t->left;
//		else
//		{
//			NODEMH *s = t, *q = s->left;
//			while(q->right != NULL)
//			{
//				s = q;
//				q = q->right;
//			}
//			p->MH= q->MH;
//			s->right = q->right;
//			delete q;
//		}
//		return 1;
//	}	
//}
//
//void read_listMH(TREEMH &t)
//{
//	int slmh;
//	ifstream file("DSmh.txt");
//	file >> slmh;
//	for(int i = 0; i < slmh; i++)
//	{
//		MonHoc a;
//		a.read_MH(file);
//		insert_MH(t, a);
//	}
//	file.close();
//}
//void write_listMH(TREEMH t)
//{
//	
//}
=======
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



void insertlist_SV(LISTSV &l)
{
	clear_screen5();
	SinhVien a;
	a.insert_SV();
	l.AddTail_SV(a);	
	l.slsv++;
}
void outputlist_SV(LISTSV l)
{
	clear_screen2();
	SetBGColor(BLACK);
	int x = 9, y = 14;
	if(l.slsv == 0)
	{
		gotoxy(x + 20, y);
		cout << "Danh sach sinh vien trong!";
		return;
	}
	gotoxy(x, y - 2); 
	cout << "So sinh vien: " << l.slsv;
	table_SV();
	for(NODESV *p = l.svFirst; p != NULL; p = p->svnext)
	{
		p->sv.output_SV(x, y);
		y++;
	}
}

///////////Doc ghi file SV////
<<<<<<< HEAD
=======




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
>>>>>>> parent of 2f7b472... update 29/7




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
>>>>>>> parent of 2f7b472... update 29/7


<<<<<<< HEAD
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
=======
void menu();         //////////////////???
int select_Lop(LISTLOP &l)
{
	int x = 1, y = 15;
	l.read_Lop();
	l.output_Lop();
	HighLight();
	mauChu(x, y, BLACK, " -> ");
	char kytu;
>>>>>>> parent of 2f7b472... update 29/7
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
<<<<<<< HEAD
	  	case 13 : return chon+1;
	  } 
	  } while (1);
=======
		case ESC :	system("cls");
					SetBGColor(BLACK);
					menu();
					break;
		case INSERT : 	clear_screen4();
						Normalw();
						l.insert_Lop();
						l.write_Lop();
						clear_screen2();
						select_Lop(l, chon);
						break;
		case DELETE :	if(l.slLop <= 0)
							break;
						else{
							clear_screen4();
							clear_screen2();
							Normalw();
							if(chon == 0 ){
								l.del_Lop(chon);
								l.write_Lop();
								select_Lop(l, chon);
							}
							else{
								l.del_Lop(chon);
								l.write_Lop();
								select_Lop(l, chon - 1);
							}						
							break;
						}
	  	case ENTER : return chon;
	  } 
	  } while (1);
}
void menu()
{
	Nocursortype(0);
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
>>>>>>> parent of 2f7b472... update 29/7

}
<<<<<<< HEAD
<<<<<<< HEAD
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
=======
=======
>>>>>>> parent of 2f7b472... update 29/7
void resizeConsole(){	
	HWND console = GetConsoleWindow();
	SetWindowPos(console, 0, 50, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1200, 700, TRUE);
>>>>>>> parent of 2f7b472... update 29/7
}
////////////////Diem//////

////////////////////////




int main(){
	
 //	ios::sync_with_stdio(0);
 //	cin.tie(0);
 	resizeConsole();
// 	 DangNhap();
 	// getch();
 	// ThongBaoDN();
// 	 MenuGV(menu1);
 	// SetBGColor(BLACK);
	listMonHoc t;
//	 NODEMH *root = NULL;
	// createtree_MH(t);
	t.read_listMH();
	t.LNRkodequy();
	t.add_MH();
	t.write_listMH();
//	t.LNR(t.root);

t.read_listMH();
	t.LNRkodequy();

////	t.add_MH();
//	t.LNR(t.root);
//	MonHoc a;
//	a.maMonHoc = "e";
//	a.tenMonHoc = "vvv";
//	t.insert_MH(root, a);
//	t.insert_MH()

//	 t.LNR(root);
 	// getch();
	// char c[16];
	// gotoxy(108, 17);
	// cout<<"nhap mh can xoa:";
	// cin>>c;
	// del_MH(t, c);
<<<<<<< HEAD
<<<<<<< HEAD
//	LISTSV l;
// 	l.read_listSV();
// 	l.outputlist_SV();
//	l.insertlist_SV();
// 	l.outputlist_SV();
//	l.write_listSV();
=======
=======
>>>>>>> parent of 2f7b472... update 29/7
	LISTSV l;
 	l.read_listSV();
 	l.outputlist_SV();
	l.insertlist_SV();
 	l.outputlist_SV();
	l.write_listSV();
<<<<<<< HEAD
>>>>>>> parent of 2f7b472... update 29/7
=======
>>>>>>> parent of 2f7b472... update 29/7

//	ifstream fsv("DSsv.txt");
//	if(fsv.fail())
//	{
//		cout<<"loi";
//	}
////	fsv.ignore();
//	getline(fsv, sv.maSV, '@');
//	cout << sv.maSV;
	
//	giao_vien();
	// LNR(t);
//	insert_CH();
//	output_CH);
 	getch();

	return 0;
}
