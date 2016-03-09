#include "print.h"
#include<iostream>
#include<string>
#include<queue>
using namespace std;
void print:: outprint()
{
	n=q.size();
	for (k = 0; k<n; k++)
	{
		cout << q.front() << endl;
		q.pop();
	}
}