/*// exam1
#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, j,h=1;
	char str[100];
	//请在此处填入所编写的若干变量定义
	scanf("%s", str);
	j = strlen(str) - 1;
	//请在此处填入所编写的若干语句，用于判断所输入的字符串是否是回文
	i = 0;
	while (i < j) {
		if (str[i] != str[j]) {
			h = 0;break;
		}
		i++, j--;
	}
	if ( h==1)//请在此处填入所编写的判定条件*)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
}*/

/*// exam2
#include <stdio.h>
int count(char *p);
int main(void)
{
	char str[100];
	int len = 0;
	gets(str);
	//请在此处填入对子函数count的调用
	len = count(str);
	printf("%d", len);
}
int count(char *p)
{
	int i=0;
	for (;*p!='\0';p++)
		if (*p >= 'A'&&*p <= 'Z')
			i++;
	return i;//请在此处填入所编写的子函数count的实现，用于计算大写字母的个数
}*/

//exam3
#include <stdio.h>
#define  N  6
struct  student
{
	int ID;
	char name[20];
	int grade;//请在此处定义一个学生结构体
};
int main(void)
{
	int max = 0; // max表示最高分学生的成绩
			 //请在此处定义其它若干变量
	struct  student  stu[N] = { { 1,"李平",85 },{ 2,"张常德",76 },{ 3,"孙祥",87 },{ 4,"陈超凡",91 },{ 5,"赵伟",72 },{ 6,"周海飞",64 } };
	
	//请在此处填入所编写的若干语句，用于统计学生信息计算最高分学生的成绩
	max = Fun(stu,N);
	printf("%d", max);
}
int Fun(struct student a[],int num)
{
	int i, yz = 0;
	for (i = 0;i < num;i++) {
		if (yz<a[i].grade) 
			yz = a[i].grade;
		}
		return yz;
}