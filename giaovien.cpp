#include "giaovien.h"

LISTLOP dsL;
//TREEMH tMH = NULL;
int MenuGV(){
	system("cls");
	string td[4]= {"    Lop    ", " Cau Hoi Thi", "  Mon Hoc  ", " Bang Diem "};
	GiaoDienGV();
	rectangle(8, 3, 15, 3, BLUE);
	rectangle(34, 3, 15, 3, BLUE);
	rectangle(58, 3, 15, 3, BLUE);
	rectangle(83, 3, 15, 3, BLUE);
	press_key();
	int chon =0;
 	int i;
 	for ( i=0; i< 4 ; i++){
	 	mauChu(cot + 25*i, dong, BLUE, td[i]);
 	}
	  	HighLight();
	  	mauChu(cot + 25*chon, dong, BLUE, td[chon]);
		Nocursortype(0);
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
	  			  }
	  			  break;
	  	case RIGHT :if (chon+1 < 4)
	  			  {
	  		        Normal();
	              	mauChu(cot + chon*25, dong, BLUE, td[chon]);
	              	chon ++;
	              	HighLight();
	              	mauChu(cot + chon*25, dong, BLUE, td[chon]);	
	  			  }
	  			  break;
	  	case ENTER : return chon+1;
	  } 
	  } while (1);

}
/////////////////////////////////////////////
int up_down(int x, int y, int a, int c)
{
	if(c == 72){
	    Normal();
	  	mauChu(x, y + a, BLACK, " -> ");
	  	a--;
	  	HighLight();
	  	mauChu(x, y + a, BLACK, " -> ");	
  	}
  	else{

	    Normal();
	  	mauChu(x, y + a, BLACK, " -> ");
	  	a++;
	  	HighLight();
	  	mauChu(x, y + a, BLACK, " -> ");	
  	}
  	return a;
}
bool del_hoi()
{
	clear_screen4(); 
	mauChu(114, 4, RED, "BAN CO MUON XOA KHONG?");
	string s[2] = {" YES ", " NO "};
	bool chon = true;
	for(int i = 0; i < 2; i++)
	{
		mauChu(118 + i*10, 6, RED, s[i]);
	}
	HighLight();
	mauChu(118, 6, RED, s[0]);
	char key;
	do{
		key = getch();
		if(key == 0) key= getch();
		switch (key){
			case LEFT: 
				    chon = true;
					Normal();
	              	mauChu(118 + 10, 6, RED, s[1]);	
	              	HighLight();
	              	mauChu(118, 6, RED, s[0]);
				break;
			case RIGHT:
				    chon = false;
					Normal();
	              	mauChu(118, 6, RED, s[0]);
	              	HighLight();
	              	mauChu(118 + 10, 6, RED, s[1]);
				break;
			case ENTER:
				 	SetBGColor(BLACK);
					return chon;
		}
	} while(1);

}
void select_Lop(int chon)
{
	int x = 1, y = 15;
	dsL.read_listLop();
	dsL.output_Lop();
	if(dsL.slLop > 0){
		HighLight();
		mauChu(x, y + chon, BLACK, " -> ");
	}
	char kytu;
	while(1)
	{
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {	
	    case UP :if (chon > 0)
	  			  {
					chon = up_down(x, y, chon, UP);
	  			  }
	  			  break;
	  	case DOWN :if (chon + 1 <dsL.slLop)
	  			  {
	  		        chon = up_down(x, y, chon, DOWN);
	  			  }
	  			  break;
		case ESC :	system("cls");
					SetBGColor(BLACK);
					giao_vien();
					break;
		case INSERT : 	clear_screen5();
						Normalw();
						dsL.insert_Lop();
						dsL.write_listLop();
						clear_screen2();
						select_Lop(chon);
						break;
		case DEL :		
						clear_screen5();				
						if(dsL.slLop <= 0)
								break;
						else{
							bool e = del_hoi();
							if(e){
								clear_screen4();
								clear_screen2();
								Normalw();
								if(chon == 0 ){
									dsL.del_Lop(chon);
									dsL.write_listLop();
									select_Lop(chon);
								}
								else{
									dsL.del_Lop(chon);
									dsL.write_listLop();
									select_Lop(chon - 1);
								}							
							}
							else 
							{
								clear_screen4();
								select_Lop(chon);
							}
					}	
					break;
	  	case ENTER : select_SV(chon, 0);
	 	} 
	} 
}
////////////////////////////////

int select_SV(int a, int b)
{
	Normalw();
	int x = 1, y = 15, number;
	number = dsL.nodesL[a]->First.slsv;
	dsL.nodesL[a]->First.outputlist_SV();
	if( number > 0){
		HighLight();
		mauChu(x, y + b, BLACK, " -> ");
	}
	Normalw();
	gotoxy(x + 6, y - 3); cout << "Lop: " << dsL.nodesL[a]->maLop << "          Ten lop: " << dsL.nodesL[a]->maLop;
	char kytu;
	bool e;
	do {
	  	kytu = getch();
	  	if (kytu==0) kytu = getch();
	  	switch (kytu) {
	    case UP :
				if (b > 0)
	  			{
					b = up_down(x, y, b, UP);
	  			}
	  			break;
	  	case DOWN :
		  		if (b + 1 < number)
	  			{
	  		        b = up_down(x, y, b, DOWN);
	  			}
	  			break;
		case ESC :	
				clear_screen2(); 
				SetBGColor(BLACK);
				select_Lop(a);
				break;
		case INSERT : 	
					clear_screen4();
					clear_screen5();
					Normalw();
					dsL.nodesL[a]->First.insertlist_SV();
					dsL.write_listLop();
					clear_screen2();
					clear_screen5();
					select_SV(a, b);
					break;
		case DEL :	
					if(number <= 0)
							break;
						else{
						e = del_hoi();
						if(e){
							clear_screen4();
							clear_screen2();
							Normalw();
							if(b == 0 ){
								dsL.nodesL[a]->First.del_SV(b);
								dsL.write_listLop();
								select_SV(a, b);
							}
							else{
								dsL.nodesL[a]->First.del_SV(b);
								dsL.write_listLop();
								select_SV(a, b - 1);
							}						
							break;
						}
						else 
						{	
							clear_screen4();
							select_SV(a, b);
						}
					}
							
	  	case ENTER : return b;
	  } 
	  } while (1);
}
///////////////////Mon Hoc//////////
//void seclect_MH()
//{
//	Normalw();
//	read
//	
//}
/////////////////////////////
void giao_vien()
{
	Nocursortype(0);
	int chon =  MenuGV();
	switch (chon)
	{
		case 1:
			SetBGColor(BLACK);
			clear_screen3();
			guide_Lop();
			int a;
			select_Lop(0);
			break;
		// case 2:
		// 	SetBGColor(BLACK);

	}
}	
