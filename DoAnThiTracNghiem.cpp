#include <iostream>
#include <iomanip>
#include "mylib.h"
#include <string>
#include "Display.h"


using namespace std;

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
#define MAXLOP 500
#define MAXCAUHOI 2000
#define WHITE 15
#define BLACK 0
#define BLUE 3
#define GREEN 10
#define RED 4
						   
const int so_item1 = 4;
const int so_item2 = 3;
const int so_item3 = 5;
const int dong = 4;
const int cot = 10;
// khai bao ds
// Khai bao mon hoc (cay nhi phan)
typedef struct MonHoc{
	char maMonHoc[16];
	char tenMonHoc[100];
};
// Khoi tao cay nhi phan
typedef struct nodeMonHoc{
	MonHoc MH;     ///// + ////
	struct nodeMonHoc *left;
	struct nodeMonHoc *right;
};
typedef struct nodeMonHoc *NODEMH;
NODEMH TREEMH;
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
	char Ho[50];
	char Ten[20];
	float phai;
	char password[32];
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

typedef struct nodeGiaoVien *NODEGV;

///Khoi tao danh sach lien ket don giao vien

struct listGiaoVien
{
	NODEGV *pFirst;
	NODEGV *pLast;
};

typedef struct listGiaoVien LISTGV;



// Khai bao lop
typedef struct Lop{
	char maLop[15];
	char tenLop[50];
	NODESV First;
};

// Khoi tao mang con tro lop
typedef struct listLop{
	int slLop;
	Lop *nodesL[MAXLOP];
};

typedef struct CauHoi{
	int id;
	char maMonHoc[16];
	char noiDung[1000];
	char A[1];
	char B[1];
	char C[1];
	char D[1];
	char dapAn[1];
};
typedef struct nodeCauHoi{
	int slCauHoi;
	CauHoi *nodesCH[MAXCAUHOI];	
};

/////////////////////////////////////////

char menu1 [so_item1][30] = {"    Lop    ", " Cau Hoi Thi", "  Mon Hoc  ", " Bang Diem "};					   	 
char menu2 [so_item2][50] = {"<-  ->: Di chuyen", "      Enter: Chon", "       Esc: Thoat"};
char menuLop [so_item3][50] = {"Esc: Quay lai", "F1: Menu chinh", "Enter: Chon lop", "Delete: Xoa lop", "Insert: Them lop"};

void Normal(){
	SetColor(BLUE);
	SetBGColor(BLACK);
}
void HighLight(){
	SetColor(BLUE);
	SetBGColor(WHITE);	
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
		gotoxy(40+i*20, 38);
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
	  	case ENTER : return chon+1;
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

/////////////////////////MonHocKhoiTao////////////
void KhoiTao_MH(NODEMH &root){

	root = NULL;

}
bool empty_MH(NODEMH root){
	return(root = NULL);
}

// void insert_MH(NODEMH &p, MonHoc a){
// 	if(p==NULL){
// 		p = new NODEMH;
// 		p->MH = a;
// 		p->left = NULL; p->right = NULL;
// 	}
// 	else
// 		if( p->MH > a)
// 			insert_MH(p->left,a);
// 		else 
// 			if(p->MH < a) 
// 			insert_MH(p->right,a);
// }

////////////////SINHVIEN////////////
void initialize_SV(LISTSV &l)
{
	l.svFirst = l.svLast = NULL;
}

NODESV* Get_nodeSV(SinhVien a)
{
	NODESV *p = new NODESV;
	if(p == NULL)
	{
		return NULL;
	}
	p -> sv = a;
	p -> svnext = NULL;
	return p;
}

void insertFist_SV(LISTSV &l, NODESV *p)
{
	if(l.svFirst == NULL)
	{
		l.svFirst == l.svLast == NULL;
	}
	else
	{
		p -> svnext = l.svFirst;
		l.svFirst = p;
	}
}
void insertLast_SV(LISTSV &l, NODESV *p)
{
	if(l.svFirst == NULL)
	{
		l.svFirst == l.svLast == NULL;
	}
	else
	{
		l.svLast -> svnext = p;
		l.svLast = p; 
	}
	
}
void Input_SV(LISTSV &l)
{
	
}

///////////////////////////////////
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
//	ThongBaoDN();
	MenuGV(menu1);
	getch();
}
