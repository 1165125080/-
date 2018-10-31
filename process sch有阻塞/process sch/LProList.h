#ifndef LPROLIST_H
#define LPROLIST_H
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define  TURE     1
#define  FALSE    0
#define  OK       1
#define  ERROR    0
#define  INFEASIBLE  -1
#define  OVERFLOW    -2
typedef  int  Status;
typedef  int ElemType;
struct LBarrageProcess
{
	int process_ID=0;
	int beginbarrage_time = 0;
	int barrage_time=0;
	int index=0;
	int sign=0;
};
typedef struct LNode
{
	LBarrageProcess data;
	struct LNode  *next;
}LNode, *LinkList;
class LList
{
private:

public:
	Status InitList_L(LinkList &L);
	Status DestroyList_L(LinkList &L);
	Status ListEmpty_L(LinkList L);
	Status GetElem_L(LinkList L, int &e);
	//Status compare(ElemType e1, ElemType e2);
	LinkList LocateElem_L(LinkList L, int e);
	Status ListInsert_L(LinkList &L, int i, LBarrageProcess e);
	LinkList ListDelete_L(LinkList &L, int i);
};

#endif