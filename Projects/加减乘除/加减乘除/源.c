#include<stdio.h>
int main()
{
	float x, y;
	char r;
	printf("请输入如1+2的格式\n");
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