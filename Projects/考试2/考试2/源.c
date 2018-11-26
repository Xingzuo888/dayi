#include<stdio.h>
int main()
{
	int year;
	int num;
	year = 2006;
	num = 10000;
	while (num < 100000)
	{
		num *= 1.25;
		year++;
	}
	printf("%d", year);
	return 0;
}