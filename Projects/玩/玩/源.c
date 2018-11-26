#include <stdio.h>
#include <string.h>
typedef struct
{
	int No;
	char name[20];
	int Math;
	int English;
	int Computer;
	int sum;
}student;
typedef struct LNode
{
	student data;
	struct LNode *next;
}LNode;
int InsertList(LNode *L)//1.��������ѧ����Ϣ 
{
	LNode *q, *p;
	student e;
	p = L;
	printf("�������ѧ����ѧ�ţ�");
	scanf("%d", &e.No);
	printf("�������ѧ�������֣�");
	scanf("%s", &e.name);
	printf("�������ѧ������ѧ�ɼ���");
	scanf("%d", &e.Math);
	printf("�������ѧ����Ӣ��ɼ���");
	scanf("%d", &e.English);
	printf("�������ѧ���ļ�����ɼ���");
	scanf("%d", &e.Computer);
	e.sum = e.Math + e.English + e.Computer;
	q = (LNode*)malloc(sizeof(LNode));
	if (q == NULL)return 0;
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}
void display(LNode *L)//2.�������ѧ���ɼ�
{
	LNode *q;
	q = L->next;
	printf("\tѧ��\t����\t��ѧ\tӢ��\t�����\t�ܷ�\n");
	while (q != NULL)
	{
		printf("\t%d\t%s\t%d\t%d\t%d\t%d\n", q->data.No
			, q->data.name, q->data.Math, q->data.English
			, q->data.Computer, q->data.sum);
		q = q->next;
	}
}
void Nodispaly(LNode *L)//3.��ѧ�Ų���ĳ��ѧ����Ϣ
{
	int a;
	LNode *q;
	q = L->next;
	printf("������Ҫ���ҵĸ�ѧ����ѧ��:");
	scanf("%d", &a);
	while (q != NULL)
	{
		if (q->data.No == a)
		{
			printf("\tѧ��\t����\t��ѧ\tӢ��\t�����\t�ܷ�\n");
			printf("\t%d\t%s\t%d\t%d\t%d\t%d\n", q->data.No
				, q->data.name, q->data.Math, q->data.English
				, q->data.Computer, q->data.sum);
			break;
		}
		q = q->next;
	}
}
void namedisplay(LNode *L)//4.����������ĳ��ѧ����Ϣ  
{
	char name[20];
	LNode *q;
	q = L->next;
	printf("������Ҫ���ҵĸ�ѧ��������:");
	scanf("%s", name);
	while (q != NULL)
	{
		if (strcmp(name, q->data.name) == 0)
		{
			printf("\tѧ��\t����\t��ѧ\tӢ��\t�����\t�ܷ�\n");
			printf("\t%d\t%s\t%d\t%d\t%d\t%d\n", q->data.No
				, q->data.name, q->data.Math, q->data.English
				, q->data.Computer, q->data.sum);
			break;
		}
		q = q->next;
	}
}
void Nosort(LNode *L)//5.��ѧ�Ŷ�ѧ������
{
	LNode *q, *p;
	student e;
	p = L;
	while (p != NULL)
	{
		p = p->next;
	}
	while (q != L->next)
	{

		for (q = L->next;q->next != p;q = q->next)
		{
			if (q->data.No>q->next->data.No)
			{
				e = q->data;
				q->data = q->next->data;
				q->next->data = e;
			}
		}
		p = q;
	}
}
void sumsort(LNode *L)//6.���ܳɼ���ѧ������
{
	LNode *q, *p;
	student e;
	p = L;
	while (p != NULL)
	{
		p = p->next;
	}
	while (q != L->next)
	{

		for (q = L->next;q->next != p;q = q->next)
		{
			if (q->data.sum>q->next->data.sum)
			{
				e = q->data;
				q->data = q->next->data;
				q->next->data = e;
			}
		}
		p = q;
	}

}
int namerevise(LNode *L)//7.�������޸�ĳ��ѧ����Ϣ
{
	LNode *p;
	int a;
	char name[20];
	p = L->next;
	printf("����Ҫ�޸ĵ�ѧ�������֣�");
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(name, p->data.name) == 0)
		{
			printf("\tѧ��\t����\t��ѧ\tӢ��\t�����\t�ܷ�\n");
			printf("\t%d\t%s\t%d\t%d\t%d\t%d\n", p->data.No
				, p->data.name, p->data.Math, p->data.English
				, p->data.Computer, p->data.sum);
			break;
		}
		p = p->next;
	}
	printf("1��ѧ�� 2������ 3����ѧ�ɼ� 4��Ӣ��ɼ� 5��������ɼ�\n");
	printf("���������ϱ��ѡ��Ҫ�޸ĸ�ѧ������Ϣ��");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("Ҫ�޸�ѧ��Ϊ��");
		scanf("%d", &p->data.No);
		return 1;
		break;
	case 2:
		printf("Ҫ�޸�����Ϊ��");
		scanf("%s", p->data.name);
		return 1;
		break;
	case 3:
		printf("Ҫ�޸���ѧ�ɼ�Ϊ��");
		scanf("%d", &p->data.Math);
		p->data.sum = p->data.Math + p->data.English + p->data.Computer;
		return 1;
		break;

	case 4:
		printf("Ҫ�޸�Ӣ��ɼ�Ϊ��");
		scanf("%d", &p->data.English);
		p->data.sum = p->data.Math + p->data.English + p->data.Computer;
		return 1;
		break;
	case 5:
		printf("Ҫ�޸ļ�����ɼ�Ϊ��");
		scanf("%d", &p->data.Computer);
		p->data.sum = p->data.Math + p->data.English + p->data.Computer;
		return 1;
		break;
	}
}
int Norevise(LNode *L)//8.��ѧ���޸�ĳ��ѧ����Ϣ
{
	LNode *p;
	int a, b;
	p = L->next;
	printf("����Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	scanf("%d", &b);
	while (p != NULL)
	{
		if (b == p->data.No)
		{
			printf("\tѧ��\t����\t��ѧ\tӢ��\t�����\t�ܷ�\n");
			printf("\t%d\t%s\t%d\t%d\t%d\t%d\n", p->data.No
				, p->data.name, p->data.Math, p->data.English
				, p->data.Computer, p->data.sum);
			break;
		}
		p = p->next;
	}
	printf("1��ѧ�� 2������ 3����ѧ�ɼ� 4��Ӣ��ɼ� 5��������ɼ�\n");
	printf("���������ϱ��ѡ��Ҫ�޸ĸ�ѧ������Ϣ��");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("Ҫ�޸�ѧ��Ϊ��");
		scanf("%d", &p->data.No);
		return 1;
		break;
	case 2:
		printf("Ҫ�޸�����Ϊ��");
		scanf("%s", p->data.name);
		return 1;
		break;
	case 3:
		printf("Ҫ�޸���ѧ�ɼ�Ϊ��");
		scanf("%d", &p->data.Math);
		p->data.sum = p->data.Math + p->data.English + p->data.Computer;
		return 1;
		break;

	case 4:
		printf("Ҫ�޸�Ӣ��ɼ�Ϊ��");
		scanf("%d", &p->data.English);
		p->data.sum = p->data.Math + p->data.English + p->data.Computer;
		return 1;
		break;
	case 5:
		printf("Ҫ�޸ļ�����ɼ�Ϊ��");
		scanf("%d", &p->data.Computer);
		p->data.sum = p->data.Math + p->data.English + p->data.Computer;
		return 1;
		break;
	}
}
int namedelete(LNode *L)
{
	LNode *p, *q;
	int a;
	char name[20];
	p = L->next; q = L;
	printf("����Ҫɾ����ѧ����Ϣ��ѧ�������֣�");
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(name, p->data.name) == 0)
		{
			printf("\tѧ��\t����\t��ѧ\tӢ��\t�����\t�ܷ�\n");
			printf("\t%d\t%s\t%d\t%d\t%d\t%d\n", p->data.No
				, p->data.name, p->data.Math, p->data.English
				, p->data.Computer, p->data.sum);
			break;
		}
		p = p->next; q = q->next;
	}
	printf("�Ƿ�ɾ����ѧ����Ϣ������1��2��\t1.�� 2.��\n");
	scanf("%d", &a);
	if (a == 1)
	{
		q->next = p->next;
		return 1;
	}
}
int Nodelete(LNode *L)
{
	LNode *p, *q;
	int a, b;
	p = L->next; q = L;
	printf("����Ҫɾ����ѧ����Ϣ��ѧ����ѧ�ţ�");
	scanf("%d", &b);
	while (p != NULL)
	{
		if (b == p->data.No)
		{
			printf("\tѧ��\t����\t��ѧ\tӢ��\t�����\t�ܷ�\n");
			printf("\t%d\t%s\t%d\t%d\t%d\t%d\n", p->data.No
				, p->data.name, p->data.Math, p->data.English
				, p->data.Computer, p->data.sum);
			break;
		}
		p = p->next; q = q->next;
	}
	printf("�Ƿ�ɾ����ѧ����Ϣ������1��2��\t1.�� 2.��\n");
	scanf("%d", &a);
	if (a == 1)
	{
		q->next = p->next;
		return 1;
	}
}
void menu(LNode *L)
{
	int select;
	int i;int a;
	do
	{
		system("cls");//����
		printf("\t*****************************\n");
		printf("\t*��ӭʹ��ѧ���ɼ�����ϵͳ!  *\n");
		printf("\t*1.��������ѧ����Ϣ         *\n");
		printf("\t*2.�������ѧ���ɼ�         *\n");
		printf("\t*3.��ѧ�Ų���ĳ��ѧ����Ϣ   *\n");
		printf("\t*4.����������ĳ��ѧ����Ϣ   *\n");
		printf("\t*5.��ѧ�Ŷ�ѧ������         *\n");
		printf("\t*6.���ܳɼ���ѧ������       *\n");
		printf("\t*7.�������޸�ĳ��ѧ����Ϣ   *\n");
		printf("\t*8.��ѧ���޸�ĳ��ѧ����Ϣ   *\n");
		printf("\t*9.������ɾ��ĳ��ѧ����Ϣ   *\n");
		printf("\t*10.��ѧ��ɾ��ĳ��ѧ����Ϣ  *\n");
		printf("\t*0.�˳�                     *\n");
		printf("\t*����������ѡ��0-10����   *\n");
		printf("\t*****************************\n");
		printf("\t������ٺʹ��룺");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			InsertList(L);
			system("pause");
			break;
		case 2:
			display(L);
			system("pause");
			break;
		case 3:
			Nodispaly(L);
			system("pause");
			break;
		case 4:
			namedisplay(L);
			system("pause");
			break;
		case 5:
			Nosort(L);
			system("pause");
			break;
		case 6:
			sumsort(L);
			system("pause");
			break;
		case 7:
			i = namerevise(L);
			if (i == 1) printf("�޸ĳɹ���\n");
			system("pause");
			break;
		case 8:
			i = Norevise(L);
			if (i == 1) printf("�޸ĳɹ���\n");
			system("pause");
			break;
		case 9:
			i = namedelete(L);
			if (i == 1) printf("ɾ���ɹ���\n");
			system("pause");
			break;
		case 10:
			i = Nodelete(L);
			if (i == 1) printf("ɾ���ɹ���\n");
			system("pause");
			break;
		case 0:
			//�˳�
			printf("\t�����Ƿ�ȷ��Ҫ�˳�����(����1��2)\n1��ȷ�� 2����");
			//�����û������ѡ��ִ���Ƿ�Ҫ�˳��Ĺ���
			scanf("%d", &a);
			if (a == 1) exit(0);
			else system("pause");
			break;
		}
	} while (select<0 || select>10);
}
int main()
{
	LNode H;
	H.next = NULL;
	while (1)
	{
		menu(&H);
	}

}