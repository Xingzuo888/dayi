#include <stdio.h>
void main()
{
	int x,i=1,j,num,y;
	printf("������һ����������λ����������");
	scanf("%d", &x);
	while (x < 0) {
		printf("���������Ϊ������\n");
		printf("���������룺");
		scanf("%d", &x);
	}
	num = x;
	while (num / 10 > 0) {
		num /= 10;
		i++;
		if (i > 5) {
			printf("����������ѳ�����λ����\n");
			printf("���������룺");
			scanf("%d", &x);
			i = 1;num = x;
		}
		if (x < 0) {
			printf("���������Ϊ������\n");
			printf("���������룺");
			scanf("%d", &x);
			while (x < 0) {
				printf("���������Ϊ������\n");
				printf("���������룺");
				scanf("%d", &x);
			}
			i = 1;num = x;
		}
	}
	printf("������%dλ��\n", i);
	for (j = 0;j <i;j++) {
		y = x % 10;
		x /= 10;
		printf("%d", y);
	}
	
}
