#include "Calculation.h"

double calculate1(double a, string c, double b)        //���ڼ���ĺ���
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

int priority(string c)                              //�ж����ȼ�
{                                                   //�˴�ֻ����ӡ������ˡ���
	if (c == "+" || c == "-")                       //�������㣬�����������⴦��
		return 0;
	if (c == "*" || c == "/")
		return 1;
}


int length_check(double number)                    //����������������ǲ��ǳ�����Χ
{
	int n;
	string string;
	stringstream stream;

	stream.clear();                               //
	stream << number;                             //����ת�ַ���
	stream >> string;                             //
	n = string.size();

	if (n > 10)
		return 0;
	else
		return 1;

}


double Calculation::calculate(queue<string>que)      //����ʵ�ֺ���
{
	while (!que.empty())                             //���в�Ϊ�������
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
				f = s_num.top();
				s_num.pop();
				e = s_num.top();
				s_num.pop();
				g = q_temp.front();
				q_temp.pop();

				if (g == "/"&&f == 0)                              //�����Ƿ�Ϊ����ж�
				{
					cout << "ERROR:divisor can't be zero!" << endl;
					break;
				}

				t = calculate1(e, g, f);                          //���м���

				if (length_check(t) == 0)                         //���ֳ��ȵ��ж�
				{
					cout << "ERROR:digital length is beyong clculation!";
					break;
				}

				s_num.push(t);                                 //�ѽ��ѹ������ջ
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
					g = s_str.top();
					s_str.pop();
					f = s_num.top();
					s_num.pop();
					e = s_num.top();
					s_num.pop();

					if (g == "/"&&f == 0)
					{
						cout << "ERROR:divisor can't be zero!" << endl;
						break;
					}

					t = calculate1(e, g, f);

					if (length_check(t) == 0)
					{
						cout << "ERROR:digital length is beyong clculation!";
						break;
					}

					s_num.push(t);
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
		f = s_num.top();
		s_num.pop();
		e = s_num.top();
		s_num.pop();
		g = s_str.top();
		s_str.pop();

		if (g == "/"&&f == 0)
		{
			cout << "ERROR:divisor can't be zero!" << endl;
			break;
		}

		t = calculate1(e, g, f);

		if (length_check(t) == 0)
		{
			cout << "ERROR:digital length is beyong clculation!";
			break;
		}

		s_num.push(t);
	}

	final_result = s_num.top();

	return final_result;
}

