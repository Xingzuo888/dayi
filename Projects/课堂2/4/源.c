#include<stdio.h>
int main()
{
	int grade;
	printf("�����������");
	scanf("%d", &grade);
	grade /= 10;
	switch (grade)
	{
	case 10:
	case 9:printf("����\n");break;
	case 8:printf("����\n");break;
	case 7:printf("һ��\n");break;
	case 6:printf("����\n");break;
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:printf("������\n");break;
	default:printf("�������\n");break;
	}
	return 0;
}