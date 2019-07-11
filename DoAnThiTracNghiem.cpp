#include <iostream>
#include <iomanip>
#include "mylib.h"
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
	char Ho[20];
	char TenDem[20];
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
typedef struct nodeSinhVien* NODESV;

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
	char maLop[15];
	char tenLop[50];
	NODESV First;
};

// Khoi tao mang con tro lop
struct listLop{
	int slLop;
	Lop *nodesL[MAXLOP];
};

listLop listLp;

struct CauHoi{
	int id;
	char maMonHoc[16];
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
		gotoxy(3+i*20, 37);
		cout<< td2[i];
	}
}
int MenuGV(char td[so_item1][30]){
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
	NODESV p = new NODESV;
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
void input_SV(LISTSV &l)
{

	initialize_SV(l);

		SinhVien a;
		gotoxy(112, 10);
		cout << "Ma Sinh Vien: ";
		cin >> a.maSV;
		// gotoxy(112, 11);
		// cout << "Ho: ";
		// cin >> a.Ho;
		// gotoxy(112, 12);
		// cout << "Ten: ";
		// cin >> a.Ten;
		// gotoxy(112, 13);
		// cout << "Phai: ";
		// cin >> a.phai;
		// gotoxy(112, 14);
		// cout << "Password: ";
		// cin >> a.password;
		NODESV *p = Get_nodeSV(a);
		insertFist_SV(l, p);

}
void table_SV()
{
	gotoxy(2, 13);
	cout << "         MASV       ||              Ho             ||          Ten            ||    Phai   ||";
}

void sex_SV(bool x)
{
	if(x == 1)
	{
		cout << "nam";
	}
	else cout << "nu";
}

void output_SV(LISTSV l)
{

	int x = 2, y = 14;
	table_SV();
	for(NODESV *p = l.svFirst; l.svFirst != NULL; p = p -> svnext)
	{	
		gotoxy(x, y);
		cout << p->sv.maSV;
		// gotoxy(x + 23, y); 
		// cout << p->sv.Ho;
		// gotoxy(x + 31, y);
		// cout << p->sv.Ten;
		// gotoxy(x + 19, y);
		// sex_SV(p->sv.phai);
		// x = 2;
		// y++;
	}
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

	nhapLop();
	xuatLop();
	getch();
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	resizeConsole();
	DangNhap();
	getch();
//	ThongBaoDN();
	MenuGV(menu1);
	SetBGColor(BLACK);
	LISTSV l;
	input_SV(l);
	output_SV(l);
	getch();
}
