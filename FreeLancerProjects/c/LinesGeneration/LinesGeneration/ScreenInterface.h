#pragma once

#include "PointStruct.h"
/*
	�������� ������������� ������
*/
void InitScreen();


/*
	������� �����������
*/
void ClearScreen();


/*
	������� ����������� �� �����������
	����� stdout
*/
void PrintScreen();

/*
	������� ������������� ������� 
		(���� � ���� ��������� ����������)
	��� ������������

	������� ���������:

	x, y - ���������� �����, ������� ���� ����������
	c - ������, ������� ���� ���������� �����
*/
void SetPoint(int x, int y, unsigned char c);


/*
	������� ���������, ����� �� �����
	� �������� ������������

	1 - ���� � �������� ������
	0 - � ��������� ������
*/
int IsPointOk(int x, int y);

void TransformPoint(struct Point* p);