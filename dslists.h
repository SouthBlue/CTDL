#ifndef DSLISTS_H
#include "mylib.h"
#include "hienthi.h"
#include "nhapxuat.h"
#include <fstream>
#define MAXLOP 500
#define MAXCAUHOI 2000

using namespace std;
// khai bao ds
// Khai bao mon hoc (cay nhi phan)
typedef struct MonHoc{
	string maMonHoc;
	string tenMonHoc;
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
	string maMonHoc;
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
	string maSV;
	string Ho;
	string Ten;
	bool phai;
	string password;
	NODEDIEM FirstDiem;
	bool sexs_SV();
	void password_in(int x, int y, int width, string &pass);
	void insert_SV();
	void sex_SV(bool x);
	void output_SV(int x, int y);
	void read_SV(ifstream &fsv);
	void write_SV(ofstream &fsv);
};
// Khoi tao danh sach lien ket don sinh vien
typedef struct nodeSinhVien{
	SinhVien sv;
	struct nodeSinhVien *svnext;
//	NODESV *createNode_SV();
};
typedef struct nodeSinhVien NODESV;
struct listSinhVien
{
	int slsv = 0;
	NODESV *svLast = NULL;
	NODESV *svFirst = NULL;
	void insertlist_SV();
	void outputlist_SV();
//	void AddHead_SV(SinhVien sv);
	void AddTail_SV(SinhVien sv);
	void read_listSV();
	void write_listSV();
};
typedef struct listSinhVien LISTSV;
//////////////////lop
typedef struct Lop{
	string maLop;
	string tenLop;
	NODESV First;
};

// khai bao mang con tro lop


typedef struct listLop{
	int slLop = 0;
	Lop *nodesL[MAXLOP];
	void insert_Lop();
	void output_Lop();
	void del_Lop(int vitri);
	void write_Lop();
	void read_Lop();
};

typedef struct listLop LISTLOP;


typedef struct CauHoi{
	int id;
	string noiDung;
	string A;
	string B;
	string C;
	string D;
	int dapAn;
};
typedef struct listCauHoi{
	int slCauHoi;
	CauHoi *nodesCH[MAXCAUHOI];
	//void dapan(int a);
	int select_DA();
	void DA_CauHoi(int x);
	void insert_CH();
	void output_CH();
	void write_CauHoi();
	void read_CauHoi();
	void output1_CH(int chon);
	void del_CauHoi( int vitri);
};
typedef struct listCauHoi LISTCH;
#endif
