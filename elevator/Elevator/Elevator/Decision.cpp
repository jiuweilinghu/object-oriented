#include "Decision.h"
#include"stdlib.h"
#include<iostream>
using namespace std;


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
bool isfinished(int arrived[5])
{
	int i = 0;

	for ( i = 0; i < 5; i++)
	{
		if (arrived[i] == 0)
			return false;
	}

	if (i == 5)
		return true;
}

// 判断该楼层是否有人进
bool isin(int request[][3],int floor)
{
	int i = 0;
	for ( i = 0; i < 5; i++)
	{
		if (floor == request[i][1])
			return true;
	}
	if (i == 5)
		return false;
}

// 判断该楼层是否有人进
bool isout(int request[][3], int floor)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		if ((request[i][2]==0 && floor == 10)
			||(request[i][2]==1 && floor == 1))
			return true;
	}
	if (i == 5)
		return false;
}

// 判断该时刻是否有请求
bool iswaiting(int waiting[11])
{
	int i = 1;
	for (i = 1; i < 11; i++)
	{
		if (waiting[i] == 1|| waiting[i] == -1)
			return true;
	}
	if (i == 11)
		return false;
}

int num = 0;
void update(int request[][3],int waiting[11],int clock)
{
	// 设置等待状态：
	// 0为该楼层没有请求
	// 1为该楼层有向上的请求
	// -1为该楼层有向下的请求
	// 2代表该楼层向上的乘客已经进入电梯
	// -2代表该楼层向下的乘客已经进入电梯
	if (clock == request[num][0])
	{
		if (request[num][2] == 1 && waiting[request[num][1]] == 0)
			waiting[request[num][1]] = -1;
		else if (request[num][2] == 0 && waiting[request[num][1]] == 0)
			waiting[request[num][1]] = 1;
		num++;
	}
}
//请求时刻 起始楼层数 去往方向
void Decision::toDeside(int request[][3])
{
	int time = 0;
	int clock=0;         // 模拟时钟
	int waiting[11] = { 0 };
	int direction = 0;  // 当前电梯方向
	int floor=1;        // 当前电梯所在层数
	int arrived[5] = { 0 };
	int upNum = 0, dwNum = 0;
	int upCost = 0, dwCost = 0;
	
	// 按请求时刻从小到大进行排序
	sort(request);

	while (!isfinished(arrived))
	{
		if (iswaiting(waiting))
		{
			upCost = (dwNum + upNum)*(10 - floor) + 9 * dwNum;
			dwCost= (dwNum + upNum)*(floor-1) + 9 * upNum;
			for (int i = 1; i < 11; i++)
			{
				switch (waiting[i])
				{
				case 1:
					if (i > floor)
					{
						upCost += 10 - floor;
						dwCost += floor + 8;
					}
					else if (i < floor)
					{
						upCost += 30-2*i-floor;
						dwCost += floor + 8;
					}
					break;
				case -1:
					if (i > floor)
					{
						upCost += 19 - floor;
						dwCost += 2*i-3+floor;
					}
					else if (i < floor)
					{
						upCost += 19 - floor;
						dwCost += floor -1;
					}
					break;
				case 0:
					break;
				}
			}
			
			if (upCost <= dwCost||dwCost==0)
			{
				floor++;
				clock++;
				update(request, waiting, clock);
				if (waiting[floor] != 0)
				{
					if (waiting[floor] == 1)
					{
						upNum++;
						cout << clock << "时，电梯停靠在" << floor << "层" << endl;
						waiting[floor] = 2;
						if (floor != 10)
						{
							clock++;
							update(request, waiting, clock);
						}
					}
					else if (waiting[floor] == -1)
					{
						dwNum++;
						cout << clock << "时，电梯停靠在" << floor << "层" << endl;
						waiting[floor] = -2;
						if (floor != 1)
						{
							clock++;
							update(request, waiting, clock);
						}
					}
				}
				if (floor == 10)
				{
					upNum = 0;
					for (int j = 1; j < 11; j++)
					{
						if (waiting[j] == 2)
						{
							for (int k = 0; k < 5; k++)
							{
								if (request[k][1] == j)
								{
									time += clock - request[k][0];
									arrived[k] = 1;
								}
							}
						}
					}
					cout <<clock<< "时，电梯停靠在" <<floor<< "层" << endl;
					clock++;
					update(request, waiting, clock);
				}
			}
			else if(upCost > dwCost || upCost == 0)
			{
				floor--;
				clock++;
				update(request, waiting, clock);
				if (waiting[floor] != 0)
				{
					if (waiting[floor] == 1)
					{
						upNum++;
						cout << clock << "时，电梯停靠在" << floor << "层" << endl;
						waiting[floor] = 2;
						if (floor != 10)
						{
							clock++;
							update(request, waiting, clock);
						}
					}
					else if (waiting[floor] == -1)
					{
						dwNum++;
						cout << clock << "时，电梯停靠在" << floor << "层" << endl;
						waiting[floor] = -2;
						if (floor != 1)
						{
							clock++;
							update(request, waiting, clock);
						}
					}
				}
				if (floor == 1)
				{
					dwNum = 0;
					for (int j = 1; j < 11; j++)
					{
						if (waiting[j] == -2)
						{
							for (int k = 0; k < 5; k++)
							{
								if (request[k][1] == j)
								{
									time += clock - request[k][0];
									arrived[k] = 1;
								}
							}
						}
					}
					cout << clock << "时，电梯停靠在" << floor << "层" << endl;
					clock++;
					update(request, waiting, clock);
				}
			}
		}
		else
		{
			clock++;
			update(request, waiting, clock);
		}
	}
	cout << time << endl;
}



