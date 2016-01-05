// 二叉排序树的基本操作.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"BST.h"
BinTree BST = NULL; /* 建立图 */
void menu()
{
	cout << "\t╔═════════════════╗" << endl;
	cout << "\t╠═══ 二叉排序树的基本操作 ═══╣" << endl;
	cout << "\t╠═══    1--- 查找数据     ═══╣" << endl;
	cout << "\t╠═══    2--- 显示数据     ═══╣" << endl;
	cout << "\t╠═══    3--- 添加数据     ═══╣" << endl;
	cout << "\t╠═══    4--- 删除数据     ═══╣" << endl;
	cout << "\t╠═══    0--- 退出系统     ═══╣" << endl;
	cout << "\t╚═════════════════╝" << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{

	int in;
	int value;
	while (1){
		system("cls");
		menu();
		cout << "请输入操作选项： ";  cin >> in;
		switch (in)
		{
		case 1: {
			BinTree Result = NULL;
			cout << "请输入查找的数据："; cin >> value;
			Result = IterFind(BST, value);
			if (Result)
				cout << "查找结果为：" << Result->Data << endl;
			else
				cout << "没有该项数据！" << endl;
		}; break;
		case 2: InOrderTraverse(BST); break;
		case 3: {
			cout << "请输入添加的数据："; cin >> value;
			if (Insert(BST, value))
				cout << "添加成功" << endl;
		}; break;
		case 4: {
			cout << "请输入要删除的数据："; cin >> value;
			if (Delete(BST, value))
				cout << "删除成功" << endl;
		}; break;
		case 0: exit(0); break;
		default: cout << "\t输入错误，请重新输入。" << endl;
		}
		cout << endl;
		system("pause");
	}
	return 0;
}


