// #include<stdafx.h>
#include <iostream>
#include <stdio.h>
#include <graphics.h>    // 引用图形库头文件
#include <conio.h>
#include <math.h>

#define PI 3.1415926

int main()
{
	double x0 = 250, y0;
	double x, y, ey, ex, e;
	double r1, r2, s, dx, dy, dt;

	int i = 0,  n = 500;
	s = 20;  // 距离常量。

	initgraph(1000, 500);    // 创建绘图窗口，大小为 1000x500 像素
	setorigin(500, 250);     // 设置点（500，250）为坐标原点
	// 画负电荷
	circle(250, 0, 20);      
	line(240, 0, 260, 0);    
	// 画正电荷
	circle(-250, 0, 20);     
	line(-260, 0, -240, 0);  
	line(-250, 10, -250, -10);    
	
	do
	{
		x = 250 + s * cos(i * PI / 10);
		y = s * sin(i * PI / 10);
		for (int j = 0; j < n; j++)
		{
			// 相关公式
			r1 = sqrt(y * y + (x0 - x)*(x0 - x));
			r2 = sqrt(y * y + (x0 + x)*(x0 + x));
			ex = ((x - x0) / (r1 * r1 * r1) - (x + x0) / (r2 * r2 * r2));
			ey = y * (1 / (r1 * r1 * r1) - 1 / (r2 * r2 * r2));
			e = sqrt(ex * ex + ey * ey);
			dt = 1 / e;
			x = x + ex * dt;  
			y = y + ey * dt;

			// 画点
			putpixel(x, y, WHITE); 
			putpixel(-x, y, WHITE);
		}
		i++; 
	} while (i < 100);
	
	_getch(); // 按任意键退出
	closegraph();

	return 0;
}
