#ifndef DSLISTS_H
//#include "mylib.h"
#include "hienthi.h"
#include "nhapxuat.h"
#include <fstream>

const int MAXLOP = 500;
const int MAXCAUHOI = 2000;


using namespace std;

struct MonHoc{
	string maMonHoc;
	string tenMonHoc;
	void read_MH(ifstream &file);
	void write_MH(ofstream &file);
};
// Khoi tao cay nhi phan
struct nodeMonHoc{
	nodeMonHoc(MonHoc a){
		MH = a;
		left = NULL;
		right = NULL;
	}
	MonHoc MH;     	
	struct nodeMonHoc *left;
	struct nodeMonHoc *right;
};
typedef struct nodeMonHoc *NODEMH;
struct listMonHoc
{
	int slmh;
	NODEMH root = NULL;
//	void LNR(NODEMH &t);
	void LNRkodequy();
	NODEMH CreateNode(MonHoc a);
	NODEMH FindInsert(MonHoc a);
	bool InsertNode(MonHoc a);
	NODEMH SearchNode_Re(NODEMH p, MonHoc a);
	void add_MH();
	void read_listMH();
	void write_listMH();
};

struct DiemThi{
	string maMonHoc;
	float diem;
};
// Khoi tao danh sach diem thi (danh sach lien ket don)
struct nodeDiemThi{
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
struct SinhVien{
	string maSV;
	string Ho;
	string Ten;
	bool phai;
	string password;
	NODEDIEM FirstDiem;
	bool sexs_SV();
	void password_in(int x, int y, int width, string &pass);
	bool insert_SV();
	void sex_SV(bool x);
	void output_SV(int x, int y);
	void read_SV(ifstream &);
	void write_SV(ofstream &);
};
// Khoi tao danh sach lien ket don sinh vien
struct nodeSinhVien{
	SinhVien sv;
	struct nodeSinhVien *svnext;
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
	bool find(SinhVien a);
	void del_SV(int);
	void delall_SV();
	void read_listSV(ifstream &);
	void write_listSV(ofstream &);
};
typedef struct listSinhVien LISTSV;
//////////////////lop
struct Lop{
	string maLop;
	string tenLop;
	LISTSV First;
	bool insertinfo_Lop();
	void read_Lop(ifstream &);
	void write_Lop(ofstream &);
};

// khai bao mang con tro lop


struct listLop{
	int slLop = 0;
	Lop *nodesL[MAXLOP];
	void insert_Lop();
	void output_Lop();
	int select_Lop(int chon);
	bool find_Lop(string);
	void del_Lop(int vitri);
	void write_listLop();
	void read_listLop();
	
};

typedef struct listLop LISTLOP;
////////////////////////////
struct CauHoi{
	int id;
	string noiDung;
	string A;
	string B;
	string C;
	string D;
	int dapAn;
};
struct listCauHoi{
	int slCauHoi;
	CauHoi *nodesCH[MAXCAUHOI];	
};
typedef struct listCauHoi LISTCH;
#endif
