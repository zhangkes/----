// �����ۺ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"AllkindsofSort.h"
int A[COUNT];
int OriginData[COUNT];
void menu()
{
	cout << "\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
	cout << "\t�d�T�T�T     ��������ʱ��     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    1--- ð������     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    2--- ������       �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    3--- ϣ������     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    4--- ��������     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    5--- �鲢����     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    6--- ��������     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    7--- ��ӡ����     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    8--- ��ʾ������ �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    9--- ������������� �T�T�g" << endl;
	cout << "\t�d�T�T�T    0--- �˳�         �T�T�T�g" << endl;
	cout << "\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int in;
	memset(ResultPackage, 0, sizeof(Statistics) * 6);
	Reset(OriginData, COUNT); //��ʼ������
	while (1){
		memcpy(A, OriginData, sizeof(A));	  //��ͬ��������
		system("cls");
		menu();
		cout << "���������ѡ� ";  cin >> in;
		switch (in)
		{
		case 1: Bubble_Sort(A, COUNT);        break;
		case 2: HeapSort(A, COUNT);     break;
		case 3: ShellSort(A, COUNT);    break;
		case 4: QuickSort(A, COUNT); break;
		case 5: Merge_Sort(A, COUNT); break;
		case 6: Insertion_Sort(A, COUNT); break;
		case 7: Print(A, COUNT); break;
		case 8: ResultTable(ResultPackage); break;
		case 9: Reset(OriginData, COUNT); break;
		case 0: exit(0);
		default: cout << "\t����������������롣" << endl;
		}
		cout << endl;
		system("pause");
	}
	return 0;
}

