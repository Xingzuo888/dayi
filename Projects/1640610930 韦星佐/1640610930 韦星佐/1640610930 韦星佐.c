#include<stdio.h>
#include<string.h>
#define N 5  //空间的增量
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
typedef struct
{
	ElemType *elem;//首地址
	int length;//元素个数
	int listSize;//容量
}sqList;
//初始化线表L,容量为size,成功返回1,失败返回0
int InitiList(sqList *L, int size)
{

	L->elem = (ElemType*)malloc(size * sizeof(ElemType));
	if (L->elem == NULL)return 0;
	L->listSize = size;
	L->length = 5;
	return 1;

}
//插入
int InsertList(sqList *L, int loc) {
	int i;
	if (loc<1 || loc>L->length)
		return 0;
	else
	{
		L->length++;
		
		for (i = L->length;i > loc - 1;i--) {
			L->elem[i] = L->elem[i - 1];
			L->elem[i].id++;
		}
		
		L->elem[loc - 1].id = loc;
		printf("\t请输入要添加的书名！");
		scanf("%s", &L->elem[loc-1].name);
		printf("\t请输入书本的价格！");
		scanf("%d", &L->elem[loc-1].price);
		printf("\t请输入出版日期(如2008 08 08)！");
		scanf("%d%d%d", &L->elem[loc-1].pubData.year, &L->elem[loc-1].pubData.month, &L->elem[loc-1].pubData.day);
		
		return 1;
	}
}
//删除
int DeleteList(sqList *L,char name[]) {
	int i;
	printf("\t请输入要删除图书的名字：");
	scanf("%s", name);
	for (i = 0;i<L->length;i++)
	{
		if (strcmp(name, L->elem[i].name) == 0)
			while (i<L->length&&L->length != 1)
			{
				memcpy(&L->elem[i], &L->elem[i + 1], sizeof L->elem[i]);
				L->elem[i].id--;
				i++;
			}
		L->length--;
		return 1;
	}

	return 0;
}
//查找
int LocateList(sqList *L, char name[])
{
	int i;
	for (i = 0;i < L->length;i++) {
		if (strcmp(name, L->elem[i].name) == 0) {
			
			printf("\t书本编号为：%d\n",L->elem[i].id);
			printf("\t书本的价格为：%d\n",L->elem[i].price);
			printf("\t出版日期为：%d/%d/%d\n"
				,L->elem[i].pubData.year, L->elem[i].pubData.month, L->elem[i].pubData.day);
			return 1;
		}
	}
	return 0;
}
//显示
int DispList(sqList *L) {
	int i;
	for (i = 0;i < L->length;i++) {
		printf("\t书本编号为：%d\n", L->elem[i].id);
		printf("\t书名为：%s\n", L->elem[i].name);
		printf("\t书本的价格为：%d\n", L->elem[i].price);
		printf("\t出版日期为：%d/%d/%d\n"
			, L->elem[i].pubData.year, L->elem[i].pubData.month, L->elem[i].pubData.day);
		printf("\n");
	}
}
//菜单
void menu(sqList *pbook)
{
	//pbook->elem[i].pubData.day

	int select, loc, result;
	
	char name[20];
	
	do
	{
		system("cls");//清屏
		printf("\t****************************\n");
		printf("\t*1.添加新的图书            *\n");
		printf("\t*2.删除指定图书            *\n");
		printf("\t*3.查找指定图书(书名)      *\n");
		printf("\t*4.显示所有的图书          *\n");
		printf("\t*0.退出                    *\n");
		printf("\t****************************\n");
		printf("\t请输入操和代码：");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			
			printf("\t请输入添加的位置！"); 
			scanf("%d", &loc);
			result = InsertList(pbook, loc);
			if (result == 0)printf("\t添加失败！\n");
			else printf("\t添加成功！\n");
			system("pause");
			break;
		case 2:
			result = DeleteList(pbook, name);
			if (result == 0)
				printf("\t删除图书失败，请正确操作");
			else
				printf("\t删除图书%s成功", name);
			system("pause");
			break;
		case 3:
			
			printf("\t请输入查找的书名！");
			scanf("%s",name);
			result = LocateList(pbook, &name);
			if (result == 0)printf("\t查找失败！\n");
			else {
				printf("\t查找成功！\n");
				
				
			}
			system("pause");
			break;
		case 4:
			//显示所有的书籍
			DispList(pbook);
			
			system("pause");
			break;
		case 0:
			//退出
			printf("\t请问是否确定要退出程序！(Y/N)");
			//接收用户输入的选择并执行是否要退出的功能
			exit(0);
			break;
		}
	} while (select<0 || select>4);
}
int main()
{
	sqList books;
	InitiList(&books, 100);

	books.elem[0].id = 1;
	books.elem[1].id = 2;
	books.elem[2].id = 3;
	books.elem[3].id = 4;
	books.elem[4].id = 5;

	strcpy(books.elem[0].name, "语文");
	strcpy(books.elem[1].name, "数学");
	strcpy(books.elem[2].name, "英语");
	strcpy(books.elem[3].name, "数据结构");
	strcpy(books.elem[4].name, "C语言");

	books.elem[0].price = 20;
	books.elem[1].price = 20;
	books.elem[2].price = 20;
	books.elem[3].price = 30;
	books.elem[4].price = 30;

	books.elem[0].pubData.year = 2004;
	books.elem[1].pubData.year = 2004;
	books.elem[2].pubData.year = 2004;
	books.elem[3].pubData.year = 2004;
	books.elem[4].pubData.year = 2004;

	books.elem[0].pubData.month = 11;
	books.elem[1].pubData.month = 11;
	books.elem[2].pubData.month = 11;
	books.elem[3].pubData.month = 11;
	books.elem[4].pubData.month = 11;

	books.elem[0].pubData.day = 12;
	books.elem[1].pubData.day = 12;
	books.elem[2].pubData.day = 12;
	books.elem[3].pubData.day = 12;
	books.elem[4].pubData.day = 12;

	while (1)
	{
		menu(&books);
	}

}