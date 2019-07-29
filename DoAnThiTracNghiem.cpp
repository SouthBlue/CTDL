#include <iomanip>
//#include <fstream>
//#include "hienthi.h"
//#include "nhapxuat.h"
//#include "dslists.h"

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
//	LISTSV l;
// 	l.read_listSV();
// 	l.outputlist_SV();
//	l.insertlist_SV();
// 	l.outputlist_SV();
//	l.write_listSV();

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
