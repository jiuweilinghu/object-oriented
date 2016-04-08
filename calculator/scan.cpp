#include "scan.h"

queue<string> scan::tostringqueue(string input)
{
	for (i = 0; i < input.size(); i++)
	{
		if (input[i] > 47 && input[i] < 58
			|| input[i] == '.')

			temp += input[i];

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

	return queue;
}
