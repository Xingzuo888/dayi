#include<stdio.h>
#include<string.h>
typedef struct student
{
	char name[20];
	char gender;
	int grade;
	struct student *next;
}ST;
int main()
{
	ST *p, *q;
	ST zhangsan = { "zhangsan",'m',10 };
	ST lisi = { "lisi",'f',20 };
	ST wangwu = { "wangwu",'f',30 };
	zhangsan.next = &lisi;
	lisi.next = &wangwu;
	wangwu.next = NULL;
	p = &zhangsan;
	
	q = (ST *)malloc(sizeof(ST));
	strcpy(q->name, "yangzhu");
	q->gender = 'm';
	q->grade = 40;
	q->next = p;
	p = q;
	
	q = p;
	while (q != NULL)
	{
		printf("%d\n", q->grade);
		q = q->next;
	}
	return 0;
}