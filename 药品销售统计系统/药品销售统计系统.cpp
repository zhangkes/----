// 药品销售统计系统.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Function_sort.h"
void menu()
{
	cout << "\t╔═════════════════════╗" << endl;
	cout << "\t╠═══       药品销售统计系统       ═══╣" << endl;
	cout << "\t╠═══        1--- 单价的排序       ═══╣" << endl;
	cout << "\t╠═══        2--- 销售额的排序     ═══╣" << endl;
	cout << "\t╠═══        3--- 销售量的排序     ═══╣" << endl;
	cout << "\t╠═══        4--- 药品编号排序     ═══╣" << endl;
	cout << "\t╠═══        5--- 查看药品         ═══╣" << endl;
	cout << "\t╠═══        0--- 退出系统         ═══╣" << endl;
	cout << "\t╚═════════════════════╝" << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	Input();
	int in;
	while (1){
		system("cls");
		menu();
		cout << "请输入操作选项： ";  cin >> in;
		switch (in)
		{
		case 1: Bubble_Sort(List.r, INITSIZE);  break;
		case 2: HeapSort(List.r, INITSIZE);     break;
		case 3: QuickSort(List.r, INITSIZE);    break;
		case 4: LSDRadixSort(List.r, INITSIZE); break;
		case 5: Show_All_Sort_Result(List.r, INITSIZE); break;
		case 0: exit(0); break;
		default: cout << "\t输入错误，请重新输入。" << endl;
		}
		cout << endl;
		system("pause");
	}
	return 0;
}

