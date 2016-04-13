#include "Calculation.h"

double calculate1(double a, string c, double b)        //用于计算的函数
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

int priority(string c)                              //判断优先级
{                                                   //此处只对针加、减、乘、除
	if (c == "+" || c == "-")                       //四种运算，括号下面另外处理
		return 0;
	if (c == "*" || c == "/")
		return 1;
}


int length_check(double number)                    //检查计算过程中数字是不是超出范围
{
	int n;
	string string;
	stringstream stream;

	stream.clear();                               //
	stream << number;                             //数字转字符串
	stream >> string;                             //
	n = string.size();

	if (n > 10)
		return 0;
	else
		return 1;

}


double Calculation::calculate(queue<string>que)      //具体实现函数
{
	while (!que.empty())                             //队列不为空则进入
	{
		if (que.front() == "(")                      //对括号内的部分进行处理（开始）
		{                                            //遇到左括号，压入
			s_str.push("(");
			que.pop();
		}

		else if (que.front() == ")")                //遇到右括号
		{
			que.pop();

			while (s_str.top() != "(")            //把字符栈里的符号弹出，压入一个队列
			{
				q_temp.push(s_str.top());
				s_str.pop();
			}

			s_str.pop();

			while (!q_temp.empty())                               //进行计算
			{
				f = s_num.top();
				s_num.pop();
				e = s_num.top();
				s_num.pop();
				g = q_temp.front();
				q_temp.pop();

				if (g == "/"&&f == 0)                              //除数是否为零的判断
				{
					cout << "ERROR:divisor can't be zero!" << endl;
					break;
				}

				t = calculate1(e, g, f);                          //进行计算

				if (length_check(t) == 0)                         //数字长度的判断
				{
					cout << "ERROR:digital length is beyong clculation!";
					break;
				}

				s_num.push(t);                                 //把结果压入数字栈
			}
		}                                                   //（结束）          

		else if (que.front() == "+" || que.front() == "-"   //对括号外部分的计算
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

