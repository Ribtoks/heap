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
	�������� ������� ���������� ��������

	������� ���������:
	arr - ������� ������
	arrSize - ������ �������� �������
	elemntSize - ������ �������� ������
	compFunc - ��������� �� ������� ��������� ���������
*/
void InsertSort(void* arr, int arrSize, int elementSize, CompareFunction compFunc);


/*
	�������� ������� ����������� ����������

	������� ���������:
	arr - ������� ������
	arrSize - ������ �������� �������
	elemntSize - ������ �������� ������
	compFunc - ��������� �� ������� ��������� ���������
*/
void BubbleSort(void* arr, int arrSize, int elementSize, CompareFunction compFunc);