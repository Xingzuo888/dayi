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
//typedef struct student ST  ȡ����
//�ڶ���ṹ��struct student��ͬʱ��Ϊ��ȡ����ΪST
/*struct student
{
	char name[20];
	char gender;
	int grade;
	struct DOB birth;
}ST;*/
//����ṹ��struct student��ͬʱ�� ��������������͵�ȫ�ֱ���
/*int main()
{
	struct student ST = { "yz",'m',70,{1974,6,18} };//��ʼ��
	//yz.grade = 59;
	//scanf("%c", &yz.gender);
	//strcpy(yz.name, "yangzhu");
	//printf("%d\n", yz.grade);
	//printf("%c\n", yz.gender);
	//printf("%s\n", yz.name);
	//yz.gender = 'm'; �ֱ�ֵ
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
	printf("%d\n", p->grade);//ָ�������->  ר��ָ��ʹ��*/
	ST *p;
	ST student[3] = { {"zhangzan",'f',67},{"yz",'m',45},{"lisi",'m',87} };
	/*float avg;
	avg = (student[0].grade + student[1].grade + student[2].grade)/3.0;
	printf("%f\n", avg);*/
	p = student;
	p++;//p=p+1  ��һ����Ԫ
	printf("%d\n", p->grade);
}