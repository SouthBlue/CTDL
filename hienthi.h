#ifndef HIENTHI_H

#include "mylib.h"
#include "constain.h"
#include <string>
#include <iostream>
#define WHITE 15
#define BLACK 0
#define BLUE 3
#define GREEN 10
#define RED 4
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
//void message_add(int x, int y, string title);
#endif
