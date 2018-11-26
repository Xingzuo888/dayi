#include<stdio.h>
typedef struct {
	int Math;      //数学
	int English;   //英语
	int Computer;  //计算机
	int sum;      //总分
}score;
typedef struct {
	int ID;//学号
	char name[20];//姓名
	score scores;
}student;
typedef student ElemType;
typedef struct LNode {
	student data;
	struct LNode *next;
}LNode;
void menu(LNode *L) {
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
			break;
		case 2:
			//输出所有学生信息
			break;
		case 3:
			//按学号查找某个学生信息
			break;
		case 4:
			//按姓名查找某个学生信息
			break;
		case 5:
			//按学号对学生排序
			break;
		case 6:
			//按总成绩对学生排序
			break;
		case 7:
			//按学号修改某个学生信息
			break;
		case 8:
			//按姓名修改某个学生信息
			break;
		case 9:
			//按学号删除某个学生信息
			break;
		case 10:
			//按姓名删除某个学生信息
			break;
		default:
			printf("输入的菜单项有误，请重新输入！\n");
		case 0:
			printf("\t请问是否确定要退出程序！(Y/N)");
			//接收用户输入的选择并执行是否要退出的功能
			exit(0);
			printf("程序结束，谢谢使用！\n");

		}
	} while (select < 0 || select>10);
}

int main() {
	LNode H;
	while (1) {
		menu(&H);
	}
}