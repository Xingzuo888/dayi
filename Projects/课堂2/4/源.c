#include<stdio.h>
int main()
{
	int grade;
	printf("请输入分数：");
	scanf("%d", &grade);
	grade /= 10;
	switch (grade)
	{
	case 10:
	case 9:printf("优秀\n");break;
	case 8:printf("良好\n");break;
	case 7:printf("一般\n");break;
	case 6:printf("及格\n");break;
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:printf("不及格\n");break;
	default:printf("输入错误\n");break;
	}
	return 0;
}