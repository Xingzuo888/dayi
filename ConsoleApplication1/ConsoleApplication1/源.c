#include <stdio.h>
void main()
{
	int x,i=1,j,num,y;
	printf("请输入一个不超过五位数的整数：");
	scanf("%d", &x);
	while (x < 0) {
		printf("您输入的数为负数！\n");
		printf("请重新输入：");
		scanf("%d", &x);
	}
	num = x;
	while (num / 10 > 0) {
		num /= 10;
		i++;
		if (i > 5) {
			printf("您输入的数已超过五位数！\n");
			printf("请重新输入：");
			scanf("%d", &x);
			i = 1;num = x;
		}
		if (x < 0) {
			printf("您输入的数为负数！\n");
			printf("请重新输入：");
			scanf("%d", &x);
			while (x < 0) {
				printf("您输入的数为负数！\n");
				printf("请重新输入：");
				scanf("%d", &x);
			}
			i = 1;num = x;
		}
	}
	printf("该数是%d位数\n", i);
	for (j = 0;j <i;j++) {
		y = x % 10;
		x /= 10;
		printf("%d", y);
	}
	
}
