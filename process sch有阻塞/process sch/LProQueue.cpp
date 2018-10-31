#include "LProQueue.h"


//���캯�������ȼ���
LProQueue::LProQueue()
{
	head = tail = nullptr;
	length = 0;
	quePriority = 0;
}
LProQueue::LProQueue(int pri/*�������ȼ��趨*/)
{
	head = tail = nullptr;
	length = 0;
	quePriority = pri;
}
//����
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
//���
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
//���ö��г���
void LProQueue::setLength()
{
	length = 0;
}
//��ö��г���
int LProQueue::getLength()
{
	return length;
}
//���ö������ȼ�
void LProQueue::setQuePriority(int pri)
{
	quePriority = pri;
}
//��ö������ȼ�
int LProQueue::getQuePriority()
{
	return quePriority;
}
//���ö��н���ʱ��Ƭ
void LProQueue::setQueTime(int time)
{
	queProTime = time;
}
//��ö��н���ʱ��Ƭ
int LProQueue::getQueTime()
{
	return queProTime;
}
//��ö����׵�ַ
LProcessNode* LProQueue::getQueHead()
{
	return head;
}
//��ö���β��ַ
LProcessNode* LProQueue::getQueTail()
{
	return tail;
}
