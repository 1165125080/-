#include <time.h>
#include"LProQueue.h"
#include "Lmenu.h"
#include "LProList.h"
int main()
{
	int processNum, queueNum;
	cout << "������Ҫ������ҵ�Ľ�����" << endl;
	cin >> processNum;
	cout << "������༶���еĶ�����" << endl;
	cin >> queueNum;
	//���ɱ�����̿�ʼʱ�̽������
	int* processBegin = new int[processNum];
	//���ɱ���������ʱ�̽��������
	int* processResult = new int[processNum];
	// ���ɼ�¼���̵�������ɵĽ���ʱ��Ƭ���Ա��ڼ���
	int *process_time = new int[processNum];
	//�����û�ָ��n�����̣�����Ϊ�������̺�
	LProcess *process = new LProcess[processNum];
	//�����û�ָ����n�����У���Ϊ�����ʱ��Ƭ�����ȼ�
	LProQueue *queue = new LProQueue[processNum];
	Lmenu menu(processNum, queueNum, processBegin, processResult, process_time, process, queue);

	menu.LInputEnTime();	//��������̽���ʱ��
	menu.LCreatProcessExeuTime();	//������ɸ�������Ҫ���е�ʱ��
	menu.LSetBarrageProcess();	//������������
	menu.LCreatQueueTime();	//�����һ�����е�ʱ��Ƭ����������ʱ��Ƭ���б�������
	menu.LExecute();
	for (int i = 0; i < processNum; i++)
	{
		cout << "����" << i + 1 << "        ����Ҫ��ʱ��" << process_time[i] << "                   ���̵���ʱ��" << processBegin[i] << "            ���ʱ��" << processResult[i] << endl;
	}
	system("pause");
	return 0;
}