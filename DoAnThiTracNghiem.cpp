#include <iostream>
#include <iomanip>
#include <mylib.h>
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
	string maMonHoc[16];
	string tenMonHoc;
};
typedef struct listMonHoc{
	int slMonHoc;
	MonHoc mh;
	listMonHoc *left;
	listMonHoc *right;
};
typedef struct listMonHoc *MH;

// Khoi tao cay nhi phan
typedef struct nodeMonHoc{
	MonHoc MH;     ///// + ////
	struct nodeMonHoc *left;
	struct nodeMonHoc *right;
};
typedef struct nodeMonHoc *nodeMH;
nodeMH tree;
// Khoi tao thong tin diem thi
typedef struct DiemThi{
	string maMonHoc;
	float diem;
};
// Khoi tao danh sach diem thi (danh sach lien ket don)
typedef struct nodeDiemThi{
	DiemThi dt;
	struct nodeDiemThi *next;
};
typedef struct nodeDiemThi *nodeDiem; /// + ///

struct listDiemThi
{
	nodeDiem *pLast;
	nodeDiem *pFirst;
};

typedef struct listDiemThi listDiem;

// Khai bao thong tin sinhvien
typedef struct SinhVien{
	string maSV;
	string Ho;
	string Ten;
	float phai;
	char password;
	nodeDiem FirstDiem;
};
// Khoi tao danh sach lien ket don sinh vien
typedef struct nodeSinhVien{
	SinhVien sv;
	struct nodeSinhVien *next;
};
typedef struct nodeSinhVien *nodeSV;

struct listSinhVien
{
	nodeSV *pLast;
	nodeSV *pFirst;
};

typedef struct listSinhVien  listSV;

// Khai bao giao vien

typedef struct GiaoVien
{
	string MaGV;
	string Ho;
	string Ten;
	string Chucvu;
	float phai;
	char password;
};

typedef struct nodeGiaoVien
{
	GiaoVien GV;
	struct nodeGiaoVien *next;
};

typedef struct nodeGiaoVien *nodeGV;

///Khoi tao danh sach lien ket don giao vien

struct listGiaoVien
{
	nodeGV *pFirst;
	nodeGV *pLast;
};

typedef struct listGiaoVien listGV;



// Khai bao lop
typedef struct Lop{
	string maLop;
	string tenLop;
	nodeSV First;
};

// Khoi tao mang con tro lop
typedef struct listLop{
	int slLop;
	Lop *nodesL[MAXLOP];
};

typedef struct CauHoi{
	int id;
	string maMonHoc;
	string noiDung;
	string A;
	string B;
	string C;
	string D;
	string dapAn;
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

}
void GiaoDienGV(){
	SetColor(3);
	rectangle(0, 0, 105, 10);
	rectangle(0, 10, 105, 27);
	rectangle(106, 0, 38, 37);
	rectangle(0, 37, 144, 3);
	gotoxy(112, 1);
	cout << "=======> THONG TIN <========";
	gotoxy(3, 37);
	cout << "---> HUONG DAN <---";
}
void press_key(char td2[so_item2][50]){
	for(int i = 0; i< so_item2; i++){
		gotoxy(40+i*20, 38);
		cout<< td2[i];
	}
}
int MenuGV(char td[so_item1][30]){
	system("cls");
	GiaoDienGV();
	rectangle(8, 3, 15, 3);
	rectangle(34, 3, 15, 3);
	rectangle(58, 3, 15, 3);
	rectangle(83, 3, 15, 3);
	press_key(menu2);
	int chon =0;
 	int i;
 	for ( i=0; i< so_item1 ; i++){
	 	gotoxy(cot + 25*i, dong);
    	cout << td[i];
 	}
	  HighLight();
	  gotoxy(cot + 25*chon, dong);
	  cout << td[chon];
	  char kytu;
	do {
	  kytu = getch();
	  if (kytu==0) kytu = getch();
	  switch (kytu) {
	    case LEFT :if (chon+1 >1)
	  			  {
	  		        Normal();
	              	gotoxy(cot + chon*25, dong);
	              	cout << td[chon];
	              	chon --;
	              	HighLight();
	              	gotoxy(cot + chon*25,dong);
              		cout << td[chon];		
	  			  }
	  			  break;
	  	case RIGHT :if (chon+1 <so_item1)
	  			  {
	  		        Normal();
	              	gotoxy(cot + chon*25, dong);
	              	cout << td[chon];
	              	chon ++;
	              	HighLight();
	              	gotoxy(cot + chon*25, dong);
	              	cout << td[chon];	
	  			  }
	  			  break;
	  	case ENTER : return chon+1;
	  } 
	  } while (1);
}	
						   
void TieuDe(){
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
	
	SetColor(GREEN);
	rectangle(0, 0, 145, 39);
	TieuDe();
	rectangle(45, 15, 50 , 15);
	rectangle(46, 16, 48 , 14);	
	rectangle(52, 19, 37, 3);
	gotoxy(55,19);
	cout << "NguoiDung:";
	rectangle(52, 23, 37, 3);
	gotoxy(57,23);
	cout << "MatKhau:";
	gotoxy(63, 16); cout << "=> DANG NHAP <=";
	rectangle(65, 26, 10, 3);
	gotoxy(69, 27);
	cout << "OK";
}

void ThongBaoDN(){
	rectangle(40, 31, 60, 6);
//	gotoxy(50, 32);
//	cout << "Tai khoan hoac mat khau khong chinh xac!";
	gotoxy(52, 32);
	cout << "Ban chua nhap tai khoan hoac mat khau!";
	gotoxy(60, 33);
	cout << "vui long nhap lai!";
	gotoxy(50, 35);
	cout << "~~~~~~~~~~~~~~~~~ENTER~~~~~~~~~~~~~~~~";
}
///////////////////////////Lop////////////////////

/////////////////////////MonHoc////////////
void KhoiTao_MH(MH &root){

	root = NULL;

}
bool empty_MH(MH root){
	return(root = NULL);
}

void insert_MH(MH &p, int x, MonHoc a){
	if(p==NULL){
		p = new listMonHoc;
		p->slMonHoc = x; p->mh = a;
		p->left = NULL; p->right = NULL;
	}
	else
		if(x < p->slMonHoc)
			insert_MH(p->left,x,a);
		else 
			if(x > p->slMonHoc) insert_MH(p->right,x,a);
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
	DangNhap();
	getch();
//	ThongBaoDN();
	MenuGV(menu1);
	getch();
}
