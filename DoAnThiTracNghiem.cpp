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
	char Ho[31];
	char Ten[21];
	float phai;
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
	char noiDung[1000];
	char A[50];
	char B[50];
	char C[50];
	char D[50];
	int dapAn;
};
struct nodeCauHoi{
	int slCauHoi;
	CauHoi *nodesCH[MAXCAUHOI];	
};

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
//////////////////////////////////SINH VIEN/////////////
void create_ListSV(LISTSV &l)
{
	l.svFirst = l.svLast = NULL;
}
NODESV* createNode_SV(SinhVien x)
{
	NODESV *p = new NODESV;
	if(p == NULL)
	{
		return NULL;
	}
	p->sv = x;
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

void input_SV(SinhVien &sv)
{
	
	int x = 108, y = 11; 
	fflush(stdin);
	gotoxy(x, y);
	cout << "Nhap ma sinh vien: ";
	input_change(127, 11, 10, 10, sv.maSV);
	gotoxy(x, y + 1);
	cout << "Nhap Ho: ";
	input_change(117, y + 1, 30, 17, sv.Ho);
	gotoxy(x, y + 2);
	cout << "Nhap Ten: ";
	input_change(118, y + 2, 20, 10, sv.Ten);
	gotoxy(x, y + 3);
	cout << "phai: ";
	cin >> sv.phai;
}
void table_SV()
{
	gotoxy(7, 13);
	cout << "  MASV            ||     Ho                       ||    Ten                  ||    Phai   ";
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
	gotoxy(x + 54, y);
	cout << sv.Ten;
	gotoxy(x + 81, y);
	sex_SV(sv.phai);
}

void inputlist_SV(LISTSV &l)
{

	create_ListSV(l);
	SinhVien x;
	input_SV(x);
	NODESV *p = createNode_SV(x);
	AddTail_SV(l, p);	
}
void outputlist_SV(LISTSV l)
{
	table_SV();
	NODESV *p;
	p = l.svFirst;
	while(p != NULL)
	{
		output_SV(9, 14, p->sv);
		p = p->svnext;
	}
}
// void AddAfter(NODESV *node, NODESV *before)
// {
//    if (!before)
//    {
// 		node->svnext = before->svnext; //s?a liên k?t c?a node m?i
// 		before->svnext = node; //s?a l?i lk c?a node có s?n
// 		if (LISTSV.svLast == before)
// 			LISTSV.svLast = node; //s?a l?i con tr? ch? danh sách
//    }
//    else
//       AddHead();
// }
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

 	
	LISTSV l;
 	inputlist_SV(l);
 	outputlist_SV(l);
 	// insert_Lop();
 	// output_Lop();

 	getch();

	return 0;
}
