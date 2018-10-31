#include "LProQueue.h"


//构造函数（优先级）
LProQueue::LProQueue()
{
	head = tail = nullptr;
	length = 0;
	quePriority = 0;
}
LProQueue::LProQueue(int pri/*队列优先级设定*/)
{
	head = tail = nullptr;
	length = 0;
	quePriority = pri;
}
//出队
bool LProQueue::dequeue(/*LProcessNode* lpn*/)
{
	if (getLength() <= 0)
	{
		return false;
	}
	else
	{
		/*lpn = head;*/
		head = head->next;
		if (head == nullptr)
		{
			tail = nullptr;
		}
		length--;
	}
	return true;
}
//入队
void LProQueue::enqueue(LProcessNode* lpn)
{
	if (getLength() <= 0)
	{
		lpn->next = nullptr;
		head = tail = lpn;
		head->next = nullptr;
		tail->next = nullptr;
	}
	else
	{
		/*if (getLength()==1)
		{
		}*/
		tail->next = lpn;
		tail = tail->next;
	}
	length++;
}
//设置队列长度
void LProQueue::setLength()
{
	length = 0;
}
//获得队列长度
int LProQueue::getLength()
{
	return length;
}
//设置队列优先级
void LProQueue::setQuePriority(int pri)
{
	quePriority = pri;
}
//获得队列优先级
int LProQueue::getQuePriority()
{
	return quePriority;
}
//设置队列进程时间片
void LProQueue::setQueTime(int time)
{
	queProTime = time;
}
//获得队列进程时间片
int LProQueue::getQueTime()
{
	return queProTime;
}
//获得队列首地址
LProcessNode* LProQueue::getQueHead()
{
	return head;
}
//获得队列尾地址
LProcessNode* LProQueue::getQueTail()
{
	return tail;
}
