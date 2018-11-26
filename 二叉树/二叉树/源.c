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
		if (bt->data == e)T == NULL;
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
//�˵�
void menu(FILE *fp)
{
	ElemType e,f;
	int select;

	do
	{
		system("cls");//����
		printf("\t***********************************\n");
		printf("\t*1.���ļ��ж���������������       *\n");
		printf("\t*2.�������������                 *\n");
		printf("\t*3.�������������                 *\n");
		printf("\t*4.�������������                 *\n");
		printf("\t*5.������������ܽ������Ҷ����� *\n");
		printf("\t*6.ɾ����������ָ�����           *\n");
		printf("\t*7.�ڶ�����ָ����㴦������     *\n");
		printf("\t*8.��������������               *\n");
		printf("\t*0.�˳�                           *\n");
		printf("\t***********************************\n");
		printf("\t������ٺʹ��룺");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			fp = fopen("BiTree.txt", "r");
			if (fp == NULL)
			{
				printf("\t�ļ���ʧ��!\b");
				return;
			}
			T = Creat(fp);
			fclose(fp);
			system("pause");
			break;
		case 2:
			printf("\t���������");
			PreOrder(T);
			printf("\n");
			system("pause");
			break;
		case 3:
			printf("\t���������");
			InOrder(T);
			printf("\n");
			system("pause");
			break;
		case 4:
			printf("\t���������");
			PostOrder(T);
			printf("\n");
			system("pause");
			break;
		case 5:
			Count(T);
			printf("\t�������Ľ�����ǣ�%d\n", length);
			printf("\t��������Ҷ������ǣ�%d\n", leaf);
			system("pause");
			break;
		case 6:
			printf("\t������Ҫɾ���Ľ���ֵ��");
			fflush(stdin);
			e = getchar();
			DeleteNode(T, e);
			printf("\t���������");
			PreOrder(T);
			printf("\n");
			system("pause");
			break;
		case 7:
			printf("Ҫ���Ǹ��ڵ���룺");
			fflush(stdin);
			e=getchar();
			printf("\t������Ҫ����Ľ���ֵ��");
			fflush(stdin);
			f = getchar();
			InsertNode(T, e, f);
			printf("\t���������");
			PreOrder(T);
			printf("\n");
			system("pause");
			break;
		case 8:
			e=Deep(T);
			printf("\t������������ǣ�%d\n", e);
			system("pause");
			break;
		case 0:
			//�˳�
			printf("\t�����Ƿ�ȷ��Ҫ�˳�����(Y/N)");
			//�����û������ѡ��ִ���Ƿ�Ҫ�˳��Ĺ���
			exit(0);
			break;
		}
	} while (select<0 || select>4);
}
int main()
{
	FILE *fp;//�ļ�ָ��
	while (1)
	{
		menu(&fp);
	}

}
