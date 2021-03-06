#include "AllHeaderCode.h"
#include <math.h>
#include <stdio.h>


#define ScreenWidth 75
#define ScreenHeight 41

#define CenterX 37
#define CenterY 20

unsigned char ScreenMatrix[ScreenHeight][ScreenWidth];

void ClearScreen()
{
	int i = 0;
	int j = 0;
	
	for (; i < ScreenHeight; ++i)
		for (j = 0; j < ScreenWidth; ++j)
			ScreenMatrix[i][j] = 250;

	for (i = 0; i < ScreenHeight; ++i)
		ScreenMatrix[i][CenterX] = '|';

	for (j = 0; j < ScreenWidth; ++j)
		ScreenMatrix[CenterY][j] = '-';

	ScreenMatrix[CenterY][CenterX] = '+';
}

void InitializeScreen()
{
	ClearScreen();
}


void PrintScreen()
{
	int i = 0;
	int j = 0;
	
	for (; i < ScreenHeight; ++i)
	{
		for (j = 0; j < ScreenWidth; ++j)
			printf("%c", ScreenMatrix[i][j]);
		printf("\n");
	}
	printf("\n");
}


int IsPointOk(int x, int y)
n{
	if (x >= 0  &&  x < ScreenWidth)
		if (y >= 0  &&  y < ScreenHeight)
			return 1;

	return 0;
}

int IsFilled(int x, int y)
{
	if (ScreenMatrix[y][x] == '*')
		return 1;
	return 0;
}

void Fill(int x, int y)
{
	ScreenMatrix[y][x] = '*';
}

void TransformPoint(struct Point* p)
{
	p->x += CenterX;
	p->y = CenterY - p->y;
}

int TriangleSquare(struct Point p1, struct Point p2, struct Point p3)
{
	return abs(p1.x*(p2.y - p3.y) - p1.y*(p2.x - p3.x) + (p2.x*p3.y - p3.x * p2.y));
}

int Max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int sign(int a)
{
	if (a > 0)
		return 1;

	if (a < 0)
		return -1;

	return 0;
}

void DrawLine(struct Point p1, struct Point p2)
{
	int length, i;
	double dx, dy;
	int currIndex = 0;

	double x, y;

	length = Max(abs(p1.x - p2.x), abs(p1.y - p2.y));

	dx = (double)(p2.x - p1.x) / length;
	dy = (double)(p2.y - p1.y) / length;

	x = p1.x + 0.5*sign(dx);
	y = p1.y + 0.5*sign(dy);

	i = 1;
	while (i <= length)
	{
		Fill((int)x, (int)y);		
		++currIndex;

		x += dx;
		y += dy;
		++i;
    }

	return currIndex;
}


int IsPointInsidePolygon (struct Point p[], int Number, int x, int y)
{
	int i1, i2, n, N, S, S1, S2, S3, flag;
	struct Point point;
	N = Number;

	point.x = x;
	point.y = y;

	for (n = 0; n < N; ++n)
	{
		flag = 0;
		i1 = n < N-1 ? n + 1 : 0;

		while (flag == 0)
		{
			i2 = i1 + 1;
			if (i2 >= N)
				i2 = 0;

			if (i2 == (n < N - 1 ? n + 1 : 0))
				break;

			S = TriangleSquare(p[i1], p[i2], p[n]);

			S1 = TriangleSquare(p[i1], p[i2], point);
			S2 = TriangleSquare(p[n], p[i1], point);
			S3 = TriangleSquare(p[n], p[i2], point);
			
			if (S == S1 + S2 + S3)
			{
				flag = 1;
				break;
			}
			i1 = i1 + 1;
			if (i1 >= N)
				i1 = 0;
		}
		if (flag == 0)
			break;
	}
 
	return flag;
}


void FillPolygon(struct Point Points[], int Count, int x, int y)
{
	if (IsPointOk(x, y))
		if (!IsFilled(x, y))
			if (IsPointInsidePolygon(Points, Count, x, y))
			{
				Fill(x, y);
				
				FillPolygon(Points, Count, x - 1, y);
				FillPolygon(Points, Count, x, y + 1);
				FillPolygon(Points, Count, x + 1, y);
				FillPolygon(Points, Count, x, y - 1);
			}
}
