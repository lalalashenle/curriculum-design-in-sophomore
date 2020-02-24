// #include"stdafx.h"
#include"stdio.h"
#include <conio.h>
#include"graphics.h"
#include"math.h"

#define PI 3.1415926
#define I 1
#define R 180
#define D 1

typedef double(*FUN)(double, double, double);

// 求f(x)的积分
double DIntegral(FUN f, double x, double y)
{
	const int iTimes = 1000;
	double dbStep = 0.25;
	double dbSum = (f(0, x, y) + f(2 * PI, x, y)) * dbStep / 2;
	int i;
	for (i = 1; i <iTimes; i++)
	{
		dbSum += f(0 + i * dbStep, x, y)*dbStep;
	}
	return dbSum;
}

// 求bx的被积函数
double Bx(double x0, double x, double y)
{
	double A = D * I;
	double r = sqrt(x * x + y * y + R * R - 2 * y * R * cos(x0));
	double bx = (A * (R * R - y * R * cos(x0))) / (r * r * r);
	return bx;
}

// 求by的被积函数
double By(double x0, double x, double y)
{
	double A = D * I;
	double r = sqrt(x * x + y * y + R * R - 2 * y * R * cos(x0));
	double by = (A *x*R*cos(x0)) / (r*r*r);
	return by;
}

int main()
{
	double bx, by, b, x, y, dt;
	int i = 0, j, n = 500;

	initgraph(640, 640); // 创建绘图窗口，大小为 640x640 像素
	setorigin(320, 320); // 设置点（320，320）为坐标原点
	ellipse(-50, 180, 50, -180);// 画载流圆线圈（画椭圆）

	for (i = 0; i < 100; i++)
	{
		x = 0;
		y = 180 - i * 10; // 取点（x, y）
		i++;
		for (j = 0; j < n; j++)
		{
			bx = DIntegral(Bx, x, y); // 求bx
			by = DIntegral(By, x, y); // 求by
			b = sqrt(bx * bx + by * by); // 求b
			dt = 1 / b;
			if (x >= 0)
			{
				putpixel(x, y, BLUE);//描点（x,y）
				putpixel(-x, y, BLUE); //描点（-x,y）
				putpixel(x, -y, BLUE); //描点（x,-y）
				putpixel(-x, -y, BLUE); //描点（-x,-y）
			}
			x = x + bx * dt;  y = y + by * dt;//求下一个点的坐标
		}
	}

	_getch(); // 按任意键退出
	closegraph();

	return 0;
}
