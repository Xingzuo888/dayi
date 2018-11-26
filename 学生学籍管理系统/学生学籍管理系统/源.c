#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct score {
	int math;
	int english;
	int compute;
	int all;//总成绩
}scores;
typedef struct teachin {
	char classes[20];//所教的班级
	char place[20];//教室
	char date[30];//时间
}teachin;
//学生基本信息
typedef struct {
	int stuID;//学号
	char classes[20];//班级
	char name[20];//姓名
	char sex[5];//性别
	char date[20];//出生日期
	char ID[30];//身份证
	char indate[20];//入学时间
	char ps[20];//政治面貌
	char home[100];//家庭住址
	char np[20];//籍贯
	char postalcode[10];//邮政编码
	char nation[20];//民族
	char graduation[20];//毕业证编码
	char faculty[50];//所属院系
	scores score;//成绩
	int Ccredit;//已修学分
	int Rcredit;//需修学分
}Student;
//教师基本信息
typedef struct {
	int ID;//教工号
	char name[20];//姓名
	char sex[5];//性别
	char pt[20];//职称
	teachin teach;//授课信息
	char faculty[20];//所属院系
	char phone[20];//电话
}Teacher;
typedef struct LNode1 {
	Student data;
	struct LNode1 *next;
}LNode1;
typedef struct LNode2 {
	Teacher data;
	struct LNode2 *next;
}LNode2;
//输入信息/
int InsertList(LNode1 *P, LNode2 *Q) {
	int i, j, k;
	LNode1 *p, *a;
	LNode2 *q, *b;
	Student e;
	Teacher r;
	p = P;
	q = Q;
	P->next = NULL;
	q->next = NULL;
	do {
		int l = 1;
		system("cls");
		printf("1.输入学生信息\n");
		printf("2.输入教师信息\n");
		printf("0.返回\n");
		printf("请输入选项(0-2)：");
		scanf("%d", &i);
		while (i < 0 || i>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i) {
		case 1:

			printf("请输入添加多少个学生信息：");
			scanf("%d", &k);
			while (l <= k) {

				printf("请输入第%d个学生的信息：\n", l);
				printf("学号：");
				scanf("%d", &e.stuID);
				printf("班级：");
				scanf("%s", &e.classes);
				printf("姓名：");
				scanf("%s", &e.name);
				printf("性别：");
				scanf("%s", &e.sex);
				printf("出生日期(如：2000-01-01)：");
				scanf("%s", &e.date);
				printf("身份证：");
				scanf("%s", &e.ID);
				printf("入学时间（如：2000-01-01）：");
				scanf("%s", &e.indate);
				printf("政治面貌：");
				scanf("%s", &e.ps);
				printf("家庭地址：");
				scanf("%s", &e.home);
				printf("籍贯：");
				scanf("%s", &e.np);
				printf("邮政编码：");
				scanf("%s", &e.postalcode);
				printf("民族：");
				scanf("%s", &e.nation);
				printf("毕业证编码：");
				scanf("%s", &e.graduation);
				printf("所属院系：");
				scanf("%s", &e.faculty);
				e.score.math = 0;
				e.score.english = 0;
				e.score.compute = 0;
				e.score.all = 0;
				e.Rcredit = 0;
				e.Ccredit = 0;
				a = (LNode1*)malloc(sizeof(LNode1));
				if (a == NULL)return 0;
				a->data = e;
				a->next = p->next;
				p->next = a;
				l++;
			}

			break;
		case 2:

			printf("请输入添加多少个教师信息：");
			scanf("%d", &k);
			while (l <= k) {

				printf("请输入第%d个教师的信息：\n", l);
				printf("教工号：");
				scanf("%d", &r.ID);
				printf("姓名：");
				scanf("%s", &r.name);
				printf("性别：");
				scanf("%s", &r.sex);
				printf("职称：");
				scanf("%s", &r.pt);
				printf("授课信息( 所教的班级 )：");
				scanf("%s", &r.teach.classes);
				printf("授课信息( 教室 )：");
				scanf("%s", &r.teach.place);
				printf("授课信息( 时间 )：");
				scanf("%s", &r.teach.date);
				printf("所属院系：");
				scanf("%s", &r.faculty);
				printf("电话号码：");
				scanf("%s", &r.phone);
				b = (LNode2*)malloc(sizeof(LNode2));
				if (b == NULL)return 0;
				b->data = r;
				b->next = q->next;
				q->next = b;
				l++;
			}

			break;
		}
		printf("是否继续添加信息（1.是  2.否）");
		scanf("%d", &j);
		while (j < 1 || j>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &j);
		}
	} while (j == 1);
	return 1;
}

//成绩输入/
int Insertscores(LNode1 *P) {
	LNode1 *p;
	int i, j, k, s, d, f, m;
	char a[10];
	do {
		p = P->next;
		system("cls");
		printf("****************************\n");
		printf("*   1.按学号查找           *\n");
		printf("*   2.按姓名查找           *\n");
		printf("*   0.返回                 *\n");
		printf("****************************\n");
		printf("请选择（0-2）：");
		scanf("%d", &m);
		while (m < 0 || m>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &m);
		}
		if (m == 0)return 1;
		switch (m) {
		case 1:
			printf("请输入要添加成绩的学生的学号：");
			scanf("%d", &i);
			while (p != NULL) {
				if (p->data.stuID == i) {
					printf("\n");
					printf("学号     \t姓名  \t班级     \t数学成绩\t英语成绩\t计算机成绩\n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute);
					printf("-------------------------------------------------------------------------------------------\n");
					printf("\n");
					printf("*********************************************************\n");
					printf("*   1.数学成绩    2.英语成绩        3.计算机成绩        *\n");
					printf("*   4.全部        0.退出                                *\n");
					printf("*********************************************************\n");
					printf("请选择添加成绩：");
					scanf("%d", &k);
					while (k < 0 || k>4) {
						printf("输入有误！  请重新输入：");
						scanf("%d", &k);
					}
					switch (k) {
					case 1:
						printf("请输入数学成绩：");
						scanf("%d", &p->data.score.math);
						printf("添加成功！");break;
					case 2:
						printf("请输入英语成绩：");
						scanf("%d", &p->data.score.english);
						printf("添加成功！");break;
					case 3:
						printf("请输入计算机成绩：");
						scanf("%d", &p->data.score.compute);
						printf("添加成功！");break;
					case 4:
						printf("请输入数学成绩：");
						scanf("%d", &p->data.score.math);
						printf("请输入英语成绩：");
						scanf("%d", &p->data.score.english);
						printf("请输入计算机成绩：");
						scanf("%d", &p->data.score.compute);
						printf("添加成功！");break;
					case 0:
						break;
					}
					if (p->data.score.math >= 60)s = 4;
					else s = 0;
					if (p->data.score.english >= 60)d = 4;
					else d = 0;
					if (p->data.score.compute >= 60)f = 4;
					else f = 0;
					p->data.Ccredit = s + d + f;
					p->data.Rcredit = 12 - p->data.Ccredit;
					break;
				}
				p = p->next;
			}
			if (p == NULL) {
				printf("在数据中找不到该学生！\n");
			}
			break;
		case 2:
			printf("请输入要添加成绩的学生的姓名：");
			scanf("%s", &a);
			while (p != NULL) {
				if (strcmp(p->data.name, a) == 0) {
					printf("\n");
					printf("学号     \t姓名  \t班级     \t数学成绩\t英语成绩\t计算机成绩\n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute);
					printf("-------------------------------------------------------------------------------------------\n");
					printf("\n");
					printf("*********************************************************\n");
					printf("*   1.数学成绩    2.英语成绩        3.计算机成绩        *\n");
					printf("*   4.全部        0.退出                                *\n");
					printf("*********************************************************\n");
					printf("请选择添加成绩：");
					scanf("%d", &k);
					while (k < 0 || k>4) {
						printf("输入有误！  请重新输入：");
						scanf("%d", &k);
					}
					switch (k) {
					case 1:
						printf("请输入数学成绩：");
						scanf("%d", &p->data.score.math);
						printf("添加成功！");break;
					case 2:
						printf("请输入英语成绩：");
						scanf("%d", &p->data.score.english);
						printf("添加成功！");break;
					case 3:
						printf("请输入计算机成绩：");
						scanf("%d", &p->data.score.compute);
						printf("添加成功！");break;
					case 4:
						printf("请输入数学成绩：");
						scanf("%d", &p->data.score.math);
						printf("请输入英语成绩：");
						scanf("%d", &p->data.score.english);
						printf("请输入计算机成绩：");
						scanf("%d", &p->data.score.compute);
						printf("添加成功！");break;
					case 0:
						break;
					}
					if (p->data.score.math >= 60)s = 4;
					else s = 0;
					if (p->data.score.english >= 60)d = 4;
					else d = 0;
					if (p->data.score.compute >= 60)f = 4;
					else f = 0;
					p->data.Ccredit = s + d + f;
					p->data.Rcredit = 12 - p->data.Ccredit;
					break;
				}
				p = p->next;
			}
			if (p == NULL) {
				printf("在数据中找不到该学生！\n");
			}
			break;
		}
		printf("\n");
		printf("是否继续添加成绩( 1.是  2.否)：");
		scanf("%d", &j);
		while (j < 1 || j>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &j);
		}
	} while (j == 1);
	return 1;
}

//修改信息/
int Modify(LNode1 *P, LNode2 *Q) {
	LNode1 *p;
	LNode2 *q;
	int i, j, k, l, m;
	char a[10];
	do {
		p = P->next;
		q = Q->next;
		system("cls");
		printf("选择要修改的信息(1.学生信息  2.教师信息  0.返回 )：");
		scanf("%d", &i);
		while (i < 0 || i>2) {
			printf("输入有误！\n");
			printf("请重新输入：");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i) {
		case 1:
			printf("1.按学号查找   2.按姓名查找  ：  ");
			scanf("%d", &m);
			while (m < 1 || m>2) {
				printf("输入有误！\n");
				printf("请重新输入：");
				scanf("%d", &m);
			}
			switch (m) {
			case 1:
				printf("输入要修改学生信息的学号：");
				scanf("%d", &j);
				while (p != NULL) {
					if (p->data.stuID == j) {
						printf("\n");
						printf("学号      \t班级    \t姓名 \t性别 \t出生日期      \t身份证号              \t入学时间     \t政治面貌    \t家庭住址                 \t籍贯\t邮政编码 \t民族 \t毕业证编码  \t所属院系\n");
						printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("%-10d\t%-10s\t%-5s\t%-2s\t%-15s\t%-20s\t%-15s\t%-10s\t%-30s\t%-5s\t%-10s\t%-5s\t%-10s\t%-10s\n", p->data.stuID, p->data.classes, p->data.name, p->data.sex, p->data.date, p->data.ID,
							p->data.indate, p->data.ps, p->data.home, p->data.np, p->data.postalcode, p->data.nation, p->data.graduation, p->data.faculty);
						printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("\n");
						printf("************************************************************************************************\n");
						printf("**  1.学号   2.班级  3.姓名   4.性别     5.出生日期  6.身份证号   	7.入学时间    8.政治面貌  **\n");
						printf("**  9.家庭住址    10.籍贯   11.邮政编码  12.民族     13.毕业证编码   14.所属院系   0.退出      **\n");
						printf("************************************************************************************************\n");
						printf("请选择要修改的信息：");
						scanf("%d", &k);
						while (k < 0 || k>14) {
							printf("输入有误！\n");
							printf("请重新输入：");
							scanf("%d", &k);
						}
						switch (k) {
						case 1:
							printf("请输入更改后的学号：");
							scanf("%d", &p->data.stuID);
							break;
						case 2:
							printf("请输入更改后的班级：");
							scanf("%s", &p->data.classes);
							break;
						case 3:
							printf("请输入更改后的姓名：");
							scanf("%s", &p->data.name);
							break;
						case 4:
							printf("请输入更改后的性别：");
							scanf("%s", &p->data.sex);
							break;
						case 5:
							printf("请输入更改后的出生日期(2000-01-01)：");
							scanf("%s", &p->data.date);
							break;
						case 6:
							printf("请输入更改后的身份证号：");
							scanf("%s", &p->data.ID);
							break;
						case 7:
							printf("请输入更改后的入学时间(2000-01-01)：");
							scanf("%s", &p->data.indate);
							break;
						case 8:
							printf("请输入更改后的政治面貌：");
							scanf("%s", &p->data.ps);
							break;
						case 9:
							printf("请输入更改后的家庭住址：");
							scanf("%s", &p->data.home);
							break;
						case 10:
							printf("请输入更改后的籍贯：");
							scanf("%s", &p->data.np);
							break;
						case 11:
							printf("请输入更改后的邮政编码：");
							scanf("%s", &p->data.postalcode);
							break;
						case 12:
							printf("请输入更改后的民族：");
							scanf("%s", &p->data.nation);
							break;
						case 13:printf("请输入更改后的毕业证编码：");
							scanf("%s", &p->data.graduation);
							break;
						case 14:
							printf("请输入更改后的所属院系：");
							scanf("%s", &p->data.faculty);
							break;
						case 0:
							break;
						}
						break;
					}
					p = p->next;
				}
				if (p == NULL) printf("找不到要修改的学生！");
				break;
			case 2:
				printf("输入要修改学生信息的姓名：");
				scanf("%s", a);
				while (p != NULL) {
					if (strcmp(p->data.name, a) == 0) {
						printf("\n");
						printf("学号      \t班级    \t姓名 \t性别 \t出生日期      \t身份证号              \t入学时间     \t政治面貌    \t家庭住址                 \t籍贯\t邮政编码 \t民族 \t毕业证编码  \t所属院系\n");
						printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("%-10d\t%-10s\t%-5s\t%-2s\t%-15s\t%-20s\t%-15s\t%-10s\t%-30s\t%-5s\t%-10s\t%-5s\t%-10s\t%-10s\n", p->data.stuID, p->data.classes, p->data.name, p->data.sex, p->data.date, p->data.ID,
							p->data.indate, p->data.ps, p->data.home, p->data.np, p->data.postalcode, p->data.nation, p->data.graduation, p->data.faculty);
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("\n");
						printf("************************************************************************************************\n");
						printf("**  1.学号   2.班级  3.姓名   4.性别      5.出生日期  6.身份证号   	7.入学时间    8.政治面貌  **\n");
						printf("**  9.家庭住址    10.籍贯   11.邮政编码  12.民族     13.毕业证编码   14.所属院系   0.退出      **\n");
						printf("************************************************************************************************\n");
						printf("请选择要修改的信息：");
						scanf("%d", &k);
						while (k < 0 || k>14) {
							printf("输入有误！\n");
							printf("请重新输入：");
							scanf("%d", &k);
						}
						switch (k) {
						case 1:
							printf("请输入更改后的学号：");
							scanf("%d", &p->data.stuID);
							break;
						case 2:
							printf("请输入更改后的班级：");
							scanf("%s", &p->data.classes);
							break;
						case 3:
							printf("请输入更改后的姓名：");
							scanf("%s", &p->data.name);
							break;
						case 4:
							printf("请输入更改后的性别：");
							scanf("%s", &p->data.sex);
							break;
						case 5:
							printf("请输入更改后的出生日期(2000-01-01)：");
							scanf("%s", &p->data.date);
							break;
						case 6:
							printf("请输入更改后的身份证号：");
							scanf("%s", &p->data.ID);
							break;
						case 7:
							printf("请输入更改后的入学时间(2000-01-01)：");
							scanf("%s", &p->data.indate);
							break;
						case 8:
							printf("请输入更改后的政治面貌：");
							scanf("%s", &p->data.ps);
							break;
						case 9:
							printf("请输入更改后的家庭住址：");
							scanf("%s", &p->data.home);
							break;
						case 10:
							printf("请输入更改后的籍贯：");
							scanf("%s", &p->data.np);
							break;
						case 11:
							printf("请输入更改后的邮政编码：");
							scanf("%s", &p->data.postalcode);
							break;
						case 12:
							printf("请输入更改后的民族：");
							scanf("%s", &p->data.nation);
							break;
						case 13:printf("请输入更改后的毕业证编码：");
							scanf("%s", &p->data.graduation);
							break;
						case 14:
							printf("请输入更改后的所属院系：");
							scanf("%s", &p->data.faculty);
							break;
						case 0:
							break;
						}
						break;
					}
					p = p->next;
				}
				if (p == NULL) printf("找不到要修改的学生！");
				break;
			}
			break;
		case 2:
			printf("1.按教工号查找   2.按姓名查找  ：  ");
			scanf("%d", &m);
			while (m < 1 || m>2) {
				printf("输入有误！\n");
				printf("请重新输入：");
				scanf("%d", &m);
			}
			switch (m) {
			case 1:
				printf("输入要修改教师信息的教工号：");
				scanf("%d", &j);
				while (q != NULL) {
					if (q->data.ID == j) {
						printf("\n");
						printf("教工号     \t姓名\t性别 \t职称       \t授课信息(班级)  \t授课信息(地点)   \t授课信息(时间)             \t所属院系  \t联系电话\n");
						printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("%-10d\t%-5s\t%-2s\t%-10s\t%-20s\t%-20s\t%-25s\t%-10s\t%-15s\n", q->data.ID, q->data.name, q->data.sex, q->data.pt,
							q->data.teach.classes, q->data.teach.place, q->data.teach.date, q->data.faculty, q->data.phone);
						printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("\n");
						printf("**********************************************************************************************************************************\n");
						printf("**    1.教工号  2.姓名  3.性别  4.职称  5.授课信息(班级)  6.授课信息(地点)  7.授课信息(时间)  8.所属院系  9.联系电话  0.退出    **\n");
						printf("**********************************************************************************************************************************\n");
						printf("请选择要修改的信息：");
						scanf("%d", &k);
						while (k < 0 || k>9) {
							printf("输入有误！\n");
							printf("请重新输入：");
							scanf("%d", &k);
						}
						switch (k) {
						case 1:
							printf("请输入修改后的教工号：");
							scanf("%d", &q->data.ID);
							break;
						case 2:
							printf("请输入修改后的姓名：");
							scanf("%s", &q->data.name);
							break;
						case 3:
							printf("请输入修改后的性别：");
							scanf("%s", &q->data.sex);
							break;
						case 4:
							printf("请输入修改后的职称：");
							scanf("%s", &q->data.pt);
							break;
						case 5:
							printf("请输入修改后的所属院系(所教的班级)：");
							scanf("%s", &q->data.teach.classes);
							break;
						case 6:
							printf("请输入修改后的所属院系(上课教室)：");
							scanf("%s", &q->data.teach.place);
							break;
						case 7:
							printf("请输入修改后的所属院系(上课时间)：");
							scanf("%s", &q->data.teach.date);
							break;
						case 8:
							printf("请输入修改后的所属院系：");
							scanf("%s", &q->data.faculty);
							break;
						case 9:
							printf("请输入修改后的联系电话：");
							scanf("%s", &q->data.phone);
							break;
						case 0:

							break;
						}
						break;
					}
					q = q->next;
				}
				if (q == NULL) printf("找不到教师信息！");
				break;
			case 2:
				printf("输入要修改教师信息的姓名：");
				scanf("%s", &a);
				while (q != NULL) {
					if (strcmp(q->data.name, a) == 0) {
						printf("\n");
						printf("教工号     \t姓名\t性别 \t职称       \t授课信息(班级)  \t授课信息(地点)   \t授课信息(时间)             \t所属院系  \t联系电话\n");
						printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("%-10d\t%-5s\t%-2s\t%-10s\t%-20s\t%-20s\t%-25s\t%-10s\t%-15s\n", q->data.ID, q->data.name, q->data.sex, q->data.pt,
							q->data.teach.classes, q->data.teach.place, q->data.teach.date, q->data.faculty, q->data.phone);
						printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("\n");
						printf("**********************************************************************************************************************************\n");
						printf("**    1.教工号  2.姓名  3.性别  4.职称  5.授课信息(班级)  6.授课信息(地点)  7.授课信息(时间)  8.所属院系  9.联系电话  0.退出    **\n");
						printf("**********************************************************************************************************************************\n");
						printf("请选择要修改的信息：");
						scanf("%d", &k);
						while (k < 0 || k>9) {
							printf("输入有误！\n");
							printf("请重新输入：");
							scanf("%d", &k);
						}
						switch (k) {
						case 1:
							printf("请输入修改后的教工号：");
							scanf("%d", &q->data.ID);
							break;
						case 2:
							printf("请输入修改后的姓名：");
							scanf("%s", &q->data.name);
							break;
						case 3:
							printf("请输入修改后的性别：");
							scanf("%s", &q->data.sex);
							break;
						case 4:
							printf("请输入修改后的职称：");
							scanf("%s", &q->data.pt);
							break;
						case 5:
							printf("请输入修改后的所属院系(所教的班级)：");
							scanf("%s", &q->data.teach.classes);
							break;
						case 6:
							printf("请输入修改后的所属院系(上课教室)：");
							scanf("%s", &q->data.teach.place);
							break;
						case 7:
							printf("请输入修改后的所属院系(上课时间)：");
							scanf("%s", &q->data.teach.date);
							break;
						case 8:
							printf("请输入修改后的所属院系：");
							scanf("%s", &q->data.faculty);
							break;
						case 9:
							printf("请输入修改后的联系电话：");
							scanf("%s", &q->data.phone);
							break;
						case 0:

							break;
						}
						break;
					}
					q = q->next;
				}
				if (q == NULL) printf("找不到教师信息！");
				break;
			}
			break;
		}
		printf("是否继续修改信息（1.是  2.否）");
		scanf("%d", &j);
		while (j < 1 || j>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &j);
		}
	} while (j == 1);
	return 1;
}

//修改成绩/
int Modifyscores(LNode1 *P) {
	LNode1 *p;
	char a[10];
	int i, j, k, m;
	int s, d, f;
	do {
		p = P->next;
		system("cls");
		printf("****************************\n");
		printf("*   1.按学号查找           *\n");
		printf("*   2.按姓名查找           *\n");
		printf("*   0.返回                 *\n");
		printf("****************************\n");
		printf("请选择（0-2）：");
		scanf("%d", &m);
		while (m < 0 || m>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &m);
		}
		if (m == 0)return 1;
		switch (m) {
		case 1:
			printf("请输入要修改学生的学号：");
			scanf("%d", &i);
			while (p != NULL) {
				if (p->data.stuID == i) {
					printf("\n");
					printf("学号     \t姓名  \t班级     \t数学成绩\t英语成绩\t计算机成绩\n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute);
					printf("-------------------------------------------------------------------------------------------\n");
					printf("\n");
					printf("*********************************************************\n");
					printf("*   1.数学成绩    2.英语成绩        3.计算机成绩        *\n");
					printf("*   4.全部        0.退出                                *\n");
					printf("*********************************************************\n");
					printf("请输入要修改的成绩：");
					scanf("%d", &j);
					while (j < 0 || j>4) {
						printf("输入有误！  请重新输入：");
						scanf("%d", &j);
					}
					switch (j) {
					case 1:
						printf("请输入数学成绩：");
						scanf("%d", &p->data.score.math);
						printf("修改成功！");
						break;
					case 2:
						printf("请输入英语成绩：");
						scanf("%d", &p->data.score.english);
						printf("修改成功！");
						break;
					case 3:
						printf("请输入计算机成绩：");
						scanf("%d", &p->data.score.compute);
						printf("修改成功！");
						break;
					case 4:
						printf("请输入数学成绩：");
						scanf("%d", &p->data.score.math);
						printf("请输入英语成绩：");
						scanf("%d", &p->data.score.english);
						printf("请输入计算机成绩：");
						scanf("%d", &p->data.score.compute);
						printf("修改成功！");
						break;
					case 0:
						break;
					}
					if (p->data.score.math >= 60)s = 4;
					else s = 0;
					if (p->data.score.english >= 60)d = 4;
					else d = 0;
					if (p->data.score.compute >= 60)f = 4;
					else f = 0;
					p->data.Ccredit = s + d + f;
					p->data.Rcredit = 12 - p->data.Ccredit;

					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("找不到学号为%d的学生\n", i);
			break;
		case 2:
			printf("请输入要修改学生的姓名：");
			scanf("%s", &a);
			while (p != NULL) {
				if (strcmp(p->data.name, a) == 0) {
					printf("\n");
					printf("学号     \t姓名  \t班级     \t数学成绩\t英语成绩\t计算机成绩\n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute);
					printf("-------------------------------------------------------------------------------------------\n");
					printf("\n");
					printf("*********************************************************\n");
					printf("*   1.数学成绩    2.英语成绩        3.计算机成绩        *\n");
					printf("*   4.全部        0.退出                                *\n");
					printf("*********************************************************\n");
					printf("请输入要修改的成绩：");
					scanf("%d", &j);
					while (j < 0 || j>4) {
						printf("输入有误！  请重新输入：");
						scanf("%d", &j);
					}
					switch (j) {
					case 1:
						printf("请输入数学成绩：");
						scanf("%d", &p->data.score.math);
						printf("修改成功！");
						break;
					case 2:
						printf("请输入英语成绩：");
						scanf("%d", &p->data.score.english);
						printf("修改成功！");
						break;
					case 3:
						printf("请输入计算机成绩：");
						scanf("%d", &p->data.score.compute);
						printf("修改成功！");
						break;
					case 4:
						printf("请输入数学成绩：");
						scanf("%d", &p->data.score.math);
						printf("请输入英语成绩：");
						scanf("%d", &p->data.score.english);
						printf("请输入计算机成绩：");
						scanf("%d", &p->data.score.compute);
						printf("修改成功！");
						break;
					case 0:
						break;
					}
					if (p->data.score.math >= 60)s = 4;
					else s = 0;
					if (p->data.score.english >= 60)d = 4;
					else d = 0;
					if (p->data.score.compute >= 60)f = 4;
					else f = 0;
					p->data.Ccredit = s + d + f;
					p->data.Rcredit = 12 - p->data.Ccredit;

					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("找不到姓名为%s的学生\n", a);
			break;
		}
		printf("是否继续修改成绩( 1. 是  2.否)： ");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("输入有误！   请重新输入：");
			scanf("%d", &k);
		}
	} while (k == 1);

	return 1;
}

//删除信息/
int Delete(LNode1 *P, LNode2 *Q) {
	LNode1 *p, *a;
	LNode2 *q, *b;
	int i, j, g,t,z,v,  m, u;
	int h[50];
	do {
		system("cls");
		int k = 1, l = 0;
		t = 0, z = 0, v = 0,
		printf("需要删除的内容( 1.删除学生信息   2.删除教师信息  0.返回 )：");
		scanf("%d", &i);
		while (i < 0 || i>2) {
			printf("输入有误！\n");
			printf("请重新输入：");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		printf("请输入要删除几个人的信息：");
		scanf("%d", &j);
		switch (i) {
		case 1:
			while (k <= j) {
				printf("请输入第%d个学生的学号：", k);
				scanf("%d", &h[l]);
				k++;l++;
			}
			k = 1;l = 0;
			printf("\n");
			printf("学号      \t班级    \t姓名 \t性别 \t出生日期      \t身份证号              \t入学时间     \t政治面貌    \t家庭住址                 \t籍贯\t邮政编码 \t民族 \t毕业证编码  \t所属院系\n");
			printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			while (k <= j) {
				p = P;
				a = p->next;
				while (a != NULL) {
					if (a->data.stuID == h[l]) {
						printf("%-10d\t%-10s\t%-5s\t%-2s\t%-15s\t%-20s\t%-15s\t%-10s\t%-30s\t%-5s\t%-10s\t%-5s\t%-10s\t%-10s\n", a->data.stuID, a->data.classes, a->data.name, a->data.sex, a->data.date,a->data.ID,
							a->data.indate, a->data.ps, a->data.home, a->data.np, a->data.postalcode, a->data.nation, a->data.graduation,a->data.faculty);
						v++;
						break;
					}
					a = a->next;
				}
				if (a == NULL) {
					printf("找不到学号为%d的学生信息\n", h[l]);t++;
				}
				k++;l++;
			}
			printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			if (t == j) break;
			printf("\n");
			printf("确定要删除信息（1.是  2.否）：");
			scanf("%d", &g);
			while (g < 1 || g>2) {
				printf("输入有误！\n");
				printf("请重新输入：");
				scanf("%d", &g);
			}
			k = 1, l = 0;
			switch (g) {
			case 1:
				while (k <= j) {
					p = P;
					a = p->next;
					while (a != NULL) {
						if (a->data.stuID == h[l]) {
							p->next = a->next;
							free(a);
							z++;
							break;
						}
						p = p->next;
						a = a->next;
					}
					k++;l++;
				}
				if (z == v) printf("删除成功！\n");
				else printf("删除失败！\n");
				break;
			case 2:
				break;
			}
			break;
		case 2:
			while (k <= j) {
				printf("请输入第%d个教师的教工号：", k);
				scanf("%d", &h[l]);
				k++;l++;
			}
			k = 1;l = 0;
			printf("\n");
			printf("教工号     \t姓名\t性别 \t职称       \t授课信息(班级)  \t授课信息(地点)   \t授课信息(时间)             \t所属院系  \t联系电话\n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
			while (k <= j) {
				q = Q;
				b = q->next;
				while (b != NULL) {
					if (b->data.ID == h[l]) {
						printf("%-10d\t%-5s\t%-2s\t%-10s\t%-20s\t%-20s\t%-25s\t%-10s\t%-15s\n", b->data.ID, b->data.name, b->data.sex, b->data.pt,
							b->data.teach.classes, b->data.teach.place, b->data.teach.date, b->data.faculty, b->data.phone);
						v++;
						break;
					}
					b = b->next;
				}
				if (b == NULL) {
					printf("找不到教工号为%d的教师信息\n", h[l]);
					t++;
				}
				k++;l++;
			}
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
			if (t == j)break;
			printf("\n");
			printf("确定要删除信息(1.是  2.否)：\n");
			scanf("%d", &g);
			while (g < 1 || g>2) {
				printf("输入有误！\n");
				printf("请重新输入：");
				scanf("%d", &g);
			}
			k = 1, l = 0;
			switch (g) {
			case 1:
				while (k <= j) {
					q = Q;
					b = q->next;
					while (b != NULL) {
						if (b->data.ID == h[l]) {
							q->next = b->next;
							free(b);

							z++;
							break;
						}
						q = q->next;
						b = b->next;
					}
					k++;l++;
				}
				if (z == v) printf("删除成功！");
				else printf("删除失败！");
				break;
			case 2:
				break;
			}
			break;
		}
		printf("是否继续删除信息（1.是  2.否）：");
		scanf("%d", &u);
		while (u < 1 || u>2) {
			printf("输入有误！ 请重新输入：");
			scanf("%d", &u);
		}
	} while (u == 1);
	return 1;
}


//删除成绩/
int Deletescores(LNode1 *P) {
	LNode1 *p;
	char a[10];
	int i, j, k, s, d, f, m;
	do {
		p = P->next;
		system("cls");
		printf("****************************\n");
		printf("*   1.按学号查找           *\n");
		printf("*   2.按姓名查找           *\n");
		printf("*   0.返回                 *\n");
		printf("****************************\n");
		printf("请选择（0-2）：");
		scanf("%d", &m);
		while (m < 0 || m>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &m);
		}
		if (m == 0)return 1;
		switch (m) {
		case 1:
			printf("请输入学生学号：");
			scanf("%d", &i);
			while (p != NULL) {
				if (p->data.stuID == i) {
					printf("\n");
					printf("学号     \t姓名  \t班级     \t数学成绩\t英语成绩\t计算机成绩\n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute);
					printf("-------------------------------------------------------------------------------------------\n");
					printf("\n");
					printf("*********************************************************\n");
					printf("*   1.数学成绩    2.英语成绩        3.计算机成绩        *\n");
					printf("*   4.全部        0.退出                                *\n");
					printf("*********************************************************\n");
					printf("请输入要删除的成绩：");
					scanf("%d", &j);
					while (j < 0 || j>4) {
						printf("输入有误！   请重新输入：");
						scanf("%d", &j);
					}
					switch (j) {
					case 1:
						p->data.score.math = NULL;

						printf("删除成功！");
						break;
					case 2:
						p->data.score.english = NULL;

						printf("删除成功！");
						break;
					case 3:
						p->data.score.compute = NULL;

						printf("删除成功！");
						break;
					case 4:
						p->data.score.math = NULL;
						p->data.score.english = NULL;
						p->data.score.compute = NULL;

						printf("删除成功！");
						break;
					case 0:
						break;
					}
					if (p->data.score.math >= 60)s = 4;
					else s = 0;
					if (p->data.score.english >= 60)d = 4;
					else d = 0;
					if (p->data.score.compute >= 60)f = 4;
					else f = 0;
					p->data.Ccredit = s + d + f;
					p->data.Rcredit = 12 - p->data.Ccredit;

					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("未找到学号为%d的学生\n", i);
			break;
		case 2:
			printf("请输入学生姓名：");
			scanf("%s", &a);
			while (p != NULL) {
				if (strcmp(p->data.name, a) == 0) {
					printf("\n");
					printf("学号     \t姓名  \t班级     \t数学成绩\t英语成绩\t计算机成绩\n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute);
					printf("-------------------------------------------------------------------------------------------\n");
					printf("\n");
					printf("*********************************************************\n");
					printf("*   1.数学成绩    2.英语成绩        3.计算机成绩        *\n");
					printf("*   7.全部        0.退出                                *\n");
					printf("*********************************************************\n");
					printf("请输入要删除的成绩：");
					scanf("%d", &j);
					while (j < 0 || j>4) {
						printf("输入有误！   请重新输入：");
						scanf("%d", &j);
					}
					switch (j) {
					case 1:
						p->data.score.math = NULL;

						printf("删除成功！");
						break;
					case 2:
						p->data.score.english = NULL;

						printf("删除成功！");
						break;
					case 3:
						p->data.score.compute = NULL;

						printf("删除成功！");
						break;
					case 4:
						p->data.score.math = NULL;
						p->data.score.english = NULL;
						p->data.score.compute = NULL;

						printf("删除成功！");
						break;
					case 0:
						break;
					}
					if (p->data.score.math >= 60)s = 4;
					else s = 0;
					if (p->data.score.english >= 60)d = 4;
					else d = 0;
					if (p->data.score.compute >= 60)f = 4;
					else f = 0;
					p->data.Ccredit = s + d + f;
					p->data.Rcredit = 12 - p->data.Ccredit;

					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("未找到姓名为%s的学生\n", a);
			break;
		}
		printf("是否继续删除成绩（1.是  2.否）：");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("输入有误！   请重新输入：");
			scanf("%d", &k);
		}
	} while (k == 1);

	return 1;
}

//查询学生基本信息/
int Locate1(LNode1 *P) {
	LNode1 *p;

	int i, k;
	char s[10];
	int a;
	do {
		p = P->next;
		system("cls");
		printf("****************************\n");
		printf("*   1.按学号查找           *\n");
		printf("*   2.按姓名查找           *\n");
		printf("*   0.返回                 *\n");
		printf("****************************\n");
		printf("请选择(0-2)：");
		scanf("%d", &i);
		while (i < 0 || i>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i) {
		case 1:
			printf("请输入学号：");
			scanf("%d", &a);
			while (p != NULL) {
				if (p->data.stuID == a)
				{
					printf("\n");
					printf("学号      \t班级    \t姓名 \t性别 \t出生日期      \t身份证号              \t入学时间     \t政治面貌    \t家庭住址                 \t籍贯\t邮政编码 \t民族 \t毕业证编码  \t所属院系\n");
					printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-10s\t%-5s\t%-2s\t%-15s\t%-20s\t%-15s\t%-10s\t%-30s\t%-5s\t%-10s\t%-5s\t%-10s\t%-10s\n", p->data.stuID, p->data.classes, p->data.name, p->data.sex, p->data.date, p->data.ID,
						p->data.indate, p->data.ps, p->data.home, p->data.np, p->data.postalcode, p->data.nation, p->data.graduation, p->data.faculty);
					printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("没有找到学号为%d的学生\n", a);
			break;
		case 2:
			printf("请输入姓名：");
			scanf("%s", &s);
			while (p != NULL) {
				if (strcmp(p->data.name, s) == 0) {
					printf("\n");
					printf("学号      \t班级    \t姓名 \t性别 \t出生日期      \t身份证号              \t入学时间     \t政治面貌    \t家庭住址                 \t籍贯\t邮政编码 \t民族 \t毕业证编码  \t所属院系\n");
					printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-10s\t%-5s\t%-2s\t%-15s\t%-20s\t%-15s\t%-10s\t%-30s\t%-5s\t%-10s\t%-5s\t%-10s\t%-10s\n", p->data.stuID, p->data.classes, p->data.name, p->data.sex, p->data.date, p->data.ID,
						p->data.indate, p->data.ps, p->data.home, p->data.np, p->data.postalcode, p->data.nation, p->data.graduation, p->data.faculty);
					printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("没有找到该学生\n");
			break;
		}
		printf("是否继续查询（1.是  2.否）：");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &k);
		}
	} while (k == 1);

	return 1;
}

//查询教师基本信息/
int Locate2(LNode2 *Q) {
	LNode2 *q;

	int i, j, k;
	char a[10];

	do {
		q = Q->next;
		system("cls");
		printf("查询的教师信息,请选择教师教工号查询或教师姓名查询(1.教工号  2.姓名  0.返回 )：");
		scanf("%d", &i);
		while (i < 0 || i > 2)
		{
			printf("输入有误\n");
			printf("请重新输入：");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i)
		{
		case 1:
			printf("请输入教师教工号： ");
			scanf("%d", &j);
			while (q != NULL)
			{
				if (q->data.ID == j)
				{
					printf("\n");
					printf("教工号     \t姓名\t性别 \t职称       \t授课信息(班级)  \t授课信息(地点)   \t授课信息(时间)             \t所属院系  \t联系电话\n");
					printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-2s\t%-10s\t%-20s\t%-20s\t%-25s\t%-10s\t%-15s\n", q->data.ID, q->data.name, q->data.sex, q->data.pt,
						q->data.teach.classes, q->data.teach.place, q->data.teach.date, q->data.faculty, q->data.phone);
					printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
					break;
				}
				q = q->next;
			}
			if (q == NULL)printf("没有找到教工号为%d的教师信息\n", j);break;
		case 2:
			printf("请输入姓名：");
			scanf("%s", &a);
			while (q != NULL) {
				if (strcmp(q->data.name, a) == 0)
				{
					printf("\n");
					printf("教工号     \t姓名\t性别 \t职称       \t授课信息(班级)  \t授课信息(地点)   \t授课信息(时间)             \t所属院系  \t联系电话\n");
					printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-2s\t%-10s\t%-20s\t%-20s\t%-25s\t%-10s\t%-15s\n", q->data.ID, q->data.name, q->data.sex, q->data.pt,
						q->data.teach.classes, q->data.teach.place, q->data.teach.date, q->data.faculty, q->data.phone);
					printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
					break;
				}
				q = q->next;
			}
			if (q == NULL)printf("没有找到该教师\n");break;
		}
		printf("是否继续查询（1.是  2.否）：");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &k);
		}
	} while (k == 1);

	return 1;
}

//授课信息/
int School(LNode2 *Q) {
	LNode2 *q;

	int i, j, k;
	char a[10];
	do {
		q = Q->next;
		system("cls");
		printf("****************************\n");
		printf("*   1.按教工号查找         *\n");
		printf("*   2.按姓名查找           *\n");
		printf("*   0.返回                 *\n");
		printf("****************************\n");
		printf("请选择(0-2)：");
		scanf("%d", &i);
		while (i <0 || i>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i) {
		case 1:
			printf("请输入教工号：");
			scanf("%d", &j);
			while (q != NULL) {
				if (q->data.ID == j) {
					printf("\n");
					printf("教工号    \t姓名\t所教班级        \t教室地点   \t授课时间\n");
					printf("----------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-20s\t%-15s\t%-20s\n", q->data.ID, q->data.name, q->data.teach.classes, q->data.teach.place, q->data.teach.date);
					printf("----------------------------------------------------------------------------------\n");
					break;
				}
				q = q->next;
			}
			if (q == NULL)printf("没有找到教工号为%d的教师\n", j);
			break;
		case 2:
			printf("请输入姓名：");
			scanf("%s", &a);
			while (q != NULL) {
				if (strcmp(q->data.name, a) == 0) {
					printf("\n");
					printf("教工号    \t姓名\t所教班级        \t教室地点   \t授课时间\n");
					printf("----------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-20s\t%-15s\t%-20s\n", q->data.ID, q->data.name, q->data.teach.classes, q->data.teach.place, q->data.teach.date);
					printf("----------------------------------------------------------------------------------\n");
					break;
				}
				q = q->next;
			}
			if (q == NULL)printf("没有找到该教师\n");
			break;
		}
		printf("是否继续查询（1.是  2.否）：");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &k);
		}
	} while (k == 1);

	return 1;
}

//查询成绩/
int Locatescores(LNode1 *P) {

	char a[10];
	int i, k, m, z;
	float j;
	do {
		LNode1 *p;
		p = P->next;
		system("cls");
		printf("****************************\n");
		printf("*  1.查看个人成绩          *\n");
		printf("*  2.查看所有人成绩        *\n");
		printf("*  0.返回                  *\n");
		printf("****************************\n");
		printf("请选择(0-2)：");
		scanf("%d", &m);
		while (m < 0 || m>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &m);
		}
		if (m == 0)return 1;
		switch (m) {
		case 1:
			printf("************************\n");
			printf("*   1.学号查询         *\n");
			printf("*   2.姓名查询         *\n");
			printf("*   0.返回             *\n");
			printf("************************\n");
			printf("请选择：");
			scanf("%d", &z);
			while (z < 0 || z>2) {
				printf("输入有误！  请重新输入：");
				scanf("%d", &z);
			}
			switch (z) {
			case 1:
				printf("请输入学号：");
				scanf("%d", &i);
				while (p != NULL) {
					if (p->data.stuID == i) {
						p->data.score.all = p->data.score.math + p->data.score.english + p->data.score.compute;
						j = p->data.score.all / 3;
						printf("\n");
						printf("学号     \t姓名  \t班级                \t数学成绩\t英语成绩\t计算机成绩\t总成绩\t平均分\n");
						printf("---------------------------------------------------------------------------------------------------------------\n");
						printf("%d\t%s\t%s\t%-8d\t%-8d\t%-8d\t%-4d\t%0.2f\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute,
							p->data.score.all, j);
						printf("---------------------------------------------------------------------------------------------------------------\n");
						break;
					}
					p = p->next;
				}
				if (p == NULL)printf("找不到学号为%d的学生\n", i);
				break;
			case 2:
				printf("请输入姓名：");
				scanf("%s", &a);
				while (p != NULL) {
					if (strcmp(p->data.name, a) == 0) {
						p->data.score.all = p->data.score.math + p->data.score.english + p->data.score.compute;
						j = p->data.score.all / 3;
						printf("\n");
						printf("学号     \t姓名  \t班级                \t数学成绩\t英语成绩\t计算机成绩\t总成绩\t平均分\n");
						printf("---------------------------------------------------------------------------------------------------------------\n");
						printf("%d\t%s\t%s\t%-8d\t%-8d\t%-8d\t%-4d\t%0.2f\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute,
							p->data.score.all, j);
						printf("---------------------------------------------------------------------------------------------------------------\n");
						break;
					}
					p = p->next;
				}
				if (p == NULL)printf("找不到姓名为%s的学生\n", a);
				break;
			case 0:break;
			}
			break;
		case 2:
			printf("\n");
			printf("学号     \t姓名  \t班级                \t数学成绩\t英语成绩\t计算机成绩\t总成绩\t平均分\n");
			printf("---------------------------------------------------------------------------------------------------------------\n");
			while (p != NULL) {
				j = 0;
				p->data.score.all = p->data.score.math + p->data.score.english + p->data.score.compute;
				j = p->data.score.all / 3;
				printf("%d\t%s\t%s\t%-8d\t%-8d\t%-8d\t%-4d\t%0.2f\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute,
					p->data.score.all, j);
				p = p->next;
			}
			printf("---------------------------------------------------------------------------------------------------------------\n");
			break;
		case 0:break;
		}
		printf("是否继续查询成绩（1. 是   2.否 ）：");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("输入有误！   请重新输入：");
			scanf("%d", &k);
		}
	} while (k == 1);

	return 1;
}

//总成绩
int All(LNode1 *P) {
	LNode1 *p;
	LNode1 T[100], U[10];
	int j, k, g, h, d, z, a;
	char i[20];
	system("cls");
	printf("1.查找班级\n0.返回\n");
	scanf("%d", &a);
	while (a < 0 || a>1) {
		printf("输入有误！  请重新输入：");
		scanf("%d", &a);
	}
	if (a == 0)return 1;
	if (a == 1) {
		do {
			int o = 0;
			p = P->next;
			system("cls");
			printf("请输入要查看的班级：");
			scanf("%s", &i);
			while (p != NULL) {
				if (strcmp(p->data.classes, i) == 0) {
					memcpy(&T[o], p, sizeof(Student));
					o++;
				}
				p = p->next;
			}
			do {
				system("cls");
				printf("1.按学号排序（前到后）\n");
				printf("2.按学号排序（后到前）\n");
				printf("3.按数学成绩（高到低）  \n");
				printf("4.按数学成绩（低到高）  \n");
				printf("5.按英语成绩（高到低）  \n");
				printf("6.按英语成绩（低到高）  \n");
				printf("7.按计算机成绩（高到低）\n");
				printf("8.按计算机成绩（低到高）\n");
				printf("9.按总成绩（高到低）    \n");
				printf("10.按总成绩（低到高）    \n");
				printf("0.返回\n");
				printf("请选择查看方式（0-10）：");
				scanf("%d", &j);
				while (j < 0 || j>10) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &j);
				}
				switch (j) {
				case 1://按学号排序（前到后）
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.stuID > T[h + 1].data.stuID) {
								memcpy(&U[0], &T[h], sizeof(Student));
								memcpy(&T[h], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("学号       \t姓名\t班级       \t数学成绩\t英语成绩\t计算机成绩\t总分\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 2://按学号排序（后到前）
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.stuID < T[h + 1].data.stuID) {
								memcpy(&U[0], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &T[h], sizeof(Student));
								memcpy(&T[h], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("学号       \t姓名\t班级       \t数学成绩\t英语成绩\t计算机成绩\t总分\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 3://按数学成绩（高到低）
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.math < T[h + 1].data.score.math) {
								memcpy(&U[0], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &T[h], sizeof(Student));
								memcpy(&T[h], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("学号       \t姓名\t班级       \t数学成绩\t英语成绩\t计算机成绩\t总分\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 4://按数学成绩（低到高）
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.math > T[h + 1].data.score.math) {
								memcpy(&U[0], &T[h], sizeof(Student));
								memcpy(&T[h], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("学号       \t姓名\t班级       \t数学成绩\t英语成绩\t计算机成绩\t总分\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 5://按英语成绩（高到低）
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.english < T[h + 1].data.score.english) {
								memcpy(&U[0], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &T[h], sizeof(Student));
								memcpy(&T[h], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("学号       \t姓名\t班级       \t数学成绩\t英语成绩\t计算机成绩\t总分\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 6://按英语成绩（低到高）
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.english > T[h + 1].data.score.english) {
								memcpy(&U[0], &T[h], sizeof(Student));
								memcpy(&T[h], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("学号       \t姓名\t班级       \t数学成绩\t英语成绩\t计算机成绩\t总分\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 7://按计算机成绩（高到低）
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.compute < T[h + 1].data.score.compute) {
								memcpy(&U[0], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &T[h], sizeof(Student));
								memcpy(&T[h], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("学号       \t姓名\t班级       \t数学成绩\t英语成绩\t计算机成绩\t总分\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 8://按计算机成绩（低到高）
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.compute > T[h + 1].data.score.compute) {
								memcpy(&U[0], &T[h], sizeof(Student));
								memcpy(&T[h], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("学号       \t姓名\t班级       \t数学成绩\t英语成绩\t计算机成绩\t总分\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 9://按总成绩（高到低）
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.all < T[h + 1].data.score.all) {
								memcpy(&U[0], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &T[h], sizeof(Student));
								memcpy(&T[h], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("学号       \t姓名\t班级       \t数学成绩\t英语成绩\t计算机成绩\t总分\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 10://按总成绩（低到高）
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.all > T[h + 1].data.score.all) {
								memcpy(&U[0], &T[h], sizeof(Student));
								memcpy(&T[h], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("学号       \t姓名\t班级       \t数学成绩\t英语成绩\t计算机成绩\t总分\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 0:break;
				}
				printf("是否继续查看本班（1.是 2.否）：");
				scanf("%d", &k);
				while (k < 1 || k>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &k);
				}
			} while (k == 1);
			printf("是否继续查看其他班（1.是  2.否）：");
			scanf("%d", &d);
			while (d < 1 || d>2) {
				printf("输入有误！  请重新输入：");
				scanf("%d", &d);
			}
		} while (d == 1);
	}
	return 1;
}

//平均分/
int Average(LNode1 *P) {
	LNode1 *p;
	int i, k;
	char a[20];
	do {
		system("cls");
		int j = 0, Allmath = 0, Allenglish = 0, Allcompute = 0;
		p = P->next;
		printf("1.查看某个班的平均分\n");
		printf("2.返回\n");
		printf("请选择（0-1）：");
		scanf("%d", &i);
		while (i < 0 || i>1) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		if (i == 1) {
			printf("请输入班级：");
			scanf("%s", a);
			while (p != NULL) {
				if (strcmp(p->data.classes, a) == 0) {
					Allmath += p->data.score.math;
					Allenglish += p->data.score.english;
					Allcompute += p->data.score.compute;
					j++;
				}
				p = p->next;
			}
			if (j == 0) {
				printf("找不到该班！\n");
				break;
			}
			printf("\n");
			printf("班级     \t数学平均分\t英语平均分\t计算机平均分\n");
			printf("--------------------------------------------------------------------\n");
			printf("%-10s\t%-8d\t%-8d\t%-8d\n", a, Allmath / j, Allenglish / j, Allcompute / j);
			printf("--------------------------------------------------------------------\n");
		}
		printf("是否继续查看（1.是  2.否）：");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &k);
		}
	} while (k == 1);
	return 1;
}

//不及格的学生/
int Fail(LNode1 *P) {
	LNode1 *p;

	int i, m;
	char k[20];
	do {
		int j = 0;
		p = P->next;
		system("cls");
		printf("****************************************\n");
		printf("**  1.查看数学不及格的学生            **\n");
		printf("**  2.查看英语不及格的学生            **\n");
		printf("**  3.查看计算机不及格的学生          **\n");
		printf("**  4.查看班级里不及格的学生          **\n");
		printf("**  0.返回                            **\n");
		printf("****************************************\n");
		printf("请输入选项(0-4)：");
		scanf("%d", &i);
		while (i < 0 || i>4) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i) {
		case 1:
			printf("\n");
			printf("学号       \t姓名\t数学成绩\t是否补考\n");
			printf("-------------------------------------------------\n");
			while (p != NULL) {
				if (p->data.score.math < 60) {
					printf("%d\t%s\t%-8d\t补考\n", p->data.stuID, p->data.name, p->data.score.math);
					j++;
				}
				p = p->next;
			}
			printf("-------------------------------------------------\n");
			printf("不及格人数有%d人\n", j);
			break;
		case 2:
			printf("\n");
			printf("学号       \t姓名\t英语成绩\t是否补考\n");
			printf("-------------------------------------------------\n");
			while (p != NULL) {
				if (p->data.score.english < 60) {
					printf("%d\t%s\t%-8d\t补考\n", p->data.stuID, p->data.name, p->data.score.english);
					j++;
				}
				p = p->next;
			}
			printf("-------------------------------------------------\n");
			printf("不及格人数有%d人\n", j);
			break;
		case 3:
			printf("\n");
			printf("学号       \t姓名\t计算机成绩\t是否补考\n");
			printf("-------------------------------------------------\n");
			while (p != NULL) {
				if (p->data.score.compute < 60) {
					printf("%d\t%s\t%-8d\t补考\n", p->data.stuID, p->data.name, p->data.score.compute);
					j++;
				}
				p = p->next;
			}
			printf("-------------------------------------------------\n");
			printf("不及格人数有%d人\n", j);
			break;
		case 4:
			p = P->next;
			printf("请输入班级：");
			scanf("%s", k);
			printf("\n");
			printf("学号       \t姓名\t数学成绩\t是否补考\n");
			printf("-------------------------------------------------\n");
			while (p != NULL) {
				if (strcmp(p->data.classes, k) == 0) {
					if (p->data.score.math < 60) {
						printf("%d\t%s\t%-8d\t补考\n", p->data.stuID, p->data.name, p->data.score.math);
						j++;
					}
				}
				p = p->next;
			}
			printf("-------------------------------------------------\n");
			printf("该班级数学不及格人数有%d人\n", j);
			printf("\n");
			p = P->next;
			j = 0;
			printf("\n");
			printf("学号       \t姓名\t英语成绩\t是否补考\n");
			printf("-------------------------------------------------\n");
			while (p != NULL) {
				if (strcmp(p->data.classes, k) == 0) {
					if (p->data.score.english < 60) {
						printf("%d\t%s\t%-8d\t补考\n", p->data.stuID, p->data.name, p->data.score.english);
						j++;
					}
				}
				p = p->next;
			}
			printf("-------------------------------------------------\n");
			printf("该班级英语不及格人数有%d人\n", j);
			printf("\n");
			p = P->next;
			j = 0;
			printf("\n");
			printf("学号       \t姓名\t计算机成绩\t是否补考\n");
			printf("-------------------------------------------------\n");
			while (p != NULL) {
				if (strcmp(p->data.classes, k) == 0) {
					if (p->data.score.compute < 60) {
						printf("%d\t%s\t%-8d\t补考\n", p->data.stuID, p->data.name, p->data.score.compute);
						j++;
					}
				}
				p = p->next;
			}
			printf("-------------------------------------------------\n");
			printf("该班级计算机不及格人数有%d人\n", j);
			break;
		}
		printf("是否继续查询（1.是  2.否）：");
		scanf("%d", &m);
		while (m < 1 || m>2) {
			printf("输入有误！　　请重新输入：");
			scanf("%d", &m);
		}
	} while (m == 1);
	return 1;
}

//显示所有信息 /
int Display(LNode1 *P, LNode2 *Q) {
	LNode1 *p;
	LNode2 *q;
	int i, j;
	do {
		p = P->next;
		q = Q->next;
		system("cls");
		printf("****************************\n");
		printf("**   1.显示学生信息       **\n");
		printf("**   2.显示教师信息       **\n");
		printf("**   0.返回               **\n");
		printf("****************************\n");
		printf("请选择（0-2）：\n");
		scanf("%d", &i);
		while (i < 0 || i>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i) {
		case 1:
			printf("\n");
			printf("学号         \t姓名\t性别 \t出生日期    \t身份证号               \t入学时间     \t政治面貌   \t家庭住址                       \t籍贯  \t邮政编码\t民族\t毕业证编码\t所属院系\n");
			printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			while (p != NULL) {
				printf("%-10d\t%-5s\t%-2s\t%-10s\t%-10s\t%-10s\t%-10s\t%-30s\t%-5s\t%-10s  \t%-5s \t%-10s\t%-10s\n",
					p->data.stuID, p->data.name, p->data.sex, p->data.date, p->data.ID, p->data.indate,
					p->data.ps, p->data.home, p->data.np, p->data.postalcode, p->data.nation, p->data.graduation, p->data.faculty);
				p = p->next;
			}
			printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			break;
		case 2:
			printf("\n");
			printf("教工号     \t姓名\t性别\t职称    \t所属院系\t电话\n");
			printf("-----------------------------------------------------------------------------\n");
			while (q != NULL) {
				printf("%-10d\t%-5s\t%-2s\t%-10s\t%-10s\t%-15s\n",
					q->data.ID, q->data.name, q->data.sex, q->data.pt, q->data.faculty, q->data.phone);
				q = q->next;
			}
			printf("-----------------------------------------------------------------------------\n");
			break;
		}
		printf("是否继续查询（1. 是   2.否 ）：");
		scanf("%d", &j);
		while (j < 1 || j>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &j);
		}
	} while (j == 1);
	return 1;
}

//查看学分/
int Credit(LNode1 *P) {
	LNode1 *p;
	int i, j, k;
	char a[10];

	do {
		p = P->next;
		system("cls");
		printf("************************\n");
		printf("*   1.学号查询         *\n");
		printf("*   2.姓名查询         *\n");
		printf("*   0.返回             *\n");
		printf("************************\n");
		printf("请选择查询方式：");
		scanf("%d", &i);
		while (i < 0 || i>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i) {
		case 1:
			printf("请输入学号：");
			scanf("%d", &j);
			while (p != NULL) {
				if (p->data.stuID == j) {
					printf("\n");
					printf("学号       \t姓名\t班级        \t已修学分\t未修学分\n");
					printf("------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.Ccredit, p->data.Rcredit);
					printf("------------------------------------------------------------------------\n");
					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("未找到学号为%d的学生！\n", j);
			break;
		case 2:
			printf("请输入姓名：");
			scanf("%s", &a);
			while (p != NULL) {
				if (strcmp(p->data.name, a) == 0) {
					printf("\n");
					printf("学号       \t姓名\t班级        \t已修学分\t未修学分\n");
					printf("------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.Ccredit, p->data.Rcredit);
					printf("------------------------------------------------------------------------\n");
					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("未找到姓名为%s的学生！\n", a);
			break;
		}
		printf("是否继续查询（1.是  2.否）：");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("输入有误！  请重新输入：");
			scanf("%d", &k);
		}
	} while (k == 1);

	return 1;
}

//查看所有学生学分/
int Allcredit(LNode1 *P) {
	LNode1 *p;
	p = P->next;
	system("cls");
	printf("学号       \t姓名\t班级    \t已修学分\t未修学分\n");
	printf("------------------------------------------------------------------------\n");
	while (p != NULL) {
		printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.Ccredit, p->data.Rcredit);
		p = p->next;
	}
	printf("------------------------------------------------------------------------\n");
	return 1;
}

//基本信息管理
void BIM(LNode1 *P, LNode2 *Q) {
	int select, k, j, l;

	do {
		do {
			system("cls");
			printf("*********************\n");
			printf("* 1.添加信息        *\n");
			printf("* 2.修改信息        *\n");
			printf("* 3.删除信息        *\n");
			printf("* 0.返回主菜单      *\n");
			printf("*********************\n");
			printf("请选择要操作的序号(0-3)：");
			scanf("%d", &select);
			switch (select) {
			case 1://添加信息
				k = InsertList(P, Q);
				if (k == 0)printf("添加失败！");
				else printf("添加成功！");
				printf("是否返回基本信息管理菜单（1. 是   2.否）");
				scanf("%d", &l);
				while (l < 1 || l>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &l);
				}
				break;
			case 2://修改信息
				k = Modify(P, Q);
				if (k == 0)printf("修改失败！");
				else printf("修改成功！");
				printf("是否返回基本信息管理菜单（1. 是   2.否）");
				scanf("%d", &l);
				while (l < 1 || l>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &l);
				}
				break;
			case 3://删除信息
				Delete(P, Q);
				printf("是否返回基本信息管理菜单（1. 是   2.否）");
				scanf("%d", &l);
				while (l < 1 || l>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &l);
				}
				break;
			case 0://返回主菜单	
				return;
			default:
				printf("输入有误！");
				system("pause"); break;
			}
		} while (select < 0 || select>3);

	} while (l == 1);

}

//学生成绩管理
void SPM(LNode1 *P) {
	int select, k, j, l;
	char i;
	do {
		do {
			system("cls");
			printf("*********************\n");
			printf("* 1.添加成绩        *\n");
			printf("* 2.修改成绩        *\n");
			printf("* 3.删除成绩        *\n");
			printf("* 4.查询成绩        *\n");
			printf("* 0.返回主菜单      *\n");
			printf("*********************\n");
			printf("请选择要操作的序号(0-4)：");
			scanf("%d", &select);
			switch (select) {
			case 1://添加成绩
				Insertscores(P);
				printf("是否返回学生成绩管理菜单（1. 是   2.否）");
				scanf("%d", &l);
				while (l < 1 || l>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &l);
				}
				break;
			case 2://修改成绩
				Modifyscores(P);
				printf("是否返回学生成绩管理菜单（1. 是   2.否）");
				scanf("%d", &l);
				while (l < 1 || l>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &l);
				}
				break;
			case 3://删除成绩
				Deletescores(P);
				printf("是否返回学生成绩管理菜单（1. 是   2.否）");
				scanf("%d", &l);
				while (l < 1 || l>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &l);
				}
				break;
			case 4://查询成绩
				Locatescores(P);
				printf("是否返回学生成绩管理菜单（1. 是   2.否）");
				scanf("%d", &l);
				while (l < 1 || l>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &l);
				}
				break;
			case 0://返回主菜单
				return;
			default:printf("输入有误！");
				system("pause"); break;
			}
		} while (select < 0 || select>4);
	} while (l == 1);
}

//信息查询统计
void IQS(LNode1 *P, LNode2 *Q) {
	int select;
	int j;
	do {
		do {
			system("cls");
			printf("****************************\n");
			printf("* 1.查询学生基本信息       *\n");
			printf("* 2.查询成绩               *\n");
			printf("* 3.查询教师基本信息       *\n");
			printf("* 4.授课信息               *\n");
			printf("* 5.查看总成绩             *\n");
			printf("* 6.查看平均分             *\n");
			printf("* 7.不及格的学生           *\n");
			printf("* 8.显示所有基本信息       *\n");
			printf("* 0.返回主菜单             *\n");
			printf("*********************\n");
			printf("请选择要操作的序号(0-8)：");
			scanf("%d", &select);
			switch (select) {
			case 1://查询学生基本信息
				Locate1(P);
				printf("是否返回信息查询统计菜单（1.是  2.否）：");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &j);
				}
				break;
			case 2://查询成绩
				Locatescores(P);
				printf("是否返回信息查询统计菜单（1.是  2.否）：");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &j);
				}
				break;
			case 3://查询教师基本信息
				Locate2(Q);
				printf("是否返回信息查询统计菜单（1.是  2.否）：");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &j);
				}
				break;
			case 4://授课信息
				School(Q);
				printf("是否返回信息查询统计菜单（1.是  2.否）：");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &j);
				}
				break;
			case 5://查看总成绩
				All(P);
				printf("是否返回信息查询统计菜单（1.是  2.否）：");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &j);
				}
				break;
			case 6://查看平均分
				Average(P);
				printf("是否返回信息查询统计菜单（1.是  2.否）：");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &j);
				}
				break;
			case 7://不及格的学生
				Fail(P);
				printf("是否返回信息查询统计菜单（1.是  2.否）：");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &j);
				}
				break;
			case 8://显示所有基本信息
				Display(P, Q);
				printf("是否返回信息查询统计菜单（1.是  2.否）：");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &j);
				}
				break;
			case 0://返回主菜单
				return;
			default:printf("输入有误！");
				system("pause"); break;
			}
		} while (select < 0 || select>8);
	} while (j == 1);
}

//毕业生信息管理
void GIM(LNode1 *P) {
	int select;
	char i;
	int j;
	do {
		do {
			system("cls");
			printf("*************************\n");
			printf("* 1.查看学分            *\n");
			printf("* 2.查看所有学生学分    *\n");
			printf("* 0.返回主菜单          *\n");
			printf("*************************\n");
			printf("请选择要操作的序号(0-2)：");
			scanf("%d", &select);
			switch (select) {
			case 1://查看学分 
				Credit(P);
				printf("是否返回毕业生信息管理菜单（1.是  2.否）：");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &j);
				}
				break;
			case 2://查看所有学生学分
				Allcredit(P);
				printf("是否返回毕业生信息管理菜单（1.是  2.否）：");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &j);
				}
				break;
			case 0://返回主菜单
				return;
			default:printf("输入有误！");
				system("pause");
				break;
			}
		} while (select < 0 || select>2);
	} while (j == 1);
}
//格式化保存学生信息
void savefile1(LNode1 *P)//P学生 
{
	FILE *fp;
	if ((fp = fopen("Student.txt", "w")) != NULL)
	{
		LNode1 *p = P->next;
		while (p != NULL)
		{
			fwrite(&p->data, sizeof(p->data), 1, fp);
			p = p->next;
		}
		fclose(fp);
	}
	else
	{
		printf("格式化保存学生信息失败！");
	}
}
//格式化保存教师信息
void savefile2(LNode2 *Q)// Q教师
{
	FILE *fp;
	if ((fp = fopen("Teacher.txt", "w")) != NULL)
	{
		LNode2 *q = Q->next;
		while (q != NULL)
		{
			fwrite(&q->data, sizeof(q->data), 1, fp);
			q = q->next;
		}
		fclose(fp);
	}
	else
	{
		printf("格式化保存教师信息失败！");
	}
}
//读取学生信息
void readfile1(LNode1 *P)
{
	LNode1 *p = P;
	LNode1 *p1;
	FILE *fp;
	if ((fp = fopen("Student.txt", "r")) != NULL)
	{
		p->next = NULL;
		while (!feof(fp))
		{
			p1 = (LNode1*)malloc(sizeof(LNode1));
			p1->next = NULL;
			fread(&p1->data, sizeof(p->data), 1, fp);
			if (strlen(p1->data.home) < 100) {
				p1->next = p->next;
				p->next = p1;
			}
			else {
				free(p1);
			}
		}
		fclose(fp);
	}
	else
	{
		printf("读取学生信息失败!");
	}

}
//读取教师信息
void readfile2(LNode2 *Q)
{
	LNode2 *q = Q;
	LNode2 *q1;
	FILE *fp;
	if ((fp = fopen("Teacher.txt", "r")) != NULL)
	{
		q->next = NULL;
		while (!feof(fp))
		{
			q1 = (LNode2*)malloc(sizeof(LNode2));
			q1->next = NULL;
			fread(&q1->data, sizeof(q1->data), 1, fp);
			if (strlen(q1->data.faculty) < 20) {
				q1->next = q->next;
				q->next = q1;
			}
			else free(q1);
		}
		fclose(fp);
	}
	else
	{
		printf("读取教师信息失败!");
	}
}
//追加保存学生信息
void appendfile1(LNode1 *P) {
	FILE *fp;
	if ((fp = fopen("Student.txt", "a")) != NULL)
	{
		LNode1 *p = P->next;
		while (p != NULL)
		{
			fwrite(&p->data, sizeof(p->data), 1, fp);
			p = p->next;
		}
		fclose(fp);
	}
	else
	{
		printf("追加保存学生信息失败！");
	}
}
//追加保存教师信息
void appendfile2(LNode2 *Q) {
	FILE *fp;
	if ((fp = fopen("Teacher.txt", "a")) != NULL)
	{
		LNode2 *q = Q->next;
		while (q != NULL)
		{
			fwrite(&q->data, sizeof(q->data), 1, fp);
			q = q->next;
		}
		fclose(fp);
	}
	else
	{
		printf("追加保存教师信息失败！");
	}
}
void nume(LNode1 *P, LNode2 *Q) {
	int select;
	int i, j;
	do {
		system("cls");//清屏
		printf("*********************\n");
		printf("* 1.文件管理        *\n");
		printf("* 2.基本信息管理    *\n");
		printf("* 3.学生成绩管理    *\n");
		printf("* 4.信息查询统计    *\n");
		printf("* 5.毕业生信息管理  *\n");
		printf("* 0.退出系统        *\n");
		printf("*********************\n");
		printf("请输入数字（0--5）：");
		scanf("%d", &select);
		switch (select) {
		case 1://打开文件
			printf("  1.格式化保存信息 \n  2.追加保存信息\n  3.读取信息\n  0.返回\n");
			printf("请选择：");
			scanf("%d", &i);
			while (i < 0 || i>3) {
				printf("输入有误！  请重新输入：");
				scanf("%d", &i);
			}
			switch (i) {
			case 1:
				printf("1.格式化保存学生信息\n2.格式化保存教师信息\n0.返回\n");
				printf("请选择：");
				scanf("%d", &j);
				while (j< 0 || j>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &j);
				}
				switch (j) {
				case 1:
					savefile1(P);break;
				case 2:
					savefile2(Q);break;
				case 0:
					break;
				}
				break;
			case 2:
				printf("1.追加保存学生信息\n2.追加保存教师信息\n0.返回\n");
				printf("请选择：");
				scanf("%d", &j);
				while (j < 0 || j>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &j);
				}
				switch (j) {
				case 1:
					appendfile1(P);break;
				case 2:
					appendfile2(Q);break;
				case 0:
					break;
				}
				break;
			case 3:
				printf("1.读取学生信息\n2.读取教师信息\n0.返回\n");
				printf("请选择：");
				scanf("%d", &j);
				while (j < 0 || j>2) {
					printf("输入有误！  请重新输入：");
					scanf("%d", &j);
				}
				switch (j) {
				case 1:
					readfile1(P);break;
				case 2:
					readfile2(Q);break;
				case 0:
					break;
				}
				break;
			case 0:
				break;
			}
			system("pause");
			break;
		case 2://基本信息管理
			BIM(P, Q);
			system("pause");
			break;
		case 3://学生成绩管理
			SPM(P);
			system("pause");
			break;
		case 4://信息查询统计
			IQS(P, Q);
			system("pause");
			break;
		case 5://毕业生信息管理
			GIM(P);
			system("pause");
			break;
		case 0://退出
			exit(0);
			break;
		default:printf("输入有误！");
			system("pause");
			break;
		}
	} while (select < 0 || select>4);
}
int main() {
	LNode1 S;
	LNode2 T;
	while (1) {
		nume(&S, &T);
	}
}