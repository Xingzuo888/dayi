#include<stdio.h>
typedef struct 
{
	int year;
	int month;
	int day;
}Data;
typedef struct
{
	int id; //图书编号
	char name[20];//图书名
	int price;//价格
	Data pubData;//出版日期
}Book;
typedef Book ElemType;
typedef struct LNode
{
	Book data;
	struct LNode *next;
}LNode;
int InsertList(LNode *L,int i,ElemType e)
{
	int j;
	LNode *p,*q;
	//初始化，指向头结点，并初始化计数器j=0
	p=L;j=0;
	//循环：将指针指向第i-1个结点
	while(p!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	//检果i是否正确(1<=i<=n+1)    j>i-1时，i<1
	if(p==NULL||j>i-1)return 0;//p==NULL时，i>n+1
	//分配空间并插入
	q=(LNode*)malloc(sizeof(LNode));
	if(q==NULL)return 0;
	q->data=e;
	q->next=p->next;
	p->next=q;
	return 1;
}
int DeleteList(LNode *L,char a[]) {
	
	LNode *p, *q;
	p = L;
	
	while (p->next!=NULL) {
		q = p->next;
		if (strcmp(q->data.name,a)==0) {
			
			p->next = q->next;
			free(q);
			return 1;
			
		}
		p = p->next;
	}
	if(p->next==NULL) return 0;
	p = L;
	
	
}
int LocateList(LNode *L, char a[]) {
	LNode *p;
	p = L->next;
	while (p!=NULL) {
		if (strcmp(p->data.name,a)==0) {
			printf("\t书号\t%-16s价格\t出版日期\n", "书名");
			printf("\t%d\t%-16s%d\t%d-%d-%d\n"
				, p->data.id, p->data.name, p->data.price
				, p->data.pubData.year
				, p->data.pubData.month
				, p->data.pubData.day);
			return 1;
		}
		p = p->next;
		
	}
	
	if (p==NULL) return 0;
}
int ChangeList(LNode *L, char a[]) {
	LNode *p;
	int i, j, k, g;
	p = L;
	while (p!=NULL) {
		if (strcmp(a, p->data.name)==0) {
			printf("\t原来的价格是：%d\n", p->data.price);
			printf("\t请输入修改价格：");
			scanf("%d",&i);
			p->data.price = i;
			printf("\t原来的出版日期是：%d-%d-%d\n"
				, p->data.pubData.year, p->data.pubData.month, p->data.pubData.day);
			printf("\t请输入修改出版日期(如2008 08 08)：");
			scanf("%d%d%d",&j,&k,&g);
			p->data.pubData.year = j;
			p->data.pubData.month = k;
			p->data.pubData.day = g;
			return 1;
		}
		p = p->next;
	}
	if(p==NULL) return 0;
}
void display(LNode *L)
{
	LNode *p;
	int i = 0;
	p=L->next;
	printf("\t书号\t%-16s价格\t出版日期\n","书名");
	while(p!=NULL)
	{
		i++;
		p->data.id = i;
		printf("\t%d\t%-16s%d\t%d-%d-%d\n"
			,p->data.id,p->data.name,p->data.price
			,p->data.pubData.year
			,p->data.pubData.month
			,p->data.pubData.day);
		p=p->next;
	}
}
//菜单
void menu(LNode *L)
{	
	ElemType e;
	
	int i,result;
	int a,b,c,d;
	int select;	
	char n[30];
	do
	{
		system("cls");//清屏
		printf("\t****************************\n");
		printf("\t*1.添加新的图书            *\n");
		printf("\t*2.删除指定图书(书名)      *\n");
		printf("\t*3.查找指定图书(书名)      *\n");
		printf("\t*4.修改图书信息            *\n");
		printf("\t*5.显示所有的图书          *\n");
		printf("\t*0.退出                    *\n");
		printf("\t****************************\n");
		printf("\t请输入操和代码：");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			//插入一个元数到指定位置
			printf("\t请输入插入的位置：");
			scanf("%d", &i);
			e.id = i;
			printf("\t请输入书名：");
			scanf("%s", n);
			strcpy(e.name, n);
			printf("\t请输入书的价格：");
			scanf("%d", &a);
			e.price = a;
			printf("\t请输入书的出版日期(如2008 08 08)：");
			scanf("%d%d%d",&b,&c,&d);
			e.pubData.year = b;
			e.pubData.month = c;
			e.pubData.day = d;
			result = InsertList(L, i, e);
			if (result == 0)printf("插入失败！");
			else printf("插入成功！");
			system("pause");
			break;
		case 2:
			//删除指定位置的元素符号
			printf("\t请输入删除的书名：");
			scanf("%s", n);
			
			result = DeleteList(L, &n);
			if (result == 0)printf("删除失败！");
			else printf("删除成功！");
			system("pause");
			break;
		case 3:
			//查找指定元素的位序
			printf("\t请输入查找的书名：");
			scanf("%s", n);
			
			result = LocateList(L, &n);
			if (result == 0)printf("查找失败！");
			else {
				printf("查找成功！");
				
			}
				system("pause");
			break;
		case 4:
			//修改图书信息
			printf("\t请输入要修改的书：");
			scanf("%s", n);
			result = ChangeList(L, &n);
			if (result == 0)printf("修改失败！");
			else printf("修改成功！");
			system("pause");
			break;
		case 5:
			//显示所有的元素
			display(L);
		
			system("pause");
			break;
		case 0:
			//退出
			printf("\t请问是否确定要退出程序！(Y/N)");
			//接收用户输入的选择并执行是否要退出的功能
			exit(0);
			break;
		}
	}while(select<0||select>5);
}
int main()
{
	LNode H;
	Book book1={1,"数据结构",34,{2014,1,25}};
	Book book2={2,"C语言程序设计",31,{2013,11,12}};
	Book book3={3,"Java面向对象",42,{2015,8,1}};
	Book book4={4,"Web应用开发",68,{2016,10,18}};
	Book book5={5,"Android开发基础",75,{2017,3,30}};
	H.next=NULL;
	InsertList(&H,1,book1);
	InsertList(&H,2,book2);
	InsertList(&H,3,book3);
	InsertList(&H,4,book4);
	InsertList(&H,5,book5);
	
	while(1)
	{
		menu(&H);
	}

}