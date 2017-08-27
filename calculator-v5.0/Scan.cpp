#include "stdafx.h"
#include "Scan.h"


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


queue<string> Scan::tostringqueue(string input)
{
	while (!queue.empty())
		queue.pop();

	if (numlength_check(input) == 0)                            //报错
	{
		queue.push("ERROR");
		return queue;
	}

	if (parentheses_check(input) == 0)
	{
		queue.push("ERROR");
		return queue;
	}
	

	for (i = 0; i < input.size(); i++)
	{

		if ((input[i] >= '0' && input[i] <= '9')             //对数字和“-”的处理
			|| input[i] == '.' || input[i] == '-')
		{
			if (input[i] == '-')
			{
				if ((i - 1 >= 0 && (input[i - 1] == '('
					|| input[i - 1] == '+' || input[i - 1] == '-'
					|| input[i - 1] == '*' || input[i - 1] == '/'))     //负号的判断
					|| (i == 0))

					temp = "-";

				else
				{
					if (!temp.empty())
					{
						queue.push(temp);
						temp.clear();
					}
					queue.push("-");
				}
			}

			else
				temp += input[i];
		}

		else
		{
			if (!temp.empty())
				queue.push(temp);

			temp.clear();
			temp = input[i];

			if (!temp.empty())
				queue.push(temp);

			temp.clear();
		}
	}

	if (!temp.empty())
		queue.push(temp);

	temp.clear();

	return queue;
}
