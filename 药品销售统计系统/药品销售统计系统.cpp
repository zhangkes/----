// ҩƷ����ͳ��ϵͳ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Function_sort.h"
void menu()
{
	cout << "\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
	cout << "\t�d�T�T�T       ҩƷ����ͳ��ϵͳ       �T�T�T�g" << endl;
	cout << "\t�d�T�T�T        1--- ���۵�����       �T�T�T�g" << endl;
	cout << "\t�d�T�T�T        2--- ���۶������     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T        3--- ������������     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T        4--- ҩƷ�������     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T        5--- �鿴ҩƷ         �T�T�T�g" << endl;
	cout << "\t�d�T�T�T        0--- �˳�ϵͳ         �T�T�T�g" << endl;
	cout << "\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	Input();
	int in;
	while (1){
		system("cls");
		menu();
		cout << "���������ѡ� ";  cin >> in;
		switch (in)
		{
		case 1: Bubble_Sort(List.r, INITSIZE);  break;
		case 2: HeapSort(List.r, INITSIZE);     break;
		case 3: QuickSort(List.r, INITSIZE);    break;
		case 4: LSDRadixSort(List.r, INITSIZE); break;
		case 5: Show_All_Sort_Result(List.r, INITSIZE); break;
		case 0: exit(0); break;
		default: cout << "\t����������������롣" << endl;
		}
		cout << endl;
		system("pause");
	}
	return 0;
}

