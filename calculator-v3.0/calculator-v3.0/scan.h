#pragma once
#include<iostream>
#include<string>
#include<queue>

using namespace std;

class scan
{
public:
	queue<string>tostringqueue(string input);  //ɨ����ʽ���������
	
	queue<string>queue;

private:
	int i;
	string temp;
};


