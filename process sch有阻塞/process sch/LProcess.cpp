#include "LProcess.h"


LProcess::LProcess()
{
	process_ID = 0;
	process_Name = "Undefined";
	begin_time = 0;
	exeu_time = 1;
	priority = 0;
	completed_time = 0;
	TimeForCurrentQueue = 0;
}
//���캯��
LProcess::LProcess(int id)
{
	process_ID = id;
	process_Name = "Undefined";
	begin_time = 0;
	exeu_time = 1;
	priority = 0;
	completed_time = 0;
	TimeForCurrentQueue = 0;
}
//���캯��
LProcess::LProcess(int id, int time, string name)
{
	process_ID = id;
	process_Name.assign(name);
	begin_time = 0;
	exeu_time = time;
	priority = 0;
	completed_time = 0;
	TimeForCurrentQueue = 0;
}

//  ��ý��̺�
int LProcess::getId()
{
	return process_ID;
}
// ���ý���ID�����̺ţ�
void LProcess::setId(int id)
{
	process_ID = id;
}
// ���ý�������
void LProcess::setProName(string name)
{
	process_Name.assign(name);
}

// ��ȡ��������
string LProcess::getProName()
{
	return process_Name;
}
//���ý��̿�ʼʱ��
void LProcess::setBeginTime(int time)
{
	begin_time = time;
}
//��ȡ���̿�ʼʱ��
int LProcess::getBeginTime()
{
	return begin_time;
}
// ���ý���ִ��ʱ��
void LProcess::setExeuTime(int time)
{
	exeu_time = time;
}
// ��ý���ִ��ʱ��
int LProcess::getExeuTime()
{
	return exeu_time;
}

// ���ý������ȼ�
void LProcess::setPriority(int pri)
{
	priority = pri;
}
// ��ý������ȼ�
int LProcess::getPriority()
{
	return priority;
}

// ���ý�������ɵ�ʱ��Ƭ
void LProcess::setCompleTime(int time)
{
	completed_time += time;
}
// ��ý�������ɵ�ʱ��Ƭ
int LProcess::getCompleTime()
{
	return completed_time;
}

//�ѻ�õ�ǰ���е�ʱ��Ƭ
int LProcess::getTFCQ()
{
	return TimeForCurrentQueue;
}
// �����Ѿ���õ�ǰ���е�ʱ��Ƭ
void LProcess::setTFCQ(int time)
{
	TimeForCurrentQueue += time;
}
