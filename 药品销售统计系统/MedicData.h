#include<iostream>
using namespace std;
#define MaxSize 10
typedef struct node
{
	char num[5];  /*药品编号*/
	char name[10]; /*药品名称*/
	float price;  /*药品单价*/
	int count;    /*销售数量*/
	float sale;  /*本药品销售额*/
}DataType;
//存储药品信息的顺序表的定义：
typedef struct
{
	DataType r[MaxSize];
	int length;
}SequenList;
SequenList List;
#define  ElementType DataType 
#define INITSIZE 10
DataType medics[INITSIZE] = {
	{ "A101", "as1", 12.0, 12, 144 },
	{ "A102", "as2", 13.0, 12, 144 },
	{ "A103", "as3", 12.0, 89, 188 },
	{ "B104", "as4", 52.0, 32, 134 },
	{ "B105", "as5", 45.0, 65, 78 },
	{ "B106", "as6", 89.0, 12, 99 },
	{ "B101", "as7", 78.0, 13, 452 },
	{ "b101", "as8", 64.0, 10, 230 },
	{ "C102", "as9", 53.0, 9, 440 },
	{ "a103", "as10", 69.0, 45, 144 },
};
