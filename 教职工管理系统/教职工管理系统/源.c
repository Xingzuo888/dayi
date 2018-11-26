#include <stdio.h>
#include <string.h>

typedef struct
{
	int ID;
	char name[20];
	int age;
	int worktime;
	char sex[20];
	char marrige[20];
	int grade;
	int wage;
	char tired[20];
}Workers;
typedef struct LNode
{
	Workers data;
	struct LNode *next;
}LNode;
int found(LNode *L, Workers e)
{
	LNode *p, *q;
	p = L;
	q = (LNode*)malloc(sizeof(LNode));
	if (q == NULL)return 0;
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;

}
int InsertList(LNode *L)//1.��������ְ����Ϣ 
{
	LNode *q, *p;
	Workers e;
	p = L;
	printf("�������ְ���Ĺ��ţ�");
	scanf("%d", &e.ID);
	printf("�������ְ�������֣�");
	scanf("%s", &e.name);
	printf("�������ְ�������䣺");
	scanf("%d", &e.age);
	printf("�������ְ���Ĺ��䣺");
	scanf("%d", &e.worktime);
	printf("�������ְ�����Ա�(�л�Ů)��");
	scanf("%s", &e.sex);
	printf("�������ְ���Ļ���״��(�ѻ��δ��)��");
	scanf("%s", &e.marrige);
	printf("�������ְ���ļ���1~5����");
	scanf("%d", &e.grade);
	printf("��ְ���Ƿ���ְ���ǻ�񣩣�");
	scanf("%s", &e.tired);
	if (strcmp(e.tired, "��") == 0) e.wage = 50;
	else e.wage = 0;
	e.wage = 20 * e.grade + e.wage;
	q = (LNode*)malloc(sizeof(LNode));
	if (q == NULL)return 0;
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}
void display(LNode *L)//2.���ְ����Ϣ
{
	LNode *q;
	q = L->next;
	printf("����\t����\t����\t����\t�Ա�\t����״��  ����\t����\t�Ƿ���ְ\n");
	while (q != NULL)
	{
		printf("%d\t%s\t%d\t%d\t%s\t%s      %d\t%d\t%s\n", q->data.ID
			, q->data.name, q->data.age, q->data.worktime, q->data.sex, q->data.marrige
			, q->data.grade, q->data.wage, q->data.tired);
		q = q->next;
	}
}
void Nodispaly(LNode *L)//3.�����Ų���
{
	int a;
	LNode *q;
	q = L->next;
	printf("������Ҫ���ҵ�ְ���Ĺ��ţ�\n");
	scanf("%d", &a);
	while (q != NULL)
	{
		if (q->data.ID == a)
		{
			printf("����\t����\t����\t����\t�Ա�\t����״��  ����\t����\t�Ƿ���ְ\n");
			printf("%d\t%s\t%d\t%d\t%s\t%s      %d\t%d\t%s\n", q->data.ID
				, q->data.name, q->data.age, q->data.worktime, q->data.sex, q->data.marrige
				, q->data.grade, q->data.wage, q->data.tired);
			break;
		}
		q = q->next;
	}
}
void namedisplay(LNode *L)//4.����������  
{
	char name[20];
	LNode *q;
	q = L->next;
	printf("������Ҫ���ҵĸ�ְ��������:");
	scanf("%s", name);
	while (q != NULL)
	{
		if (strcmp(name, q->data.name) == 0)
		{
			printf("����\t����\t����\t����\t�Ա�\t����״��  ����\t����\t�Ƿ���ְ\n");
			printf("%d\t%s\t%d\t%d\t%s\t%s      %d\t%d\t%s\n", q->data.ID
				, q->data.name, q->data.age, q->data.worktime, q->data.sex, q->data.marrige
				, q->data.grade, q->data.wage, q->data.tired);
			break;
		}
		q = q->next;
	}
}
void Nosort(LNode *L)//5.����������
{
	LNode *q, *p;
	Workers e;
	p = L;
	while (p != NULL)
	{
		p = p->next;
	}
	while (q != L->next)
	{

		for (q = L->next;q->next != p;q = q->next)
		{
			if (q->data.ID>q->next->data.ID)
			{
				e = q->data;
				q->data = q->next->data;
				q->next->data = e;
			}
		}
		p = q;
	}
}
void sumsort(LNode *L)//6.����������
{
	LNode *q, *p;
	Workers e;
	p = L;
	while (p != NULL)
	{
		p = p->next;
	}
	while (q != L->next)
	{

		for (q = L->next;q->next != p;q = q->next)
		{
			if (q->data.grade>q->next->data.grade)
			{
				e = q->data;
				q->data = q->next->data;
				q->next->data = e;
			}
		}
		p = q;
	}

}
int Norevise(LNode *L)//8.�������޸�ĳ����Ϣ
{
	LNode *p;
	int a, b;
	p = L->next;
	printf("����Ҫ�޸ĵ�ְ���Ĺ��ţ�");
	scanf("%d", &b);
	while (p != NULL)
	{
		if (b == p->data.ID)
		{
			printf("����\t����\t����\t����\t�Ա�\t����״��  ����\t����\t�Ƿ���ְ\n");
			printf("%d\t%s\t%d\t%d\t%s\t%s      %d\t%d\t%s\n", p->data.ID
				, p->data.name, p->data.age, p->data.worktime, p->data.sex, p->data.marrige
				, p->data.grade, p->data.wage, p->data.tired);
			break;
		}
		p = p->next;
	}
	printf("1.���� 2.���� 3.���� 4.���� 5.�Ա� 6.����״�� 7.����  8.�Ƿ���ְ\n");
	printf("���������ϱ��ѡ��Ҫ�޸ĸ�ְ������Ϣ��");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("Ҫ�޸Ĺ���Ϊ��");
		scanf("%d", &p->data.ID);
		return 1;
		break;
	case 2:
		printf("Ҫ�޸�����Ϊ��");
		scanf("%s", p->data.name);
		return 1;
		break;
	case 3:
		printf("Ҫ�޸�����Ϊ��");
		scanf("%d", &p->data.age);
		return 1;
		break;
	case 4:
		printf("Ҫ�޸Ĺ���Ϊ��");
		scanf("%d", &p->data.worktime);
		return 1;
		break;
	case 5:
		printf("Ҫ�Ա�Ϊ(�л�Ů)��");
		scanf("%s", &p->data.sex);
		return 1;
		break;
	case 6:
		printf("Ҫ����״��Ϊ(�ѻ��δ��)��");
		scanf("%s", &p->data.marrige);
		return 1;
		break;
	case 7:
		printf("Ҫ�޸ļ���Ϊ��1~5����");
		scanf("%d", &p->data.grade);
		if (strcmp(p->data.tired, "��") == 0) p->data.wage = 50;
		else p->data.wage = 0;
		p->data.wage = 20 * p->data.grade + p->data.wage;
		return 1;
		break;
	case 8:
		printf("Ҫ�޸��Ƿ���ְΪ���ǻ�񣩣�");
		scanf("%s", &p->data.tired);
		if (strcmp(p->data.tired, "��") == 0) p->data.wage = 50;
		else p->data.wage = 0;
		p->data.wage = 20 * p->data.grade + p->data.wage;
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
	printf("����Ҫɾ����ְ����Ϣ��ְ�������֣�");
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(name, p->data.name) == 0)
		{
			printf("����\t����\t����\t����\t�Ա�\t����״��  ����\t����\t�Ƿ���ְ\n");
			printf("%d\t%s\t%d\t%d\t%s\t%s      %d\t%d\t%s\n", p->data.ID
				, p->data.name, p->data.age, p->data.worktime, p->data.sex, p->data.marrige
				, p->data.grade, p->data.wage, p->data.tired);
			break;
		}
		p = p->next; q = q->next;
	}
	printf("�Ƿ�ɾ����ְ����Ϣ������1��2��1.�� 2.��:");
	scanf("%d", &a);
	if (a == 1)
	{
		q->next = p->next;
		printf("ɾ���ɹ���\n");
		return 1;
	}
}
int Nodelete(LNode *L)//������ɾ��
{
	LNode *p, *q;
	int a, b;
	p = L->next; q = L;
	printf("����Ҫɾ����ְ����Ϣ��ְ���Ĺ��ţ�");
	scanf("%d", &b);
	while (p != NULL)
	{
		if (b == p->data.ID)
		{
			printf("����\t����\t����\t����\t�Ա�\t����״��  ����\t����\t�Ƿ���ְ\n");
			printf("%d\t%s\t%d\t%d\t%s\t%s      %d\t%d\t%s\n", p->data.ID
				, p->data.name, p->data.age, p->data.worktime, p->data.sex, p->data.marrige
				, p->data.grade, p->data.wage, p->data.tired);
			break;
		}
		p = p->next; q = q->next;
	}
	printf("�Ƿ�ɾ����ְ����Ϣ������1��2��1.�� 2.��:");
	scanf("%d", &a);
	if (a == 1)
	{
		q->next = p->next;
		printf("ɾ���ɹ���\n");
		return 1;
	}
}
//��ȡ��Ϣ
void rfile(LNode *L) {
	FILE *fp;
	LNode *p = L;
	LNode *p1;
	if ((fp = fopen("file.txt", "r")) != NULL) {
		p->next = NULL;
		while (!feof(fp)) {
			p1 = (LNode*)malloc(sizeof(LNode));
			p1->next = NULL;
			fread(&p1->data, sizeof(p->data), 1, fp);
			if (strlen(p1->data.name) < 20) {
				p1->next = p->next;
				p->next = p1;
			}
			else free(p1);
		}
		fclose(fp);
	}
	else {
		printf("���ļ�ʧ�ܣ�");
	}
}
//��ʽ��д����Ϣ
void wfile(LNode *L) {
	FILE *fp;
	if ((fp = fopen("file.txt", "w")) != NULL) {
		LNode *p = L->next;
		while (p != NULL) {
			fwrite(&p->data, sizeof(p->data), 1, fp);
			p = p->next;
		}
		fclose(fp);
	}
	else printf("��ʽ������ѧ����Ϣʧ�ܣ�");
}

void menu(LNode *L)
{
	FILE *fp;
	int select;
	int a, b;
	char code1[10],code[10];
	/*Workers worker1 = { 1,"����",34,6,"��","�ѻ�",4,80,"��" };
	Workers worker2 = { 2,"����",37,4,"��","�ѻ�",3,110,"��" };
	Workers worker3 = { 3,"��ٻ",22,3,"Ů","�ѻ�",1,20,"��" };
	Workers worker4 = { 4,"����",44,15,"��","δ��",5,150,"��" };*/
	do
	{
		system("cls");//����
		printf("\t*******************************************\n");
		printf("\t*         ��ӭʹ�ñ�ְ����Ϣ����ϵͳ      *\n");
		printf("\t*1.д����Ϣ           2.��ѯְ����Ϣ      *\n");
		printf("\t*3.�޸�ְ����Ϣ       4.���ְ����Ϣ      *\n");
		printf("\t*5.ɾ��ְ����Ϣ       6.�����Ŷ���Ϣ����  *\n");
		printf("\t*7.���������Ϣ����   8.�޸Ĺ���Ա����    *\n");
		printf("\t*9.�˳�����           10.��ȡ��Ϣ         *\n");
		printf("\t*******************************************\n");
		printf("\t��������Ӧ��ţ�");
		scanf("%d", &select);
		switch (select)
		{
		case 10:
			rfile(L);
			system("pause");
			break;
		case 1:
			wfile(L);
			system("pause");
			break;
		case 4:
			InsertList(L);
			system("pause");
			break;
		case 2:
			printf("1.�����Ų�ѯ 2.��������ѯ 3.��ѯ����ְ����Ϣ ��ѡ��1��2��3��");
			scanf("%d", &b);
			if (b == 1) Nodispaly(L);
			if (b == 2) namedisplay(L);
			if (b == 3) display(L);
			system("pause");
			break;
		/*case 1:
			found(L, worker1);
			found(L, worker2);
			found(L, worker3);
			found(L, worker4);
			printf("�����ɹ���\n");
			system("pause");
			break;*/
		case 3:
			Norevise(L);
			printf("�޸ĳɹ���");
			system("pause");
			break;
		case 5:
			printf("1.������ɾ�� 2.������ɾ�� ��ѡ��1��2��");
			scanf("%d", &b);
			if (b == 1) Nodelete(L);
			if (b == 2) namedelete(L);
			system("pause");
			break;
		case 6:
			Nosort(L);
			printf("����ɹ�!\n");
			system("pause");
			break;
		case 7:
			sumsort(L);
			printf("����ɹ�!\n");
			system("pause");
			break;
		case 8:
			printf("������ԭʼ����:");
			scanf("%s", code1);
			if ((fp = fopen("code.txt", "r")) != NULL) {
				fgets(code, 10, fp);
			}
			else printf("��ȡ����");
			fclose(fp);
			if (strcmp(code1, code) == 0)
			{
				printf("�����������룺");
				scanf("%s", code1);
				strcpy(code, code1);
				if ((fp = fopen("code.txt", "w")) != NULL) {
					fputs(code, fp);
				}
				else printf("д�����");
				fclose(fp);
				printf("�޸ĳɹ���");
			}
			else printf("�������");
			system("pause");
			break;
		case 9:
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
	FILE *fp;
	int a;
	char code[10];
	char code1[10];
	LNode H;
	H.next = NULL;
	printf("��ӭʹ�ñ�ְ����Ϣ����ϵͳ\n");
	if ((fp = fopen("code.txt", "r")) != NULL) {
		fgets(code, 10, fp);
	}
	else printf("��ȡ����");
	fclose(fp);
	for (a = 3;a>0;a--)
	{
		printf("���������룺");
		scanf("%s", code1);
		if (strcmp(code1, code) == 0)
		{
			printf("���ǺϷ��û���\n");
			system("pause");
			while (1)
			{
				menu(&H);
			}
		}
		else printf("��������㻹��%d�λ���\n", a - 1);
	}
	printf("���ǷǷ��û����� ����������򼴽��رգ���\n");

}
