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
//����һ��������(�������������У���#��ʾ����)����������)
BiNode *Creat(FILE *fp)
{
	BiNode *p;
	ElemType e;
	//e=getchar();
	if (!feof(fp))e = fgetc(fp);
	else return NULL;
	if (e != '#')
	{
		p = (BiNode*)malloc(sizeof(BiNode));//����ռ�
		if (p == NULL)return NULL;
		p->data = e;
		//��ֵ
		p->lchild = Creat(fp);//������������
		p->rchild = Creat(fp);//������������
	}
	else return NULL;
	return p;

}
//�������
void PreOrder(BiNode *bt)
{
	if (bt != NULL)
	{
		visit(bt->data);//���ʸ����
		PreOrder(bt->lchild);//�������������
		PreOrder(bt->rchild);//�������������
	}
}
//�������
void InOrder(BiNode *bt)
{
	if (bt != NULL)
	{
		InOrder(bt->lchild);//�������������
		visit(bt->data);//���ʸ����		
		InOrder(bt->rchild);//�������������
	}
}
//�������
void PostOrder(BiNode *bt)
{
	if (bt != NULL)
	{
		PostOrder(bt->lchild);//�������������
		PostOrder(bt->rchild);//�������������
		visit(bt->data);//���ʸ����		

	}
}
int length = 0;
int leaf = 0;
void Count(BiNode *bt)
{

	if (bt != NULL)
	{
		length++;//���ʸ����
		if (bt->lchild == NULL&&bt->rchild == NULL)leaf++;
		Count(bt->lchild);//�������������
		Count(bt->rchild);//�������������
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
			DeleteNode(bt->lchild, e);//�������������
			DeleteNode(bt->rchild, e);//�������������
		}


	}

}
int main()
{
	BiNode *T;
	FILE *fp;//�ļ�ָ��
			 //fp=fopen(�ļ�·������ģʽ:r w  a(�ı��ļ�) rb,wr,ab;
			 //fp=fopen("E:\\Data\\BiTree.txt","r");  //����·��
	fp = fopen("Data\\BiTree.txt", "r"); //���·��
	if (fp == NULL)
	{
		printf("�ļ���ʧ��!\b");
		return;
	}

	T = Creat(fp);
	fclose(fp);
	printf("���������");
	PreOrder(T);
	printf("\n");
	printf("���������");
	InOrder(T);
	printf("\n");
	printf("���������");
	PostOrder(T);
	printf("\n");
	Count(T);
	printf("�������Ľ�����ǣ�%d\n", length);
	printf("��������Ҷ������ǣ�%d\n", leaf);

	DeleteNode(T, 'D');
	printf("���������");
	PreOrder(T);
	printf("\n");
}
