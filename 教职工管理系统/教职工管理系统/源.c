#include <stdio.h>
#include <string.h>

typedef struct
{
	int ID;
	char name[20];
	int age;
	int worktime;
	char sex[20];
	char marrige[20];
	int grade;
	int wage;
	char tired[20];
}Workers;
typedef struct LNode
{
	Workers data;
	struct LNode *next;
}LNode;
int found(LNode *L, Workers e)
{
	LNode *p, *q;
	p = L;
	q = (LNode*)malloc(sizeof(LNode));
	if (q == NULL)return 0;
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;

}
int InsertList(LNode *L)//1.输入所有职工信息 
{
	LNode *q, *p;
	Workers e;
	p = L;
	printf("请输入该职工的工号：");
	scanf("%d", &e.ID);
	printf("请输入该职工的名字：");
	scanf("%s", &e.name);
	printf("请输入该职工的年龄：");
	scanf("%d", &e.age);
	printf("请输入该职工的工龄：");
	scanf("%d", &e.worktime);
	printf("请输入该职工的性别(男或女)：");
	scanf("%s", &e.sex);
	printf("请输入该职工的婚姻状况(已婚或未婚)：");
	scanf("%s", &e.marrige);
	printf("请输入该职工的级别（1~5）：");
	scanf("%d", &e.grade);
	printf("该职工是否在职（是或否）：");
	scanf("%s", &e.tired);
	if (strcmp(e.tired, "否") == 0) e.wage = 50;
	else e.wage = 0;
	e.wage = 20 * e.grade + e.wage;
	q = (LNode*)malloc(sizeof(LNode));
	if (q == NULL)return 0;
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}
void display(LNode *L)//2.输出职工信息
{
	LNode *q;
	q = L->next;
	printf("工号\t姓名\t年龄\t工龄\t性别\t婚姻状况  级别\t工资\t是否在职\n");
	while (q != NULL)
	{
		printf("%d\t%s\t%d\t%d\t%s\t%s      %d\t%d\t%s\n", q->data.ID
			, q->data.name, q->data.age, q->data.worktime, q->data.sex, q->data.marrige
			, q->data.grade, q->data.wage, q->data.tired);
		q = q->next;
	}
}
void Nodispaly(LNode *L)//3.按工号查找
{
	int a;
	LNode *q;
	q = L->next;
	printf("请输入要查找的职工的工号：\n");
	scanf("%d", &a);
	while (q != NULL)
	{
		if (q->data.ID == a)
		{
			printf("工号\t姓名\t年龄\t工龄\t性别\t婚姻状况  级别\t工资\t是否在职\n");
			printf("%d\t%s\t%d\t%d\t%s\t%s      %d\t%d\t%s\n", q->data.ID
				, q->data.name, q->data.age, q->data.worktime, q->data.sex, q->data.marrige
				, q->data.grade, q->data.wage, q->data.tired);
			break;
		}
		q = q->next;
	}
}
void namedisplay(LNode *L)//4.按姓名查找  
{
	char name[20];
	LNode *q;
	q = L->next;
	printf("请输入要查找的该职工的姓名:");
	scanf("%s", name);
	while (q != NULL)
	{
		if (strcmp(name, q->data.name) == 0)
		{
			printf("工号\t姓名\t年龄\t工龄\t性别\t婚姻状况  级别\t工资\t是否在职\n");
			printf("%d\t%s\t%d\t%d\t%s\t%s      %d\t%d\t%s\n", q->data.ID
				, q->data.name, q->data.age, q->data.worktime, q->data.sex, q->data.marrige
				, q->data.grade, q->data.wage, q->data.tired);
			break;
		}
		q = q->next;
	}
}
void Nosort(LNode *L)//5.按工号排序
{
	LNode *q, *p;
	Workers e;
	p = L;
	while (p != NULL)
	{
		p = p->next;
	}
	while (q != L->next)
	{

		for (q = L->next;q->next != p;q = q->next)
		{
			if (q->data.ID>q->next->data.ID)
			{
				e = q->data;
				q->data = q->next->data;
				q->next->data = e;
			}
		}
		p = q;
	}
}
void sumsort(LNode *L)//6.按级别排序
{
	LNode *q, *p;
	Workers e;
	p = L;
	while (p != NULL)
	{
		p = p->next;
	}
	while (q != L->next)
	{

		for (q = L->next;q->next != p;q = q->next)
		{
			if (q->data.grade>q->next->data.grade)
			{
				e = q->data;
				q->data = q->next->data;
				q->next->data = e;
			}
		}
		p = q;
	}

}
int Norevise(LNode *L)//8.按工号修改某个信息
{
	LNode *p;
	int a, b;
	p = L->next;
	printf("输入要修改的职工的工号：");
	scanf("%d", &b);
	while (p != NULL)
	{
		if (b == p->data.ID)
		{
			printf("工号\t姓名\t年龄\t工龄\t性别\t婚姻状况  级别\t工资\t是否在职\n");
			printf("%d\t%s\t%d\t%d\t%s\t%s      %d\t%d\t%s\n", p->data.ID
				, p->data.name, p->data.age, p->data.worktime, p->data.sex, p->data.marrige
				, p->data.grade, p->data.wage, p->data.tired);
			break;
		}
		p = p->next;
	}
	printf("1.工号 2.姓名 3.年龄 4.工龄 5.性别 6.婚姻状况 7.级别  8.是否在职\n");
	printf("请输入以上编号选择要修改该职工的信息：");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("要修改工号为：");
		scanf("%d", &p->data.ID);
		return 1;
		break;
	case 2:
		printf("要修改姓名为：");
		scanf("%s", p->data.name);
		return 1;
		break;
	case 3:
		printf("要修改年龄为：");
		scanf("%d", &p->data.age);
		return 1;
		break;
	case 4:
		printf("要修改工龄为：");
		scanf("%d", &p->data.worktime);
		return 1;
		break;
	case 5:
		printf("要性别为(男或女)：");
		scanf("%s", &p->data.sex);
		return 1;
		break;
	case 6:
		printf("要婚姻状况为(已婚或未婚)：");
		scanf("%s", &p->data.marrige);
		return 1;
		break;
	case 7:
		printf("要修改级别为（1~5）：");
		scanf("%d", &p->data.grade);
		if (strcmp(p->data.tired, "否") == 0) p->data.wage = 50;
		else p->data.wage = 0;
		p->data.wage = 20 * p->data.grade + p->data.wage;
		return 1;
		break;
	case 8:
		printf("要修改是否在职为（是或否）：");
		scanf("%s", &p->data.tired);
		if (strcmp(p->data.tired, "否") == 0) p->data.wage = 50;
		else p->data.wage = 0;
		p->data.wage = 20 * p->data.grade + p->data.wage;
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
	printf("输入要删除该职工信息的职工的名字：");
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(name, p->data.name) == 0)
		{
			printf("工号\t姓名\t年龄\t工龄\t性别\t婚姻状况  级别\t工资\t是否在职\n");
			printf("%d\t%s\t%d\t%d\t%s\t%s      %d\t%d\t%s\n", p->data.ID
				, p->data.name, p->data.age, p->data.worktime, p->data.sex, p->data.marrige
				, p->data.grade, p->data.wage, p->data.tired);
			break;
		}
		p = p->next; q = q->next;
	}
	printf("是否删除该职工信息（输入1或2）1.是 2.否:");
	scanf("%d", &a);
	if (a == 1)
	{
		q->next = p->next;
		printf("删除成功！\n");
		return 1;
	}
}
int Nodelete(LNode *L)//按工号删除
{
	LNode *p, *q;
	int a, b;
	p = L->next; q = L;
	printf("输入要删除该职工信息的职工的工号：");
	scanf("%d", &b);
	while (p != NULL)
	{
		if (b == p->data.ID)
		{
			printf("工号\t姓名\t年龄\t工龄\t性别\t婚姻状况  级别\t工资\t是否在职\n");
			printf("%d\t%s\t%d\t%d\t%s\t%s      %d\t%d\t%s\n", p->data.ID
				, p->data.name, p->data.age, p->data.worktime, p->data.sex, p->data.marrige
				, p->data.grade, p->data.wage, p->data.tired);
			break;
		}
		p = p->next; q = q->next;
	}
	printf("是否删除该职工信息（输入1或2）1.是 2.否:");
	scanf("%d", &a);
	if (a == 1)
	{
		q->next = p->next;
		printf("删除成功！\n");
		return 1;
	}
}
//读取信息
void rfile(LNode *L) {
	FILE *fp;
	LNode *p = L;
	LNode *p1;
	if ((fp = fopen("file.txt", "r")) != NULL) {
		p->next = NULL;
		while (!feof(fp)) {
			p1 = (LNode*)malloc(sizeof(LNode));
			p1->next = NULL;
			fread(&p1->data, sizeof(p->data), 1, fp);
			if (strlen(p1->data.name) < 20) {
				p1->next = p->next;
				p->next = p1;
			}
			else free(p1);
		}
		fclose(fp);
	}
	else {
		printf("打开文件失败！");
	}
}
//格式化写入信息
void wfile(LNode *L) {
	FILE *fp;
	if ((fp = fopen("file.txt", "w")) != NULL) {
		LNode *p = L->next;
		while (p != NULL) {
			fwrite(&p->data, sizeof(p->data), 1, fp);
			p = p->next;
		}
		fclose(fp);
	}
	else printf("格式化保存学生信息失败！");
}

void menu(LNode *L)
{
	FILE *fp;
	int select;
	int a, b;
	char code1[10],code[10];
	/*Workers worker1 = { 1,"张三",34,6,"男","已婚",4,80,"是" };
	Workers worker2 = { 2,"李四",37,4,"男","已婚",3,110,"否" };
	Workers worker3 = { 3,"赵倩",22,3,"女","已婚",1,20,"是" };
	Workers worker4 = { 4,"王五",44,15,"男","未婚",5,150,"否" };*/
	do
	{
		system("cls");//清屏
		printf("\t*******************************************\n");
		printf("\t*         欢迎使用本职工信息管理系统      *\n");
		printf("\t*1.写入信息           2.查询职工信息      *\n");
		printf("\t*3.修改职工信息       4.添加职工信息      *\n");
		printf("\t*5.删除职工信息       6.按工号对信息排序  *\n");
		printf("\t*7.按级别对信息排序   8.修改管理员口令    *\n");
		printf("\t*9.退出程序           10.读取信息         *\n");
		printf("\t*******************************************\n");
		printf("\t请输入相应编号：");
		scanf("%d", &select);
		switch (select)
		{
		case 10:
			rfile(L);
			system("pause");
			break;
		case 1:
			wfile(L);
			system("pause");
			break;
		case 4:
			InsertList(L);
			system("pause");
			break;
		case 2:
			printf("1.按工号查询 2.按姓名查询 3.查询所有职工信息 ，选择1、2或3：");
			scanf("%d", &b);
			if (b == 1) Nodispaly(L);
			if (b == 2) namedisplay(L);
			if (b == 3) display(L);
			system("pause");
			break;
		/*case 1:
			found(L, worker1);
			found(L, worker2);
			found(L, worker3);
			found(L, worker4);
			printf("创建成功！\n");
			system("pause");
			break;*/
		case 3:
			Norevise(L);
			printf("修改成功！");
			system("pause");
			break;
		case 5:
			printf("1.按工号删除 2.按姓名删除 ，选择1或2：");
			scanf("%d", &b);
			if (b == 1) Nodelete(L);
			if (b == 2) namedelete(L);
			system("pause");
			break;
		case 6:
			Nosort(L);
			printf("排序成功!\n");
			system("pause");
			break;
		case 7:
			sumsort(L);
			printf("排序成功!\n");
			system("pause");
			break;
		case 8:
			printf("请输入原始密码:");
			scanf("%s", code1);
			if ((fp = fopen("code.txt", "r")) != NULL) {
				fgets(code, 10, fp);
			}
			else printf("读取出错！");
			fclose(fp);
			if (strcmp(code1, code) == 0)
			{
				printf("请输入新密码：");
				scanf("%s", code1);
				strcpy(code, code1);
				if ((fp = fopen("code.txt", "w")) != NULL) {
					fputs(code, fp);
				}
				else printf("写入出错！");
				fclose(fp);
				printf("修改成功！");
			}
			else printf("密码错误！");
			system("pause");
			break;
		case 9:
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
	FILE *fp;
	int a;
	char code[10];
	char code1[10];
	LNode H;
	H.next = NULL;
	printf("欢迎使用本职工信息管理系统\n");
	if ((fp = fopen("code.txt", "r")) != NULL) {
		fgets(code, 10, fp);
	}
	else printf("读取出错！");
	fclose(fp);
	for (a = 3;a>0;a--)
	{
		printf("请输入密码：");
		scanf("%s", code1);
		if (strcmp(code1, code) == 0)
		{
			printf("你是合法用户。\n");
			system("pause");
			while (1)
			{
				menu(&H);
			}
		}
		else printf("密码错误！你还有%d次机会\n", a - 1);
	}
	printf("你是非法用户！！ 按任意键程序即将关闭！！\n");

}
