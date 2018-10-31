#pragma once
// LProcess.h
#include <string.h>
#include <iostream>
using namespace std;


//������
class LProcess
{
private:
	int process_ID;            //���̺�
	string process_Name;       //��������
	int begin_time;				//���̿�ʼʱ��
	int	exeu_time;             //����Ҫ���ִ��ʱ��
	int priority;              //�������ȼ�
	int completed_time;        //�����Ѿ���õ�ʱ��Ƭ
	int TimeForCurrentQueue;   //�ѻ�õ�ǰ���е�ʱ��Ƭ
public:
	//���캯��
	LProcess();
	LProcess(int id);
	LProcess(int id, int time, string name);
	// ��ý���ID�����̺ţ�
	int getId();
	// ���ý���ID�����̺ţ�
	void setId(int id);
	// ���ý�������
	void setProName(string name);
	// ��ȡ��������
	string getProName();
	//���ý��̿�ʼʱ��
	void setBeginTime(int time);
	//��ȡ���̿�ʼʱ��
	int getBeginTime();
	// ���ý���ִ��ʱ��
	void setExeuTime(int time);
	// ��ý���ִ��ʱ��
	int getExeuTime();
	// ���ý������ȼ�
	void setPriority(int pri);
	// ��ý������ȼ�
	int getPriority();
	// ���ý�������ɵ�ʱ��Ƭ
	void setCompleTime(int time);
	// ���ý�������ɵ�ʱ��Ƭ
	int getCompleTime();
	//�ѻ�õ�ǰ���е�ʱ��Ƭ
	int getTFCQ();
	// �����Ѿ���õ�ǰ���е�ʱ��Ƭ
	void setTFCQ(int time);
};
