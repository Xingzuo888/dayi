#include<stdio.h>
#include<string.h>
#define ROW 10
#define COL 10
int main()
{
	int i, j;
	int a[ROW][COL] = { 0 };
	for (i = 0;i < ROW;i++)
		a[i][0] = 1;
	for (i = 1;i < ROW;i++)
		for (j = 1;j <= i;j++)
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
	for (i = 0;i < ROW;i++) {
		for (j = 0;j <= i;j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
	return 0;
}