/*************************************************************
 Author:         jiuweilinghu           Date:  May 4th.
 Description:    ask for radius of a circle and print its area
 Function List:
	 double calculate (double r):
		 to calculate the area of the circle

**************************************************************/
#include"calculate.h"
#include<iostream>
using namespace std;

int main()
{
	double radius;
	double square;

	cout << "Please enter radius of the circle:" << endl;
	cout << "radius=";
	cin >> radius;

	square = calculate(radius);

	cout << "area=" << square << endl;

	return 0;
}