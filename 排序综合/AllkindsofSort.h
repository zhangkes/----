#include<iostream>
#include<time.h>
using namespace std;
#define COUNT 40000	   //�������ݵ�����
#define MAX     30000   //������ķ�Χ
#define ElementType int	 //�������ݵ�����
typedef struct Statistics{
	long   CompareTimes;	 //�Ƚϴ���
	long   ExchangeTimes;	 //��������
	double time;			 //��ʱ
};
Statistics ResultPackage[6];   //ͳ��������ֹ۲�ֵ
void Reset(ElementType A[],int N)         //�������������
{
	srand((unsigned)time(0));
	for (int i = 0; i<N; i++) //20��
	{
		A[i] = rand() % MAX;
	}
	cout << "��������������ɹ���" << endl;
}
void Print(ElementType A[], int N)
{
	cout << "�����Ϊ��\n";
	for (int i = 0; i<N; i++)
	{
		cout << A[i] << "\t";
		if (i %5 == 0)cout << endl;
	}
	cout << endl;
}
void ResultTable(Statistics ResultPackage[])
{
		cout << "��������" << "\t\t�Ƚϴ���" << "\t\t��������" << "\t\t��ʱ" << endl;
		cout << "ð������\t" << "\t" << ResultPackage[0].CompareTimes << "\t\t" << ResultPackage[0].ExchangeTimes << "\t\t" << ResultPackage[0].time << endl;
		cout << "������  \t" << "\t" << ResultPackage[1].CompareTimes << "\t\t" << ResultPackage[1].ExchangeTimes << "\t\t" << ResultPackage[1].time << endl;
		cout << "ϣ������\t" << "\t" << ResultPackage[2].CompareTimes << "\t\t" << ResultPackage[2].ExchangeTimes << "\t\t" << ResultPackage[2].time << endl;
		cout << "��������\t" << "\t" << ResultPackage[3].CompareTimes << "\t\t" << ResultPackage[3].ExchangeTimes << "\t\t" << ResultPackage[3].time << endl;
		cout << "�鲢����\t" << "\t" << ResultPackage[4].CompareTimes << "\t\t" << ResultPackage[4].ExchangeTimes << "\t\t" << ResultPackage[4].time << endl;
		cout << "��������\t" << "\t" << ResultPackage[5].CompareTimes << "\t\t" << ResultPackage[5].ExchangeTimes << "\t\t" << ResultPackage[5].time << endl;
}
/*ð������*/
void  Bubble_Sort(ElementType A[], int N)
{
	double Start, Finish;
	Start = clock();
	ElementType temp;       //��ʱ���ݣ������������������
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
{ /* �������� */

	double Start, Finish;
	Start = clock();
	int P, i;
	ElementType Tmp;

	for (P = 1; P<N; P++) {
		Tmp = A[P]; ResultPackage[5].ExchangeTimes++;/* ȡ��δ���������еĵ�һ��Ԫ��*/
		for (i = P; i > 0 && A[i - 1] > Tmp; i--)
		{
			ResultPackage[5].CompareTimes++;
			ResultPackage[5].ExchangeTimes++;
			A[i] = A[i - 1]; /*������������������Ԫ�رȽϲ�����*/
		}
		ResultPackage[5].ExchangeTimes++;
		A[i] = Tmp; /* �Ž����ʵ�λ�� */
	}
	Finish = clock();
	ResultPackage[5].time = Finish - Start;
}
/*ϣ����shell������*/
void ShellSort(ElementType A[], int N)
{/* ϣ������ - ��Sedgewick�������� */
	double Start, Finish;
	Start = clock();
	int Si, D, P, i;
	ElementType Tmp;
	/* ����ֻ�г�һС�������� */
	int Sedgewick[] = { 1045505, 587521, 260609, 146305, 64769,
		36289, 16001, 8929, 3905, 2161, 929,
		505, 209, 109, 41, 19, 5, 1, 0 };

	for (Si = 0; Sedgewick[Si] >= N; Si++); /* ��ʼ������Sedgewick[Si]���ܳ����������г��� */

	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
		for (P = D; P < N; P++) { /* ��������*/
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
/*������*/
void Swap(ElementType *a, ElementType *b)
{
	ResultPackage[1].ExchangeTimes+=3;
	ElementType t = *a; *a = *b; *b = t;
}

void PercDown(ElementType A[], int p, int N)
{
	/* ��N��Ԫ�ص���������A[p]Ϊ�����Ӷѵ���Ϊ���� */
	int Parent, Child;
	ElementType X;
	
	X = A[p]; /* ȡ��������ŵ�ֵ */
	for (Parent = p; (Parent * 2 + 1)<N; Parent = Child) {
		Child = Parent * 2 + 1;	 
		ResultPackage[1].CompareTimes++;
		if ((Child != N - 1) && (A[Child]<A[Child + 1]))
			Child++;  /* Childָ�������ӽ��Ľϴ��� */
		ResultPackage[1].CompareTimes++;
		if (X>= A[Child]) break; /* �ҵ��˺���λ�� */
		else  /* ����X */
		{
			ResultPackage[1].ExchangeTimes++;
			A[Parent] = A[Child];
		}
	}
	A[Parent] = X;	 ResultPackage[1].ExchangeTimes++;
}

void HeapSort(ElementType A[], int N)
{ /* ������ */
	double Start, Finish;
	Start = clock();
	int i;
	for (i = N / 2 - 1; i >= 0; i--)/* �������� */
		PercDown(A, i, N);

	for (i = N - 1; i>0; i--) {
		/* ɾ�����Ѷ� */
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
	int pivotkey = a[low]; //ȡ֧��Ĺؼ������pivotkey����
	while (low<high) {       //�ӱ�����˽�������м�ɨ��
		while (low<high && Left(a[high], pivotkey))
			--high;
		a[low] = a[high];  //����֧��С�ļ�¼�������Ͷˣ�
		ResultPackage[3].ExchangeTimes++;
		while (low<high && Right(a[low], pivotkey))
			++low;
		a[high] = a[low];  //����֧���ļ�¼�������߶ˣ�
		ResultPackage[3].ExchangeTimes++;
	}
	a[low] = dt;
	ResultPackage[3].ExchangeTimes ++;
	return low;          // ������������λ��
} // Partition

void Qsort(int a[], int low, int high){
	if (low<high){
		int pivotloc = Partition(a, low, high);
		Qsort(a, low, pivotloc - 1);
		Qsort(a, pivotloc + 1, high);
	}
}
void QuickSort(ElementType A[], int N)
{ /* ͳһ�ӿ� */
	double Start, Finish;
	Start = clock();
	Qsort(A, 0, N - 1);
	Finish = clock();
	ResultPackage[3].time = Finish - Start;
}
/* �鲢���� - ѭ��ʵ�� */
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{ /* �������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ���������� */
	int LeftEnd, NumElements, Tmp;
	int i;

	LeftEnd = R - 1; /* ����յ�λ�� */
	Tmp = L;         /* �������е���ʼλ�� */
	NumElements = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd) {
		ResultPackage[4].CompareTimes++;
		if (A[L]<= A[R])
			TmpA[Tmp++] = A[L++]; /* �����Ԫ�ظ��Ƶ�TmpA */
		else
			TmpA[Tmp++] = A[R++]; /* ���ұ�Ԫ�ظ��Ƶ�TmpA */
		ResultPackage[4].ExchangeTimes++;
	}

	while (L <= LeftEnd)
	{
		ResultPackage[4].ExchangeTimes++;
		TmpA[Tmp++] = A[L++]; /* ֱ�Ӹ������ʣ�µ� */
	}
		
	while (R <= RightEnd)
	{
		ResultPackage[4].ExchangeTimes++;
		TmpA[Tmp++] = A[R++]; /* ֱ�Ӹ����ұ�ʣ�µ� */
	}
	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd]; /* �������TmpA[]���ƻ�A[] */
}
/* length = ��ǰ�������еĳ���*/
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{ /* �����鲢������������ */
	int i, j;

	for (i = 0; i <= N - 2 * length; i += 2 * length)
		Merge(A, TmpA, i, i + length, i + 2 * length - 1);

	if (i + length < N) /* �鲢���2������*/
		Merge(A, TmpA, i, i + length, N - 1);
	else /* ���ֻʣ1������*/
		for (j = i; j < N; j++) TmpA[j] = A[j];
}

void Merge_Sort(ElementType A[], int N)
{
	double Start, Finish;
	Start = clock();
	int length;
	ElementType *TmpA;

	length = 1; /* ��ʼ�������г���*/
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
	else printf("�ռ䲻��");
	Finish = clock();
	ResultPackage[4].time = Finish - Start;
}