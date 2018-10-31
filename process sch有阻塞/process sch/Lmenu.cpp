#include "Lmenu.h"
#include <iostream>

Lmenu::Lmenu()
{}
Lmenu::Lmenu(int processNum, int queueNum, int*processBegin, int *processResult, int*process_time, LProcess*process, LProQueue*queue)
{
	SYS_TIME = 0;				//��¼CPU�������ʱ��
	isWork = false;
	this->processNum = processNum;
	this->queueNum = queueNum;
	queue_first_time = 0;
	restProNum = processNum;
	//���ɱ�����̿�ʼʱ�̽��������
	this->processBegin = processBegin;
	//���ɱ���������ʱ�̽��������
	this->processResult = processResult;
	// ���ɼ�¼���̵�������ɵĽ���ʱ��Ƭ���Ա��ڼ���
	this->process_time = process_time;
	//�����û�ָ��n�����̣�����Ϊ�������̺�
	this->process = process;
	//�����û�ָ����n�����У���Ϊ�����ʱ��Ƭ�����ȼ�
	this->queue = queue;
	//��ѡ������ʹ�������Ľ��̽���ʱ������
	//void selectSort(int r[], int n);
	LNode *L;	//����洢
	LList list;		//������
}

void Lmenu::LInputEnTime()	//��������̽���ʱ��
{

	//��ʼʱ��ͽ���ʱ�������
	for (int i = 0; i < processNum; i++)
	{
		processBegin[i] = -1;
		processResult[i] = -1;
	}
	cout << endl<<"********************************************************************" <<endl;
	cout << "����������̽����ʱ��" << endl;

	for (int t = 1; t <= processNum; t++)
	{
		cout << "�������" << t << "�����̽����ʱ�䣺";
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
void Lmenu::LCreatProcessExeuTime()		//������ɸ�������Ҫ���е�ʱ��
{
	cout << endl << "********************************************************************"<<endl;
	for (int i = 0; i < processNum; i++)
	{
		process[i].setId(i + 1);
		process_time[i] = 1 + rand() % 10;
		process[i].setExeuTime(process_time[i]);
		cout << "��" << i + 1 << "������Ҫ���е�ʱ��Ϊ" << process_time[i] << endl;
	}
}
void Lmenu::LCreatQueueTime()	//�����һ�����е�ʱ��Ƭ����������ʱ��Ƭ���б�������
{
	cout << endl << "********************************************************************"<<endl;
	cout << "��ָ����һ�����е�ʱ��Ƭ:" ;
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
	int processSerial = 1;	//iΪ���̺�
	for (; restProNum > 0;)
	{
		for (; SYS_TIME == process[processSerial - 1].getBeginTime(); processSerial++)
		{
			LProcessNode *node = new LProcessNode();	//LProcessNodeֻ��ID��next
			node->process_ID = processSerial;	//ID����
			queue[0].enqueue(node);	//node���
			process[SYS_TIME].setPriority(queue[0].getQuePriority());	//���ȼ�ÿ���ݼ�
		}

		int index = -1;
		for (int i = 0; i < queueNum; i++)
		{
			if (0 != queue[i].getLength())	//�жϽ�����һ������
			{
				index = i;
				break;
			}
		}
		if (index == -1)
		{
			LNode *p = L->next;
			for (; p; p = p->next)	//��������
			{
				
				if (p->data.sign == 1)	//����ʱ��-1
					p->data.barrage_time--;
				if (p->data.barrage_time == -1)	//����ʱ����ɣ�ɾ����Ԫ�أ����½���ԭ����ĩβ
				{
					LProcessNode *node1 = new LProcessNode();	//LProcessNodeֻ��ID��next
					node1->process_ID = p->data.process_ID;	//�����̵�ID��ֵ��*node1��ID
					node1->next = nullptr;
 					queue[list.LocateElem_L(L, p->data.process_ID)->data.index].enqueue(node1);
					p=list.ListDelete_L(L, list.GetElem_L(L, list.LocateElem_L(L, p->data.process_ID)->data.process_ID));
				}
			}
			SYS_TIME++;
			continue;
		}
		int process_working = queue[index].getQueHead()->process_ID;	//�������еĽ��̺�
		process[process_working - 1].setCompleTime(1);	//������ʱ��+1
		process[process_working - 1].setTFCQ(1);	//�ڱ����е�����ʱ��+1


		if (list.LocateElem_L(L, process_working))	//�������е��Ƿ�������������Ľ���
		{
			if (process[process_working - 1].getCompleTime() == list.LocateElem_L(L, process_working)->data.beginbarrage_time)	// 
			{
				list.LocateElem_L(L, process_working)->data.sign = 1;	//ָʾ�ҵ��������̣����Խ���ɾ����
				list.LocateElem_L(L, process_working)->data.index = index;
				LProcessNode *node1 = new LProcessNode();	//LProcessNodeֻ��ID��next
				node1->process_ID = queue[index].getQueHead()->process_ID;	//�����̵�ID��ֵ��*node1��ID
				node1->next = nullptr;
				queue[index].dequeue();	//�����̳���     
			}
		}
		LNode *p = L->next;
		for (; p; p = p->next)	//��������
		{
			if (p->data.sign == 1)	//����ʱ��-1
				p->data.barrage_time--;
			if (p->data.barrage_time == -1)	//����ʱ����ɣ�ɾ����Ԫ�أ����½���ԭ����ĩβ
			{
				LProcessNode *node1 = new LProcessNode();	//LProcessNodeֻ��ID��next
				node1->process_ID = p->data.process_ID;	//�����̵�ID��ֵ��*node1��ID
				node1->next = nullptr;
				//if (process[list.LocateElem_L(L, process_working)->data.process_ID - 1].getTFCQ() == queue[list.LocateElem_L(L, process_working)->data.index].getQueTime())

				//{
				//	list.LocateElem_L(L, process_working)->data.index++;
				//	process[list.LocateElem_L(L, process_working)->data.process_ID - 1].setTFCQ(0);	//�ڱ����е�����ʱ���0
				//}
				queue[list.LocateElem_L(L, process_working)->data.index].enqueue(node1);
				list.ListDelete_L(L, list.GetElem_L(L,list.LocateElem_L(L, process_working)->data.process_ID));
			}
			//SYS_TIME++;
			//continue;
		}

		//�ж�����ʱ���Ƿ�ﵽ����ʱ��
		if (process[process_working - 1].getExeuTime() == process[process_working - 1].getCompleTime())
		{
			queue[index].dequeue();	//����
			processResult[process_working - 1] = SYS_TIME + 1;	//���н���ʱ��
			restProNum--;	//�����н�����--
		}
		else if (queue[index].getQueTime() == process[process_working - 1].getTFCQ())	//�ж����н���ʱ���Ƿ���ڱ�����ʱ��Ƭ
		{
			if (index == queueNum - 1)
			{

				LProcessNode *node1 = new LProcessNode();	//LProcessNodeֻ��ID��next
				node1->process_ID = queue[index].getQueHead()->process_ID;	//�����̵�ID��ֵ��*node1��ID
				node1->next = nullptr;
				queue[index].enqueue(node1);	//������δ���н������������뱾�Ӷ�β
				queue[index].dequeue();	//�����̳���
				process[process_working - 1].setTFCQ(0);	//�ڱ����е�����ʱ���0
			}
			else	//���������
			{
				LProcessNode *node1 = new LProcessNode();
				node1->process_ID = queue[index].getQueHead()->process_ID;
				node1->next = nullptr;
				queue[index + 1].enqueue(node1);	//������Ϊ���н�����������һ����
				queue[index].dequeue();	//�����̳���
				//process[process_working - 1].setPriority(queue[index + 1].getQuePriority());
				process[process_working - 1].setTFCQ(0);	//�ڶ�������ʱ���0
			}
		}
		SYS_TIME++;	//ϵͳʱ��++
	}
}
void Lmenu::LSetBarrageProcess()
{
	list.InitList_L(L);
	cout << endl << "********************************************************************"<<endl;
	cout << "������Ҫ�������̵ĸ���:"<<endl;
	int processBarrageNum;
	cin >> processBarrageNum;
	for (int i = 0; i < processBarrageNum; i++)
	{

		cout << "��Ҫ�����Ľ���:" ;
		cin >> L->data.process_ID;
		cout << "�����ж���ʱ�������:" ;
		cin >> L->data.beginbarrage_time;
		cout << "�����೤ʱ��:";
		cin >> L->data.barrage_time;
		list.ListInsert_L(L, i+1, L->data);

	}


}