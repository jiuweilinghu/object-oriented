#pragma once
#include<iostream>
#include<string>
#include<queue>
#include<sstream>                  //stringstream���ͷ�ļ�
#include<stack>

using namespace std;

class Calculation
{
public:
	double calculate(queue<string>que);

private:
	stringstream stream;           //���ڽ����������ַ�����ת��
	stack<double>s_num;            //���ڴ������
	stack<string>s_str;            //���ڴ�������
	queue<string>q_temp;
	double final_result;
	double change, e, f, t;
	string g;
};

