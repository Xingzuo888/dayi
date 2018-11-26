#include<stdio.h>
int main()
{
	int x, y = 1, sum = 0;
	int n;int i;
	scanf("%d", &n);
	//j=1;
	for (x = 1;x <= n;x++)
	{
		/*j=j*i;
		sum=sum+j*/
		i = x;
		while (x)
		{
			y *= x;
			x--;
		}
		sum += y;
		x = i;y = 1;
	}
	printf("sum=%d\n", sum);
	return 0;
}
