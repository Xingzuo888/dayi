/*// exam1
#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, j,h=1;
	char str[100];
	//���ڴ˴���������д�����ɱ�������
	scanf("%s", str);
	j = strlen(str) - 1;
	//���ڴ˴���������д��������䣬�����ж���������ַ����Ƿ��ǻ���
	i = 0;
	while (i < j) {
		if (str[i] != str[j]) {
			h = 0;break;
		}
		i++, j--;
	}
	if ( h==1)//���ڴ˴���������д���ж�����*)
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
	//���ڴ˴�������Ӻ���count�ĵ���
	len = count(str);
	printf("%d", len);
}
int count(char *p)
{
	int i=0;
	for (;*p!='\0';p++)
		if (*p >= 'A'&&*p <= 'Z')
			i++;
	return i;//���ڴ˴���������д���Ӻ���count��ʵ�֣����ڼ����д��ĸ�ĸ���
}*/

//exam3
#include <stdio.h>
#define  N  6
struct  student
{
	int ID;
	char name[20];
	int grade;//���ڴ˴�����һ��ѧ���ṹ��
};
int main(void)
{
	int max = 0; // max��ʾ��߷�ѧ���ĳɼ�
			 //���ڴ˴������������ɱ���
	struct  student  stu[N] = { { 1,"��ƽ",85 },{ 2,"�ų���",76 },{ 3,"����",87 },{ 4,"�³���",91 },{ 5,"��ΰ",72 },{ 6,"�ܺ���",64 } };
	
	//���ڴ˴���������д��������䣬����ͳ��ѧ����Ϣ������߷�ѧ���ĳɼ�
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