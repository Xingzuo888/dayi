#include <stdio.h>
#include <string.h>
typedef struct
{
	int No;
	char name[20];
	int Math;
	int English;
	int Computer;
	int sum;
}student;
typedef struct LNode
{
	student data;
	struct LNode *next;
}LNode;
int InsertList(LNode *L)//1.输入所有学生信息 
{
	LNode *q, *p;
	student e;
	p = L;
	printf("请输入该学生的学号：");
	scanf("%d", &e.No);
	printf("请输入该学生的名字：");
	scanf("%s", &e.name);
	printf("请输入该学生的数学成绩：");
	scanf("%d", &e.Math);
	printf("请输入该学生的英语成绩：");
	scanf("%d", &e.English);
	printf("请输入该学生的计算机成绩：");
	scanf("%d", &e.Computer);
	e.sum = e.Math + e.English + e.Computer;
	q = (LNode*)malloc(sizeof(LNode));
	if (q == NULL)return 0;
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}
void display(LNode *L)//2.输出所有学生成绩
{
	LNode *q;
	q = L->next;
	printf("\t学号\t姓名\t数学\t英语\t计算机\t总分\n");
	while (q != NULL)
	{
		printf("\t%d\t%s\t%d\t%d\t%d\t%d\n", q->data.No
			, q->data.name, q->data.Math, q->data.English
			, q->data.Computer, q->data.sum);
		q = q->next;
	}
}
void Nodispaly(LNode *L)//3.按学号查找某个学生信息
{
	int a;
	LNode *q;
	q = L->next;
	printf("请输入要查找的该学生的学号:");
	scanf("%d", &a);
	while (q != NULL)
	{
		if (q->data.No == a)
		{
			printf("\t学号\t姓名\t数学\t英语\t计算机\t总分\n");
			printf("\t%d\t%s\t%d\t%d\t%d\t%d\n", q->data.No
				, q->data.name, q->data.Math, q->data.English
				, q->data.Computer, q->data.sum);
			break;
		}
		q = q->next;
	}
}
void namedisplay(LNode *L)//4.按姓名查找某个学生信息  
{
	char name[20];
	LNode *q;
	q = L->next;
	printf("请输入要查找的该学生的姓名:");
	scanf("%s", name);
	while (q != NULL)
	{
		if (strcmp(name, q->data.name) == 0)
		{
			printf("\t学号\t姓名\t数学\t英语\t计算机\t总分\n");
			printf("\t%d\t%s\t%d\t%d\t%d\t%d\n", q->data.No
				, q->data.name, q->data.Math, q->data.English
				, q->data.Computer, q->data.sum);
			break;
		}
		q = q->next;
	}
}
void Nosort(LNode *L)//5.按学号对学生排序
{
	LNode *q, *p;
	student e;
	p = L;
	while (p != NULL)
	{
		p = p->next;
	}
	while (q != L->next)
	{

		for (q = L->next;q->next != p;q = q->next)
		{
			if (q->data.No>q->next->data.No)
			{
				e = q->data;
				q->data = q->next->data;
				q->next->data = e;
			}
		}
		p = q;
	}
}
void sumsort(LNode *L)//6.按总成绩对学生排序
{
	LNode *q, *p;
	student e;
	p = L;
	while (p != NULL)
	{
		p = p->next;
	}
	while (q != L->next)
	{

		for (q = L->next;q->next != p;q = q->next)
		{
			if (q->data.sum>q->next->data.sum)
			{
				e = q->data;
				q->data = q->next->data;
				q->next->data = e;
			}
		}
		p = q;
	}

}
int namerevise(LNode *L)//7.按姓名修改某个学生信息
{
	LNode *p;
	int a;
	char name[20];
	p = L->next;
	printf("输入要修改的学生的名字：");
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(name, p->data.name) == 0)
		{
			printf("\t学号\t姓名\t数学\t英语\t计算机\t总分\n");
			printf("\t%d\t%s\t%d\t%d\t%d\t%d\n", p->data.No
				, p->data.name, p->data.Math, p->data.English
				, p->data.Computer, p->data.sum);
			break;
		}
		p = p->next;
	}
	printf("1、学号 2、姓名 3、数学成绩 4、英语成绩 5、计算机成绩\n");
	printf("请输入以上编号选择要修改该学生的信息：");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("要修改学号为：");
		scanf("%d", &p->data.No);
		return 1;
		break;
	case 2:
		printf("要修改姓名为：");
		scanf("%s", p->data.name);
		return 1;
		break;
	case 3:
		printf("要修改数学成绩为：");
		scanf("%d", &p->data.Math);
		p->data.sum = p->data.Math + p->data.English + p->data.Computer;
		return 1;
		break;

	case 4:
		printf("要修改英语成绩为：");
		scanf("%d", &p->data.English);
		p->data.sum = p->data.Math + p->data.English + p->data.Computer;
		return 1;
		break;
	case 5:
		printf("要修改计算机成绩为：");
		scanf("%d", &p->data.Computer);
		p->data.sum = p->data.Math + p->data.English + p->data.Computer;
		return 1;
		break;
	}
}
int Norevise(LNode *L)//8.按学号修改某个学生信息
{
	LNode *p;
	int a, b;
	p = L->next;
	printf("输入要修改的学生的学号：");
	scanf("%d", &b);
	while (p != NULL)
	{
		if (b == p->data.No)
		{
			printf("\t学号\t姓名\t数学\t英语\t计算机\t总分\n");
			printf("\t%d\t%s\t%d\t%d\t%d\t%d\n", p->data.No
				, p->data.name, p->data.Math, p->data.English
				, p->data.Computer, p->data.sum);
			break;
		}
		p = p->next;
	}
	printf("1、学号 2、姓名 3、数学成绩 4、英语成绩 5、计算机成绩\n");
	printf("请输入以上编号选择要修改该学生的信息：");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("要修改学号为：");
		scanf("%d", &p->data.No);
		return 1;
		break;
	case 2:
		printf("要修改姓名为：");
		scanf("%s", p->data.name);
		return 1;
		break;
	case 3:
		printf("要修改数学成绩为：");
		scanf("%d", &p->data.Math);
		p->data.sum = p->data.Math + p->data.English + p->data.Computer;
		return 1;
		break;

	case 4:
		printf("要修改英语成绩为：");
		scanf("%d", &p->data.English);
		p->data.sum = p->data.Math + p->data.English + p->data.Computer;
		return 1;
		break;
	case 5:
		printf("要修改计算机成绩为：");
		scanf("%d", &p->data.Computer);
		p->data.sum = p->data.Math + p->data.English + p->data.Computer;
		return 1;
		break;
	}
}
int namedelete(LNode *L)
{
	LNode *p, *q;
	int a;
	char name[20];
	p = L->next; q = L;
	printf("输入要删除该学生信息的学生的名字：");
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(name, p->data.name) == 0)
		{
			printf("\t学号\t姓名\t数学\t英语\t计算机\t总分\n");
			printf("\t%d\t%s\t%d\t%d\t%d\t%d\n", p->data.No
				, p->data.name, p->data.Math, p->data.English
				, p->data.Computer, p->data.sum);
			break;
		}
		p = p->next; q = q->next;
	}
	printf("是否删除该学生信息（输入1或2）\t1.是 2.否\n");
	scanf("%d", &a);
	if (a == 1)
	{
		q->next = p->next;
		return 1;
	}
}
int Nodelete(LNode *L)
{
	LNode *p, *q;
	int a, b;
	p = L->next; q = L;
	printf("输入要删除该学生信息的学生的学号：");
	scanf("%d", &b);
	while (p != NULL)
	{
		if (b == p->data.No)
		{
			printf("\t学号\t姓名\t数学\t英语\t计算机\t总分\n");
			printf("\t%d\t%s\t%d\t%d\t%d\t%d\n", p->data.No
				, p->data.name, p->data.Math, p->data.English
				, p->data.Computer, p->data.sum);
			break;
		}
		p = p->next; q = q->next;
	}
	printf("是否删除该学生信息（输入1或2）\t1.是 2.否\n");
	scanf("%d", &a);
	if (a == 1)
	{
		q->next = p->next;
		return 1;
	}
}
void menu(LNode *L)
{
	int select;
	int i;int a;
	do
	{
		system("cls");//清屏
		printf("\t*****************************\n");
		printf("\t*欢迎使用学生成绩管理系统!  *\n");
		printf("\t*1.输入所有学生信息         *\n");
		printf("\t*2.输出所有学生成绩         *\n");
		printf("\t*3.按学号查找某个学生信息   *\n");
		printf("\t*4.按姓名查找某个学生信息   *\n");
		printf("\t*5.按学号对学生排序         *\n");
		printf("\t*6.按总成绩对学生排序       *\n");
		printf("\t*7.按姓名修改某个学生信息   *\n");
		printf("\t*8.按学号修改某个学生信息   *\n");
		printf("\t*9.按姓名删除某个学生信息   *\n");
		printf("\t*10.按学号删除某个学生信息  *\n");
		printf("\t*0.退出                     *\n");
		printf("\t*请输入您的选择（0-10）：   *\n");
		printf("\t*****************************\n");
		printf("\t请输入操和代码：");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			InsertList(L);
			system("pause");
			break;
		case 2:
			display(L);
			system("pause");
			break;
		case 3:
			Nodispaly(L);
			system("pause");
			break;
		case 4:
			namedisplay(L);
			system("pause");
			break;
		case 5:
			Nosort(L);
			system("pause");
			break;
		case 6:
			sumsort(L);
			system("pause");
			break;
		case 7:
			i = namerevise(L);
			if (i == 1) printf("修改成功！\n");
			system("pause");
			break;
		case 8:
			i = Norevise(L);
			if (i == 1) printf("修改成功！\n");
			system("pause");
			break;
		case 9:
			i = namedelete(L);
			if (i == 1) printf("删除成功！\n");
			system("pause");
			break;
		case 10:
			i = Nodelete(L);
			if (i == 1) printf("删除成功！\n");
			system("pause");
			break;
		case 0:
			//退出
			printf("\t请问是否确定要退出程序！(输入1或2)\n1、确定 2、否");
			//接收用户输入的选择并执行是否要退出的功能
			scanf("%d", &a);
			if (a == 1) exit(0);
			else system("pause");
			break;
		}
	} while (select<0 || select>10);
}
int main()
{
	LNode H;
	H.next = NULL;
	while (1)
	{
		menu(&H);
	}

}