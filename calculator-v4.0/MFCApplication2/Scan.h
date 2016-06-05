#pragma once
#include<iostream>
#include<string>
#include<queue>

using namespace std;

class scan
{
public:
	queue<string>tostringqueue(string input);  //扫描表达式并存入队列
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


