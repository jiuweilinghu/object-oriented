#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<queue>

using namespace std;

class print
{
public:
	void printstring(queue<string>queue);    //���ԭ���ʽ

	void printresult(double res);            //������

	void printres(string address, double res); //���ļ�������

private:
	int j, l;
};

