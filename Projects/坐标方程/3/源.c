#include<stdio.h>
int main()
{
	long x1, x2, y1, y2, x, y;
	printf("���������꣺");
	scanf("%d%d", &x1, &y1); 
	printf("���������꣺");
	scanf("%d%d", &x2, &y2);
	float k,b;
	k = (y2 - y1) / (x2 - x1);
	printf("%.2f\n", k);
	if (k!=0)
		b = y1 - k*x1;
		
	else
		printf("�÷���������");
	printf("%.2f\n", b);
	printf("y = %.2f*x%+.2f\n", k, b);
	return 0;
}