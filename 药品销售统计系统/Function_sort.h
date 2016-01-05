#include"MedicData.h"
void Input()
{
	//for (int i = 0; i < INITSIZE; i++)
	memcpy(List.r, medics, sizeof(medics));
}
void Show_All_Sort_Result(ElementType A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "ҩƷ����" << A[i].name << "\tҩƷ���: " << A[i].num;
		cout << "\tҩƷ���ۣ�" << A[i].price << "\t����������" << A[i].count << "\t���۶" << A[i].sale << endl;
	}
}
/*****************************�����㷨******************************************/
/*ð�����򡪡����۵�����*/
void  Bubble_Sort(ElementType A[], int N)
{
	ElementType temp;       //��ʱ���ݣ������������������
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++)
			if (A[j].price > A[j + 1].price)
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}		
	Show_All_Sort_Result(List.r, INITSIZE);
}
/*�����򡪡����۶������*/
void Swap(ElementType *a, ElementType *b)
{
	ElementType t = *a; *a = *b; *b = t;
}

void PercDown(ElementType A[], int p, int N)
{
	/* ��N��Ԫ�ص���������A[p]Ϊ�����Ӷѵ���Ϊ���� */
	int Parent, Child;
	ElementType X;

	X = A[p]; /* ȡ��������ŵ�ֵ */
	for (Parent = p; (Parent * 2 + 1) < N; Parent = Child) {
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (A[Child].sale < A[Child + 1].sale))
			Child++;  /* Childָ�������ӽ��Ľϴ��� */
		if (X.sale >= A[Child].sale) break; /* �ҵ��˺���λ�� */
		else  /* ����X */
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}

void HeapSort(ElementType A[], int N)
{ /* ������ */
	int i;

	for (i = N / 2 - 1; i >= 0; i--)/* �������� */
		PercDown(A, i, N);

	for (i = N - 1; i>0; i--) {
		/* ɾ�����Ѷ� */
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
	Show_All_Sort_Result(List.r, INITSIZE);
}

/*�������򡪡�������������*/
ElementType Median3(ElementType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left].count > A[Center].count)
		Swap(&A[Left], &A[Center]);
	if (A[Left].count > A[Right].count)
		Swap(&A[Left], &A[Right]);
	if (A[Center].count > A[Right].count)
		Swap(&A[Center], &A[Right]);
	/* ��ʱA[Left] <= A[Center] <= A[Right] */
	Swap(&A[Center], &A[Right - 1]); /* ����׼Pivot�ص��ұ�*/
	/* ֻ��Ҫ����A[Left+1] �� A[Right-2] */
	return  A[Right - 1];  /* ���ػ�׼Pivot */
}

/*��������*/
void InsertionSort(ElementType A[], int N)
{ /* �������� */
	int P, i;
	ElementType Tmp;

	for (P = 1; P<N; P++) {
		Tmp = A[P]; /* ȡ��δ���������еĵ�һ��Ԫ��*/
		for (i = P; i>0 && A[i - 1].count>Tmp.count; i--)
			A[i] = A[i - 1]; /*������������������Ԫ�رȽϲ�����*/
		A[i] = Tmp; /* �Ž����ʵ�λ�� */
	}
}
void Qsort(ElementType A[], int Left, int Right)
{ /* ���ĵݹ麯�� */
	int  Cutoff = 100, Low, High;
	ElementType	Pivot;
	if (Cutoff <= Right - Left) { /* �������Ԫ�س�ֶ࣬������� */
		Pivot = Median3(A, Left, Right); /* ѡ��׼ */
		Low = Left; High = Right - 1;
		while (1) { /*�������бȻ�׼С���Ƶ���׼��ߣ�����Ƶ��ұ�*/
			while (A[++Low].count < Pivot.count);
			while (A[--High].count > Pivot.count);
			if (Low < High) Swap(&A[Low], &A[High]);
			else break;
		}
		Swap(&A[Low], &A[Right - 1]);   /* ����׼������ȷ��λ�� */
		Qsort(A, Left, Low - 1);    /* �ݹ������ */
		Qsort(A, Low + 1, Right);   /* �ݹ����ұ� */
	}
	else InsertionSort(A + Left, Right - Left + 1); /* Ԫ��̫�٣��ü����� */
}

void QuickSort(ElementType A[], int N)
{ /* ͳһ�ӿ� */
	Qsort(A, 0, N - 1);
	Show_All_Sort_Result(List.r, INITSIZE);
}

/* �������򡪡�ҩƷ���*/
#define MaxDigit 4	  /*�����MaxDigit���ؼ���*/		
#define KeyType  ElementType
#define Radixint 10 //����Ϊ0-9
#define Radixchar 26 //����ΪA-Z��a-z
#define Radix Radixint+Radixchar*2
/*ASCII 48-57 0-9  65-90 A-Z 97-122 a-z*/
typedef struct Node *PtrToNode;	 /* ͰԪ�ؽ�� */
struct Node {
	KeyType key;
	PtrToNode next;
};

/* Ͱͷ��� */
struct HeadNode {
	PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];

int GetDigit(KeyType X, int D)
{ /* Ĭ�ϴ�λD=1, ��λD<=MaxDigit */
	int d;
	if ((X.num[D] >= 'A'&&X.num[D] <= 'Z'))
		d = (int)X.num[D] - 55;
	else if (X.num[D] >= 'a'&&X.num[D] <= 'z')
		d = (int)X.num[D] - 61;
	else if (X.num[D] >= '0'&&X.num[D] <= '9')
	    d = (int)X.num[D] - 48;
	return d;
}
void LSDRadixSort(ElementType A[], int N)
{ /* �������� - ��λ���� */
	int D, Di, i;
	Bucket B;
	PtrToNode tmp, p, List = NULL;

	for (i = 0; i< Radix; i++) /* ��ʼ��ÿ��ͰΪ������ */
		B[i].head = B[i].tail = NULL;
	for (i = 0; i<N; i++) { /* ��ԭʼ������������ʼ����List */
		tmp = (PtrToNode)malloc(sizeof(struct Node));
		tmp->key = A[i];
		tmp->next = List;
		List = tmp;
	}
	/* ���濪ʼ���� */
	for (D = MaxDigit-1; D >=0; D--) { /* �����ݵ�ÿһλѭ������ */
		/* �����Ƿ���Ĺ��� */
		p = List;
		while (p) {
			Di = GetDigit(p->key, D); /* ��õ�ǰԪ�صĵ�ǰλ���� */
			/* ��List��ժ�� */
			tmp = p; p = p->next;
			/* ����B[Di]��Ͱβ */
			tmp->next = NULL;
			if (B[Di].head == NULL)
				B[Di].head = B[Di].tail = tmp;
			else {
				B[Di].tail->next = tmp;
				B[Di].tail = tmp;
			}
		}
		/* �������ռ��Ĺ��� */
		List = NULL;
		for (Di = Radix - 1; Di >= 0; Di--) { /* ��ÿ��Ͱ��Ԫ��˳���ռ���List */
			if (B[Di].head) { /* ���Ͱ��Ϊ�� */
				/* ��Ͱ����List��ͷ */
				B[Di].tail->next = List;
				tmp=List = B[Di].head;
				B[Di].head = B[Di].tail = NULL; /* ���Ͱ */
			}
		}
	}
	/* ��List����A[]���ͷſռ� */
	for (i = 0; i<N; i++) {
		tmp = List;
		List = List->next;
		A[i] = tmp->key;
		free(tmp);
	}
	Show_All_Sort_Result(A, INITSIZE);
}

