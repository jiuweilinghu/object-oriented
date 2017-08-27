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
	string calculate(queue<string>que);

private:
	stringstream stream;           //用于进行数字与字符串的转换

	stack<double>s_num;            //用于存放数字
	stack<string>s_str;            //用于存放运算符
	queue<string>q_temp;

	string final_result;
	double change, num1, num2, temp;
	string oper;                   //运算符号
};



