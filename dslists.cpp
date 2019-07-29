#include "dslists.h"
int xmh = 7, ymh = 15;
///////////////////////lop//////////
bool Lop::insertinfo_Lop()
{
	int x = 108, y= 12;
	mauChu(x, y, RED, "-----THEM LOP-----");
	gotoxy(x, y + 1);
	cout << "Nhap vao ma lop: ";
	input_check(x + 17, y + 1, 15, 15, maLop);
	gotoxy(x, y + 2);
	cout << "Nhap vao ten lop: ";
	input_check(x + 18, y + 2, 50, 17, tenLop);
	if(maLop == "" || tenLop == "")
	{
		return 0;
	}
	else{
		return 1;
	}

}
void Lop::read_Lop(ifstream &fl)
{
	fl.ignore();
	getline(fl, maLop, '@');
	fl.ignore();
	getline(fl, tenLop, '@');
	First.read_listSV(fl);
}
void Lop::write_Lop(ofstream &fl)
{
	fl << maLop <<"@ ";
	fl << tenLop <<"@ ";
	First.write_listSV(fl);
}
bool listLop::find_Lop(string ma)
{
	for(int i = 0; i < slLop; i++)
	{
		if(ma.compare(nodesL[i]->maLop) ==0)
		{
			return 1;
		}
	}
	return 0;
}
void listLop::insert_Lop()
{
	Nocursortype(1);
	nodesL[slLop] = new Lop;
	bool e = nodesL[slLop]->insertinfo_Lop();
	if(find_Lop(nodesL[slLop]->maLop))
	{
		mauChu(113, 4, YELLOW, "MA LOP DA TON TAI!");
		Nocursortype(0);
		return;
	}
	else
	{
		if(e)
		{
			slLop++;
			mauChu(113, 4, YELLOW, "THEM LOP THANH CONG!");	
		}
		else
		{
			mauChu(113, 4, YELLOW, "THEM LOP KHONG THANH CONG!");	
		}
	}
	Nocursortype(0);
}
void listLop::output_Lop()
{
	
	int x = 7, y = 15;
	table_LOP();
	gotoxy(x, y - 3);
	cout << "So luong lop: " << slLop <<"/200";
	if(slLop <= 0)
	{
		gotoxy(x + 20, y + 1);
		cout << "Danh sach lop hoc trong!";
		return;
	}
	for (int i = 0; i < slLop; i ++)
	{
		 gotoxy(x, y);	
		 cout << nodesL[i]->maLop;
		 gotoxy(x + 30, y );
		 cout << nodesL[i]->tenLop;
		 gotoxy(x + 62, y);
		 cout << nodesL[i]->First.slsv;
		x = 7;
		y++; 
	}
}
void listLop::del_Lop(int vitri)
{
	for(int i = vitri; i < slLop - 1; i++)
	{
		nodesL[i]->maLop = nodesL[i + 1]->maLop;
		nodesL[i]->tenLop = nodesL[i + 1]->tenLop;
		nodesL[i]->First.delall_SV();
	}
	slLop--;
}
void listLop::write_listLop()
{
	ofstream fl("DSlop.txt");
	fl << slLop << "\n";
	for(int i = 0; i < slLop; i++)
	{
		nodesL[i]->write_Lop(fl);
	}
	fl.close();
}
void listLop::read_listLop()
{
	ifstream fl("DSlop.txt");
	fl >> slLop;
	for(int i = 0; i < slLop; i++)
	{
		nodesL[i] = new Lop;
		nodesL[i]->read_Lop(fl);
	}
	fl.close();
}

///////////////////////sinh vien.///////
NODESV *createNode_SV(SinhVien a)
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
//void listSinhVien::listAddHead_SV(NODESV *p)
//{
//   if (svFirst == NULL) 
//      svFirst  = svLast = p;
//   else
//   {
//      p->svnext = svFirst; 
//      svFirst = p; 
//   }
//}
void listSinhVien::AddTail_SV(SinhVien a)
{
	NODESV *p = new NODESV;
	p->sv = a;
	p->svnext = NULL;
   if (svFirst == NULL) 
    	svFirst  = svLast = p;
   else
   {
      	svLast->svnext = p;
      	svLast = p;
   }
}
bool SinhVien::sexs_SV()
{
	string s[2] = {" nam ", " nu "};
	bool chon = true;
	for(int i = 0; i < 2; i++)
	{
		mauChu(120 + i*10, 16, RED, s[i]);
	}
	HighLight();
	mauChu(120, 16, RED, s[0]);
	char key;
	do{
		key = getch();
		if(key == 0) key= getch();
		switch (key){
			case LEFT: 
				    chon = true;
					Normal();
	              	mauChu(120 + 10, 16, RED, s[1]);	
	              	HighLight();
	              	mauChu(120, 16, RED, s[0]);
				break;
			case RIGHT:
				    chon = false;
					Normal();
	              	mauChu(120, 16, RED, s[0]);
	              	HighLight();
	              	mauChu(120 + 10, 16, RED, s[1]);
				break;
			case ENTER:
				 	SetBGColor(BLACK);
					return chon;
		}
	} while(1);

}
void SinhVien::password_in(int x, int y, int width, string &pass)
 {
 	int a = 0, b = 0;
	char key;
	string result;
	while(1)
	{
		key = getch();
		if (key==0) key = getch();
		switch(key)
		{
			case ENTER :
				pass = result;
				return;
			case SPACE :
				break;
			case BACKSPACE :
				if(result.size() != 0) 
				{
					if(a == 0) 
					{
						b--;
						a = width;
					}
					result.pop_back();
					a--;
					gotoxy(x + a, y + b); 
					cout << " ";
					gotoxy(x + a, y + b); 
				}	
				break;
			default:				
					if(result.length() != width)
					{	
						result.push_back(key);	
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
 bool SinhVien::insert_SV()
{
	int x = 108, y = 12; 
	fflush(stdin);
	mauChu(x, y, RED, "----Them sinh vien----");
	gotoxy(x, y + 1);
	cout << "Nhap ma sinh vien: ";
	input_check(127, y + 1, 10, 10, maSV);
	gotoxy(x, y + 2);
	cout << "Nhap Ho: ";
	input_check(117, y + 2, 25, 25, Ho);
	gotoxy(x, y + 3);
	cout << "Nhap Ten: ";
	input_check(118, y + 3, 15, 15, Ten);
	gotoxy(x, y + 4);
	cout << "Phai: ";
	phai = sexs_SV();
	gotoxy(x, y + 5);
	cout << "Password: ";
	password_in(x + 10, y + 5, 16, password);
	if(maSV == "" || Ho == "" || Ten == "" || password == "")
	{
		return 0;
	}
	else  return 1;
}
void SinhVien::sex_SV(bool x)
{
	if(x == 1)
	{
		cout << "nam";
	}
	else cout << "nu";
}
void SinhVien::output_SV(int x, int y)
{
	gotoxy(x, y);
	cout << maSV;
	gotoxy(x + 25, y);
	cout << Ho;
	gotoxy(x + 59, y);
	cout << Ten;
	gotoxy(x + 86, y);
	sex_SV(phai);
}
void listSinhVien::insertlist_SV()
{
	Nocursortype(1);
	clear_screen5();
	SinhVien a;
	bool s = a.insert_SV();
	if(find(a))
	{
		mauChu(113, 4, YELLOW, "MA SINH VIEN DA TON TAI!");
		Nocursortype(0);
		return;
	}
	else
	{
		if(s)
		{
			AddTail_SV(a);	
			slsv++;
			mauChu(116, 4, YELLOW, "THEM THANH CONG!");
		}
		else{
			mauChu(113, 4, YELLOW, "THEM KHONG THANH CONG!");
			Nocursortype(0);
			return;
		}
	}
	Nocursortype(0);

}
void listSinhVien::outputlist_SV()
{
	int x = 7, y = 15;
	clear_screen2();
	SetBGColor(BLACK);
	gotoxy(x, y - 2); 
	cout << "So sinh vien: " << slsv;
	table_SV();
	if(slsv == 0)
	{
		gotoxy(x + 27, y + 2);
		cout << "Danh sach sinh vien trong!";
		return;
	}
	for(NODESV *p = svFirst; p != NULL; p = p->svnext)
	{
		p->sv.output_SV(x, y);
		y++;
	}
	clear_screen3();
	guide_SV();
}
bool listSinhVien::find(SinhVien a)
{
	NODESV *p = svFirst;
	while(p != NULL)
	{
		if(a.maSV.compare(p->sv.maSV ) == 0)
		{
			return 1;
		}
		p = p->svnext;
	}
	return 0;
}
void listSinhVien::del_SV(int k)
{
	NODESV *p = svFirst;
	int count = 0;
	if (k==0)
	{
		svFirst = p->svnext;
		delete p;
		slsv--;
		return;
	}
	else
	  	while ((count + 1 < k)&&(p != NULL))
	  	{
		   p = p->svnext;
		   count++;
	 	}
	
	if (p==NULL) return;
	if (p->svnext == NULL) return;	
	else
	{
	    NODESV *pLink = p->svnext->svnext;
	    NODESV *pDelete = p->svnext; 
	    p->svnext = pLink;
	    delete pDelete;
	    slsv--;
	}

} 
void listSinhVien::delall_SV()
{
	NODESV *p = svFirst;
	while(p != NULL)
	{
		p = p->svnext;
		delete p;
	}
	slsv = 0;
}
void SinhVien::read_SV(ifstream &fsv)
{	
	fsv.ignore();
	getline(fsv, maSV, '@');
	fsv.ignore();
	getline(fsv, Ho, '@');
	fsv.ignore();
	getline(fsv, Ten, '@');
	fsv.ignore();
	getline(fsv, password, ' ');
	fsv >> phai ;
}
void SinhVien::write_SV(ofstream &fsv)
{
	fsv << maSV << "@ ";
	fsv << Ho << "@ ";
	fsv << Ten << "@ ";
	fsv << password << ' ';
	fsv << phai;
}
void listSinhVien::read_listSV(ifstream &fsv)
{
	fsv >> slsv;
	for(int i = 0; i < slsv; i++){
		SinhVien sv;
		sv.read_SV(fsv);
		AddTail_SV(sv);
	}
}
void listSinhVien::write_listSV(ofstream &fsv)
{
	fsv << slsv << "\n";
	NODESV *p = svFirst;
	for(int i = 0; i < slsv; i++)
	{
		p->sv.write_SV(fsv);
		fsv << "\n";
		p = p->svnext;
	}
}
//////////////////////Mon Hoc//////////////
MonHoc input_MH(MonHoc a)
{ 
	int x = 108, y = 11;
	gotoxy(x,y);
	cout << "Nhap ma mon hoc: ";
	input_check(x + 17, y, 15, 15, a.maMonHoc);
	gotoxy(x, y + 1);
	cout << "Nhap ten mon hoc: ";
	input_check(x + 18, y + 1, 50, 17, a.tenMonHoc);
	return a;
}
void listMonHoc::add_MH(){
	MonHoc a;
	a = input_MH(a);
	if(InsertNode(a)) {
		++slmh;
		mauChu(108, 6, YELLOW, "Them mon hoc thanh cong!");
	}
	else mauChu(108, 6, YELLOW, "Ma mon hoc da ton tai!");
}
void output_MH(int x, int y, MonHoc a)
{
	gotoxy(x, y);
	cout << a.maMonHoc;
	gotoxy(x + 34, y);
	cout<< a.tenMonHoc;
}
NODEMH listMonHoc::CreateNode(MonHoc a)
{
    NODEMH p = new nodeMonHoc(a);
    return p;
}
NODEMH listMonHoc::SearchNode_Re(NODEMH root, MonHoc a)
{
	if (root == NULL) return NULL;
	NODEMH p = root;
	while (p != NULL)
	{
		if (p->MH.maMonHoc.compare(a.maMonHoc) == 0) return p;
		if (p->MH.maMonHoc.compare(a.maMonHoc) > 0) p = p->left;
		else p = p->right;
	}
	return NULL;
}
NODEMH listMonHoc::FindInsert(MonHoc a)
{
    if(root == NULL) return NULL;
    NODEMH p = root;
    NODEMH f = p;
    while (p != NULL)
    {
        f = p;
        if (p->MH.maMonHoc.compare(a.maMonHoc) > 0) p = p->left;
        else p = p->right;
    }        
    return f;
}
bool listMonHoc::InsertNode(MonHoc a)
{
	if(SearchNode_Re(root, a) != NULL) return 0;
    NODEMH n = CreateNode(a);
    if (root == NULL)
    {
        root = n;
        return 1;
    }
    else
    {
        NODEMH f = FindInsert(a);
        if (f != NULL)
        {
            if (f->MH.maMonHoc.compare(a.maMonHoc) > 0) f->left = n;
            else f->right = n;
        }
    }
    return 1;
}

//void listMonHoc::LNR(NODEMH &t)
//{
//	table_MH();
//	gotoxy(7, 13);
//	cout << "So mon hoc: " << slmh;
//
//	if(t != NULL)
//	{
//		LNR(t->left);
//		output_MH(xmh, ymh, t->MH);
//		LNR(t->right);
//	}
//}
void listMonHoc::LNRkodequy()
{
	int x = 7, y = 15;
	table_MH();
	gotoxy(x, y - 2);
	cout << "So mon hoc: " << slmh;
	NODEMH p;
	while(root)
	{
		if(root->left == NULL)
		{
			output_MH(x, y, root->MH);
			y++;
			root = root->right;
		}
		else
		{
			p = root->left;
			while(p->right && p->right != root)
			{
				p = p->right;
			}
			if(p->right == NULL)
			{
				p->right = root;
				root = root->left;
			}
			else
			{
				p->right = NULL;
				output_MH(x, y, root->MH);
				y++;
				root = root->right;
			}
		}
	}
}
void MonHoc::read_MH(ifstream &file)
{
	file.ignore();
	getline(file, maMonHoc, '@');
	file.ignore();
	getline(file, tenMonHoc, '@');
}
void MonHoc::write_MH(ofstream &file)
{
	file << maMonHoc <<"@ ";
	file << tenMonHoc << "@ " << "\n";
}
void listMonHoc::read_listMH()
{
	ifstream file("DSmh.txt");
	file >> slmh;
	for(int i = 0; i < slmh; i++)
	{
		MonHoc a;
		a.read_MH(file);
		InsertNode(a);
	}
	file.close();
}
void listMonHoc::write_listMH()
{
	ofstream file("DSmh.txt");
	file << slmh << "\n";
	NODEMH p;
	while(root)
	{
		if(root->left == NULL)
		{
			root->MH.write_MH(file);
			root = root->right;
		}
		else
		{
			p = root->left;
			while(p->right && p->right != root)
			{
				p = p->right;
			}
			if(p->right == NULL)
			{
				p->right = root;
				root = root->left;
			}
			else
			{
				p->right = NULL;
				root->MH.write_MH(file);
				root = root->right;
			}
		}
	}
	file.close();
}
int listCauHoi::select_DA()
{
	int x = 20, y = 8;
	string da[4] = {"  A  ", "  B  ", "  C  ", "  D  "};
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
	  	case RIGHT :if (chon+1 < 4)
	  			  {
	  		        Normal();
	              	mauChu(x + chon*10, y, RED, da[chon]);
	              	chon ++;
	              	HighLight();
	              	mauChu(x + chon*10, y, RED, da[chon]);
	  			  }
	  			  break;
	  	case ENTER : 
	  				SetBGColor(BLACK);
	  				//cout << chon;
	  				return chon;
	  } 
	  } while (1);

}
void listCauHoi::DA_CauHoi(int x)
{
	if(x == 0)
	{
		cout << "A";
	}
	else if(x == 1)
	{
		cout << "B";
	}
	else if(x == 2)
	{
		cout << "C";
	}
	else
	{
		cout << "D";
	}
}
void listCauHoi::insert_CH()
{
	clear_screen1();
	int x = 3, y = 1;
	int i = 0;
	nodesCH[slCauHoi] = new CauHoi;
	gotoxy(x, y);
	cout << "Nhap cau hoi: ";
	input_check(x + 14, y, 250, 86, nodesCH[slCauHoi]->noiDung);
	gotoxy(x, y + 3);
	cout << "A: ";
	input_check(x + 2, y + 3, 80, 80, nodesCH[slCauHoi]->A);
	gotoxy(x, y + 4);
	cout << "B: ";
	input_check(x + 2, y + 4, 80, 80, nodesCH[slCauHoi]->B);
	gotoxy(x, y + 5);
	cout << "C: ";
	input_check(x + 2, y + 5, 80, 80, nodesCH[slCauHoi]->C);
	gotoxy(x, y + 6);
	cout << "D: ";
	input_check(x + 2, y + 6, 80, 80, nodesCH[slCauHoi]->D);
	gotoxy(x, y + 7);
	cout << "Dap An: ";
	nodesCH[slCauHoi]->dapAn = select_DA();
	//cout << nodesCH[slCauHoi]->dapAn;
	slCauHoi++;
}
void listCauHoi::output_CH()
{
	SetBGColor(BLACK);
	int x = 7, y = 15;
	if(slCauHoi == 0)
	{
		gotoxy(x + 20, y);
		cout << "Danh cau hoi trong!";
		return;
	}
	table_CH();
	for (int i = 0; i < slCauHoi; i++)
	{
		 gotoxy(x, y);	
		 cout << nodesCH[i]->noiDung;
		 gotoxy(x + 54, y);
		 DA_CauHoi(nodesCH[i]->dapAn);
		x = 7;
		y++; 
	}
}
void listCauHoi::output1_CH(int chon)
{
	int x = 3, y = 1;
	gotoxy(x,y);
	cout << "Noi dung cau hoi: " <<nodesCH[chon]->noiDung;
	gotoxy(x, y + 3);
	cout << "A:    " << nodesCH[chon]->A;
	gotoxy(x, y + 4);
	cout << "B:    " << nodesCH[chon]->B;
	gotoxy(x, y + 5);
	cout << "C:    " << nodesCH[chon]->C;
	gotoxy(x, y + 6);
	cout << "D:    " << nodesCH[chon]->D;
	if(nodesCH[chon]->dapAn == 0)
	{
		gotoxy(x+3,y+3);
		cout << "*";
	}
		else if(nodesCH[chon]->dapAn == 1)
		{
			gotoxy(x+3,y+4);
			cout << "*";
		}
			else if(nodesCH[chon]->dapAn == 2)
			{
				gotoxy(x+3,y+5);
				cout << "*";
			}
				else if(nodesCH[chon]->dapAn == 3)
				{
					gotoxy(x+3,y+6);
					cout << "*";
				}
}
void listCauHoi::write_CauHoi()
{
	ofstream flo("DScauhoi.txt");
	if(flo.fail()){
		cout << "that bai";
	}
	flo << slCauHoi << "\n";
	for(int i = 0; i < slCauHoi; i++)
	{
		flo << nodesCH[i]->noiDung <<"@ ";
		flo << nodesCH[i]->A <<"@ ";
		flo << nodesCH[i]->B <<"@ ";
		flo << nodesCH[i]->C <<"@ ";
		flo << nodesCH[i]->D <<" ";
		flo << nodesCH[i]->dapAn <<"\n" ;
		
	}
	flo.close();
}
void listCauHoi::read_CauHoi()
{
	ifstream fli("DScauhoi.txt");
	if(fli.fail())
	{
		cout << "that bai";
	}
	fli >> slCauHoi;
	for(int i = 0; i < slCauHoi; i++)
	{
		nodesCH[i] = new CauHoi;
		fli.ignore();
		getline(fli, nodesCH[i]->noiDung, '@');
		fli.ignore();
		getline(fli, nodesCH[i]->A, '@');
		fli.ignore();
		getline(fli, nodesCH[i]->B, '@');
		fli.ignore();
		getline(fli, nodesCH[i]->C, '@');
		fli.ignore();
		getline(fli, nodesCH[i]->D, ' ');
		//fli.ignore();
		fli >> nodesCH[i]->dapAn;
	}
}
void listCauHoi::del_CauHoi( int vitri)
{
	for(int i = vitri; i < slCauHoi - 1; i++)
	{
		nodesCH[i]->noiDung = nodesCH[i + 1]->noiDung;
		nodesCH[i]->A = nodesCH[i + 1]->A;
		nodesCH[i]->B = nodesCH[i + 1]->B;
		nodesCH[i]->C = nodesCH[i + 1]->C;
		nodesCH[i]->D = nodesCH[i + 1]->D;
		nodesCH[i]->dapAn = nodesCH[i + 1]->dapAn;
		
	}
	slCauHoi--;
}
