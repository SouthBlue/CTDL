#include <iostream>
#include <iomanip>
#include <mylib.h>
#include <string>
#include "Display.h"
using namespace std;

const int so_item1 = 4;
const int so_item2 = 5;
const int dong = 2;
const int cot = 3;
const int Up = 72;
const int Down = 80;
const int RIGHT = 77;
const int LEFT = 75;

#define MAXLOP 500
#define MAXCAUHOI 2000
						   

// khai bao ds
// Khai bao mon hoc (cay nhi phan)
typedef struct MonHoc{
	string maMonHoc[16];
	string tenMonHoc;
};
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
struct Lop{
	string maLop;
	string tenLop;
	//nodeSV First;
};

// Khoi tao mang con tro lop
struct listLop{
	int slLop;
	Lop *nodesL[MAXLOP];
};

listLop listLp;

struct CauHoi{
	int id;
	string maMonHoc;
	string noiDung;
	string A;
	string B;
	string C;
	string D;
	string dapAn;
};
struct nodeCauHoi{
	int slCauHoi;
	CauHoi *nodesCH[MAXCAUHOI];	
};

///////////////////Code doi voi cac danh sach//////////////////

void nhapLop()
{
	int i;
	cout << "nhap vao so lop muon them " << endl;
	cin >> i;
	for (int j = 0; j < i; j++)
	{
		listLp.nodesL[j] = new Lop;
		cout << "Nhap vao ma lop: ";
		cin >> listLp.nodesL[j]->maLop;
		cout << "Nhap vao ten lop: ";
		cin >> listLp.nodesL[j]->tenLop;
		listLp.slLop ++;

	}
}
void xuatLop()
{
	cout << "So luong lop hien tai la" << listLp.slLop << endl;
	for (int i = 0; i <= listLp.slLop; i ++)
	{
		cout << "Thong tin cac lop la: " << endl;
		cout << "Ma lop: " << listLp.nodesL[i]->maLop << endl;
		cout << "Ten Lop: " << listLp.nodesL[i]->tenLop << endl;
		cout << "////////////////////" << endl;
	}
}










/////////////////////////////////////////

char menu1 [so_item1][30] = {"Lop", 
							 "Cau Hoi Thi",
						  	 "Mon Hoc",
						  	 "Bang Diem",
						   	};
						   	 
char menu2 [so_item2][50] = {"Nhan: ", "<-, ->: Di chuyen", "Enter: Chon", "Esc: Thoat"};

void Normal(){
	SetColor(3);
	SetBGColor(0);
}
void HighLight(){
	SetColor(3);
	SetBGColor(15);
}
void rectangle(int x, int y, int width, int height)
{
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
}
void GiaoDienGV(){
	SetColor(3);
	rectangle(0, 0, 105, 5);
	rectangle(0, 5, 105, 31);
	rectangle(106, 0, 38, 36);
	rectangle(0, 36, 144, 4);
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
		gotoxy(3+i*20, 37);
		cout<< td2[i];
	}
}
int MenuGV(char td[so_item1][30]){
	GiaoDienGV();
	press_key(menu2);
	int chon =0;
 	int i;
 	for ( i=0; i< so_item1 ; i++){
	 	gotoxy(cot + 20*i, dong);
    	cout << td[i];
 	}
	  HighLight();
	  gotoxy(cot + 20*chon, dong);
	  cout << td[chon];
	  char kytu;
	do {
	  kytu = getch();
	  if (kytu==0) kytu = getch();
	  switch (kytu) {
	    case LEFT :if (chon+1 >1)
	  			  {
	  		        Normal();
	              	gotoxy(cot + chon*20, dong);
	              	cout << td[chon];
	              	chon --;
	              	HighLight();
	              	gotoxy(cot + chon*20,dong);
              	cout << td[chon];
  				
	  			  }
	  			  break;
	  	case RIGHT :if (chon+1 <so_item1)
	  			  {
	  		        Normal();
	              	gotoxy(cot + chon*20, dong);
	              	cout << td[chon];
	              	chon ++;
	              	HighLight();
	              	gotoxy(cot + chon*20, dong);
	              	cout << td[chon];
	  				
	  			  }
	  			  break;
	  	case 13 : return chon+1;
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
	
	SetColor(3);
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



void resizeConsole(){
	
	HWND console = GetConsoleWindow();
	SetWindowPos(console, 0, 50, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1200, 700, TRUE);
}




int main(){

	nhapLop();
	xuatLop();
	getch();
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	resizeConsole();
//	DangNhap();
// 	ThongBaoDN();
//	MenuGV(menu1);
}
