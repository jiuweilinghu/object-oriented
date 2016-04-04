#include<iostream>
#include<string>
#include<queue>
#include"scan.h"
#include"print.h"

using namespace std;

int numlen(string str)
{
	int i, num = 0, real = 0;

	for (i = 0; i < str.size(); i++)
	{
		if (str[i] > 47 && str[i] < 58
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
			num = 0;
	}

	return 1;
}



int main()
{
	queue<string>q;
	string string;

	cin >> string;

	if (numlen(string) == 0)
		cout << "ERROR" << endl;

	else
	{
		scan scan;
		print print;
		q = scan.tostringqueue(string);
		print.printstring(q);
	}

	return 0;
}