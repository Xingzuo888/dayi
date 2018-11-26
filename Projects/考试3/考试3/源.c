#include<stdio.h>
int main()
{
	int sum = 0;
	int i,j;
	int iszhishu;
	for (i = 100;i <= 1000;i++)
	{
		iszhishu = 1;
		for (j = 2;j <= i - 1;j++)
		{
			if (i%j == 0)
			{
				iszhishu = 0;
				break;
			}
		}
		if (iszhishu == 1)
			sum += i;
	}
	printf("%d", sum);
	return 0;
}