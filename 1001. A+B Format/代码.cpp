#include<stdio.h>
int main()
{
	int a, b, sum, i, num = 0;
	int c[11];

	scanf("%d%d", &a, &b);
	sum = a + b;

	if (sum >= 1000 && sum < 1000000)
	{
		for (i = 0; sum != 0; i++)
		{
			c[i] = sum % 10;
			num = num + 1;
			sum = sum / 10;
		}

		for (i = num - 1; i > 2; i--)
		{
			printf("%d", c[i]);
		}
		printf(",");

		for (i = 2; i >= 0; i--)
			printf("%d", c[i]);
	}

	else if (sum <= -1000 && sum > -1000000)
	{
		sum = -sum;

		for (i = 0; sum != 0; i++)
		{
			c[i] = sum % 10;
			num = num + 1;
			sum = sum / 10;
		}

		printf("-");

		for (i = num - 1; i > 2; i--)
		{
			printf("%d", c[i]);
		}

		printf(",");

		for (i = 2; i >= 0; i--)
			printf("%d", c[i]);
	}

	else if (sum >= 1000000)
	{
		for (i = 0; sum != 0; i++)
		{
			c[i] = sum % 10;
			num = num + 1;
			sum = sum / 10;
		}

		for (i = num - 1; i > 5; i--)
		{
			printf("%d", c[i]);
		}

		printf(",");

		for (i = 5; i > 2; i--)
		{
			printf("%d", c[i]);
		}

		printf(",");

		for (i = 2; i >= 0; i--)
			printf("%d", c[i]);
	}
	else if (sum <= -1000000)
	{
		sum = -sum;

		for (i = 0; sum != 0; i++)
		{
			c[i] = sum % 10;
			num = num + 1;
			sum = sum / 10;
		}

		printf("-");

		for (i = num - 1; i > 5; i--)
		{
			printf("%d", c[i]);
		}

		printf(",");

		for (i = 5; i > 2; i--)
		{
			printf("%d", c[i]);
		}

		printf(",");

		for (i = 2; i >= 0; i--)
			printf("%d", c[i]);
	}

	else
		printf("%d", sum);

	return 0;
}

