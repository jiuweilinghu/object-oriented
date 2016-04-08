#include "print.h"

void print::printstring(queue<string>queue)
{
	l = queue.size();

	for (j = 0; j < l; j++)
	{
		cout << queue.front() << endl;
		queue.pop();
	}
}

