#include "print.h"
#include"stdafx.h"

void print::printstring(queue<string>queue)
{

	l = queue.size();

	for (j = 0; j < l; j++)
	{
		cout << queue.front();
		queue.pop();
	}

	cout << " ";
}


void print::printresult(double res)
{
	cout << res << endl;
}


void print::printres(string address, double res)
{
	ofstream outfile(address, ios::app);
	outfile << res << endl;
}