#include<iostream>
#include<time.h>
using namespace std;
#define COUNT 40000	   //待排数据的数量
#define MAX     30000   //随机数的范围
#define ElementType int	 //待排数据的类型
typedef struct Statistics{
	long   CompareTimes;	 //比较次数
	long   ExchangeTimes;	 //交换次数
	double time;			 //耗时
};
Statistics ResultPackage[6];   //统计排序各种观察值
void Reset(ElementType A[],int N)         //重新生成随机数
{
	srand((unsigned)time(0));
	for (int i = 0; i<N; i++) //20个
	{
		A[i] = rand() % MAX;
	}
	cout << "重新生成随机数成功！" << endl;
}
void Print(ElementType A[], int N)
{
	cout << "排序后为：\n";
	for (int i = 0; i<N; i++)
	{
		cout << A[i] << "\t";
		if (i %5 == 0)cout << endl;
	}
	cout << endl;
}
void ResultTable(Statistics ResultPackage[])
{
		cout << "排序名称" << "\t\t比较次数" << "\t\t交换次数" << "\t\t耗时" << endl;
		cout << "冒泡排序\t" << "\t" << ResultPackage[0].CompareTimes << "\t\t" << ResultPackage[0].ExchangeTimes << "\t\t" << ResultPackage[0].time << endl;
		cout << "堆排序  \t" << "\t" << ResultPackage[1].CompareTimes << "\t\t" << ResultPackage[1].ExchangeTimes << "\t\t" << ResultPackage[1].time << endl;
		cout << "希尔排序\t" << "\t" << ResultPackage[2].CompareTimes << "\t\t" << ResultPackage[2].ExchangeTimes << "\t\t" << ResultPackage[2].time << endl;
		cout << "快速排序\t" << "\t" << ResultPackage[3].CompareTimes << "\t\t" << ResultPackage[3].ExchangeTimes << "\t\t" << ResultPackage[3].time << endl;
		cout << "归并排序\t" << "\t" << ResultPackage[4].CompareTimes << "\t\t" << ResultPackage[4].ExchangeTimes << "\t\t" << ResultPackage[4].time << endl;
		cout << "插入排序\t" << "\t" << ResultPackage[5].CompareTimes << "\t\t" << ResultPackage[5].ExchangeTimes << "\t\t" << ResultPackage[5].time << endl;
}
/*冒泡排序*/
void  Bubble_Sort(ElementType A[], int N)
{
	double Start, Finish;
	Start = clock();
	ElementType temp;       //临时数据，具体类型视情况而定
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++)
		{
			ResultPackage[0].CompareTimes++;
				if (A[j] > A[j + 1])
				{
					ResultPackage[0].ExchangeTimes+=3;
					temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
		}
	Finish = clock();
	ResultPackage[0].time = Finish - Start;
}

void Insertion_Sort(ElementType A[], int N)
{ /* 插入排序 */

	double Start, Finish;
	Start = clock();
	int P, i;
	ElementType Tmp;

	for (P = 1; P<N; P++) {
		Tmp = A[P]; ResultPackage[5].ExchangeTimes++;/* 取出未排序序列中的第一个元素*/
		for (i = P; i > 0 && A[i - 1] > Tmp; i--)
		{
			ResultPackage[5].CompareTimes++;
			ResultPackage[5].ExchangeTimes++;
			A[i] = A[i - 1]; /*依次与已排序序列中元素比较并右移*/
		}
		ResultPackage[5].ExchangeTimes++;
		A[i] = Tmp; /* 放进合适的位置 */
	}
	Finish = clock();
	ResultPackage[5].time = Finish - Start;
}
/*希尔（shell）排序*/
void ShellSort(ElementType A[], int N)
{/* 希尔排序 - 用Sedgewick增量序列 */
	double Start, Finish;
	Start = clock();
	int Si, D, P, i;
	ElementType Tmp;
	/* 这里只列出一小部分增量 */
	int Sedgewick[] = { 1045505, 587521, 260609, 146305, 64769,
		36289, 16001, 8929, 3905, 2161, 929,
		505, 209, 109, 41, 19, 5, 1, 0 };

	for (Si = 0; Sedgewick[Si] >= N; Si++); /* 初始的增量Sedgewick[Si]不能超过待排序列长度 */

	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
		for (P = D; P < N; P++) { /* 插入排序*/
			Tmp = A[P];	  ResultPackage[2].ExchangeTimes++;
			for (i = P; i >= D && A[i - 1] > Tmp; i -= D)
			{
				ResultPackage[2].CompareTimes++;
				ResultPackage[2].ExchangeTimes++;
				A[i] = A[i - D];
			}
			ResultPackage[2].ExchangeTimes++;
			A[i] = Tmp;
		}
	Finish = clock();
	ResultPackage[2].time = Finish - Start;
}
/*堆排序*/
void Swap(ElementType *a, ElementType *b)
{
	ResultPackage[1].ExchangeTimes+=3;
	ElementType t = *a; *a = *b; *b = t;
}

void PercDown(ElementType A[], int p, int N)
{
	/* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
	int Parent, Child;
	ElementType X;
	
	X = A[p]; /* 取出根结点存放的值 */
	for (Parent = p; (Parent * 2 + 1)<N; Parent = Child) {
		Child = Parent * 2 + 1;	 
		ResultPackage[1].CompareTimes++;
		if ((Child != N - 1) && (A[Child]<A[Child + 1]))
			Child++;  /* Child指向左右子结点的较大者 */
		ResultPackage[1].CompareTimes++;
		if (X>= A[Child]) break; /* 找到了合适位置 */
		else  /* 下滤X */
		{
			ResultPackage[1].ExchangeTimes++;
			A[Parent] = A[Child];
		}
	}
	A[Parent] = X;	 ResultPackage[1].ExchangeTimes++;
}

void HeapSort(ElementType A[], int N)
{ /* 堆排序 */
	double Start, Finish;
	Start = clock();
	int i;
	for (i = N / 2 - 1; i >= 0; i--)/* 建立最大堆 */
		PercDown(A, i, N);

	for (i = N - 1; i>0; i--) {
		/* 删除最大堆顶 */
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
	Finish = clock();
	ResultPackage[1].time = Finish - Start;
}
int  Left(int a, int b)
{
	ResultPackage[3].CompareTimes++;
	return a >= b;
}
int  Right(int a, int b)
{
	ResultPackage[3].CompareTimes++;
	return a <= b;
}
int Partition(int a[], int low, int high) {
	int dt;
	dt = a[low];
	int pivotkey = a[low]; //取支点的关键码存入pivotkey变量
	while (low<high) {       //从表的两端交替地向中间扫描
		while (low<high && Left(a[high], pivotkey))
			--high;
		a[low] = a[high];  //将比支点小的记录交换到低端；
		ResultPackage[3].ExchangeTimes++;
		while (low<high && Right(a[low], pivotkey))
			++low;
		a[high] = a[low];  //将比支点大的记录交换到高端；
		ResultPackage[3].ExchangeTimes++;
	}
	a[low] = dt;
	ResultPackage[3].ExchangeTimes ++;
	return low;          // 返回枢轴所在位置
} // Partition

void Qsort(int a[], int low, int high){
	if (low<high){
		int pivotloc = Partition(a, low, high);
		Qsort(a, low, pivotloc - 1);
		Qsort(a, pivotloc + 1, high);
	}
}
void QuickSort(ElementType A[], int N)
{ /* 统一接口 */
	double Start, Finish;
	Start = clock();
	Qsort(A, 0, N - 1);
	Finish = clock();
	ResultPackage[3].time = Finish - Start;
}
/* 归并排序 - 循环实现 */
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{ /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
	int LeftEnd, NumElements, Tmp;
	int i;

	LeftEnd = R - 1; /* 左边终点位置 */
	Tmp = L;         /* 有序序列的起始位置 */
	NumElements = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd) {
		ResultPackage[4].CompareTimes++;
		if (A[L]<= A[R])
			TmpA[Tmp++] = A[L++]; /* 将左边元素复制到TmpA */
		else
			TmpA[Tmp++] = A[R++]; /* 将右边元素复制到TmpA */
		ResultPackage[4].ExchangeTimes++;
	}

	while (L <= LeftEnd)
	{
		ResultPackage[4].ExchangeTimes++;
		TmpA[Tmp++] = A[L++]; /* 直接复制左边剩下的 */
	}
		
	while (R <= RightEnd)
	{
		ResultPackage[4].ExchangeTimes++;
		TmpA[Tmp++] = A[R++]; /* 直接复制右边剩下的 */
	}
	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd]; /* 将有序的TmpA[]复制回A[] */
}
/* length = 当前有序子列的长度*/
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{ /* 两两归并相邻有序子列 */
	int i, j;

	for (i = 0; i <= N - 2 * length; i += 2 * length)
		Merge(A, TmpA, i, i + length, i + 2 * length - 1);

	if (i + length < N) /* 归并最后2个子列*/
		Merge(A, TmpA, i, i + length, N - 1);
	else /* 最后只剩1个子列*/
		for (j = i; j < N; j++) TmpA[j] = A[j];
}

void Merge_Sort(ElementType A[], int N)
{
	double Start, Finish;
	Start = clock();
	int length;
	ElementType *TmpA;

	length = 1; /* 初始化子序列长度*/
	TmpA = (ElementType*)malloc(N * sizeof(ElementType));
	if (TmpA != NULL) {
		while (length < N) {
			Merge_pass(A, TmpA, N, length);
			length *= 2;
			Merge_pass(TmpA, A, N, length);
			length *= 2;
		}
		free(TmpA);
	}
	else printf("空间不足");
	Finish = clock();
	ResultPackage[4].time = Finish - Start;
}