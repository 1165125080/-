#pragma once
// LProcess.h
#include <string.h>
#include <iostream>
using namespace std;


//进程类
class LProcess
{
private:
	int process_ID;            //进程号
	string process_Name;       //进程描述
	int begin_time;				//进程开始时间
	int	exeu_time;             //进程要求的执行时间
	int priority;              //进程优先级
	int completed_time;        //进程已经获得的时间片
	int TimeForCurrentQueue;   //已获得当前队列的时间片
public:
	//构造函数
	LProcess();
	LProcess(int id);
	LProcess(int id, int time, string name);
	// 获得进程ID（进程号）
	int getId();
	// 设置进程ID（进程号）
	void setId(int id);
	// 设置进程描述
	void setProName(string name);
	// 读取进程描述
	string getProName();
	//设置进程开始时间
	void setBeginTime(int time);
	//读取进程开始时间
	int getBeginTime();
	// 设置进程执行时间
	void setExeuTime(int time);
	// 获得进程执行时间
	int getExeuTime();
	// 设置进程优先级
	void setPriority(int pri);
	// 获得进程优先级
	int getPriority();
	// 设置进程已完成的时间片
	void setCompleTime(int time);
	// 设置进程已完成的时间片
	int getCompleTime();
	//已获得当前队列的时间片
	int getTFCQ();
	// 设置已经获得当前队列的时间片
	void setTFCQ(int time);
};
