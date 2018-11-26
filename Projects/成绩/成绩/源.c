#include<stdio.h>
typedef struct {
	int Math;      //数学
	int English;   //英语
	int Computer;  //计算机

}Score;
typedef struct {
	int ID;//学号
	char name[20];//姓名
	Score scores;
}Student;
typedef Student ElemType;
typedef struct LNode {
	Student data;
	struct LNode *next;
}LNode;
//输入学生信息
int InserstList(LNode *L, ElemType e) {

	LNode *p, *q;
	p = L;

	q = (LNode*)malloc(sizeof(LNode));
	if (q == NULL)return 0;
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}
//输出学生成绩
int Display(LNode *L) {
	LNode *p;
	int sum, i, j, k;
	p = L->next;
	printf("\t学号\t姓名\t数学\t英语\t计算机\t总成绩\n");
	while (p != NULL) {
		i = p->data.scores.Math;
		j = p->data.scores.English;
		k = p->data.scores.Computer;
		sum = i + j + k;
		printf("\t%d\t%s\t%d\t%d\t%d\t%d\n"
			, p->data.ID, p->data.name, p->data.scores.Math
			, p->data.scores.English, p->data.scores.Computer
			, sum);
		p = p->next;
	}
}
//按学号查找某个学生信息
int IdLocateList(LNode *L, int i) {
	int a, b, c, sum, k;
	LNode *p;
	p = L->next;
	while (p != NULL) {
		k = p->data.ID;
		if (k == i) {
			printf("\t学号\t姓名\t数学\t英语\t计算机\t总成绩\n");
			a = p->data.scores.Math;
			b = p->data.scores.English;
			c = p->data.scores.Computer;
			sum = a + b + c;
			printf("\t%d\t%s\t%d\t%d\t%d\t%d\n"
				, p->data.ID, p->data.name, p->data.scores.Math
				, p->data.scores.English, p->data.scores.Computer
				, sum);
			return 1;
		}
		p = p->next;
	}
	if (p == NULL)return 0;
}
void menu(LNode *L) {
	int i, result, a, b, c, d;
	char name[20];
	ElemType e;
	char choice;
	int select;
	do {
		system("cls");//清屏
					  //显示菜单
		printf("*************************************\n");
		printf("欢迎使用学生成绩管理系统\n");
		printf("[1] 输入所有学生信息\n");
		printf("[2] 输出所有学生成绩\n");
		printf("[3] 按学号查找某个学生信息\n");
		printf("[4] 按姓名查找某个学生信息\n");
		printf("[5] 按学号对学生排序\n");
		printf("[6] 按总成绩对学生排序\n");
		printf("[7] 按学号修改某个学生信息\n");
		printf("[8] 按姓名修改某个学生信息\n");
		printf("[9] 按学号删除某个学生信息\n");
		printf("[10] 按姓名删除某个学生信息\n");
		printf("[0] 退出程序\n");
		printf("请输入您的选择（0 - 9）：\n");
		printf("**************************************)\n");

		//接收用户的输入		
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			//输入所有学生信息
			printf("请输入学生信息：");

			printf("请输入学号：");
			scanf("%d", &a);e.ID = a;
			printf("请输入姓名：");
			scanf("%s", name);
			strcpy(e.name, name);
			printf("请输入数学成绩：");
			scanf("%d", &b);e.scores.Math = b;
			printf("请输入英语成绩：");
			scanf("%d", &c);e.scores.English = c;
			printf("请输入计算机成绩：");
			scanf("%d", &d);e.scores.Computer = d;
			result = InserstList(L, e);
			if (result == 0)printf("输入失败！");
			else printf("输入成功！");
			system("pause");
			break;
		case 2:
			//输出所有学生信息
			Display(L);
			system("pause");
			break;
		case 3:
			//按学号查找某个学生信息
			printf("请输入学号查找某个学生信息：");
			scanf("%d", &a);
			result = IdLocateList(L, &a);
			if (result == 0)printf("查找失败！");
			else printf("查找成功！");
			system("pause");
			break;
		case 4:
			//按姓名查找某个学生信息
			system("pause");
			break;
		case 5:
			//按学号对学生排序
			system("pause");
			break;
		case 6:
			//按总成绩对学生排序
			system("pause");
			break;
		case 7:
			//按学号修改某个学生信息
			system("pause");
			break;
		case 8:
			//按姓名修改某个学生信息
			system("pause");
			break;
		case 9:
			//按学号删除某个学生信息
			system("pause");
			break;
		case 10:
			//按姓名删除某个学生信息
			system("pause");
			break;
		default:
			printf("输入的菜单项有误，请重新输入！\n");
			system("pause");
			break;
		case 0:

			printf("程序结束，谢谢使用！\n");
			exit(0);

			break;
		}
	} while (select < 0 || select>10);
}
int main() {
	LNode H;
	Student student1 = { 1640610901,"大一",{ 51,23,65 } };
	Student student2 = { 1640610902,"二狗",{ 51,23,65 } };
	Student student3 = { 1640610903,"张三",{ 51,23,65 } };
	Student student4 = { 1640610904,"李四",{ 51,23,65 } };
	Student student5 = { 1640610905,"五龙",{ 51,23,65 } };
	H.next = NULL;
	InserstList(&H, student1);
	InserstList(&H, student2);
	InserstList(&H, student3);
	InserstList(&H, student4);
	InserstList(&H, student5);
	while (1) {
		menu(&H);
	}
}