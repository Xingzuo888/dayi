#include<stdio.h>
int a(int i)
{
	int tmp;
	if (i == 1)
		return 1;
	tmp = i*a(i - 1);
	return tmp;
}
int main()
{
	int i, j;
	scanf("%d", &i);
	j = a(i);
	printf("result=%d\n", j);
	return 0;
}