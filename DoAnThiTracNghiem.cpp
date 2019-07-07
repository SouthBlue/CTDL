#include <iostream>
#include <iomanip>
#include <mylib.h>
#include <string>
using namespace std;

const int so_item1 = 5;
const int so_item2 = 5;
const int dong = 2;
const int cot = 3;
const int Up = 72;
const int Down = 80;
const int RIGHT = 77;
const int LEFT = 75;

#define MAXLOP 500;
#define MAXCAUHOI 2000;
						   

// khai bao ds
typedef struct MonHoc{
	string maMonHoc;
	string tenMonHoc;
};
typedef struct listMonHoc{
	int slMonHoc;
	listMonHoc *left;
	listMonHoc *right;
};

typedef struct DiemThi{
	string maMonHoc;
	float diem;
};
typedef struct nodeDiemThi{
	DiemThi dt;
	struct nodeDiemThi *next;
};
typedef struct nodeDiemThi *Diem;

typedef struct SinhVien{
	int maSV;
	string ho;
	string tenDem;
	string ten;
	float phai;
	char password;
	Diem FirstDiem;
};
typedef struct nodeSinhVien{
	SinhVien sv;
	struct nodeSinhVien *next;
};
typedef struct nodeSinhVien *SV

typedef struct Lop{
	string maLop;
	string tenLop;
	SV First;
};
typedef struct listLop{
	int slLop;
	lop nodesL[MAXLOP];
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
	CauHoi nodesCH[MAXCAUHOI];	
};

/////////////////////

char menu1 [so_item1][30] = {"Nhap Lop",
							 "In Danh Sach Lop",
						  	 "Nhap SV Cua Lop",
						  	 "Nhap Mon Hoc",
						   	 "Nhap Cau Hoi Thi"};
						   	 
char menu2 [so_item2][50] = {"Nhan: ", "<-, ->: De di chuyen", "Enter: De chon", "Esc: De thoat"};

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
	cout<<static_cast<char>(201);
	for(int i = x; i < x+width-2; i++){
		gotoxy(i+1,y);
		cout<<static_cast<char>(205);
		gotoxy(i+1,y+height-1);
		cout<<static_cast<char>(205);
	}
	gotoxy(x+width-1,y);
	cout<<static_cast<char>(187)<<endl;
	for(int i = y; i < y+height-1; i++){
		gotoxy(x, i+1);
		cout<<static_cast<char>(186);
		gotoxy(x+width-1,i+1);
		cout<<static_cast<char>(186)<<endl;
	}
	gotoxy(x,y+height-1);
	cout<<static_cast<char>(200);
	gotoxy(x+width-1, y+height-1);
	cout<<static_cast<char>(188);

}
void teacherInterface(){
	SetColor(3);
	rectangle(0, 0, 105, 5);
	rectangle(0, 5, 105, 33);
	rectangle(106, 0, 60, 38);
	rectangle(0, 38, 166, 3);
}
void press_key(char td2[so_item2][50]){
	for(int i = 0; i< so_item2; i++){
		gotoxy(3+i*30, 39);
		cout<< td2[i];
	}
}
int teacherMenu(char td[so_item1][30]){
	teacherInterface();
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
						   

 	
void loginDisplay(){
	SetColor(3);
	for(int i = 60; i < 110; i++){
		for(int j = 15; j < 28; j++){
		gotoxy(i,j); 
		if(i>62 && i<107 && j>15 && j<27 ) cout<<" ";
		cout << static_cast<char>(219);	
		}
	}		
	gotoxy(70,19);
	cout << "UserName:";
	gotoxy(70,21);
	cout << "Password:";
	for(int i=70; i<100; i++){		
		gotoxy(i, 24);
		cout << static_cast<char>(219);
	}
	gotoxy(82, 24); cout << "LOGIN";

}


void resizeConsole(){
	
	HWND console = GetConsoleWindow();
	SetWindowPos(console, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1365, 730, TRUE);
}




int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	resizeConsole();
//	loginDisplay();
	teacherMenu(menu1);
	getch();
}
