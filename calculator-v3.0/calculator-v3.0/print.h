#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<queue>

using namespace std;

class print
{
public:
	void printstring(queue<string>queue);    //输出原表达式

	void printresult(double res);            //输出结果

	void printres(string address, double res); //用文件输出结果

private:
	int j, l;
};

