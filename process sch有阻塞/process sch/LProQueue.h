#pragma once
// LProQueue.h
#include "LProcess.h"
struct LProcessNode
{
	int process_ID;
	struct LProcessNode* next;
};
class LProQueue
{
private:
	LProcessNode* head;     // ָ������׽���ָ��
	LProcessNode* tail;     // ָ��������һ������ָ��
	int length=0;				// ���г���
	int quePriority;		// ���̶������ȼ�
	int queProTime;				// ����ʱ��Ƭ
public:
	//���캯�������ȼ���
	LProQueue();
	LProQueue(int pri/*�������ȼ��趨*/);
	//����
	bool dequeue(/*LProcessNode* lpn*/);
	//���
	void enqueue(LProcessNode* lpn);
	//��ö��г���
	int getLength();
	//���ö������ȼ�
	void setQuePriority(int pri);
	//��ö������ȼ�	
	int getQuePriority();
	//���ö��н���ʱ��Ƭ
	void setQueTime(int time);
	//��ö��н���ʱ��Ƭ
	int getQueTime();
	//��ö����׵�ַ
	LProcessNode* getQueHead();
	//��ö���β��ַ
	LProcessNode* getQueTail();
	void setLength();
};
