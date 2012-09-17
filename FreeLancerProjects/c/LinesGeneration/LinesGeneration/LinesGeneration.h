#pragma once
#include "PointStruct.h"
/*
	��������� ������� �� ������ (�������������) � �������
	��������� ��� - DDC (Digital Differential Analyzer)

	������� ���������:

	p1 - ��������� ����� �����
	p2 - �������� ����� �����

	��������� - ���������� ����� � ������
*/
int GenerateLineDDC(struct Point p1, struct Point p2, struct Point* resultArray);

/*
	��������� ������� �� ������ (�������������) � �������
	��������� ����������

	������� ���������:

	p1 - ��������� ����� �����
	p2 - �������� ����� �����

	��������� - ���������� ����� � ������
*/
int GenerateLineBresenham(struct Point p1, struct Point p2, struct Point* resultArray);