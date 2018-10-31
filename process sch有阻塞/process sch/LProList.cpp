#include "LProList.h"
Status LList::InitList_L(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if (!L)
		exit(OVERFLOW);
	L->next = NULL;
	return OK;
}
Status LList::DestroyList_L(LinkList &L)
{
	LinkList  p;
	while (L)
	{
		p = L->next;
		free(L);
		L = p;
	}
	return OK;
}
Status LList::ListEmpty_L(LinkList L)
{
	if (L->next)     //要看首元结点中是否有元素 
		return ERROR;
	else
		return OK;
}

Status compare(int e1, int e2)
{
	if (e1 == e2)
		return OK;
	else
		return ERROR;
}
LinkList LList::LocateElem_L(LinkList L, int e)
{
	LinkList p;
	p = L->next;
	while (p && !compare(p->data.process_ID, e))//只有p为空指针或者定位成功才结束
	{
		p = p->next;
	}
	return p;
}
Status LList::GetElem_L(LinkList L, int &e)
{
	LinkList p;
	p = L->next;
	int t = 0;
	while (p && !compare(p->data.process_ID, e))//只有p为空指针或者定位成功才结束
	{
		p = p->next;
		t++;
	}
	return t+1;
}
Status LList::ListInsert_L(LinkList &L, int i, LBarrageProcess e)
{
	int j = 0;
	LinkList p = L, s;
	while (p&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
LinkList LList::ListDelete_L(LinkList &L, int i)
{
	int j = 0;
	LinkList p, q;
	p = L;
	while (p->next&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next || j > i - 1))
		return ERROR;
	q = p->next;
	p->next = q->next;
	free(q);
	return p;
}