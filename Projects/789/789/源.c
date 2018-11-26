#include<stdio.h>
typedef char ElemType;
typedef struct BiNode
{
	ElemType data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode;
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
int main()
{
	BiNode *T;
	FILE *fp;//文件指针
			 //fp=fopen(文件路径，打开模式:r w  a(文本文件) rb,wr,ab;
			 //fp=fopen("E:\\Data\\BiTree.txt","r");  //绝对路径
	fp = fopen("Data\\BiTree.txt", "r"); //相对路径
	if (fp == NULL)
	{
		printf("文件打开失败!\b");
		return;
	}

	T = Creat(fp);
	fclose(fp);
	printf("先序遍历：");
	PreOrder(T);
	printf("\n");
	printf("中序遍历：");
	InOrder(T);
	printf("\n");
	printf("后序遍历：");
	PostOrder(T);
	printf("\n");
	Count(T);
	printf("二叉树的结点数是：%d\n", length);
	printf("二叉树的叶结点数是：%d\n", leaf);

	DeleteNode(T, 'D');
	printf("先序遍历：");
	PreOrder(T);
	printf("\n");
}
