#include "Lmenu.h"
#include <iostream>

Lmenu::Lmenu()
{}
Lmenu::Lmenu(int processNum, int queueNum, int*processBegin, int *processResult, int*process_time, LProcess*process, LProQueue*queue)
{
	SYS_TIME = 0;				//记录CPU处理机的时刻
	isWork = false;
	this->processNum = processNum;
	this->queueNum = queueNum;
	queue_first_time = 0;
	restProNum = processNum;
	//生成保存进程开始时刻结果的数组
	this->processBegin = processBegin;
	//生成保存进程完成时刻结果的数组
	this->processResult = processResult;
	// 生成记录进程的随机生成的进程时间片，以便于检验
	this->process_time = process_time;
	//生成用户指定n个进程，并将为其分配进程号
	this->process = process;
	//生成用户指定的n个队列，并为其分配时间片和优先级
	this->queue = queue;
	//简单选择排序，使随机输入的进程进入时间有序
	//void selectSort(int r[], int n);
	LNode *L;	//链表存储
	LList list;		//链表类
}

void Lmenu::LInputEnTime()	//输入各进程进入时间
{

	//开始时间和结束时间的置数
	for (int i = 0; i < processNum; i++)
	{
		processBegin[i] = -1;
		processResult[i] = -1;
	}
	cout << endl<<"********************************************************************" <<endl;
	cout << "请输入各进程进入的时间" << endl;

	for (int t = 1; t <= processNum; t++)
	{
		cout << "请输入第" << t << "个进程进入的时间：";
		cin >> processBegin[t - 1];
	}
	Selectsort(processBegin, processNum);
	for (int t = 1; t <= processNum; *processBegin++)
	{
		//cout << i;
		process[t - 1].setBeginTime(*processBegin);
		t++;
	}
}
void Lmenu::LCreatProcessExeuTime()		//随机生成各进程需要运行的时间
{
	cout << endl << "********************************************************************"<<endl;
	for (int i = 0; i < processNum; i++)
	{
		process[i].setId(i + 1);
		process_time[i] = 1 + rand() % 10;
		process[i].setExeuTime(process_time[i]);
		cout << "第" << i + 1 << "进程需要运行的时间为" << process_time[i] << endl;
	}
}
void Lmenu::LCreatQueueTime()	//输入第一个队列的时间片并对随后队列时间片进行倍增生成
{
	cout << endl << "********************************************************************"<<endl;
	cout << "请指定第一级队列的时间片:" ;
	cin >> queue_first_time;
	cout << endl;
	queue[0].setQuePriority(queueNum);
	queue[0].setQueTime(queue_first_time);
	for (int i = 1; i < queueNum; i++)
	{
		queue[i].setQuePriority(queueNum - i);
		queue[i].setQueTime(queue[i - 1].getQueTime() * 2);
	}
}

void Lmenu::Selectsort(int a[], int n) {
	int i, j;
	for (i = 0; i < n; i++)
	{
		int minIndex = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[minIndex])
			{
				minIndex = j;
			}
		}
		swap(a[i], a[minIndex]);
	}
}

void Lmenu::LExecute()
{
	for (int i = 0; i < queueNum; i++)
	{
		queue[i].setLength();
	}
	int processSerial = 1;	//i为进程号
	for (; restProNum > 0;)
	{
		for (; SYS_TIME == process[processSerial - 1].getBeginTime(); processSerial++)
		{
			LProcessNode *node = new LProcessNode();	//LProcessNode只有ID和next
			node->process_ID = processSerial;	//ID命名
			queue[0].enqueue(node);	//node入队
			process[SYS_TIME].setPriority(queue[0].getQuePriority());	//优先级每级递减
		}

		int index = -1;
		for (int i = 0; i < queueNum; i++)
		{
			if (0 != queue[i].getLength())	//判断进入哪一级队列
			{
				index = i;
				break;
			}
		}
		if (index == -1)
		{
			LNode *p = L->next;
			for (; p; p = p->next)	//遍历链表
			{
				
				if (p->data.sign == 1)	//阻塞时间-1
					p->data.barrage_time--;
				if (p->data.barrage_time == -1)	//阻塞时间完成，删除该元素，重新进入原队列末尾
				{
					LProcessNode *node1 = new LProcessNode();	//LProcessNode只有ID和next
					node1->process_ID = p->data.process_ID;	//本进程的ID赋值给*node1的ID
					node1->next = nullptr;
 					queue[list.LocateElem_L(L, p->data.process_ID)->data.index].enqueue(node1);
					p=list.ListDelete_L(L, list.GetElem_L(L, list.LocateElem_L(L, p->data.process_ID)->data.process_ID));
				}
			}
			SYS_TIME++;
			continue;
		}
		int process_working = queue[index].getQueHead()->process_ID;	//正在运行的进程号
		process[process_working - 1].setCompleTime(1);	//已运行时间+1
		process[process_working - 1].setTFCQ(1);	//在本队列的运行时间+1


		if (list.LocateElem_L(L, process_working))	//正在运行的是否是阻塞链表里的进程
		{
			if (process[process_working - 1].getCompleTime() == list.LocateElem_L(L, process_working)->data.beginbarrage_time)	// 
			{
				list.LocateElem_L(L, process_working)->data.sign = 1;	//指示找到阻塞进程，可以进行删除了
				list.LocateElem_L(L, process_working)->data.index = index;
				LProcessNode *node1 = new LProcessNode();	//LProcessNode只有ID和next
				node1->process_ID = queue[index].getQueHead()->process_ID;	//本进程的ID赋值给*node1的ID
				node1->next = nullptr;
				queue[index].dequeue();	//本进程出队     
			}
		}
		LNode *p = L->next;
		for (; p; p = p->next)	//遍历链表
		{
			if (p->data.sign == 1)	//阻塞时间-1
				p->data.barrage_time--;
			if (p->data.barrage_time == -1)	//阻塞时间完成，删除该元素，重新进入原队列末尾
			{
				LProcessNode *node1 = new LProcessNode();	//LProcessNode只有ID和next
				node1->process_ID = p->data.process_ID;	//本进程的ID赋值给*node1的ID
				node1->next = nullptr;
				//if (process[list.LocateElem_L(L, process_working)->data.process_ID - 1].getTFCQ() == queue[list.LocateElem_L(L, process_working)->data.index].getQueTime())

				//{
				//	list.LocateElem_L(L, process_working)->data.index++;
				//	process[list.LocateElem_L(L, process_working)->data.process_ID - 1].setTFCQ(0);	//在本队列的运行时间归0
				//}
				queue[list.LocateElem_L(L, process_working)->data.index].enqueue(node1);
				list.ListDelete_L(L, list.GetElem_L(L,list.LocateElem_L(L, process_working)->data.process_ID));
			}
			//SYS_TIME++;
			//continue;
		}

		//判断运行时间是否达到结束时间
		if (process[process_working - 1].getExeuTime() == process[process_working - 1].getCompleTime())
		{
			queue[index].dequeue();	//出队
			processResult[process_working - 1] = SYS_TIME + 1;	//运行结束时间
			restProNum--;	//在运行进程数--
		}
		else if (queue[index].getQueTime() == process[process_working - 1].getTFCQ())	//判断运行进程时间是否等于本队列时间片
		{
			if (index == queueNum - 1)
			{

				LProcessNode *node1 = new LProcessNode();	//LProcessNode只有ID和next
				node1->process_ID = queue[index].getQueHead()->process_ID;	//本进程的ID赋值给*node1的ID
				node1->next = nullptr;
				queue[index].enqueue(node1);	//本进程未运行结束，继续进入本队对尾
				queue[index].dequeue();	//本进程出队
				process[process_working - 1].setTFCQ(0);	//在本队列的运行时间归0
			}
			else	//与上面相仿
			{
				LProcessNode *node1 = new LProcessNode();
				node1->process_ID = queue[index].getQueHead()->process_ID;
				node1->next = nullptr;
				queue[index + 1].enqueue(node1);	//本进程为运行结束，进入下一队列
				queue[index].dequeue();	//本进程出队
				//process[process_working - 1].setPriority(queue[index + 1].getQuePriority());
				process[process_working - 1].setTFCQ(0);	//在队列运行时间归0
			}
		}
		SYS_TIME++;	//系统时间++
	}
}
void Lmenu::LSetBarrageProcess()
{
	list.InitList_L(L);
	cout << endl << "********************************************************************"<<endl;
	cout << "输入需要阻塞进程的个数:"<<endl;
	int processBarrageNum;
	cin >> processBarrageNum;
	for (int i = 0; i < processBarrageNum; i++)
	{

		cout << "需要阻塞的进程:" ;
		cin >> L->data.process_ID;
		cout << "在运行多少时间后阻塞:" ;
		cin >> L->data.beginbarrage_time;
		cout << "阻塞多长时间:";
		cin >> L->data.barrage_time;
		list.ListInsert_L(L, i+1, L->data);

	}


}