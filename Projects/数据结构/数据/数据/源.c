#define N 10
#include<stdio.h>
int a[N];//线性表
int len = 0;//长度
void Display(int x[], int n)
{
	int i;
	for (i = 0;i<n;i++)
	{
		printf("%3d", x[i]);
	}
	printf("\n");
}
//插入：在线性表x的第loc个位置插入元素e,成功：1,失败:0
int InsertList(int x[], int loc, int e)
{
	int j;
	//插入位置是否正确  1<=loc<=len+1
	if (loc<1 || loc>len + 1)return 0;
	//空间是否满
	if (len >= N)
	{
		return 0;
	}
	//从最后一个元素到第loc个元素，依次后移
	for (j = len;j >= loc;j--)
	{
		x[j] = x[j - 1];
	}
	x[loc - 1] = e;//在第loc个位置，插入e
	len++;//线性表的长度加1
	return 1;
}
//删除:把线性表x的第loc个元素删除，并将删除后的值赋给*e
//成功：1,失败:0
int DeleteList(int x[], int loc, int *e)
{
	//检查删除位置是否正确 1<=loc<=len
	//把第loc个元素的值赋给*e
	//从第loc+1个元素到第len个元素，依次前移
	//长度减1
}
//查找：在线性表x中查找和元素e相等的第一个元素
//返回其位序,如果不存在，则返回0
int LocateList(int x[], int e)
{

}
//菜单
void menu()
{

	int select, result;
	int e;
	int loc;

	do
	{
		system("cls");//清屏
		printf("\t****************************\n");
		printf("\t*1.插入一个元数到指定位置  *\n");
		printf("\t*2.删除指定位置的元素符号  *\n");
		printf("\t*3.查找指定元素的位序      *\n");
		printf("\t*4.显示所有的元素          *\n");
		printf("\t*0.退出                    *\n");
		printf("\t****************************\n");
		printf("\t请输入操和代码：");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			//插入一个元数到指定位置
			printf("\t请输入要插入的元素:");
			scanf("%d", &e);
			printf("\t请输入要插入的位置:");
			scanf("%d", &loc);
			result = InsertList(a, loc, e);
			if (result == 0)printf("\t插入元素%d失败!\n", e);
			else printf("\t插入元素%d成功!\n", e);
			system("pause");
			break;
		case 2:
			//删除指定位置的元素符号
			printf("删除\n");
			system("pause");
			break;
		case 3:
			//查找指定元素的位序
			printf("查找\n");
			system("pause");
			break;
		case 4:
			//显示所有的元素
			printf("\t");
			Display(a, len);
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

	while (1)
	{
		menu();
	}
}
