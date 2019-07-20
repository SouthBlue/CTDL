#include <iostream>
#include <iomanip>
#include "mylib.h"
#include <string>
#include <vector>
using namespace std;

const int so_item1 = 4;
const int so_item2 = 3;
const int so_item3 = 5;
const int dong = 4;
const int cot = 10;
int xmh = 7, ymh = 15;

#define MAXLOP 500
#define MAXCAUHOI 2000

#define Up 72
#define Down 80
#define RIGHT 77
#define LEFT 75
#define	ENTER 13
#define	ESC 27
#define	INSERT 45
#define	DELETE 46
#define SPACE 32
#define TAB 9
#define BACKSPACE 8
#define MAXLOP 500
#define MAXCAUHOI 2000
#define WHITE 15
#define BLACK 0
#define BLUE 3
#define GREEN 10
#define RED 4						   

// khai bao ds
// Khai bao mon hoc (cay nhi phan)
typedef struct MonHoc{
	char maMonHoc[16];
	char tenMonHoc[51];
};
// Khoi tao cay nhi phan
typedef struct nodeMonHoc{
	MonHoc MH;     ///// + ////
	struct nodeMonHoc *left;
	struct nodeMonHoc *right;
};
typedef struct nodeMonHoc NODEMH;
typedef NODEMH *TREEMH;
// Khoi tao thong tin diem thi
typedef struct DiemThi{
	char maMonHoc[16];
	float diem;
};
// Khoi tao danh sach diem thi (danh sach lien ket don)
typedef struct nodeDiemThi{
	DiemThi dt;
	struct nodeDiemThi *dnext;
};
typedef struct nodeDiemThi *NODEDIEM; /// + ///

struct listDiemThi
{
	NODEDIEM *dLast;
	NODEDIEM *dFirst;
};

typedef struct listDiemThi LISTDIEM;

// Khai bao thong tin sinhvien
typedef struct SinhVien{
	char maSV[11];
	char Ho[26];
	char Ten[16];
	bool phai;
	char password[17];
	NODEDIEM FirstDiem;
};
// Khoi tao danh sach lien ket don sinh vien
typedef struct nodeSinhVien{
	SinhVien sv;
	struct nodeSinhVien *svnext;
};
typedef struct nodeSinhVien NODESV;

struct listSinhVien
{
	NODESV *svLast;
	NODESV *svFirst;
};
typedef struct listSinhVien LISTSV;


// Khai bao giao vien

typedef struct GiaoVien
{
	char MaGV[11];
	char Ho[50];
	char Ten[20];
	char Chucvu[30];
	float phai;
	char password[32];
};

typedef struct nodeGiaoVien
{
	GiaoVien GV;
	struct nodeGiaoVien *gvnext;
};

typedef struct nodeGiaoVien* NODEGV;

///Khoi tao danh sach lien ket don giao vien

struct listGiaoVien
{
	NODEGV *pFirst;
	NODEGV *pLast;
};

typedef struct listGiaoVien LISTGV;

// Khai bao lop
typedef struct Lop{
	char maLop[16];
	char tenLop[51];
	NODESV First;
};

// khai bao mang con tro lop
struct listLop{
	int slLop;
	Lop *nodesL[MAXLOP];
};
listLop LISTLOP;

struct CauHoi{
	int id;
	char maMonHoc[16];
	char noiDung[301];
	char A[51];
	char B[51];
	char C[51];
	char D[51];
	int dapAn;
};
struct listCauHoi{
	int slCauHoi;
	CauHoi *nodesCH[MAXCAUHOI];	
};
listCauHoi LISTCH;
///////////////////////////

char menu1 [so_item1][30] = {"    Lop    ", " Cau Hoi Thi", "  Mon Hoc  ", " Bang Diem "};					   	 
char menu2 [so_item2][50] = {"<-  ->: Di chuyen", "      Enter: Chon", "       Esc: Thoat"};
char menuLop [so_item3][50] = {"Esc: Quay lai", "F1: Menu chinh", "Enter: Chon lop", "Delete: Xoa lop", "Insert: Them lop"};

void Normal(){
	SetColor(3);
	SetBGColor(0);
}
void HighLight(){
	SetColor(3);
	SetBGColor(15);
}
void rectangle(int x, int y, int width, int height, int color)
{
	SetColor(color);
	gotoxy(x, y);
	cout << static_cast<char>(201);
	for (int i = x; i < x + width - 2; i++) {
		gotoxy(i + 1, y);
		cout << static_cast<char>(205);
		gotoxy(i + 1, y + height - 1);
		cout << static_cast<char>(205);
	}
	gotoxy(x + width - 1, y);
	cout << static_cast<char>(187) << endl;
	for (int i = y; i < y + height - 1; i++) {
		gotoxy(x, i + 1);
		cout << static_cast<char>(186);
		gotoxy(x + width - 1, i + 1);
		cout << static_cast<char>(186) << endl;
	}
	gotoxy(x, y + height - 1);
	cout << static_cast<char>(200);
	gotoxy(x + width - 1, y + height - 1);
	cout << static_cast<char>(188);
	SetColor(WHITE);
}
void mauChu(int x, int y, int color, string chu){
	SetColor(color);
	gotoxy(x, y);
	cout << chu;
	SetColor(WHITE);
}
void GiaoDienGV(){
	SetColor(3);
	rectangle(0, 0, 105, 10, BLUE);
	rectangle(0, 10, 105, 27, BLUE);
	rectangle(106, 0, 38, 37, BLUE);
	rectangle(0, 37, 144, 3, BLUE);
	mauChu(112, 1, RED, "=======> THONG TIN <========");
	mauChu(3, 37, RED, "---> HUONG DAN <---");
}
void press_key(char td2[so_item2][50]){
	SetColor(WHITE);
	for(int i = 0; i< so_item2; i++){
		gotoxy(3+i*20, 38);
		cout<< td2[i];
	}
}
int MenuGV(char td[so_item1][30]){
	system("cls");
	GiaoDienGV();
	rectangle(8, 3, 15, 3, BLUE);
	rectangle(34, 3, 15, 3, BLUE);
	rectangle(58, 3, 15, 3, BLUE);
	rectangle(83, 3, 15, 3, BLUE);
	press_key(menu2);
	int chon =0;
 	int i;
 	for ( i=0; i< so_item1 ; i++){
	 	mauChu(cot + 25*i, dong, BLUE, td[i]);
 	}
	  	HighLight();
	  	mauChu(cot + 25*chon, dong, BLUE, td[chon]);
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
					gotoxy(0, 0);	
	  			  }
	  			  break;
	  	case RIGHT :if (chon+1 <so_item1)
	  			  {
	  		        Normal();
	              	mauChu(cot + chon*25, dong, BLUE, td[chon]);
	              	chon ++;
	              	HighLight();
	              	mauChu(cot + chon*25, dong, BLUE, td[chon]);
					gotoxy(0, 0);

	  			  }
	  			  break;
	  	case 13 : return chon+1;
	  } 
	  } while (1);

}	
						   
void TieuDe(){
	SetColor(GREEN);
	gotoxy(5, 2);
	cout << "       ______  __              ______                          __  __          __                   \n";
	gotoxy(5, 3);
	cout << "      /\\__  _\\/\\ \\      __    /\\__  _\\                        /\\ \\/\\ \\        /\\ \\      __              \n";
	gotoxy(5, 4); 
	cout << "      \\/_/\\ \\/\\ \\ \\___ /\\_\\   \\/_/\\ \\/ _ __    __      ___    \\ \\ `\\\\ \\     __\\ \\ \\___ /\\_\\     __    ___ ___     \n";
	gotoxy(5, 5);
	cout << "         \\ \\ \\ \\ \\  _ `\\/\\ \\     \\ \\ \\/\\`'__\\/'__`\\   /'___\\   \\ \\ , ` \\  /'_ `\\ \\  _ `\\/\\ \\  /'__`\\/' __` __`\\   \n";
	gotoxy(5, 6);
	cout << "          \\ \\ \\ \\ \\ \\ \\ \\ \\ \\     \\ \\ \\ \\ \\//\\ \\L\\.\\_/\\ \\__/    \\ \\ \\`\\ \\/\\ \\L\\ \\ \\ \\ \\ \\ \\ \\/\\  __//\\ \\/\\ \\/\\ \\  \n";
	gotoxy(5, 7);
	cout << "           \\ \\_\\ \\ \\_\\ \\_\\ \\_\\     \\ \\_\\ \\_\\\\ \\__/.\\_\\ \\____\\    \\ \\_\\ \\_\\ \\____ \\ \\_\\ \\_\\ \\_\\ \\____\\ \\_\\ \\_\\ \\_\\ \n";
	gotoxy(5, 8);
	cout << "            \\/_/  \\/_/\\/_/\\/_/      \\/_/\\/_/ \\/__/\\/_/\\/____/     \\/_/\\/_/\\/___L\\ \\/_/\\/_/\\/_/\\/____/\\/_/\\/_/\\/_/ \n";
	gotoxy(5, 9);
	cout << "                                                                            /\\____/                               \n";
	gotoxy(5, 10);
	cout << "                                                                            \\_/__/                                \n";
}
 	
void DangNhap(){
	rectangle(0, 0, 145, 39, GREEN);
	TieuDe();
	rectangle(45, 15, 50 , 15, GREEN);
	rectangle(46, 16, 48 , 14, GREEN);	
	rectangle(52, 19, 37, 3, GREEN);
	mauChu(63, 16, RED, "=> DANG NHAP <=");
	rectangle(65, 26, 10, 3, GREEN);
	mauChu(69, 27, RED, "OK");
	mauChu(55, 19, WHITE, "NguoiDung:");
	rectangle(52, 23, 37, 3, GREEN);
	mauChu(57, 23, WHITE, "MatKhau:");
	gotoxy(55, 20);
}

void ThongBaoDN(){
	rectangle(40, 31, 60, 6, GREEN);
// mauChu(50, 32, GREEN, "Tai khoan hoac mat khau khong chinh xac!");
	mauChu(52, 32, GREEN, "Ban chua nhap tai khoan hoac mat khau!");
	mauChu(60, 33, GREEN, "vui long nhap lai!");
	mauChu(50, 35, RED, "~~~~~~~~~~~~~~~~~ENTER~~~~~~~~~~~~~~~~");
}
void clear_screen(int x, int y, int width, int height)
{
	for(int i = 0; i < height; ++i)
	{
		gotoxy(x, i + y);
		for(int j = 0; j < width; ++j)
		{
			cout << " ";
		}
	}
}
void clear_screen1()
{
	Normal();
	clear_screen(1, 1, 100, 8);
}
void clear_screen2()
{
	Normal();
	clear_screen(1, 11, 100, 25);
}
void clear_screen3()
{
	Normal();
	clear_screen(1, 38, 140, 1);
}
void clear_screen4()
{
	Normal();
	clear_screen(107, 1, 36 , 35);
}
///////////////////Code doi voi cac danh sach//////////////////

vector<char> input_check(int x, int y, int max, int width)
{
	int a = 0, b = 0;
	char key;
	vector<char> re;
	while(1)
	{
		key = getch();
		if (key==0) key = getch();
		switch(key)
		{
			case ENTER :
				re.push_back('\0');
				return re;
			case BACKSPACE :
				if(re.size() != 0) 
				{
					if(a == 0) 
					{
						b--;
						a = width;
					}
					re.pop_back();
					a--;
					gotoxy(x + a, y + b); 
					cout << " ";
					gotoxy(x + a, y + b); 
				}	
				break;
			default:				
					if(re.size() != max)
					{	
						re.push_back(key);	
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
void input_change(int x, int y, int max, int width, char *data)
{
	vector<char> ans = input_check(x, y, max, width);	
	for(int i = 0; i < ans.size(); i++) data[i] = ans[i];	
}
void insert_Lop()
{
	int x = 108, y= 10;
	 int i;
	 gotoxy(x, y);
	 cout << "So lop muon them: ";
	 cin >> i;
	 for (int j = 0; j < i; j++)
	 {
	 	LISTLOP.nodesL[j] = new Lop;
	 	gotoxy(x, y + j + 1);
	 	cout << "Nhap vao ma lop: ";
	 	input_change(x + 17, y + 1, 15, 15, LISTLOP.nodesL[j]->maLop);
	 	gotoxy(x, y + j + 2);
	 	cout << "Nhap vao ten lop: ";
	 	input_change(x + 18, y + 2, 50, 17, LISTLOP.nodesL[j]->tenLop);
	 	LISTLOP.slLop ++;
	 	cout<<endl;
	 }
	
}
void table_LOP()
{
	mauChu(35, 11, RED, "=====** DANH SACH CAC LOP **=====");
	mauChu(6, 14, WHITE, " Ma Lop                   ||   Ten Lop                     ||  So luong SV");
}
void output_Lop()
{


	int x = 7, y = 15;
	if(LISTLOP.slLop == 0)
	{
		gotoxy(x + 20, y);
		cout << "Danh sach lop hoc trong!";
		return;
	}
	table_LOP();
	gotoxy(x, y - 3);
	cout << "So luong lop: " << LISTLOP.slLop <<"/200";
	for (int i = 0; i < LISTLOP.slLop; i ++)
	{
		 gotoxy(x, y + i);	
		 cout << LISTLOP.nodesL[i]->maLop;
		 gotoxy(x + 30, y );
		 cout << LISTLOP.nodesL[i]->tenLop;
		x = 7;
		y++; 
	}
}



//------------------ DOC GHI FILE LOP ---------------
// void write_Lop(LISTLOP l)
// {
// 	ofstream fo("DSLop.txt");
// 	if(!fo)
// 	{
// 		return;
// 	}
// 	fo << 
// }

/////////////////////////////////////////
/////////////////////////MonHocKhoiTao////////////

int compare_MH(MonHoc a, MonHoc b)
{
	return strcmp(a.maMonHoc, b.maMonHoc);
}
MonHoc input_MH()
{ 
	int x = 108, y = 11;
	MonHoc a;
	gotoxy(x,y);
	cout << "Nhap ma mon hoc: ";
	input_change(x + 17, y, 15, 15, a.maMonHoc);
	gotoxy(x, y + 1);
	cout << "Nhap ten mon hoc: ";
	input_change(x + 18, y + 1, 50, 17, a.tenMonHoc);
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
void table_MH(){
	mauChu(35, 11, RED, "=====** DANH SACH CAC MON **=====");
	mauChu(6, 14, WHITE, " Ma Mon Hoc                   ||   Ten Mon Hoc              ");
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
int del_MH(TREEMH &t, char* ma)
{
	if(t == NULL)
	{
		return 0;
	}
	else if(strcmp(t->MH.maMonHoc, ma) > 0)
		return del_MH(t->left, ma);
	else if(strcmp(t->MH.maMonHoc, ma) < 0)
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
	char s[2][10] = {" nam ", " nu "};
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
	input_change(127, 11, 10, 10, sv.maSV);
	gotoxy(x, y + 1);
	cout << "Nhap Ho: ";
	input_change(117, y + 1, 25, 25, sv.Ho);
	gotoxy(x, y + 2);
	cout << "Nhap Ten: ";
	input_change(118, y + 2, 15, 15, sv.Ten);
	gotoxy(x, y + 3);
	cout << "Phai: ";
	sv.phai = sex_SV();
	gotoxy(x, y + 4);
	cout << "Password: ";
	input_change(x + 10, y + 4, 16, 16, sv.password);
}
void table_SV()
{
	mauChu(30, 11, RED, "=====** DANH SACH SINH VIEN CUA LOP **=====");
	gotoxy(7, 13);
	cout << "  MASV            ||     Ho                          ||    Ten                  ||    Phai   ";
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
	char da[4][50] = {"  A  ", "  B  ", "  C  ", "  D  "};
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
	clear_screen1();
	int x = 3, y = 1;
	int i = 0;
	LISTCH.nodesCH[i] = new CauHoi;
	gotoxy(x, y);
	cout << "Nhap cau hoi: ";
	input_change(x + 14, y, 300, 50, LISTCH.nodesCH[i]->noiDung);
	gotoxy(x, y + 3);
	cout << "A: ";
	input_change(x + 2, y + 3, 50, 50, LISTCH.nodesCH[i]->A);
	gotoxy(x, y + 4);
	cout << "B: ";
	input_change(x + 2, y + 4, 50, 50, LISTCH.nodesCH[i]->B);
	gotoxy(x, y + 5);
	cout << "C: ";
	input_change(x + 2, y + 5, 50, 50, LISTCH.nodesCH[i]->C);
	gotoxy(x, y + 6);
	cout << "D: ";
	input_change(x + 2, y + 6, 50, 50, LISTCH.nodesCH[i]->D);
	gotoxy(x, y + 7);
	cout << "Dap An: ";
	LISTCH.nodesCH[i]->dapAn = select_DA(); 
	LISTCH.slCauHoi++;
}
void table_CH()
{
	mauChu(35, 11, RED, "=====** DANH SACH CAU HOI **=====");
	mauChu(6, 14, WHITE, " Cau hoi                                          ||   Dap an  ");
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
	SetBGColor(BLACK);
	int x = 7, y = 15;
	if(LISTCH.slCauHoi == 0)
	{
		gotoxy(x + 20, y);
		cout << "Danh cau hoi trong!";
		return;
	}
	table_CH();
	for (int i = 0; i < LISTCH.slCauHoi; i++)
	{
		 gotoxy(x, y + i);	
		 cout << LISTCH.nodesCH[i]->noiDung;
		 gotoxy(x + 54, y + i);
		 dapan(LISTCH.nodesCH[i]->dapAn);
		x = 7;
		y++; 
	}
}
////////////////////////
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
 	DangNhap();
 	getch();
 	// ThongBaoDN();
 	MenuGV(menu1);
 	SetBGColor(BLACK);
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
 	// insert_Lop();
 	// output_Lop();
	// LNR(t);
	insert_CH();
	output_CH();
 	getch();

	return 0;
}
