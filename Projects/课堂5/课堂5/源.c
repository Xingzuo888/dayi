#include<stdio.h>
void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
	return ;
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("����ǰ��a=%d,b=%d\n", a, b);
	swap(&a, &b);
	printf("������a=%d,b=%d\n",a,b);
	return 0;
}