#include "stdafx.h"
#include "Calculation.h"


/**************************************************
Description��	To calculate.

Input:	A double type number,
a string type oprator,
another double type number.

Return: The result.
**************************************************/

double calculate1(double a, string c, double b)
{
	if (c == "+")
		return (a + b);

	if (c == "-")
		return (a - b);

	if (c == "*")
		return (a*b);

	if (c == "/")
		return (a / b);
}

/**********************************************
Description:
To decide the priority of operators,
including '+' '-' '*' '/'.

Input: A string type operator.

Return:	0 or 1.
***********************************************/

int priority(string c)                              //�ж����ȼ�
{                                                   //�˴�ֻ����ӡ������ˡ���
	if (c == "+" || c == "-")                       //�������㣬�����������⴦��
		return 0;

	if (c == "*" || c == "/")
		return 1;
}

/*************************************
Description:
Check whether the length of
numbers is too long.

Input:	A double type number.

Return: 0 or 1.
*************************************/

string Calculation::calculate(queue<string>que)      //����ʵ�ֺ���
{
	if (que.front() == "ERROR")
	{
		final_result = "ERROR";
		return final_result;
	}
	while (que.front() != "=")                             //���в�Ϊ�������
	{
		if (que.front() == "(")                      //�������ڵĲ��ֽ��д�����ʼ��
		{                                            //���������ţ�ѹ��
			s_str.push("(");
			que.pop();
		}

		else if (que.front() == ")")                //����������
		{
			que.pop();

			while (s_str.top() != "(")            //���ַ�ջ��ķ��ŵ�����ѹ��һ������
			{
				q_temp.push(s_str.top());
				s_str.pop();
			}

			s_str.pop();

			while (!q_temp.empty())                               //���м���
			{
				num2 = s_num.top();
				s_num.pop();
				num1 = s_num.top();
				s_num.pop();
				oper = q_temp.front();
				q_temp.pop();

				if (oper == "/"&&num2 == 0)                              //�����Ƿ�Ϊ����ж�
				{
					final_result = "ERROR";
					return final_result;
				}

				temp = calculate1(num1, oper, num2);                          //���м���

				s_num.push(temp);                                 //�ѽ��ѹ������ջ
			}
		}                                                   //��������          

		else if (que.front() == "+" || que.front() == "-"   //�������ⲿ�ֵļ���
			|| que.front() == "*" || que.front() == "/")
		{
			if (s_str.empty() || s_str.top() == "(")
			{
				s_str.push(que.front());
				que.pop();
			}

			else
			{
				if (priority(que.front()) > priority(s_str.top()))
				{
					s_str.push(que.front());
					que.pop();
				}

				else
				{
					oper = s_str.top();
					s_str.pop();
					num2 = s_num.top();
					s_num.pop();
					num1 = s_num.top();
					s_num.pop();

					if (oper == "/"&&num2 == 0)
					{
						final_result = "ERROR";
						return final_result;
					}

					temp = calculate1(num1, oper, num2);

					s_num.push(temp);
				}
			}
		}

		else
		{
			stream.clear();
			stream << que.front();
			stream >> change;
			s_num.push(change);
			que.pop();
		}
	}

	while (!s_str.empty())
	{
		num2 = s_num.top();
		s_num.pop();
		num1 = s_num.top();
		s_num.pop();
		oper = s_str.top();
		s_str.pop();

		if (oper == "/"&&num2 == 0)
		{
			final_result = "ERROR";
			return final_result;
		}

		temp = calculate1(num1, oper, num2);

		s_num.push(temp);
	}

	stream.clear();
	stream << s_num.top();
	stream >> final_result;
	s_num.pop();
	que.pop();

	return final_result;
}
