#include<stdio.h>
#include <string.h>
#define N 5  //空间的增量
typedef struct
{
	int year;
	int month;
	int day;
}Date;
typedef struct
{
	int id; //图书编号
	char name[20];//图书名
	int price;//价格
	Date pubDate;//出版日期
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
	L->length = N;
	return 1;

}
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
			for (i = L->length;i >= len - 1;i--)
			{
				memcpy(&L->elem[i], &L->elem[i - 1], sizeof L->elem[i]);
				L->elem[i].id++;
			}
		}
		printf("\t请输入书名：");
		scanf("%s", L->elem[len - 1].name);
		L->elem[len - 1].id = len;
		printf("\t请输入价格：");
		scanf("%d", &L->elem[len - 1].price);
		printf("\t请输入出版日期（例：2017 11 11）：");
		scanf("%d%d%d", &L->elem[len - 1].pubDate.year, &L->elem[len - 1].pubDate.month, &L->elem[len - 1].pubDate.day);
		return len;
	}


}
int Delete(sqList *L, char name[])
{
	int i;
	for (i = 0;i<L->length;i++)
	{
		if (strcmp(name, L->elem[i].name) == 0)
		{
			while (i<L->length && L->length != 1)
			{
				memcpy(&L->elem[i], &L->elem[i + 1], sizeof L->elem[i - 1]);
				L->elem[i].id--;
				i++;
			}
			L->length--;
			return 1;
		}
	}
	return 0;
}
void Locate(sqList *L, char name[])
{
	int i;;
	for (i = 0;i<L->length;i++)
		if (strcmp(name, L->elem[i].name) == 0)
		{
			printf("\t所查书%s在第%d位置\n", name, L->elem[i].id);
			return;
		}
	printf("\t本库中没有%s这本书\n", name);
	return;
}
void Display(sqList *L)
{
	int i;
	for (i = 0;i<L->length;i++)
	{
		printf("\t编号：%d\n", L->elem[i].id);
		printf("\t书名：");
		puts(L->elem[i].name);
		printf("\t价格：%d\n", L->elem[i].price);
		printf("\t出版日期：%d-%d-%d\n", L->elem[i].pubDate.year, L->elem[i].pubDate.month, L->elem[i].pubDate.day);
		printf("\n");
	}
	return;
}
//菜单
void menu(sqList *pbook)
{
	//pbook->elem[i].pubData.day

	int select, len, result;
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
			//插入一个元数到指定位置
			printf("\t本库已有%d本书，请在有效范围内添加\n", pbook->length);
			printf("\t请输入添加位置");
			scanf("%d", &len);
			result = Insert(pbook, len);
			if (result == 0)
				printf("\t添加失败\n");
			else
				printf("\t已成功添加到%d位置\n", result);
			system("pause");
			break;
		case 2:
			//删除指定位置的元素符号
			printf("\t请输入删除的书名：");
			scanf("%s", name);
			result = Delete(pbook, name);
			if (result == 0)
				printf("\t删除失败\n");
			else
			{
				printf("\t已成功删除");
				puts(name);
			}
			system("pause");
			break;
		case 3:
			//查找指定元素的位序
			printf("\t请输入查找的书名：");
			scanf("%s", name);
			Locate(pbook, name);
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
	//初始化
	books.elem[0].id = 1;
	books.elem[1].id = 2;
	books.elem[2].id = 3;
	books.elem[3].id = 4;
	books.elem[4].id = 5;

	strcpy(books.elem[0].name, "Datestructure");
	strcpy(books.elem[1].name, "Math");
	strcpy(books.elem[2].name, "Chinese");
	strcpy(books.elem[3].name, "English");
	strcpy(books.elem[4].name, "Numberlogic");


	books.elem[0].price = 50;
	books.elem[1].price = 50;
	books.elem[2].price = 50;
	books.elem[3].price = 50;
	books.elem[4].price = 50;


	books.elem[0].pubDate.year = 2017;
	books.elem[1].pubDate.year = 2017;
	books.elem[2].pubDate.year = 2017;
	books.elem[3].pubDate.year = 2017;
	books.elem[4].pubDate.year = 2017;


	books.elem[0].pubDate.month = 11;
	books.elem[1].pubDate.month = 11;
	books.elem[2].pubDate.month = 11;
	books.elem[3].pubDate.month = 11;
	books.elem[4].pubDate.month = 11;


	books.elem[0].pubDate.day = 11;
	books.elem[1].pubDate.day = 11;
	books.elem[2].pubDate.day = 11;
	books.elem[3].pubDate.day = 11;
	books.elem[4].pubDate.day = 11;

	//结束初始化
	while (1)
	{
		menu(&books);
	}

}