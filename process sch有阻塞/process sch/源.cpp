#include <time.h>
#include"LProQueue.h"
#include "Lmenu.h"
#include "LProList.h"
int main()
{
	int processNum, queueNum;
	cout << "请输入要进行作业的进程数" << endl;
	cin >> processNum;
	cout << "请输入多级队列的队列数" << endl;
	cin >> queueNum;
	//生成保存进程开始时刻结果的数
	int* processBegin = new int[processNum];
	//生成保存进程完成时刻结果的数组
	int* processResult = new int[processNum];
	// 生成记录进程的随机生成的进程时间片，以便于检验
	int *process_time = new int[processNum];
	//生成用户指定n个进程，并将为其分配进程号
	LProcess *process = new LProcess[processNum];
	//生成用户指定的n个队列，并为其分配时间片和优先级
	LProQueue *queue = new LProQueue[processNum];
	Lmenu menu(processNum, queueNum, processBegin, processResult, process_time, process, queue);

	menu.LInputEnTime();	//输入各进程进入时间
	menu.LCreatProcessExeuTime();	//随机生成各进程需要运行的时间
	menu.LSetBarrageProcess();	//输入阻塞进程
	menu.LCreatQueueTime();	//输入第一个队列的时间片并对随后队列时间片进行倍增生成
	menu.LExecute();
	for (int i = 0; i < processNum; i++)
	{
		cout << "进程" << i + 1 << "        进程要求时间" << process_time[i] << "                   进程到达时刻" << processBegin[i] << "            完成时刻" << processResult[i] << endl;
	}
	system("pause");
	return 0;
}