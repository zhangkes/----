// �����������Ļ�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"BST.h"
BinTree BST = NULL; /* ����ͼ */
void menu()
{
	cout << "\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
	cout << "\t�d�T�T�T �����������Ļ������� �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    1--- ��������     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    2--- ��ʾ����     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    3--- �������     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    4--- ɾ������     �T�T�T�g" << endl;
	cout << "\t�d�T�T�T    0--- �˳�ϵͳ     �T�T�T�g" << endl;
	cout << "\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{

	int in;
	int value;
	while (1){
		system("cls");
		menu();
		cout << "���������ѡ� ";  cin >> in;
		switch (in)
		{
		case 1: {
			BinTree Result = NULL;
			cout << "��������ҵ����ݣ�"; cin >> value;
			Result = IterFind(BST, value);
			if (Result)
				cout << "���ҽ��Ϊ��" << Result->Data << endl;
			else
				cout << "û�и������ݣ�" << endl;
		}; break;
		case 2: InOrderTraverse(BST); break;
		case 3: {
			cout << "��������ӵ����ݣ�"; cin >> value;
			if (Insert(BST, value))
				cout << "��ӳɹ�" << endl;
		}; break;
		case 4: {
			cout << "������Ҫɾ�������ݣ�"; cin >> value;
			if (Delete(BST, value))
				cout << "ɾ���ɹ�" << endl;
		}; break;
		case 0: exit(0); break;
		default: cout << "\t����������������롣" << endl;
		}
		cout << endl;
		system("pause");
	}
	return 0;
}


