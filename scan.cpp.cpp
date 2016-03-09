#include<iostream>
#include"scan.h"
#include"print.h"
#include<string>
#include<queue>
using namespace std;
void scan:: tostringqueue()
{
	cin >> string1;
	l = string1.length();
	for (i = 0; i<l; i++)
	{
		if (string1[i]<48 || string1[i]>57 && string1[i] != '.')
		{
			string3 = string1[i];
			q.push(string3);
		}
		else
		{
			for (j = i;; j++)
			{
				string2 = string1[j] + string2;
				a = a + 1;
				if (a>10)
				{
					printf("ERROR");
				}
				if (string1[i]<48 || string1[i]>57 && string1[i] != '.')
				{
					i = j;
					q.push(string2);
					string2 = '\0';
					break;
				}
			}
		}
	}
}