#include<stdio.h>
#include <string.h>
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
	L->length = 3;
	return 1;

}
//新增一本图书
int Insert(sqList *L, int len)
{
	int i;
	if (len<1 || len>L->length + 1)
		return 0;
	else
	{
		L->length++;
		if (L->length>1)
		{
			for (i = L->length;i >= len;i--)
			{
				L->elem[i] = L->elem[i - 1];
				L->elem[i].id++;
			}
		}
		printf("\t请输入书名：");
		scanf("%s", L->elem[len - 1].name);
		L->elem[len - 1].id = len;
		printf("\t请输入价格：");
		scanf("%d", &L->elem[len - 1].price);
		printf("\t请输入出版日期（例：2008 10 16）：");
		scanf("%d%d%d", &L->elem[len - 1].pubData.year, &L->elem[len - 1].pubData.month, &L->elem[len - 1].pubData.day);
		return len;
	}


}
//查找一本图书，如果存在 返回书序， 如果不存在，返回0
int LocateList(sqList *L)
{
	char name[20];
	int i;
	printf("\t请输入要查找的书名：");
	scanf("%s", name);
	for (i = 0;i<L->length;i++)
	{
		if (strcmp(name, L->elem[i].name) == 0)
			printf("\t%s的书序为%d\n", name, L->elem[i].id);
		else
			printf("\t所查找的书不存在\n");
		break;
	}
}//打印出已存在的所有书
void Display(sqList *L)
{
	int i;
	for (i = 0;i<L->length;i++)
	{
		printf("\t编号：%d\n", L->elem[i].id);
		printf("\t书名：");
		puts(L->elem[i].name);
		printf("\t价格：%d\n", L->elem[i].price);
		printf("\t出版日期：%d-%d-%d\n", L->elem[i].pubData.year, L->elem[i].pubData.month, L->elem[i].pubData.day);
		printf("\n");
	}
	return;
}
//删除一本图书
int Delete(sqList *L, char name[])
{
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
//菜单
void menu(sqList *pbook)
{
	//pbook->elem[i].pubData.day

	int select, len;
	int result;
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
			//增加一本图书
			printf("\t书库中有%d本书，请再有效的范围中增加图书。\n", pbook->length);
			printf("\t请输入增加图书的位置：");
			scanf("%d", &len);
			result = Insert(pbook, len);
			if (result == 0)
				printf("\t增加图书失败，请进行正确操作。");
			else
				printf("\t增加图书成功，序列号为%d\n", result);
			system("pause");
			break;
		case 2:
			//删除指定位置的元素符号
			result = Delete(pbook, name);
			if (result == 0)
				printf("\t删除图书失败，请正确操作");
			else
				printf("\t删除图书%s成功", name);
			system("pause");
			break;
		case 3:
			//查找指定元素的位序
			LocateList(pbook);
			system("pause");
			break;
		case 4:
			//显示所有的元素
			Display(pbook);
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

	strcpy(books.elem[0].name, "心理学");
	strcpy(books.elem[1].name, "日语");
	strcpy(books.elem[2].name, "周易哲学");


	books.elem[0].price = 36;
	books.elem[1].price = 80;
	books.elem[2].price = 66;


	books.elem[0].pubData.year = 2008;
	books.elem[1].pubData.year = 2012;
	books.elem[2].pubData.year = 2010;


	books.elem[0].pubData.month = 11;
	books.elem[1].pubData.month = 10;
	books.elem[2].pubData.month = 8;

	books.elem[0].pubData.day = 11;
	books.elem[1].pubData.day = 12;
	books.elem[2].pubData.day = 16;
	while (1)
	{
		menu(&books);
	}

}