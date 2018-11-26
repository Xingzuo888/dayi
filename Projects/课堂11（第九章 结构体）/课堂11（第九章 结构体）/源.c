#include<stdio.h>
/*struct DOB
{
	int year;
	int month;
	int day;
};
/*typedef struct student
{
	char name[20];
	char gender;
	int grade;
	struct DOB birth;
}ST;*/
//typedef struct student ST  取别名
//在定义结构体struct student的同时，为其取别名为ST
/*struct student
{
	char name[20];
	char gender;
	int grade;
	struct DOB birth;
}ST;*/
//定义结构体struct student的同时， 定义该种数据类型的全局变量
/*int main()
{
	struct student ST = { "yz",'m',70,{1974,6,18} };//初始化
	//yz.grade = 59;
	//scanf("%c", &yz.gender);
	//strcpy(yz.name, "yangzhu");
	//printf("%d\n", yz.grade);
	//printf("%c\n", yz.gender);
	//printf("%s\n", yz.name);
	//yz.gender = 'm'; 分别赋值
	//yz.birth.year = 1974;
	//ST zhangsan;
	//zhangsan = yz;
	printf("%d\n", ST.birth.year);
	return 0;
}*/
typedef struct student
{
	char name[20];
	char gender;
	int grade;
}ST;
int main()
{
	/*ST yz = { "yz",'m',98 };
	ST *p;
	p = &yz;
	//printf("%d\n", (*p).grade);
	printf("%d\n", p->grade);//指向运算符->  专供指针使用*/
	ST *p;
	ST student[3] = { {"zhangzan",'f',67},{"yz",'m',45},{"lisi",'m',87} };
	/*float avg;
	avg = (student[0].grade + student[1].grade + student[2].grade)/3.0;
	printf("%f\n", avg);*/
	p = student;
	p++;//p=p+1  加一个单元
	printf("%d\n", p->grade);
}