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
//构造函数
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
//构造函数
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

//  获得进程号
int LProcess::getId()
{
	return process_ID;
}
// 设置进程ID（进程号）
void LProcess::setId(int id)
{
	process_ID = id;
}
// 设置进程描述
void LProcess::setProName(string name)
{
	process_Name.assign(name);
}

// 读取进程描述
string LProcess::getProName()
{
	return process_Name;
}
//设置进程开始时间
void LProcess::setBeginTime(int time)
{
	begin_time = time;
}
//读取进程开始时间
int LProcess::getBeginTime()
{
	return begin_time;
}
// 设置进程执行时间
void LProcess::setExeuTime(int time)
{
	exeu_time = time;
}
// 获得进程执行时间
int LProcess::getExeuTime()
{
	return exeu_time;
}

// 设置进程优先级
void LProcess::setPriority(int pri)
{
	priority = pri;
}
// 获得进程优先级
int LProcess::getPriority()
{
	return priority;
}

// 设置进程已完成的时间片
void LProcess::setCompleTime(int time)
{
	completed_time += time;
}
// 获得进程已完成的时间片
int LProcess::getCompleTime()
{
	return completed_time;
}

//已获得当前队列的时间片
int LProcess::getTFCQ()
{
	return TimeForCurrentQueue;
}
// 设置已经获得当前队列的时间片
void LProcess::setTFCQ(int time)
{
	TimeForCurrentQueue += time;
}
