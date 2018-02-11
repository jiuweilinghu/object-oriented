#include "Decision.h"
#include"stdlib.h"
#include<iostream>
using namespace std;

int state[5][4];
int time = 0;
int direction = 0;  // 当前电梯方向
int upNum = 0, dwNum = 0;
int upCost = 0, dwCost = 0;

int clock = 0;         // 模拟时钟

// 交换函数，排序时用到
void exchange(int array[][3], int a, int b)
{
	int temp;
	for (int i = 0; i < 3; i++)
	{
		temp = array[a][i];
		array[a][i] = array[b][i];
		array[b][i] = temp;
	}
}

// 按请求时刻从小到大进行排序
void sort(int array[][3])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (array[i][0] > array[j][0])
			{
				exchange(array,i, j);
			}
		}
	}
}

// 判断所有人是否都已经到达
bool isfinished()
{
	int i = 0;

	for ( i = 0; i < 5; i++)
	{
		if (state[i][3]!=-1)
			return false;
	}

	if (i == 5)
		return true;
}

void update()
{
	// 设置等待状态：
	// 0为该楼层没有请求
	// 1为该楼层有向上的请求
	// -1为该楼层有向下的请求
	// 2代表该楼层向上的乘客已经进入电梯
	// -2代表该楼层向下的乘客已经进入电梯
	for (int i = 0; i < 5; i++)
	{
		if (clock == state[i][0] && state[i][3] == 0)
		{
			state[i][3] = 1;
		}
	}
}

// 判断该楼层是否要停止
void isStop(int floor)
{
	bool stop = false;
	int i = 0;
	int temp;

	temp = clock;

	for ( i = 0; i < 5; i++)
	{
		if (state[i][3] == 1 && floor == state[i][1]  )
		{
			state[i][3] = 0;
			stop = true;
			if (state[i][2] == 0)
			{
				upNum++;
				if (floor != 10)
				{
					clock++;
					update();
				}
			}
			else
			{
				dwNum++;
				if (floor != 1)
				{
					clock++;
					update();
				}
			}
		}
	}
	
	if (floor == 10&&upNum>0)
	{
		upNum = 0;
		stop = true;
		for (int i = 0; i<5; i++)
		{
			if (state[i][3] == 0 && state[i][0]<clock&&state[i][2] == 0)
			{
				time += clock - state[i][0];
				state[i][3] = -1;
			}
		}
		clock++;
		update();
	}

	else if (floor == 1 && dwNum>0)
	{
		dwNum = 0;
		stop = true;
		for (int i = 0; i<5; i++)
		{
			if (state[i][3] == 0 && state[i][0]<clock&&state[i][2]==1)
			{
				time += clock - state[i][0];
				state[i][3] = -1;
			}
		}
		clock++;
		update();
	}

	if (stop)
	{
		cout << temp << "时，电梯停靠在" << floor << "层" << endl;
	}
}


// 判断该时刻是否有请求
bool iswaiting()
{
	int i = 10;
	for (i = 0; i < 5; i++)
	{
		if (state[i][3] == 1)
			return true;
	}
	if (i == 5)
		return false;
}

bool callCheck(int floor,int flag)
{
	int i = 0;
	if (flag == 1)
	{
		for (i = 0; i < 5; i++)
		{
			if (state[i][3] == 1 && state[i][1]<floor)
				return false;
		}
	}
	else
	{
		for (i = 0; i < 5; i++)
		{
			if (state[i][3] == 1 && state[i][1]>floor)
				return false;
		}
	}
		return true;
}
void Decision::toDeside(int request[][3])
{
	int floor = 1;        // 当前电梯所在层数
	// 按请求时刻从小到大进行排序
	sort(request);

	for (int i = 0; i < 5; i++)
	{
		state[i][3] = 0;
		for (int j = 0; j < 3; j++)
			state[i][j] = request[i][j];
	}

	while (!isfinished())
	{
		if (iswaiting()||upNum+dwNum>0)
		{
			isStop(floor);
			
			if ((dwNum==0&&callCheck(floor,1))||(floor==1&&upNum>0))
			{
				floor++;
				clock++;
				update();
			}
			else if ((upNum == 0 && callCheck(floor, 0))||(floor==10&&dwNum>0))
			{
				floor--;
				clock++;
				update();
			}
			else
			{
				upCost = (dwNum + upNum)*(10 - floor) + 9 * dwNum;
				dwCost = (dwNum + upNum)*(floor - 1) + 9 * upNum;

				for (int i = 0; i < 5; i++)
				{
					if (state[i][3] == 1)
					{
						switch (state[i][2])
						{
						case 0:
							if (state[i][1] > floor)
							{
								upCost += 10 - floor;
								dwCost += floor + 8;
							}
							else if (state[i][1] < floor)
							{
								upCost += 30 - 2 * i - floor;
								dwCost += floor + 8;
							}
							break;
						case 1:
							if (state[i][1] > floor)
							{
								upCost += 19 - floor;
								dwCost += 2 * i - 3 + floor;
							}
							else if (state[i][1] < floor)
							{
								upCost += 19 - floor;
								dwCost += floor - 1;
							}
							break;
						default:
							break;
						}
					}
				}
				if (upCost <= dwCost)
				{
					floor++;
					clock++;
					update();
				}
				else if (upCost > dwCost)
				{
					floor--;
					clock++;
					update();
				}
			}
		}
		else
		{
			clock++;
			update();
		}
	}
	cout << "总等待时间为："<<time << endl;
}



