/*
	��������� �� ������� ��������� ��������� ������

	���������� 
	-�������� ������ ����, ���� 
	  ������ ������� ������ �������
	-����, ���� ��� �����
	-�������� ������ ����, ���� 
	  ������ ������ �������
*/
typedef int (CompareFunction) (const void*, const void*);

/*
	�������� ������� ������������� ����������

	������� ���������:
	arr - ������� ������
	arrSize - ������ �������� �������
	elemntSize - ������ �������� ������
	compFunc - ��������� �� ������� ��������� ���������
*/

void HeapSort(void* arr, int arrSize, int elementSize, CompareFunction compFunc);