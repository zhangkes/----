// 排序综合.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"AllkindsofSort.h"
int A[COUNT];
int OriginData[COUNT];
void menu()
{
	cout << "\t╔═════════════════╗" << endl;
	cout << "\t╠═══     测试排序时间     ═══╣" << endl;
	cout << "\t╠═══    1--- 冒泡排序     ═══╣" << endl;
	cout << "\t╠═══    2--- 堆排序       ═══╣" << endl;
	cout << "\t╠═══    3--- 希尔排序     ═══╣" << endl;
	cout << "\t╠═══    4--- 快速排序     ═══╣" << endl;
	cout << "\t╠═══    5--- 归并排序     ═══╣" << endl;
	cout << "\t╠═══    6--- 插入排序     ═══╣" << endl;
	cout << "\t╠═══    7--- 打印数组     ═══╣" << endl;
	cout << "\t╠═══    8--- 显示排序结果 ═══╣" << endl;
	cout << "\t╠═══    9--- 重新生成随机数 ══╣" << endl;
	cout << "\t╠═══    0--- 退出         ═══╣" << endl;
	cout << "\t╚═════════════════╝" << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int in;
	memset(ResultPackage, 0, sizeof(Statistics) * 6);
	Reset(OriginData, COUNT); //初始化数据
	while (1){
		memcpy(A, OriginData, sizeof(A));	  //相同数据排序
		system("cls");
		menu();
		cout << "请输入操作选项： ";  cin >> in;
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
		default: cout << "\t输入错误，请重新输入。" << endl;
		}
		cout << endl;
		system("pause");
	}
	return 0;
}

