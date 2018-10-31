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
	int	SYS_TIME;				//��¼CPU�������ʱ��
	bool isWork;
	int	processNum;
	int	queueNum;
	int	queue_first_time;
	int restProNum;
	//���ɱ�����̿�ʼʱ�̽��������
	int *processBegin;
	//���ɱ���������ʱ�̽��������
	int *processResult;
	// ���ɼ�¼���̵�������ɵĽ���ʱ��Ƭ���Ա��ڼ���
	int *process_time;
	//�����û�ָ��n�����̣�����Ϊ�������̺�
	LProcess *process;
	//�����û�ָ����n�����У���Ϊ�����ʱ��Ƭ�����ȼ�
	LProQueue *queue;
	//��ѡ������ʹ�������Ľ��̽���ʱ������
	LNode *L;	//����洢
	LList list;		//������
	void Selectsort(int a[], int n);
public:
	Lmenu();
	Lmenu(int processNum, int queueNum, int*processBegin, int*processResult, int*process_time, LProcess*process, LProQueue*queue);
	int LInputQueueNum();
	//��������̽���ʱ��
	void LInputEnTime();
	//������ɸ�������Ҫ���е�ʱ��
	void LCreatProcessExeuTime();
	//�����һ�����е�ʱ��Ƭ�����������е�ʱ��Ƭ
	void LCreatQueueTime();
	void LExecute();
	void LSetBarrageProcess();

};

#endif