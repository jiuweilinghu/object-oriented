#pragma once
#include<iostream>
#include<string>
#include<queue>
#include<stack>

using namespace std;

class Scan
{
public:
	queue<string>tostringqueue(string input);  //ɨ����ʽ���������

	queue<string>queue;

private:
	int i;
	string temp;
};

