#include "hienthi.h"





void press_key(){
	SetColor(WHITE);
	char menu2 [3][50] = {"<-  ->: DI CHUYEN", "      ENTER: CHON", "       ESC: THOAT"};
	for(int i = 0; i< 3; i++){
		gotoxy(3+i*20, 38);
		cout<< menu2[i];
	}
}
void Normal(){
	SetColor(BLUE);
	SetBGColor(BLACK);
}
void Normalw()
{
	SetColor(WHITE);
	SetBGColor(BLACK);
}
void HighLight(){
	SetColor(BLUE);
	SetBGColor(WHITE);
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
	mauChu(112, 10, RED, "========> TAC VU <=========");
	mauChu(3, 37, RED, "---> HUONG DAN <---");
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
void clear_screen(int x, int y, int width, int height)
{
	for(int i = 0; i < height; ++i)
	{
		gotoxy(x, i + y);
		for(int j = 0; j < width; ++j)
		{
			cout << " ";
		}
	}
	SetColor(WHITE);
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
void clear_screen1()
{
	Normal();
	clear_screen(1, 1, 100, 8);
}
void clear_screen2()
{
	Normal();
	clear_screen(1, 12, 100, 25);
}
void clear_screen3()
{
	Normal();
	clear_screen(1, 38, 140, 1);
}
void clear_screen4()
{
	Normal();
	clear_screen(107, 2, 36 , 7);
}
void clear_screen5()
{
	Normal();
	clear_screen(107, 11, 36 , 25);
}
void guide_Lop(){
	SetColor(WHITE);
	char l[6][20] = {"ESC: TRO VE", "HOME: TRANG CHINH", "F1: SUA", "INSERT: THEM", "DELETE: XOA", "ENTER: CHON"};
	for(int i = 0; i< 6; i++){
		gotoxy(3+i*20, 38);
		cout<< l[i];
	}
}
void table_LOP()
{
	mauChu(35, 11, RED, "=====** DANH SACH CAC LOP **=====");
	mauChu(6, 14, WHITE, " Ma Lop                   ||   Ten Lop                     ||  So luong SV");
}
void guide_MH(){
	SetColor(WHITE);
	char l[6][20] = {"ESC: TRO VE", "HOME: TRANG CHINH", "F1: SUA", "INSERT: THEM", "DELETE: XOA", "ENTER: CHON"};
	for(int i = 0; i< 6; i++){
		gotoxy(3+i*20, 38);
		cout<< l[i];
	}
}
void table_MH(){
	mauChu(35, 11, RED, "=====** DANH SACH CAC MON **=====");
	mauChu(6, 14, WHITE, " Ma Mon Hoc                   ||   Ten Mon Hoc              ");
}
void table_SV()
{
	mauChu(30, 11, RED, "=====** DANH SACH SINH VIEN CUA LOP **=====");
	gotoxy(7, 13);
	cout << "  MASV            ||     Ho                          ||    Ten                  ||    Phai   ";
}
void table_CH()
{
	mauChu(35, 11, RED, "=====** DANH SACH CAU HOI **=====");
	mauChu(6, 14, WHITE, " Cau hoi                                          ||   Dap an  ");
}
//void message_add(int x, int y, string title)
//{
//	gotoxy()
//}
