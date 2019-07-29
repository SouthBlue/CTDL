#include <iostream>
#include <iomanip>
#include "mylib.h"
#include <string>
#include <vector>
#include <fstream>
#include "hienthi.h"
#include "nhapxuat.h"
#include "dslists.h"

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
		Nocursortype(0);
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
	  			  }
	  			  break;
	  	case RIGHT :if (chon+1 <so_item1)
	  			  {
	  		        Normal();
	              	mauChu(cot + chon*25, dong, BLUE, td[chon]);
	              	chon ++;
	              	HighLight();
	              	mauChu(cot + chon*25, dong, BLUE, td[chon]);	
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






/////////////////////////MonHocKhoiTao////////////

void KhoitaoMH(TREEMH &t)
{
	t = NULL;
}

//int insert_MH(TREEMH &t, MonHoc a){
//	if(t != NULL){
//		if(compare_MH(t->MH, a) == 0)
//			return -1;				// node da co
//		if(compare_MH(t->MH, a) > 0)
//			return insert_MH(t->left, a); // chen trai
//		else if(compare_MH(t->MH, a) < 0)
//			return insert_MH(t->right, a); // chen phai
//	}
//	t = new NODEMH;
//	if (t == NULL)
//		return 0;
//	t->MH = a;
//	t->left = t->right = NULL;
//	return 1;
//}


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


//void createtree_MH(TREEMH &t){
//	MonHoc a;
//	int n = 3;
//	while(n > 0){
//		a = input_MH();
//		int check = insert_MH(t, a);
//		if(check == -1){
//			gotoxy(108, 6);
//			cout << "Ma mon hoc da co!";
//		}
//		if(check == 0)
//			cout<<"Bo nho day";
//		n--;
//	}
//}

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

////////////////Diem//////

////////////////////////
void select_SV(LISTSV &l, int chon)
{
	
}

void menu();         //////////////////???
int select_Lop(LISTLOP &l,int chon)
{
	int x = 1, y = 15;
	l.read_Lop();
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
	  			  }
	  			  break;
	  	case DOWN :if (chon + 1 <l.slLop)
	  			  {
	  		        Normal();
	              	mauChu(x, y + chon, BLACK, " -> ");
	              	chon ++;
	              	HighLight();
	              	mauChu(x, y + chon, BLACK, " -> ");
	  			  }
	  			  break;
		case ESC :	system("cls");
					SetBGColor(BLACK);
					menu();
					break;
		case INSERT : 	clear_screen2();
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
			select_Lop(l,0);
			break;
		// case 2:
		// 	SetBGColor(BLACK);

	}
}

int select_CauHoi(listCauHoi &l,int chon)
{
	int x = 1, y = 15;
	l.read_CauHoi();
	l.output_CH();
	HighLight();
	mauChu(x, y + chon, BLACK, " -> ");
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
	  			  }
	  			  break;
	  	case DOWN :if (chon + 1 <l.slCauHoi)
	  			  {
	  		        Normal();
	              	mauChu(x, y + chon, BLACK, " -> ");
	              	chon ++;
	              	HighLight();
	              	mauChu(x, y + chon, BLACK, " -> ");
	  			  }
	  			  break;
		case ESC :	system("cls");
					SetBGColor(BLACK);
					menu();
					break;
		case INSERT : 	clear_screen4();
						Normalw();
						l.insert_CH();
						l.write_CauHoi();
						clear_screen2();
						select_CauHoi(l, chon);
						break;
		case DELETE :	if(l.slCauHoi <= 0)
							break;
						else{
							clear_screen4();
							clear_screen2();
							Normalw();
							if(chon == 0 ){
								l.del_CauHoi(chon);
								l.write_CauHoi();
								select_CauHoi(l, chon);
							}
							else{
								l.del_CauHoi(chon);
								l.write_CauHoi();
								select_CauHoi(l, chon - 1);
							}						
							break;
						}
	  	case ENTER  : 	clear_screen1();
	  					//l.slCauHoi = chon;
	  					l.output1_CH(chon);
	  					//clear_screen2();
						select_CauHoi(l,chon); 
							
		  				return chon;
	  } 
	  } while (1);
}
void menu_CH()
{
	Nocursortype(0);
	int chon =  MenuGV(menu1);
	switch (chon)
	{
//		case 1:
//			SetBGColor(BLACK);
//			clear_screen3();
//			guide_Lop();
//			LISTLOP l;
//			select_Lop(l,0);
//			break;
		case 2:
			SetBGColor(BLACK);
			clear_screen3();
			guide_MH();
			listCauHoi lc;
			select_CauHoi(lc,0);
			break;

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
// 	 MenuGV(menu1);
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
//	LISTSV l;
// 	l.read_listSV();
// 	l.outputlist_SV();
//	l.insertlist_SV();
// 	l.outputlist_SV();
//	l.write_listSV();
//	LISTCH l;
//	l.read_CauHoi();
//	l.output_CH();
//	l.insert_CH();
//	l.output_CH();
//	l.write_CauHoi();
//	listCauHoi lc;
	//l.select_DA();
//	l.write_CauHoi();

	menu_CH(); 

//	ifstream fsv("DSsv.txt");
//	if(fsv.fail())
//	{
//		cout<<"loi";
//	}
////	fsv.ignore();
//	getline(fsv, sv.maSV, '@');
//	cout << sv.maSV;
	
//	menu();
	// LNR(t);
//	insert_CH();
//	output_CH);
 	getch();

	return 0;
}
