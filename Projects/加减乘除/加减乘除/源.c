#include<stdio.h>
int main()
{
	float x, y;
	char r;
	printf("��������1+2�ĸ�ʽ\n");
	scanf("%f%c%f",&x,&r,&y);
	if (r=='+')
		printf("x+y=%f\n",x+y);
	else if (r=='-')
		printf("x-y=%f\n", x - y);
	else if (r=='*')
		printf("x*y=%f\n", x * y);
	else if (r=='/')
		printf("x/y=%f\n", x / y);
	
	return 0;
}