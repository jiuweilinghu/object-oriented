#pragma once
#include<iostream>
#include<string>
#include<queue>

using namespace std;

class scan
{
public:
	queue<string>tostringqueue(string input);  //ɨ����ʽ���������
	bool judge()
	{
		return flag;
	}
	queue<string>queue;

private:
	int i;
	bool flag;
	string temp;
};


