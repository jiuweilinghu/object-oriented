#include<iostream>
#include<string>
#include<stdlib.h>
#include<iomanip>

using namespace std;

struct node
{
	int address;
	int data;
	int nextad;

	node *next;
};

int main()
{
	node *head, *newp, *temp, *tail, *p;
	int k, n, i, j, l, num,count=1;
	int a, a1, a2;

	head = (node*)malloc(sizeof(node));
	if (head == NULL)
	{
		cout << "failed" << endl;
		return NULL;
	}

	cin >> a >> n >> k;
	tail = head;

	for (i = 0; i < n; i++)
	{
		scanf_s("%d%d%d", &a1, &num, &a2);

		newp = (node*)malloc(sizeof(node));
		if (newp == NULL)
		{
			cout << "failed" << endl;
			return NULL;
		}
		
		newp->address = a1;
		newp->data = num;
		newp->nextad = a2;
		newp->next = NULL;
		tail->next = newp;
		tail = tail->next;
	}

	temp = head;
	tail = head;
	
	while (1)
	{
		p = temp->next;
		
		if (p->address == a)
		{
			temp->next = p->next;
			p->next = tail->next;
			tail->next = p;
			tail = tail->next;
			break;
		}
		
		else
			temp = temp->next;
	}

	temp = tail;
	
	while (1)
	{
		if (tail->nextad == -1)
			break;
		
		p = temp->next;
		
		if (p->address == tail->nextad)
		{
			temp->next = p->next;
			p->next = tail->next;
			tail->next = p;
			tail = tail->next;
			temp = tail;
		}
		
		else
			temp = temp->next;
	}
	
	p = head->next;
	
	while (p ->next!= NULL)
	{
		if (p->nextad == -1)
		{
			p->next = NULL;
			break;
		}
		count++;
		p = p->next;
	}

	tail = head;
	temp = tail;
	p = temp->next;
	n = count;

	for (l = 0; l < n / k; l++)
	{
		for (i = 1; i < k; i++)
		{
			for (j = 0; j < k - i; j++)
			{
				temp = temp->next;
				p = temp->next;
			}
			
			temp->next = p->next;
			p->next = tail->next;
			tail->next = p;
			tail = tail->next;
			temp = tail;
			p = temp->next;
		}
		
		tail = tail->next;
		temp = tail;
		p = temp->next;
	}
	
	p = head->next;

	while (p->next != NULL)
	{
		p->nextad = p->next->address;
		p = p->next;
	}
	
	p->nextad = -1;
	p = head->next;

	while (p->next != NULL)
	{
		cout << setfill('0') << setw(5) << p->address << " ";
		cout << p->data << " ";
		cout << setfill('0') << setw(5) << p->nextad << endl;
		
		p = p->next;
	}

	cout << setfill('0') << setw(5) << p->address << " "
		<< p->data << " " << p->nextad << endl;

	return 0;
}