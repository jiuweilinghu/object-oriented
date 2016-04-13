#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include"scan.h"
#include"print.h"
#include "Calculation.h"

using namespace std;

int numlength_check(string str)                          //�ж�����������Ƿ񳬳���Χ
{
	int i, num = 0, real = 0;

	for (i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9'
			|| str[i] == '.')

		{
			num++;

			if (str[i] == '.')
				real = 1;

			if (num > 10 && real == 0)
			{
				return 0;
				break;
			}

			else if (num > 11 && real == 1)
			{
				return 0;
				break;
			}
		}
		else
			return 1;
	}
}



int parentheses_check(string str)                  //�ж������Ƿ�ƥ��
{
	stack<string>s;
	int i, length;
	length = str.size();

	for (i = 0; i < length; i++)
	{
		if (str[i] == '(')
			s.push("(");

		if (str[i] == ')')
		{
			if (!s.empty() && s.top() == "(")
				s.pop();

			else
			{
				return 0;
				break;
			}
		}
	}

	if (s.empty())
		return 1;
	else
		return 0;
}


int main(int argc, char* argv[])           //��ӡ�int argc, char* argv[]��
{                                          //����ʹ�������н�������
	queue<string>q;
	string string, string1;
	int k = 0;
	double output;
	
	if (argc == 3)                        
	{
		k = 1;                            //����Ƿ��в���-a
		string = argv[2];                //�������д���string��ֵ
	}
	
	if (argc == 2)
		string=argv[1];

	if (numlength_check(string) == 0)                            //����
		cout << "ERROR:digital length is too long!" << endl;

	if (parentheses_check(string) == 0)
		cout << "ERROR:parentheses are not matched!" << endl;

	if (numlength_check(string) == 1
		&& parentheses_check(string) == 1)
	{
		scan scan;
		print print;
		Calculation calculate;

		q = scan.tostringqueue(string);
		output = calculate.calculate(q);

		if(k==1)                             //�в�����-a�������ԭ���ʽ
			print.printstring(q);
		
		cout << output << endl;             //������
	}

	return 0;
}