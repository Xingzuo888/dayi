#include<stdio.h>
int main()
{
	int x, y,z,sum;
	scanf("%d%d%d", &x,&y,&z);
	sum=x*x+y*y+z*z;
	if (sum > 1000)
	{
		sum = sum / 1000;
		sum = sum % 10;
	}
	else
		sum = x + y + z;
	printf("%d", sum);
	return 0;
}