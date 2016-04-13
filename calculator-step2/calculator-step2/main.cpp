#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include"scan.h"
#include"print.h"
#include "Calculation.h"

using namespace std;

int numlength_check(string str)                          //判断输入的数字是否超出范围
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



int parentheses_check(string str)                  //判断括号是否匹配
{
	stack<string>s;
	int i, length;
	length = str.size();

	for (i = 0; i < length; i++)
	{
		if (str[i] == '(')
			s.push("(");

		if (str[i] == ')')
		{
			if (!s.empty() && s.top() == "(")
				s.pop();

			else
			{
				return 0;
				break;
			}
		}
	}

	if (s.empty())
		return 1;
	else
		return 0;
}


int main(int argc, char* argv[])           //添加“int argc, char* argv[]”
{                                          //用于使用命令行进行运行
	queue<string>q;
	string string, string1;
	int k = 0;
	double output;
	
	if (argc == 3)                        
	{
		k = 1;                            //标记是否有参数-a
		string = argv[2];                //由命令行传入string的值
	}
	
	if (argc == 2)
		string=argv[1];

	if (numlength_check(string) == 0)                            //报错
		cout << "ERROR:digital length is too long!" << endl;

	if (parentheses_check(string) == 0)
		cout << "ERROR:parentheses are not matched!" << endl;

	if (numlength_check(string) == 1
		&& parentheses_check(string) == 1)
	{
		scan scan;
		print print;
		Calculation calculate;

		q = scan.tostringqueue(string);
		output = calculate.calculate(q);

		if(k==1)                             //有参数“-a”，输出原表达式
			print.printstring(q);
		
		cout << output << endl;             //输出结果
	}

	return 0;
}