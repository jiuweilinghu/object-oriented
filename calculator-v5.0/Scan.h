#pragma once
#include<iostream>
#include<string>
#include<queue>
#include<stack>

using namespace std;

class Scan
{
public:
	queue<string>tostringqueue(string input);  //扫描表达式并存入队列

	queue<string>queue;

private:
	int i;
	string temp;
};

