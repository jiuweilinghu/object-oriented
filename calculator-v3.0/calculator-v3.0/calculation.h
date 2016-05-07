#pragma once
#include<iostream>
#include<string>
#include<queue>
#include<sstream>                  
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
	double change, num1, num2, temp;
	string oper;                   //�������
};


