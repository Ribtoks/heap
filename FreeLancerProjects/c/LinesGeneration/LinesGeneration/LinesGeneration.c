#include <math.h>
#include <stdlib.h>

#include "LinesGeneration.h"
#include "ScreenInterface.h"
#include "PointStruct.h"

#define BresenhamCoordChar 42
#define DDCCoordChar 4

/*
	������� ��� ���������� ��������� 
	2-� ����� �����
*/
int Max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

/*
	������� ���������� ����� ������ �����
*/
int sign(int a)
{
	if (a > 0)
		return 1;

	if (a < 0)
		return -1;

	return 0;
}

/*
	��������� ������� �� ������ (�������������) � �������
	��������� ��� - DDC (Digital Differential Analyzer)

	������� ���������:

	p1 - ��������� ����� �����
	p2 - �������� ����� �����

	��������� - ���������� ����� � ������
*/
int GenerateLineDDC(struct Point p1, struct Point p2, struct Point* resultArray)
{
	int length, i;
	double dx, dy;
	int currIndex = 0;

	double x, y;

	// ����� ��� �������� �������� �� X � �� Y
	length = Max(abs(p1.x - p2.x), abs(p1.y - p2.y));

	// �������� ������� �� ���������� dx ��� dy ������� ������� ������
	dx = (double)(p2.x - p1.x) / length;
	dy = (double)(p2.y - p1.y) / length;

	// ��������� ��������, � �� ����������� ������� �����
	// ������������� �������� ������� ������ �������� ��������� ��� ���� ����������
	x = p1.x + 0.5*sign(dx);
	y = p1.y + 0.5*sign(dy);

	// ������ ��������� �����
	i = 1;
	while (i <= length)
	{
		// ������ ������� �����
		//SetPoint((int)x, (int)y, DDCCoordChar);
		resultArray[currIndex].x = x;
		resultArray[currIndex].y = y;
		++currIndex;

		// ������������� ���� ����������
		x += dx;
		y += dy;
		++i;
    }

	return currIndex;
}


/*
	��������� ������� �� ������ (�������������) � �������
	��������� ����������

	������� ���������:

	p1 - ��������� ����� �����
	p2 - �������� ����� �����

	��������� - ���������� ����� � ������
*/
int GenerateLineBresenham(struct Point p1, struct Point p2, struct Point* resultArray)
{
	int dx, dy;
	int sx, sy;

	int x, y;
	int i;
	int d1, d2;

	int currIndex = 0;

	/*
		���� D ������������ ��� �������� ��� ������ ��������� ��������� �����. 
		���� D < 0, �� ������ Y-�������� ����������� �� �������� ���������� 
		�������������� �������� Y, �.�. Y-���������� �� �������� �� ��������� � 
		���������� ������. � ��������� ������ Y ������������� �� 1.
	*/
	int d;

	// ����� �������� �� X � �� Y
	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);

	// ����������� ����� ����������� �� ��� X
	if (p2.x >= p1.x)
		sx = 1;
	else
		sx = -1;

	// ����������� ����� ����������� �� ��� Y
	if (p2.y >= p1.y)
		sy = 1;
	else
		sy = -1;

	//�������� ���� ������� �����
    if (dy <= dx)
    {
		//������� �� ��� ��� ����������� �������� ������������
		d = (dy << 1) - dx;

		d1 = dy << 1;
		d2 = (dy - dx) << 1;

		// ��������� ��������� ����� �����
		//SetPoint(p1.x, p1.y, BresenhamCoordChar);
		resultArray[currIndex].x = p1.x;
		resultArray[currIndex].y = p1.y;
		++currIndex;

		// ���� ������ ����� �� �����
		for (x = p1.x + sx, y = p1.y, i = 1; i <= dx; i++, x += sx)
		{
			// ���� d < 0 �������� y �� �������� �� ��������� � ���������� ������, ����� y �������������
			if (d > 0)
			{
				d += d2;
				y += sy;
			}
			else 
				d += d1;

			// ����� �� ����� ��������� ����� �����
			//SetPoint(x, y, BresenhamCoordChar);		     
			resultArray[currIndex].x = x;
			resultArray[currIndex].y = y;
			++currIndex;
		}
	}
    else
    {
        d = (dx << 1) - dy;

        d1 = dx << 1;
        d2 = (dx - dy) << 1;

		// ��������� ��������� ����� �����
        //SetPoint(p1.x, p1.y, BresenhamCoordChar);
		resultArray[currIndex].x = p1.x;
		resultArray[currIndex].y = p1.y;
		++currIndex;

		// ���� ������ ����� �� �����
        for (x = p1.x, y = p1.y + sy, i = 1;  i <= dy;  i++, y += sy)
        {
			// ���� d < 0 �������� y �� �������� �� ��������� � ���������� ������, ����� y �������������
            if (d > 0)
            {
                d += d2;
                x += sx;
            }
            else 
				d += d1;

			// ����� �� ����� ��������� ����� �����
            //SetPoint(x, y, BresenhamCoordChar);
			resultArray[currIndex].x = x;
			resultArray[currIndex].y = y;
			++currIndex;
		}
	}
	return currIndex;
}