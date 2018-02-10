#include<iostream>
#include"Decision.h"
using namespace std;

int main()
{
	int request[5][3];
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> request[i][j];
		}
	}

	Decision decision;
	decision.toDeside(request);
}