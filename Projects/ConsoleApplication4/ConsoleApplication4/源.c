#include <stdio.h> 
int main()
{
	int i, j, k, week, year,n;
	int day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	scanf("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		day[1]++;
	week = year % 7;
	for(i = 0;i < 12;i++)
	{
		n = i + 1;
		printf("¡­¡­¡­¡­¡­¡­¡­¡­%d¡­¡­¡­¡­¡­¡­¡­¡­\n",n);
		printf(" Mon  Tue  Wed  Thu  Fri Sat Sun\n");
		for (j = 0;j < week;j++) printf(" ");
		for (k = 1;k < day[i];k++)
		{
			printf("  %3d", k);
			if (++week > 7)
			{
				printf("\n");
				week %= 7;
				printf("\n");
			}
			if (i = 10);
		}
		printf("\n");
	}
	return 0;
}