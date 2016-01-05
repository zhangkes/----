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
		cout << "药品名：" << A[i].name << "\t药品编号: " << A[i].num;
		cout << "\t药品单价：" << A[i].price << "\t销出数量：" << A[i].count << "\t销售额：" << A[i].sale << endl;
	}
}
/*****************************排序算法******************************************/
/*冒泡排序——单价的排序*/
void  Bubble_Sort(ElementType A[], int N)
{
	ElementType temp;       //临时数据，具体类型视情况而定
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
/*堆排序——销售额的排序*/
void Swap(ElementType *a, ElementType *b)
{
	ElementType t = *a; *a = *b; *b = t;
}

void PercDown(ElementType A[], int p, int N)
{
	/* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
	int Parent, Child;
	ElementType X;

	X = A[p]; /* 取出根结点存放的值 */
	for (Parent = p; (Parent * 2 + 1) < N; Parent = Child) {
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (A[Child].sale < A[Child + 1].sale))
			Child++;  /* Child指向左右子结点的较大者 */
		if (X.sale >= A[Child].sale) break; /* 找到了合适位置 */
		else  /* 下滤X */
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}

void HeapSort(ElementType A[], int N)
{ /* 堆排序 */
	int i;

	for (i = N / 2 - 1; i >= 0; i--)/* 建立最大堆 */
		PercDown(A, i, N);

	for (i = N - 1; i>0; i--) {
		/* 删除最大堆顶 */
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
	Show_All_Sort_Result(List.r, INITSIZE);
}

/*快速排序——销售量的排序*/
ElementType Median3(ElementType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left].count > A[Center].count)
		Swap(&A[Left], &A[Center]);
	if (A[Left].count > A[Right].count)
		Swap(&A[Left], &A[Right]);
	if (A[Center].count > A[Right].count)
		Swap(&A[Center], &A[Right]);
	/* 此时A[Left] <= A[Center] <= A[Right] */
	Swap(&A[Center], &A[Right - 1]); /* 将基准Pivot藏到右边*/
	/* 只需要考虑A[Left+1] … A[Right-2] */
	return  A[Right - 1];  /* 返回基准Pivot */
}

/*插入排序*/
void InsertionSort(ElementType A[], int N)
{ /* 插入排序 */
	int P, i;
	ElementType Tmp;

	for (P = 1; P<N; P++) {
		Tmp = A[P]; /* 取出未排序序列中的第一个元素*/
		for (i = P; i>0 && A[i - 1].count>Tmp.count; i--)
			A[i] = A[i - 1]; /*依次与已排序序列中元素比较并右移*/
		A[i] = Tmp; /* 放进合适的位置 */
	}
}
void Qsort(ElementType A[], int Left, int Right)
{ /* 核心递归函数 */
	int  Cutoff = 100, Low, High;
	ElementType	Pivot;
	if (Cutoff <= Right - Left) { /* 如果序列元素充分多，进入快排 */
		Pivot = Median3(A, Left, Right); /* 选基准 */
		Low = Left; High = Right - 1;
		while (1) { /*将序列中比基准小的移到基准左边，大的移到右边*/
			while (A[++Low].count < Pivot.count);
			while (A[--High].count > Pivot.count);
			if (Low < High) Swap(&A[Low], &A[High]);
			else break;
		}
		Swap(&A[Low], &A[Right - 1]);   /* 将基准换到正确的位置 */
		Qsort(A, Left, Low - 1);    /* 递归解决左边 */
		Qsort(A, Low + 1, Right);   /* 递归解决右边 */
	}
	else InsertionSort(A + Left, Right - Left + 1); /* 元素太少，用简单排序 */
}

void QuickSort(ElementType A[], int N)
{ /* 统一接口 */
	Qsort(A, 0, N - 1);
	Show_All_Sort_Result(List.r, INITSIZE);
}

/* 基数排序——药品编号*/
#define MaxDigit 4	  /*最多有MaxDigit个关键字*/		
#define KeyType  ElementType
#define Radixint 10 //基数为0-9
#define Radixchar 26 //基数为A-Z或a-z
#define Radix Radixint+Radixchar*2
/*ASCII 48-57 0-9  65-90 A-Z 97-122 a-z*/
typedef struct Node *PtrToNode;	 /* 桶元素结点 */
struct Node {
	KeyType key;
	PtrToNode next;
};

/* 桶头结点 */
struct HeadNode {
	PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];

int GetDigit(KeyType X, int D)
{ /* 默认次位D=1, 主位D<=MaxDigit */
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
{ /* 基数排序 - 次位优先 */
	int D, Di, i;
	Bucket B;
	PtrToNode tmp, p, List = NULL;

	for (i = 0; i< Radix; i++) /* 初始化每个桶为空链表 */
		B[i].head = B[i].tail = NULL;
	for (i = 0; i<N; i++) { /* 将原始序列逆序存入初始链表List */
		tmp = (PtrToNode)malloc(sizeof(struct Node));
		tmp->key = A[i];
		tmp->next = List;
		List = tmp;
	}
	/* 下面开始排序 */
	for (D = MaxDigit-1; D >=0; D--) { /* 对数据的每一位循环处理 */
		/* 下面是分配的过程 */
		p = List;
		while (p) {
			Di = GetDigit(p->key, D); /* 获得当前元素的当前位数字 */
			/* 从List中摘除 */
			tmp = p; p = p->next;
			/* 插入B[Di]号桶尾 */
			tmp->next = NULL;
			if (B[Di].head == NULL)
				B[Di].head = B[Di].tail = tmp;
			else {
				B[Di].tail->next = tmp;
				B[Di].tail = tmp;
			}
		}
		/* 下面是收集的过程 */
		List = NULL;
		for (Di = Radix - 1; Di >= 0; Di--) { /* 将每个桶的元素顺序收集入List */
			if (B[Di].head) { /* 如果桶不为空 */
				/* 整桶插入List表头 */
				B[Di].tail->next = List;
				tmp=List = B[Di].head;
				B[Di].head = B[Di].tail = NULL; /* 清空桶 */
			}
		}
	}
	/* 将List倒入A[]并释放空间 */
	for (i = 0; i<N; i++) {
		tmp = List;
		List = List->next;
		A[i] = tmp->key;
		free(tmp);
	}
	Show_All_Sort_Result(A, INITSIZE);
}

