#include "nhapxuat.h"
void input_check(int x, int y, int max, int width, string &data)
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
				data = result;
				return;
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
					if(result.length() != max)
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

