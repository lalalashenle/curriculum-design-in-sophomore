// #include"stdafx.h"
#include"graphics.h"
#include"stdio.h"
#include"math.h"
#include"conio.h"

#define PI 3.1415926
#define R 140

double Bx(double x, double y, double dt)
{
	double r1, r2, t, bx, A = 100, I = 1;
	bx = 0;
	for (t = 0; t <= 2 * PI; t = t + dt)
	{
		r1 = sqrt((x + 100)*(x + 100) + y*y + R*R - 2 * y*R*cos(t));
		r2 = sqrt((x - 100)*(x - 100) + y*y + R*R - 2 * y*R*cos(t));
		bx = bx + A*I*dt*((R*R - y*R*cos(t))*dt / (r1*r1*r1) + (R*R - y*R*cos(t)) / (r2*r2*r2));
	}
	return(bx);
}

double By(double x, double y, double dt)
{
	double r1, r2, t, by, A = 100, I = 1;
	by = 0;
	for (t = 0; t <= 2 * PI; t = t + dt)
	{
		r1 = sqrt((x + 100)*(x + 100) + y*y + R*R - 2 * y*R*cos(t));
		r2 = sqrt((x - 100)*(x - 100) + y*y + R*R - 2 * y*R*cos(t));
		by = by + A*I*dt*((x + 100)*R*cos(t) / (r1*r1*r1) + (x - 100)*R*cos(t) / (r2*r2*r2));
	}
	return(by);
}

double B(double bx, double by)
{
	double b;
	b = sqrt(bx * bx + by * by);
	return(b);
}

double Dx(double bx, double db)
{
	double dx;
	dx = bx * db;
	return(dx);
}

double Dy(double by, double db)
{
	double dy;
	dy = by * db;
	return(dy);
}

void main()
{
	double x, y, t, dt, A = 100, I = 1, r1, r2, b, bx, by, db;
	double x1, y1, bx1, by1, db1;
	unsigned int i, j, n = 12;
	dt = 2 * PI / n;

	initgraph(640, 480);
	setorigin(320, 240);
	ellipse(-140, 140, -60, -140);
	ellipse(60, 140, 140, -140);

	for (i = 0; i < 11; i++)
	{
		x = 100;
		y = 140 - 14 * i;
		x1 = x;
		y1 = y;
		for (j = 0; j < 1000; j++)
		{
			bx1 = Bx(x1, y1, dt);
			by1 = By(x1, y1, dt);
			db1 = 1 / (B(bx1, by1));
			x1 = x1 - Dx(bx1, db1);
			y1 = y1 - Dy(by1, db1);
			if (x1 >= 0 && x1 <= 100)
			{
				putpixel(x1, y1, WHITE);
				putpixel(x1, -y1, WHITE);
				putpixel(-x1, y1, WHITE);
				putpixel(-x1, -y1, WHITE);
			}
			else break;
		}
		for (j = 0; j < 1000; j++)
		{
			bx = Bx(x, y, dt);
			by = By(x, y, dt);
			db = 1 / (B(bx, by));
			x = x + Dx(bx, db);
			y = y + Dy(by, db);
			if (x >= 100)
			{
				putpixel(x, y, WHITE);
				putpixel(x, -y, WHITE);
				putpixel(-x, y, WHITE);
				putpixel(-x, -y, WHITE);
			}
			else break;
		}
	}
	_getch();
	closegraph();
}
