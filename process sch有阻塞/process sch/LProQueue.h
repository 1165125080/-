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
	LProcessNode* head;     // 指向队列首结点的指针
	LProcessNode* tail;     // 指向队列最后一个结点的指针
	int length=0;				// 队列长度
	int quePriority;		// 进程队列优先级
	int queProTime;				// 进程时间片
public:
	//构造函数（优先级）
	LProQueue();
	LProQueue(int pri/*队列优先级设定*/);
	//出队
	bool dequeue(/*LProcessNode* lpn*/);
	//入队
	void enqueue(LProcessNode* lpn);
	//获得队列长度
	int getLength();
	//设置队列优先级
	void setQuePriority(int pri);
	//获得队列优先级	
	int getQuePriority();
	//设置队列进程时间片
	void setQueTime(int time);
	//获得队列进程时间片
	int getQueTime();
	//获得队列首地址
	LProcessNode* getQueHead();
	//获得队列尾地址
	LProcessNode* getQueTail();
	void setLength();
};
