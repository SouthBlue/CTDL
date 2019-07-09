#include <iostream>
#include <iomanip>
//#include <mylib.h>
#include <string>
//#include "Display.h"

using namespace std;

#define MAXLOP 10

typedef struct Lop{
	string maLop;
	string tenLop;
	//SV First;
};

//typedef struct listLop{
//	//int slLop;
//	Lop *nodesL[MAXLOP];
//};
//void nhap_thong_tin_sinhvien(Lop &sv)
//{
//	
//}
void nhapLop(Lop *listlop[]) {
	for (int i = 0; i < MAXLOP; i++)
	{
		//string malop;
		listlop[i] = new Lop;
		cout << "Nhap vao ma lop";
		cin >> listlop[i]->maLop;
		cout << "Nhap vao ten lop";
		cin >> listlop[i]->tenLop;
		//listlop[i].maLop = malop; 
	}
}

void xuatLop(Lop *listlop[]) {
	for(int i = 0; i < MAXLOP; i++)
	{
		cout << "Thong tin lop thu " << i << endl;
		cout << "Ma lop thu " << i << " : " << listlop[i]->maLop << endl;
		cout << "Ten lop thu " << i << " : " << listlop[i]->tenLop << endl;
	}
}

int main(){
	Lop *listlop[MAXLOP];
	nhapLop(listlop);
	xuatLop(listlop);
}


