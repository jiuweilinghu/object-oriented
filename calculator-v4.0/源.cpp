/****************************************************
File Name:	main.cpp
Author:		jiuweilinghu
version:	3.0		Date:	May 7th.

Description:
This is a calculator.
Only for operators ,
including "+" "-" "*" "/" "(" ")".
Use cmd to run it.

Function List:
int numlength_check(string str);
int parentheses_check(string str);
****************************************************/

#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<fstream>
#include"scan.h"
#include"print.h"
#include "Calculation.h"

using namespace std;

/***************************************************
Description:
Check whether the length of
numbers in the equation is too long.

Input:	A string type equation.

Return: 0 or 1.
***************************************************/

int numlength_check(string str)
{
	int i, num = 0, real = 0;

	for (i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9'
			|| str[i] == '.')

		{
			num++;

			if (str[i] == '.')
				real = 1;

			if (num > 10 && real == 0)
			{
				return 0;
				break;
			}

			else if (num > 11 && real == 1)
			{
				return 0;
				break;
			}
		}
		else
			return 1;
	}
}

/***********************************************
Description:
Check whether the parentheses are matched.

Input:	A string type equation.

Return:	0 or 1.
*************************************************/

int parentheses_check(string str)
{
	stack<string>sta;
	int i, length;

	length = str.size();

	for (i = 0; i < length; i++)
	{

		if (str[i] == '(')
			sta.push("(");

		if (str[i] == ')')
		{
			if (!sta.empty() && sta.top() == "(")
				sta.pop();

			else
			{
				return 0;
				break;
			}
		}
	}

	if (sta.empty())
		return 1;
	else
		return 0;
}


int main(int argc, char* argv[])           //��ӡ�int argc, char* argv[]��
{											//����ʹ�������н�������
	scan scan;
	print print;
	Calculation calculate;

	queue<string>que;

	string string;
	int k = 0;
	double output;

	if (argc == 3)
	{
		k = 1;                            //����Ƿ��в���-a
		string = argv[2];                //�������д���string��ֵ
	}

	if (argc == 2)
		string = argv[1];

	if (numlength_check(string) == 0)                            //����
		cout << "ERROR:digital length is too long!" << endl;

	if (parentheses_check(string) == 0)
		cout << "ERROR:parentheses are not matched!" << endl;

	if (numlength_check(string) == 1
		&& parentheses_check(string) == 1)
	{
		while (!que.empty())
			que.pop();

		que = scan.tostringqueue(string);
		output = calculate.calculate(que);

		if (k == 1)                           //�в�����-a�������ԭ���ʽ
			print.printstring(que);

		print.printresult(output);             //������
	}

	if (argc == 4)
	{
		ifstream infile(argv[2]);

		while (!infile.eof())
		{
			string.clear();
			getline(infile, string);

			if (numlength_check(string) == 0)                            //����
				cout << "ERROR:digital length is too long!" << endl;

			if (parentheses_check(string) == 0)
				cout << "ERROR:parentheses are not matched!" << endl;

			if (numlength_check(string) == 1
				&& parentheses_check(string) == 1)
			{
				while (!que.empty())
					que.pop();

				que = scan.tostringqueue(string);
				output = calculate.calculate(que);

				print.printres(argv[3], output);
			}
		}
	}

	return 0;
}