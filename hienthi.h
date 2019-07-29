#ifndef HIENTHI_H

#include "mylib.h"
#include "constain.h"
#include <string>
#include <iostream>

const int YELLOW = 14;
const int WHITE = 15;
const int BLACK = 0;
const int BLUE = 3;
const int GREEN = 10;
const int RED = 4;

using namespace std;
void press_key();
void Normal();
void Normalw();
void HighLight();
void rectangle(int x, int y, int width, int height, int color);
void mauChu(int x, int y, int color, string chu);
void GiaoDienGV();
void TieuDe(); 	
void DangNhap();
void clear_screen(int x, int y, int width, int height);
void clear_screen1();
void clear_screen2();
void clear_screen3();
void clear_screen4();
void clear_screen5();
void guide_Lop();
void table_LOP();
void guide_MH();
void table_MH();
void table_SV();
void table_CH();
void guide_SV();

#endif
