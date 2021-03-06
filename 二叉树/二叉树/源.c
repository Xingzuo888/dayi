#include<stdio.h>
typedef char ElemType;
typedef struct BiNode
{
	ElemType data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode;
BiNode *T;
void visit(ElemType e)
{
	printf("%3c", e);
}
//创建一个二叉树(用先序输入序列（以#表示空树)创建二叉树)
BiNode *Creat(FILE *fp)
{
	BiNode *p;
	ElemType e;
	//e=getchar();
	if (!feof(fp))e = fgetc(fp);
	else return NULL;
	if (e != '#')
	{
		p = (BiNode*)malloc(sizeof(BiNode));//分配空间
		if (p == NULL)return NULL;
		p->data = e;
		//赋值
		p->lchild = Creat(fp);//创建其左子树
		p->rchild = Creat(fp);//创建其右子树
	}
	else return NULL;
	return p;

}
//先序遍历
void PreOrder(BiNode *bt)
{
	if (bt != NULL)
	{
		visit(bt->data);//访问根结点
		PreOrder(bt->lchild);//先序访问左子树
		PreOrder(bt->rchild);//先序访问右子树
	}
}
//中序遍历
void InOrder(BiNode *bt)
{
	if (bt != NULL)
	{
		InOrder(bt->lchild);//中序访问左子树
		visit(bt->data);//访问根结点		
		InOrder(bt->rchild);//中序访问右子树
	}
}
//后序遍历
void PostOrder(BiNode *bt)
{
	if (bt != NULL)
	{
		PostOrder(bt->lchild);//后序访问左子树
		PostOrder(bt->rchild);//后序访问右子树
		visit(bt->data);//访问根结点		

	}
}
int length = 0;
int leaf = 0;
void Count(BiNode *bt)
{

	if (bt != NULL)
	{
		length++;//访问根结点
		if (bt->lchild == NULL&&bt->rchild == NULL)leaf++;
		Count(bt->lchild);//先序访问左子树
		Count(bt->rchild);//先序访问右子树
	}


}
void DeleteNode(BiNode *bt, ElemType e)
{
	if (bt != NULL)
	{
		if (bt->data == e)T == NULL;
		if (bt->lchild != NULL&&bt->lchild->data == e)
		{
			bt->lchild = NULL;
		}
		else if (bt->rchild != NULL&&bt->rchild->data == e) {

			bt->rchild = NULL;
		}
		else {
			DeleteNode(bt->lchild, e);//先序访问左子树
			DeleteNode(bt->rchild, e);//先序访问右子树
		}


	}

}
void InsertNode(BiNode *bt, ElemType x, ElemType y) {
	BiNode *p;
	if (bt != NULL)
	{
		if (bt->data == x) {
			p = (BiNode*)malloc(sizeof(BiNode));
			if (p == NULL)return NULL;
			p->data = y;
			p->lchild = p->rchild = NULL;
			if (bt->lchild == NULL)
			{
				bt->lchild = p;
			}
			else if (bt->rchild == NULL) {

				bt->rchild = p;
			}
			else {
				p->lchild = bt->lchild;
				bt->lchild = p;
			}
		}
		else {
			InsertNode(bt->lchild, x, y);
			InsertNode(bt->rchild, x, y);
		}
	}
}
int Deep(BiNode *bt) {
	int ld, rd;
	if (bt != NULL) {
		ld = Deep(bt->lchild);
		rd = Deep(bt->rchild);
		if (ld > rd)return ld + 1;
		else return rd + 1;
	}
	return 0;
}
//菜单
void menu(FILE *fp)
{
	ElemType e,f;
	int select;

	do
	{
		system("cls");//清屏
		printf("\t***********************************\n");
		printf("\t*1.从文件中读出并创建二叉树       *\n");
		printf("\t*2.先序遍历二叉树                 *\n");
		printf("\t*3.中序遍历二叉树                 *\n");
		printf("\t*4.后序遍历二叉树                 *\n");
		printf("\t*5.输出二叉树的总结点数、叶结点数 *\n");
		printf("\t*6.删除二叉树中指定结点           *\n");
		printf("\t*7.在二叉树指定结点处插入结点     *\n");
		printf("\t*8.输出二叉树的深度               *\n");
		printf("\t*0.退出                           *\n");
		printf("\t***********************************\n");
		printf("\t请输入操和代码：");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			fp = fopen("BiTree.txt", "r");
			if (fp == NULL)
			{
				printf("\t文件打开失败!\b");
				return;
			}
			T = Creat(fp);
			fclose(fp);
			system("pause");
			break;
		case 2:
			printf("\t先序遍历：");
			PreOrder(T);
			printf("\n");
			system("pause");
			break;
		case 3:
			printf("\t中序遍历：");
			InOrder(T);
			printf("\n");
			system("pause");
			break;
		case 4:
			printf("\t后序遍历：");
			PostOrder(T);
			printf("\n");
			system("pause");
			break;
		case 5:
			Count(T);
			printf("\t二叉树的结点数是：%d\n", length);
			printf("\t二叉树的叶结点数是：%d\n", leaf);
			system("pause");
			break;
		case 6:
			printf("\t请输入要删除的结点的值：");
			fflush(stdin);
			e = getchar();
			DeleteNode(T, e);
			printf("\t先序遍历：");
			PreOrder(T);
			printf("\n");
			system("pause");
			break;
		case 7:
			printf("要在那个节点插入：");
			fflush(stdin);
			e=getchar();
			printf("\t请输入要插入的结点的值：");
			fflush(stdin);
			f = getchar();
			InsertNode(T, e, f);
			printf("\t先序遍历：");
			PreOrder(T);
			printf("\n");
			system("pause");
			break;
		case 8:
			e=Deep(T);
			printf("\t二叉树的深度是：%d\n", e);
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
	FILE *fp;//文件指针
	while (1)
	{
		menu(&fp);
	}

}
