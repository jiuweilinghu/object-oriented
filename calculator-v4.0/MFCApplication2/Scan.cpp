#include "scan.h"
#include"stdafx.h"

queue<string> scan::tostringqueue(string input)
{
	while (!queue.empty())
		queue.pop();

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


