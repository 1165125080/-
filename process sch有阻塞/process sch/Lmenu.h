#pragma once
//Lmenu.h
#ifndef LMENU_H
#define LMENU_H
#include "LProcess.h"
#include "LProQueue.h"
#include "LProList.h"
class Lmenu
{

private:
	int	SYS_TIME;				//记录CPU处理机的时刻
	bool isWork;
	int	processNum;
	int	queueNum;
	int	queue_first_time;
	int restProNum;
	//生成保存进程开始时刻结果的数组
	int *processBegin;
	//生成保存进程完成时刻结果的数组
	int *processResult;
	// 生成记录进程的随机生成的进程时间片，以便于检验
	int *process_time;
	//生成用户指定n个进程，并将为其分配进程号
	LProcess *process;
	//生成用户指定的n个队列，并为其分配时间片和优先级
	LProQueue *queue;
	//简单选择排序，使随机输入的进程进入时间有序
	LNode *L;	//链表存储
	LList list;		//链表类
	void Selectsort(int a[], int n);
public:
	Lmenu();
	Lmenu(int processNum, int queueNum, int*processBegin, int*processResult, int*process_time, LProcess*process, LProQueue*queue);
	int LInputQueueNum();
	//输入各进程进入时间
	void LInputEnTime();
	//随机生成各进程需要运行的时间
	void LCreatProcessExeuTime();
	//输入第一个队列的时间片并生成随后队列的时间片
	void LCreatQueueTime();
	void LExecute();
	void LSetBarrageProcess();

};

#endif