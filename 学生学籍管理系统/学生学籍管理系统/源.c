#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct score {
	int math;
	int english;
	int compute;
	int all;//�ܳɼ�
}scores;
typedef struct teachin {
	char classes[20];//���̵İ༶
	char place[20];//����
	char date[30];//ʱ��
}teachin;
//ѧ��������Ϣ
typedef struct {
	int stuID;//ѧ��
	char classes[20];//�༶
	char name[20];//����
	char sex[5];//�Ա�
	char date[20];//��������
	char ID[30];//���֤
	char indate[20];//��ѧʱ��
	char ps[20];//������ò
	char home[100];//��ͥסַ
	char np[20];//����
	char postalcode[10];//��������
	char nation[20];//����
	char graduation[20];//��ҵ֤����
	char faculty[50];//����Ժϵ
	scores score;//�ɼ�
	int Ccredit;//����ѧ��
	int Rcredit;//����ѧ��
}Student;
//��ʦ������Ϣ
typedef struct {
	int ID;//�̹���
	char name[20];//����
	char sex[5];//�Ա�
	char pt[20];//ְ��
	teachin teach;//�ڿ���Ϣ
	char faculty[20];//����Ժϵ
	char phone[20];//�绰
}Teacher;
typedef struct LNode1 {
	Student data;
	struct LNode1 *next;
}LNode1;
typedef struct LNode2 {
	Teacher data;
	struct LNode2 *next;
}LNode2;
//������Ϣ/
int InsertList(LNode1 *P, LNode2 *Q) {
	int i, j, k;
	LNode1 *p, *a;
	LNode2 *q, *b;
	Student e;
	Teacher r;
	p = P;
	q = Q;
	P->next = NULL;
	q->next = NULL;
	do {
		int l = 1;
		system("cls");
		printf("1.����ѧ����Ϣ\n");
		printf("2.�����ʦ��Ϣ\n");
		printf("0.����\n");
		printf("������ѡ��(0-2)��");
		scanf("%d", &i);
		while (i < 0 || i>2) {
			printf("��������  ���������룺");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i) {
		case 1:

			printf("��������Ӷ��ٸ�ѧ����Ϣ��");
			scanf("%d", &k);
			while (l <= k) {

				printf("�������%d��ѧ������Ϣ��\n", l);
				printf("ѧ�ţ�");
				scanf("%d", &e.stuID);
				printf("�༶��");
				scanf("%s", &e.classes);
				printf("������");
				scanf("%s", &e.name);
				printf("�Ա�");
				scanf("%s", &e.sex);
				printf("��������(�磺2000-01-01)��");
				scanf("%s", &e.date);
				printf("���֤��");
				scanf("%s", &e.ID);
				printf("��ѧʱ�䣨�磺2000-01-01����");
				scanf("%s", &e.indate);
				printf("������ò��");
				scanf("%s", &e.ps);
				printf("��ͥ��ַ��");
				scanf("%s", &e.home);
				printf("���᣺");
				scanf("%s", &e.np);
				printf("�������룺");
				scanf("%s", &e.postalcode);
				printf("���壺");
				scanf("%s", &e.nation);
				printf("��ҵ֤���룺");
				scanf("%s", &e.graduation);
				printf("����Ժϵ��");
				scanf("%s", &e.faculty);
				e.score.math = 0;
				e.score.english = 0;
				e.score.compute = 0;
				e.score.all = 0;
				e.Rcredit = 0;
				e.Ccredit = 0;
				a = (LNode1*)malloc(sizeof(LNode1));
				if (a == NULL)return 0;
				a->data = e;
				a->next = p->next;
				p->next = a;
				l++;
			}

			break;
		case 2:

			printf("��������Ӷ��ٸ���ʦ��Ϣ��");
			scanf("%d", &k);
			while (l <= k) {

				printf("�������%d����ʦ����Ϣ��\n", l);
				printf("�̹��ţ�");
				scanf("%d", &r.ID);
				printf("������");
				scanf("%s", &r.name);
				printf("�Ա�");
				scanf("%s", &r.sex);
				printf("ְ�ƣ�");
				scanf("%s", &r.pt);
				printf("�ڿ���Ϣ( ���̵İ༶ )��");
				scanf("%s", &r.teach.classes);
				printf("�ڿ���Ϣ( ���� )��");
				scanf("%s", &r.teach.place);
				printf("�ڿ���Ϣ( ʱ�� )��");
				scanf("%s", &r.teach.date);
				printf("����Ժϵ��");
				scanf("%s", &r.faculty);
				printf("�绰���룺");
				scanf("%s", &r.phone);
				b = (LNode2*)malloc(sizeof(LNode2));
				if (b == NULL)return 0;
				b->data = r;
				b->next = q->next;
				q->next = b;
				l++;
			}

			break;
		}
		printf("�Ƿ���������Ϣ��1.��  2.��");
		scanf("%d", &j);
		while (j < 1 || j>2) {
			printf("��������  ���������룺");
			scanf("%d", &j);
		}
	} while (j == 1);
	return 1;
}

//�ɼ�����/
int Insertscores(LNode1 *P) {
	LNode1 *p;
	int i, j, k, s, d, f, m;
	char a[10];
	do {
		p = P->next;
		system("cls");
		printf("****************************\n");
		printf("*   1.��ѧ�Ų���           *\n");
		printf("*   2.����������           *\n");
		printf("*   0.����                 *\n");
		printf("****************************\n");
		printf("��ѡ��0-2����");
		scanf("%d", &m);
		while (m < 0 || m>2) {
			printf("��������  ���������룺");
			scanf("%d", &m);
		}
		if (m == 0)return 1;
		switch (m) {
		case 1:
			printf("������Ҫ��ӳɼ���ѧ����ѧ�ţ�");
			scanf("%d", &i);
			while (p != NULL) {
				if (p->data.stuID == i) {
					printf("\n");
					printf("ѧ��     \t����  \t�༶     \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute);
					printf("-------------------------------------------------------------------------------------------\n");
					printf("\n");
					printf("*********************************************************\n");
					printf("*   1.��ѧ�ɼ�    2.Ӣ��ɼ�        3.������ɼ�        *\n");
					printf("*   4.ȫ��        0.�˳�                                *\n");
					printf("*********************************************************\n");
					printf("��ѡ����ӳɼ���");
					scanf("%d", &k);
					while (k < 0 || k>4) {
						printf("��������  ���������룺");
						scanf("%d", &k);
					}
					switch (k) {
					case 1:
						printf("��������ѧ�ɼ���");
						scanf("%d", &p->data.score.math);
						printf("��ӳɹ���");break;
					case 2:
						printf("������Ӣ��ɼ���");
						scanf("%d", &p->data.score.english);
						printf("��ӳɹ���");break;
					case 3:
						printf("�����������ɼ���");
						scanf("%d", &p->data.score.compute);
						printf("��ӳɹ���");break;
					case 4:
						printf("��������ѧ�ɼ���");
						scanf("%d", &p->data.score.math);
						printf("������Ӣ��ɼ���");
						scanf("%d", &p->data.score.english);
						printf("�����������ɼ���");
						scanf("%d", &p->data.score.compute);
						printf("��ӳɹ���");break;
					case 0:
						break;
					}
					if (p->data.score.math >= 60)s = 4;
					else s = 0;
					if (p->data.score.english >= 60)d = 4;
					else d = 0;
					if (p->data.score.compute >= 60)f = 4;
					else f = 0;
					p->data.Ccredit = s + d + f;
					p->data.Rcredit = 12 - p->data.Ccredit;
					break;
				}
				p = p->next;
			}
			if (p == NULL) {
				printf("���������Ҳ�����ѧ����\n");
			}
			break;
		case 2:
			printf("������Ҫ��ӳɼ���ѧ����������");
			scanf("%s", &a);
			while (p != NULL) {
				if (strcmp(p->data.name, a) == 0) {
					printf("\n");
					printf("ѧ��     \t����  \t�༶     \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute);
					printf("-------------------------------------------------------------------------------------------\n");
					printf("\n");
					printf("*********************************************************\n");
					printf("*   1.��ѧ�ɼ�    2.Ӣ��ɼ�        3.������ɼ�        *\n");
					printf("*   4.ȫ��        0.�˳�                                *\n");
					printf("*********************************************************\n");
					printf("��ѡ����ӳɼ���");
					scanf("%d", &k);
					while (k < 0 || k>4) {
						printf("��������  ���������룺");
						scanf("%d", &k);
					}
					switch (k) {
					case 1:
						printf("��������ѧ�ɼ���");
						scanf("%d", &p->data.score.math);
						printf("��ӳɹ���");break;
					case 2:
						printf("������Ӣ��ɼ���");
						scanf("%d", &p->data.score.english);
						printf("��ӳɹ���");break;
					case 3:
						printf("�����������ɼ���");
						scanf("%d", &p->data.score.compute);
						printf("��ӳɹ���");break;
					case 4:
						printf("��������ѧ�ɼ���");
						scanf("%d", &p->data.score.math);
						printf("������Ӣ��ɼ���");
						scanf("%d", &p->data.score.english);
						printf("�����������ɼ���");
						scanf("%d", &p->data.score.compute);
						printf("��ӳɹ���");break;
					case 0:
						break;
					}
					if (p->data.score.math >= 60)s = 4;
					else s = 0;
					if (p->data.score.english >= 60)d = 4;
					else d = 0;
					if (p->data.score.compute >= 60)f = 4;
					else f = 0;
					p->data.Ccredit = s + d + f;
					p->data.Rcredit = 12 - p->data.Ccredit;
					break;
				}
				p = p->next;
			}
			if (p == NULL) {
				printf("���������Ҳ�����ѧ����\n");
			}
			break;
		}
		printf("\n");
		printf("�Ƿ������ӳɼ�( 1.��  2.��)��");
		scanf("%d", &j);
		while (j < 1 || j>2) {
			printf("��������  ���������룺");
			scanf("%d", &j);
		}
	} while (j == 1);
	return 1;
}

//�޸���Ϣ/
int Modify(LNode1 *P, LNode2 *Q) {
	LNode1 *p;
	LNode2 *q;
	int i, j, k, l, m;
	char a[10];
	do {
		p = P->next;
		q = Q->next;
		system("cls");
		printf("ѡ��Ҫ�޸ĵ���Ϣ(1.ѧ����Ϣ  2.��ʦ��Ϣ  0.���� )��");
		scanf("%d", &i);
		while (i < 0 || i>2) {
			printf("��������\n");
			printf("���������룺");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i) {
		case 1:
			printf("1.��ѧ�Ų���   2.����������  ��  ");
			scanf("%d", &m);
			while (m < 1 || m>2) {
				printf("��������\n");
				printf("���������룺");
				scanf("%d", &m);
			}
			switch (m) {
			case 1:
				printf("����Ҫ�޸�ѧ����Ϣ��ѧ�ţ�");
				scanf("%d", &j);
				while (p != NULL) {
					if (p->data.stuID == j) {
						printf("\n");
						printf("ѧ��      \t�༶    \t���� \t�Ա� \t��������      \t���֤��              \t��ѧʱ��     \t������ò    \t��ͥסַ                 \t����\t�������� \t���� \t��ҵ֤����  \t����Ժϵ\n");
						printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("%-10d\t%-10s\t%-5s\t%-2s\t%-15s\t%-20s\t%-15s\t%-10s\t%-30s\t%-5s\t%-10s\t%-5s\t%-10s\t%-10s\n", p->data.stuID, p->data.classes, p->data.name, p->data.sex, p->data.date, p->data.ID,
							p->data.indate, p->data.ps, p->data.home, p->data.np, p->data.postalcode, p->data.nation, p->data.graduation, p->data.faculty);
						printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("\n");
						printf("************************************************************************************************\n");
						printf("**  1.ѧ��   2.�༶  3.����   4.�Ա�     5.��������  6.���֤��   	7.��ѧʱ��    8.������ò  **\n");
						printf("**  9.��ͥסַ    10.����   11.��������  12.����     13.��ҵ֤����   14.����Ժϵ   0.�˳�      **\n");
						printf("************************************************************************************************\n");
						printf("��ѡ��Ҫ�޸ĵ���Ϣ��");
						scanf("%d", &k);
						while (k < 0 || k>14) {
							printf("��������\n");
							printf("���������룺");
							scanf("%d", &k);
						}
						switch (k) {
						case 1:
							printf("��������ĺ��ѧ�ţ�");
							scanf("%d", &p->data.stuID);
							break;
						case 2:
							printf("��������ĺ�İ༶��");
							scanf("%s", &p->data.classes);
							break;
						case 3:
							printf("��������ĺ��������");
							scanf("%s", &p->data.name);
							break;
						case 4:
							printf("��������ĺ���Ա�");
							scanf("%s", &p->data.sex);
							break;
						case 5:
							printf("��������ĺ�ĳ�������(2000-01-01)��");
							scanf("%s", &p->data.date);
							break;
						case 6:
							printf("��������ĺ�����֤�ţ�");
							scanf("%s", &p->data.ID);
							break;
						case 7:
							printf("��������ĺ����ѧʱ��(2000-01-01)��");
							scanf("%s", &p->data.indate);
							break;
						case 8:
							printf("��������ĺ��������ò��");
							scanf("%s", &p->data.ps);
							break;
						case 9:
							printf("��������ĺ�ļ�ͥסַ��");
							scanf("%s", &p->data.home);
							break;
						case 10:
							printf("��������ĺ�ļ��᣺");
							scanf("%s", &p->data.np);
							break;
						case 11:
							printf("��������ĺ���������룺");
							scanf("%s", &p->data.postalcode);
							break;
						case 12:
							printf("��������ĺ�����壺");
							scanf("%s", &p->data.nation);
							break;
						case 13:printf("��������ĺ�ı�ҵ֤���룺");
							scanf("%s", &p->data.graduation);
							break;
						case 14:
							printf("��������ĺ������Ժϵ��");
							scanf("%s", &p->data.faculty);
							break;
						case 0:
							break;
						}
						break;
					}
					p = p->next;
				}
				if (p == NULL) printf("�Ҳ���Ҫ�޸ĵ�ѧ����");
				break;
			case 2:
				printf("����Ҫ�޸�ѧ����Ϣ��������");
				scanf("%s", a);
				while (p != NULL) {
					if (strcmp(p->data.name, a) == 0) {
						printf("\n");
						printf("ѧ��      \t�༶    \t���� \t�Ա� \t��������      \t���֤��              \t��ѧʱ��     \t������ò    \t��ͥסַ                 \t����\t�������� \t���� \t��ҵ֤����  \t����Ժϵ\n");
						printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("%-10d\t%-10s\t%-5s\t%-2s\t%-15s\t%-20s\t%-15s\t%-10s\t%-30s\t%-5s\t%-10s\t%-5s\t%-10s\t%-10s\n", p->data.stuID, p->data.classes, p->data.name, p->data.sex, p->data.date, p->data.ID,
							p->data.indate, p->data.ps, p->data.home, p->data.np, p->data.postalcode, p->data.nation, p->data.graduation, p->data.faculty);
						printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("\n");
						printf("************************************************************************************************\n");
						printf("**  1.ѧ��   2.�༶  3.����   4.�Ա�      5.��������  6.���֤��   	7.��ѧʱ��    8.������ò  **\n");
						printf("**  9.��ͥסַ    10.����   11.��������  12.����     13.��ҵ֤����   14.����Ժϵ   0.�˳�      **\n");
						printf("************************************************************************************************\n");
						printf("��ѡ��Ҫ�޸ĵ���Ϣ��");
						scanf("%d", &k);
						while (k < 0 || k>14) {
							printf("��������\n");
							printf("���������룺");
							scanf("%d", &k);
						}
						switch (k) {
						case 1:
							printf("��������ĺ��ѧ�ţ�");
							scanf("%d", &p->data.stuID);
							break;
						case 2:
							printf("��������ĺ�İ༶��");
							scanf("%s", &p->data.classes);
							break;
						case 3:
							printf("��������ĺ��������");
							scanf("%s", &p->data.name);
							break;
						case 4:
							printf("��������ĺ���Ա�");
							scanf("%s", &p->data.sex);
							break;
						case 5:
							printf("��������ĺ�ĳ�������(2000-01-01)��");
							scanf("%s", &p->data.date);
							break;
						case 6:
							printf("��������ĺ�����֤�ţ�");
							scanf("%s", &p->data.ID);
							break;
						case 7:
							printf("��������ĺ����ѧʱ��(2000-01-01)��");
							scanf("%s", &p->data.indate);
							break;
						case 8:
							printf("��������ĺ��������ò��");
							scanf("%s", &p->data.ps);
							break;
						case 9:
							printf("��������ĺ�ļ�ͥסַ��");
							scanf("%s", &p->data.home);
							break;
						case 10:
							printf("��������ĺ�ļ��᣺");
							scanf("%s", &p->data.np);
							break;
						case 11:
							printf("��������ĺ���������룺");
							scanf("%s", &p->data.postalcode);
							break;
						case 12:
							printf("��������ĺ�����壺");
							scanf("%s", &p->data.nation);
							break;
						case 13:printf("��������ĺ�ı�ҵ֤���룺");
							scanf("%s", &p->data.graduation);
							break;
						case 14:
							printf("��������ĺ������Ժϵ��");
							scanf("%s", &p->data.faculty);
							break;
						case 0:
							break;
						}
						break;
					}
					p = p->next;
				}
				if (p == NULL) printf("�Ҳ���Ҫ�޸ĵ�ѧ����");
				break;
			}
			break;
		case 2:
			printf("1.���̹��Ų���   2.����������  ��  ");
			scanf("%d", &m);
			while (m < 1 || m>2) {
				printf("��������\n");
				printf("���������룺");
				scanf("%d", &m);
			}
			switch (m) {
			case 1:
				printf("����Ҫ�޸Ľ�ʦ��Ϣ�Ľ̹��ţ�");
				scanf("%d", &j);
				while (q != NULL) {
					if (q->data.ID == j) {
						printf("\n");
						printf("�̹���     \t����\t�Ա� \tְ��       \t�ڿ���Ϣ(�༶)  \t�ڿ���Ϣ(�ص�)   \t�ڿ���Ϣ(ʱ��)             \t����Ժϵ  \t��ϵ�绰\n");
						printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("%-10d\t%-5s\t%-2s\t%-10s\t%-20s\t%-20s\t%-25s\t%-10s\t%-15s\n", q->data.ID, q->data.name, q->data.sex, q->data.pt,
							q->data.teach.classes, q->data.teach.place, q->data.teach.date, q->data.faculty, q->data.phone);
						printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("\n");
						printf("**********************************************************************************************************************************\n");
						printf("**    1.�̹���  2.����  3.�Ա�  4.ְ��  5.�ڿ���Ϣ(�༶)  6.�ڿ���Ϣ(�ص�)  7.�ڿ���Ϣ(ʱ��)  8.����Ժϵ  9.��ϵ�绰  0.�˳�    **\n");
						printf("**********************************************************************************************************************************\n");
						printf("��ѡ��Ҫ�޸ĵ���Ϣ��");
						scanf("%d", &k);
						while (k < 0 || k>9) {
							printf("��������\n");
							printf("���������룺");
							scanf("%d", &k);
						}
						switch (k) {
						case 1:
							printf("�������޸ĺ�Ľ̹��ţ�");
							scanf("%d", &q->data.ID);
							break;
						case 2:
							printf("�������޸ĺ��������");
							scanf("%s", &q->data.name);
							break;
						case 3:
							printf("�������޸ĺ���Ա�");
							scanf("%s", &q->data.sex);
							break;
						case 4:
							printf("�������޸ĺ��ְ�ƣ�");
							scanf("%s", &q->data.pt);
							break;
						case 5:
							printf("�������޸ĺ������Ժϵ(���̵İ༶)��");
							scanf("%s", &q->data.teach.classes);
							break;
						case 6:
							printf("�������޸ĺ������Ժϵ(�Ͽν���)��");
							scanf("%s", &q->data.teach.place);
							break;
						case 7:
							printf("�������޸ĺ������Ժϵ(�Ͽ�ʱ��)��");
							scanf("%s", &q->data.teach.date);
							break;
						case 8:
							printf("�������޸ĺ������Ժϵ��");
							scanf("%s", &q->data.faculty);
							break;
						case 9:
							printf("�������޸ĺ����ϵ�绰��");
							scanf("%s", &q->data.phone);
							break;
						case 0:

							break;
						}
						break;
					}
					q = q->next;
				}
				if (q == NULL) printf("�Ҳ�����ʦ��Ϣ��");
				break;
			case 2:
				printf("����Ҫ�޸Ľ�ʦ��Ϣ��������");
				scanf("%s", &a);
				while (q != NULL) {
					if (strcmp(q->data.name, a) == 0) {
						printf("\n");
						printf("�̹���     \t����\t�Ա� \tְ��       \t�ڿ���Ϣ(�༶)  \t�ڿ���Ϣ(�ص�)   \t�ڿ���Ϣ(ʱ��)             \t����Ժϵ  \t��ϵ�绰\n");
						printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("%-10d\t%-5s\t%-2s\t%-10s\t%-20s\t%-20s\t%-25s\t%-10s\t%-15s\n", q->data.ID, q->data.name, q->data.sex, q->data.pt,
							q->data.teach.classes, q->data.teach.place, q->data.teach.date, q->data.faculty, q->data.phone);
						printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("\n");
						printf("**********************************************************************************************************************************\n");
						printf("**    1.�̹���  2.����  3.�Ա�  4.ְ��  5.�ڿ���Ϣ(�༶)  6.�ڿ���Ϣ(�ص�)  7.�ڿ���Ϣ(ʱ��)  8.����Ժϵ  9.��ϵ�绰  0.�˳�    **\n");
						printf("**********************************************************************************************************************************\n");
						printf("��ѡ��Ҫ�޸ĵ���Ϣ��");
						scanf("%d", &k);
						while (k < 0 || k>9) {
							printf("��������\n");
							printf("���������룺");
							scanf("%d", &k);
						}
						switch (k) {
						case 1:
							printf("�������޸ĺ�Ľ̹��ţ�");
							scanf("%d", &q->data.ID);
							break;
						case 2:
							printf("�������޸ĺ��������");
							scanf("%s", &q->data.name);
							break;
						case 3:
							printf("�������޸ĺ���Ա�");
							scanf("%s", &q->data.sex);
							break;
						case 4:
							printf("�������޸ĺ��ְ�ƣ�");
							scanf("%s", &q->data.pt);
							break;
						case 5:
							printf("�������޸ĺ������Ժϵ(���̵İ༶)��");
							scanf("%s", &q->data.teach.classes);
							break;
						case 6:
							printf("�������޸ĺ������Ժϵ(�Ͽν���)��");
							scanf("%s", &q->data.teach.place);
							break;
						case 7:
							printf("�������޸ĺ������Ժϵ(�Ͽ�ʱ��)��");
							scanf("%s", &q->data.teach.date);
							break;
						case 8:
							printf("�������޸ĺ������Ժϵ��");
							scanf("%s", &q->data.faculty);
							break;
						case 9:
							printf("�������޸ĺ����ϵ�绰��");
							scanf("%s", &q->data.phone);
							break;
						case 0:

							break;
						}
						break;
					}
					q = q->next;
				}
				if (q == NULL) printf("�Ҳ�����ʦ��Ϣ��");
				break;
			}
			break;
		}
		printf("�Ƿ�����޸���Ϣ��1.��  2.��");
		scanf("%d", &j);
		while (j < 1 || j>2) {
			printf("��������  ���������룺");
			scanf("%d", &j);
		}
	} while (j == 1);
	return 1;
}

//�޸ĳɼ�/
int Modifyscores(LNode1 *P) {
	LNode1 *p;
	char a[10];
	int i, j, k, m;
	int s, d, f;
	do {
		p = P->next;
		system("cls");
		printf("****************************\n");
		printf("*   1.��ѧ�Ų���           *\n");
		printf("*   2.����������           *\n");
		printf("*   0.����                 *\n");
		printf("****************************\n");
		printf("��ѡ��0-2����");
		scanf("%d", &m);
		while (m < 0 || m>2) {
			printf("��������  ���������룺");
			scanf("%d", &m);
		}
		if (m == 0)return 1;
		switch (m) {
		case 1:
			printf("������Ҫ�޸�ѧ����ѧ�ţ�");
			scanf("%d", &i);
			while (p != NULL) {
				if (p->data.stuID == i) {
					printf("\n");
					printf("ѧ��     \t����  \t�༶     \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute);
					printf("-------------------------------------------------------------------------------------------\n");
					printf("\n");
					printf("*********************************************************\n");
					printf("*   1.��ѧ�ɼ�    2.Ӣ��ɼ�        3.������ɼ�        *\n");
					printf("*   4.ȫ��        0.�˳�                                *\n");
					printf("*********************************************************\n");
					printf("������Ҫ�޸ĵĳɼ���");
					scanf("%d", &j);
					while (j < 0 || j>4) {
						printf("��������  ���������룺");
						scanf("%d", &j);
					}
					switch (j) {
					case 1:
						printf("��������ѧ�ɼ���");
						scanf("%d", &p->data.score.math);
						printf("�޸ĳɹ���");
						break;
					case 2:
						printf("������Ӣ��ɼ���");
						scanf("%d", &p->data.score.english);
						printf("�޸ĳɹ���");
						break;
					case 3:
						printf("�����������ɼ���");
						scanf("%d", &p->data.score.compute);
						printf("�޸ĳɹ���");
						break;
					case 4:
						printf("��������ѧ�ɼ���");
						scanf("%d", &p->data.score.math);
						printf("������Ӣ��ɼ���");
						scanf("%d", &p->data.score.english);
						printf("�����������ɼ���");
						scanf("%d", &p->data.score.compute);
						printf("�޸ĳɹ���");
						break;
					case 0:
						break;
					}
					if (p->data.score.math >= 60)s = 4;
					else s = 0;
					if (p->data.score.english >= 60)d = 4;
					else d = 0;
					if (p->data.score.compute >= 60)f = 4;
					else f = 0;
					p->data.Ccredit = s + d + f;
					p->data.Rcredit = 12 - p->data.Ccredit;

					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("�Ҳ���ѧ��Ϊ%d��ѧ��\n", i);
			break;
		case 2:
			printf("������Ҫ�޸�ѧ����������");
			scanf("%s", &a);
			while (p != NULL) {
				if (strcmp(p->data.name, a) == 0) {
					printf("\n");
					printf("ѧ��     \t����  \t�༶     \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute);
					printf("-------------------------------------------------------------------------------------------\n");
					printf("\n");
					printf("*********************************************************\n");
					printf("*   1.��ѧ�ɼ�    2.Ӣ��ɼ�        3.������ɼ�        *\n");
					printf("*   4.ȫ��        0.�˳�                                *\n");
					printf("*********************************************************\n");
					printf("������Ҫ�޸ĵĳɼ���");
					scanf("%d", &j);
					while (j < 0 || j>4) {
						printf("��������  ���������룺");
						scanf("%d", &j);
					}
					switch (j) {
					case 1:
						printf("��������ѧ�ɼ���");
						scanf("%d", &p->data.score.math);
						printf("�޸ĳɹ���");
						break;
					case 2:
						printf("������Ӣ��ɼ���");
						scanf("%d", &p->data.score.english);
						printf("�޸ĳɹ���");
						break;
					case 3:
						printf("�����������ɼ���");
						scanf("%d", &p->data.score.compute);
						printf("�޸ĳɹ���");
						break;
					case 4:
						printf("��������ѧ�ɼ���");
						scanf("%d", &p->data.score.math);
						printf("������Ӣ��ɼ���");
						scanf("%d", &p->data.score.english);
						printf("�����������ɼ���");
						scanf("%d", &p->data.score.compute);
						printf("�޸ĳɹ���");
						break;
					case 0:
						break;
					}
					if (p->data.score.math >= 60)s = 4;
					else s = 0;
					if (p->data.score.english >= 60)d = 4;
					else d = 0;
					if (p->data.score.compute >= 60)f = 4;
					else f = 0;
					p->data.Ccredit = s + d + f;
					p->data.Rcredit = 12 - p->data.Ccredit;

					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("�Ҳ�������Ϊ%s��ѧ��\n", a);
			break;
		}
		printf("�Ƿ�����޸ĳɼ�( 1. ��  2.��)�� ");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("��������   ���������룺");
			scanf("%d", &k);
		}
	} while (k == 1);

	return 1;
}

//ɾ����Ϣ/
int Delete(LNode1 *P, LNode2 *Q) {
	LNode1 *p, *a;
	LNode2 *q, *b;
	int i, j, g,t,z,v,  m, u;
	int h[50];
	do {
		system("cls");
		int k = 1, l = 0;
		t = 0, z = 0, v = 0,
		printf("��Ҫɾ��������( 1.ɾ��ѧ����Ϣ   2.ɾ����ʦ��Ϣ  0.���� )��");
		scanf("%d", &i);
		while (i < 0 || i>2) {
			printf("��������\n");
			printf("���������룺");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		printf("������Ҫɾ�������˵���Ϣ��");
		scanf("%d", &j);
		switch (i) {
		case 1:
			while (k <= j) {
				printf("�������%d��ѧ����ѧ�ţ�", k);
				scanf("%d", &h[l]);
				k++;l++;
			}
			k = 1;l = 0;
			printf("\n");
			printf("ѧ��      \t�༶    \t���� \t�Ա� \t��������      \t���֤��              \t��ѧʱ��     \t������ò    \t��ͥסַ                 \t����\t�������� \t���� \t��ҵ֤����  \t����Ժϵ\n");
			printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			while (k <= j) {
				p = P;
				a = p->next;
				while (a != NULL) {
					if (a->data.stuID == h[l]) {
						printf("%-10d\t%-10s\t%-5s\t%-2s\t%-15s\t%-20s\t%-15s\t%-10s\t%-30s\t%-5s\t%-10s\t%-5s\t%-10s\t%-10s\n", a->data.stuID, a->data.classes, a->data.name, a->data.sex, a->data.date,a->data.ID,
							a->data.indate, a->data.ps, a->data.home, a->data.np, a->data.postalcode, a->data.nation, a->data.graduation,a->data.faculty);
						v++;
						break;
					}
					a = a->next;
				}
				if (a == NULL) {
					printf("�Ҳ���ѧ��Ϊ%d��ѧ����Ϣ\n", h[l]);t++;
				}
				k++;l++;
			}
			printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			if (t == j) break;
			printf("\n");
			printf("ȷ��Ҫɾ����Ϣ��1.��  2.�񣩣�");
			scanf("%d", &g);
			while (g < 1 || g>2) {
				printf("��������\n");
				printf("���������룺");
				scanf("%d", &g);
			}
			k = 1, l = 0;
			switch (g) {
			case 1:
				while (k <= j) {
					p = P;
					a = p->next;
					while (a != NULL) {
						if (a->data.stuID == h[l]) {
							p->next = a->next;
							free(a);
							z++;
							break;
						}
						p = p->next;
						a = a->next;
					}
					k++;l++;
				}
				if (z == v) printf("ɾ���ɹ���\n");
				else printf("ɾ��ʧ�ܣ�\n");
				break;
			case 2:
				break;
			}
			break;
		case 2:
			while (k <= j) {
				printf("�������%d����ʦ�Ľ̹��ţ�", k);
				scanf("%d", &h[l]);
				k++;l++;
			}
			k = 1;l = 0;
			printf("\n");
			printf("�̹���     \t����\t�Ա� \tְ��       \t�ڿ���Ϣ(�༶)  \t�ڿ���Ϣ(�ص�)   \t�ڿ���Ϣ(ʱ��)             \t����Ժϵ  \t��ϵ�绰\n");
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
			while (k <= j) {
				q = Q;
				b = q->next;
				while (b != NULL) {
					if (b->data.ID == h[l]) {
						printf("%-10d\t%-5s\t%-2s\t%-10s\t%-20s\t%-20s\t%-25s\t%-10s\t%-15s\n", b->data.ID, b->data.name, b->data.sex, b->data.pt,
							b->data.teach.classes, b->data.teach.place, b->data.teach.date, b->data.faculty, b->data.phone);
						v++;
						break;
					}
					b = b->next;
				}
				if (b == NULL) {
					printf("�Ҳ����̹���Ϊ%d�Ľ�ʦ��Ϣ\n", h[l]);
					t++;
				}
				k++;l++;
			}
			printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
			if (t == j)break;
			printf("\n");
			printf("ȷ��Ҫɾ����Ϣ(1.��  2.��)��\n");
			scanf("%d", &g);
			while (g < 1 || g>2) {
				printf("��������\n");
				printf("���������룺");
				scanf("%d", &g);
			}
			k = 1, l = 0;
			switch (g) {
			case 1:
				while (k <= j) {
					q = Q;
					b = q->next;
					while (b != NULL) {
						if (b->data.ID == h[l]) {
							q->next = b->next;
							free(b);

							z++;
							break;
						}
						q = q->next;
						b = b->next;
					}
					k++;l++;
				}
				if (z == v) printf("ɾ���ɹ���");
				else printf("ɾ��ʧ�ܣ�");
				break;
			case 2:
				break;
			}
			break;
		}
		printf("�Ƿ����ɾ����Ϣ��1.��  2.�񣩣�");
		scanf("%d", &u);
		while (u < 1 || u>2) {
			printf("�������� ���������룺");
			scanf("%d", &u);
		}
	} while (u == 1);
	return 1;
}


//ɾ���ɼ�/
int Deletescores(LNode1 *P) {
	LNode1 *p;
	char a[10];
	int i, j, k, s, d, f, m;
	do {
		p = P->next;
		system("cls");
		printf("****************************\n");
		printf("*   1.��ѧ�Ų���           *\n");
		printf("*   2.����������           *\n");
		printf("*   0.����                 *\n");
		printf("****************************\n");
		printf("��ѡ��0-2����");
		scanf("%d", &m);
		while (m < 0 || m>2) {
			printf("��������  ���������룺");
			scanf("%d", &m);
		}
		if (m == 0)return 1;
		switch (m) {
		case 1:
			printf("������ѧ��ѧ�ţ�");
			scanf("%d", &i);
			while (p != NULL) {
				if (p->data.stuID == i) {
					printf("\n");
					printf("ѧ��     \t����  \t�༶     \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute);
					printf("-------------------------------------------------------------------------------------------\n");
					printf("\n");
					printf("*********************************************************\n");
					printf("*   1.��ѧ�ɼ�    2.Ӣ��ɼ�        3.������ɼ�        *\n");
					printf("*   4.ȫ��        0.�˳�                                *\n");
					printf("*********************************************************\n");
					printf("������Ҫɾ���ĳɼ���");
					scanf("%d", &j);
					while (j < 0 || j>4) {
						printf("��������   ���������룺");
						scanf("%d", &j);
					}
					switch (j) {
					case 1:
						p->data.score.math = NULL;

						printf("ɾ���ɹ���");
						break;
					case 2:
						p->data.score.english = NULL;

						printf("ɾ���ɹ���");
						break;
					case 3:
						p->data.score.compute = NULL;

						printf("ɾ���ɹ���");
						break;
					case 4:
						p->data.score.math = NULL;
						p->data.score.english = NULL;
						p->data.score.compute = NULL;

						printf("ɾ���ɹ���");
						break;
					case 0:
						break;
					}
					if (p->data.score.math >= 60)s = 4;
					else s = 0;
					if (p->data.score.english >= 60)d = 4;
					else d = 0;
					if (p->data.score.compute >= 60)f = 4;
					else f = 0;
					p->data.Ccredit = s + d + f;
					p->data.Rcredit = 12 - p->data.Ccredit;

					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("δ�ҵ�ѧ��Ϊ%d��ѧ��\n", i);
			break;
		case 2:
			printf("������ѧ��������");
			scanf("%s", &a);
			while (p != NULL) {
				if (strcmp(p->data.name, a) == 0) {
					printf("\n");
					printf("ѧ��     \t����  \t�༶     \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\n");
					printf("-------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute);
					printf("-------------------------------------------------------------------------------------------\n");
					printf("\n");
					printf("*********************************************************\n");
					printf("*   1.��ѧ�ɼ�    2.Ӣ��ɼ�        3.������ɼ�        *\n");
					printf("*   7.ȫ��        0.�˳�                                *\n");
					printf("*********************************************************\n");
					printf("������Ҫɾ���ĳɼ���");
					scanf("%d", &j);
					while (j < 0 || j>4) {
						printf("��������   ���������룺");
						scanf("%d", &j);
					}
					switch (j) {
					case 1:
						p->data.score.math = NULL;

						printf("ɾ���ɹ���");
						break;
					case 2:
						p->data.score.english = NULL;

						printf("ɾ���ɹ���");
						break;
					case 3:
						p->data.score.compute = NULL;

						printf("ɾ���ɹ���");
						break;
					case 4:
						p->data.score.math = NULL;
						p->data.score.english = NULL;
						p->data.score.compute = NULL;

						printf("ɾ���ɹ���");
						break;
					case 0:
						break;
					}
					if (p->data.score.math >= 60)s = 4;
					else s = 0;
					if (p->data.score.english >= 60)d = 4;
					else d = 0;
					if (p->data.score.compute >= 60)f = 4;
					else f = 0;
					p->data.Ccredit = s + d + f;
					p->data.Rcredit = 12 - p->data.Ccredit;

					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("δ�ҵ�����Ϊ%s��ѧ��\n", a);
			break;
		}
		printf("�Ƿ����ɾ���ɼ���1.��  2.�񣩣�");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("��������   ���������룺");
			scanf("%d", &k);
		}
	} while (k == 1);

	return 1;
}

//��ѯѧ��������Ϣ/
int Locate1(LNode1 *P) {
	LNode1 *p;

	int i, k;
	char s[10];
	int a;
	do {
		p = P->next;
		system("cls");
		printf("****************************\n");
		printf("*   1.��ѧ�Ų���           *\n");
		printf("*   2.����������           *\n");
		printf("*   0.����                 *\n");
		printf("****************************\n");
		printf("��ѡ��(0-2)��");
		scanf("%d", &i);
		while (i < 0 || i>2) {
			printf("��������  ���������룺");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i) {
		case 1:
			printf("������ѧ�ţ�");
			scanf("%d", &a);
			while (p != NULL) {
				if (p->data.stuID == a)
				{
					printf("\n");
					printf("ѧ��      \t�༶    \t���� \t�Ա� \t��������      \t���֤��              \t��ѧʱ��     \t������ò    \t��ͥסַ                 \t����\t�������� \t���� \t��ҵ֤����  \t����Ժϵ\n");
					printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-10s\t%-5s\t%-2s\t%-15s\t%-20s\t%-15s\t%-10s\t%-30s\t%-5s\t%-10s\t%-5s\t%-10s\t%-10s\n", p->data.stuID, p->data.classes, p->data.name, p->data.sex, p->data.date, p->data.ID,
						p->data.indate, p->data.ps, p->data.home, p->data.np, p->data.postalcode, p->data.nation, p->data.graduation, p->data.faculty);
					printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("û���ҵ�ѧ��Ϊ%d��ѧ��\n", a);
			break;
		case 2:
			printf("������������");
			scanf("%s", &s);
			while (p != NULL) {
				if (strcmp(p->data.name, s) == 0) {
					printf("\n");
					printf("ѧ��      \t�༶    \t���� \t�Ա� \t��������      \t���֤��              \t��ѧʱ��     \t������ò    \t��ͥסַ                 \t����\t�������� \t���� \t��ҵ֤����  \t����Ժϵ\n");
					printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-10s\t%-5s\t%-2s\t%-15s\t%-20s\t%-15s\t%-10s\t%-30s\t%-5s\t%-10s\t%-5s\t%-10s\t%-10s\n", p->data.stuID, p->data.classes, p->data.name, p->data.sex, p->data.date, p->data.ID,
						p->data.indate, p->data.ps, p->data.home, p->data.np, p->data.postalcode, p->data.nation, p->data.graduation, p->data.faculty);
					printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("û���ҵ���ѧ��\n");
			break;
		}
		printf("�Ƿ������ѯ��1.��  2.�񣩣�");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("��������  ���������룺");
			scanf("%d", &k);
		}
	} while (k == 1);

	return 1;
}

//��ѯ��ʦ������Ϣ/
int Locate2(LNode2 *Q) {
	LNode2 *q;

	int i, j, k;
	char a[10];

	do {
		q = Q->next;
		system("cls");
		printf("��ѯ�Ľ�ʦ��Ϣ,��ѡ���ʦ�̹��Ų�ѯ���ʦ������ѯ(1.�̹���  2.����  0.���� )��");
		scanf("%d", &i);
		while (i < 0 || i > 2)
		{
			printf("��������\n");
			printf("���������룺");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i)
		{
		case 1:
			printf("�������ʦ�̹��ţ� ");
			scanf("%d", &j);
			while (q != NULL)
			{
				if (q->data.ID == j)
				{
					printf("\n");
					printf("�̹���     \t����\t�Ա� \tְ��       \t�ڿ���Ϣ(�༶)  \t�ڿ���Ϣ(�ص�)   \t�ڿ���Ϣ(ʱ��)             \t����Ժϵ  \t��ϵ�绰\n");
					printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-2s\t%-10s\t%-20s\t%-20s\t%-25s\t%-10s\t%-15s\n", q->data.ID, q->data.name, q->data.sex, q->data.pt,
						q->data.teach.classes, q->data.teach.place, q->data.teach.date, q->data.faculty, q->data.phone);
					printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
					break;
				}
				q = q->next;
			}
			if (q == NULL)printf("û���ҵ��̹���Ϊ%d�Ľ�ʦ��Ϣ\n", j);break;
		case 2:
			printf("������������");
			scanf("%s", &a);
			while (q != NULL) {
				if (strcmp(q->data.name, a) == 0)
				{
					printf("\n");
					printf("�̹���     \t����\t�Ա� \tְ��       \t�ڿ���Ϣ(�༶)  \t�ڿ���Ϣ(�ص�)   \t�ڿ���Ϣ(ʱ��)             \t����Ժϵ  \t��ϵ�绰\n");
					printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-2s\t%-10s\t%-20s\t%-20s\t%-25s\t%-10s\t%-15s\n", q->data.ID, q->data.name, q->data.sex, q->data.pt,
						q->data.teach.classes, q->data.teach.place, q->data.teach.date, q->data.faculty, q->data.phone);
					printf("---------------------------------------------------------------------------------------------------------------------------------------------------\n");
					break;
				}
				q = q->next;
			}
			if (q == NULL)printf("û���ҵ��ý�ʦ\n");break;
		}
		printf("�Ƿ������ѯ��1.��  2.�񣩣�");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("��������  ���������룺");
			scanf("%d", &k);
		}
	} while (k == 1);

	return 1;
}

//�ڿ���Ϣ/
int School(LNode2 *Q) {
	LNode2 *q;

	int i, j, k;
	char a[10];
	do {
		q = Q->next;
		system("cls");
		printf("****************************\n");
		printf("*   1.���̹��Ų���         *\n");
		printf("*   2.����������           *\n");
		printf("*   0.����                 *\n");
		printf("****************************\n");
		printf("��ѡ��(0-2)��");
		scanf("%d", &i);
		while (i <0 || i>2) {
			printf("��������  ���������룺");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i) {
		case 1:
			printf("������̹��ţ�");
			scanf("%d", &j);
			while (q != NULL) {
				if (q->data.ID == j) {
					printf("\n");
					printf("�̹���    \t����\t���̰༶        \t���ҵص�   \t�ڿ�ʱ��\n");
					printf("----------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-20s\t%-15s\t%-20s\n", q->data.ID, q->data.name, q->data.teach.classes, q->data.teach.place, q->data.teach.date);
					printf("----------------------------------------------------------------------------------\n");
					break;
				}
				q = q->next;
			}
			if (q == NULL)printf("û���ҵ��̹���Ϊ%d�Ľ�ʦ\n", j);
			break;
		case 2:
			printf("������������");
			scanf("%s", &a);
			while (q != NULL) {
				if (strcmp(q->data.name, a) == 0) {
					printf("\n");
					printf("�̹���    \t����\t���̰༶        \t���ҵص�   \t�ڿ�ʱ��\n");
					printf("----------------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-20s\t%-15s\t%-20s\n", q->data.ID, q->data.name, q->data.teach.classes, q->data.teach.place, q->data.teach.date);
					printf("----------------------------------------------------------------------------------\n");
					break;
				}
				q = q->next;
			}
			if (q == NULL)printf("û���ҵ��ý�ʦ\n");
			break;
		}
		printf("�Ƿ������ѯ��1.��  2.�񣩣�");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("��������  ���������룺");
			scanf("%d", &k);
		}
	} while (k == 1);

	return 1;
}

//��ѯ�ɼ�/
int Locatescores(LNode1 *P) {

	char a[10];
	int i, k, m, z;
	float j;
	do {
		LNode1 *p;
		p = P->next;
		system("cls");
		printf("****************************\n");
		printf("*  1.�鿴���˳ɼ�          *\n");
		printf("*  2.�鿴�����˳ɼ�        *\n");
		printf("*  0.����                  *\n");
		printf("****************************\n");
		printf("��ѡ��(0-2)��");
		scanf("%d", &m);
		while (m < 0 || m>2) {
			printf("��������  ���������룺");
			scanf("%d", &m);
		}
		if (m == 0)return 1;
		switch (m) {
		case 1:
			printf("************************\n");
			printf("*   1.ѧ�Ų�ѯ         *\n");
			printf("*   2.������ѯ         *\n");
			printf("*   0.����             *\n");
			printf("************************\n");
			printf("��ѡ��");
			scanf("%d", &z);
			while (z < 0 || z>2) {
				printf("��������  ���������룺");
				scanf("%d", &z);
			}
			switch (z) {
			case 1:
				printf("������ѧ�ţ�");
				scanf("%d", &i);
				while (p != NULL) {
					if (p->data.stuID == i) {
						p->data.score.all = p->data.score.math + p->data.score.english + p->data.score.compute;
						j = p->data.score.all / 3;
						printf("\n");
						printf("ѧ��     \t����  \t�༶                \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܳɼ�\tƽ����\n");
						printf("---------------------------------------------------------------------------------------------------------------\n");
						printf("%d\t%s\t%s\t%-8d\t%-8d\t%-8d\t%-4d\t%0.2f\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute,
							p->data.score.all, j);
						printf("---------------------------------------------------------------------------------------------------------------\n");
						break;
					}
					p = p->next;
				}
				if (p == NULL)printf("�Ҳ���ѧ��Ϊ%d��ѧ��\n", i);
				break;
			case 2:
				printf("������������");
				scanf("%s", &a);
				while (p != NULL) {
					if (strcmp(p->data.name, a) == 0) {
						p->data.score.all = p->data.score.math + p->data.score.english + p->data.score.compute;
						j = p->data.score.all / 3;
						printf("\n");
						printf("ѧ��     \t����  \t�༶                \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܳɼ�\tƽ����\n");
						printf("---------------------------------------------------------------------------------------------------------------\n");
						printf("%d\t%s\t%s\t%-8d\t%-8d\t%-8d\t%-4d\t%0.2f\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute,
							p->data.score.all, j);
						printf("---------------------------------------------------------------------------------------------------------------\n");
						break;
					}
					p = p->next;
				}
				if (p == NULL)printf("�Ҳ�������Ϊ%s��ѧ��\n", a);
				break;
			case 0:break;
			}
			break;
		case 2:
			printf("\n");
			printf("ѧ��     \t����  \t�༶                \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܳɼ�\tƽ����\n");
			printf("---------------------------------------------------------------------------------------------------------------\n");
			while (p != NULL) {
				j = 0;
				p->data.score.all = p->data.score.math + p->data.score.english + p->data.score.compute;
				j = p->data.score.all / 3;
				printf("%d\t%s\t%s\t%-8d\t%-8d\t%-8d\t%-4d\t%0.2f\n", p->data.stuID, p->data.name, p->data.classes, p->data.score.math, p->data.score.english, p->data.score.compute,
					p->data.score.all, j);
				p = p->next;
			}
			printf("---------------------------------------------------------------------------------------------------------------\n");
			break;
		case 0:break;
		}
		printf("�Ƿ������ѯ�ɼ���1. ��   2.�� ����");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("��������   ���������룺");
			scanf("%d", &k);
		}
	} while (k == 1);

	return 1;
}

//�ܳɼ�
int All(LNode1 *P) {
	LNode1 *p;
	LNode1 T[100], U[10];
	int j, k, g, h, d, z, a;
	char i[20];
	system("cls");
	printf("1.���Ұ༶\n0.����\n");
	scanf("%d", &a);
	while (a < 0 || a>1) {
		printf("��������  ���������룺");
		scanf("%d", &a);
	}
	if (a == 0)return 1;
	if (a == 1) {
		do {
			int o = 0;
			p = P->next;
			system("cls");
			printf("������Ҫ�鿴�İ༶��");
			scanf("%s", &i);
			while (p != NULL) {
				if (strcmp(p->data.classes, i) == 0) {
					memcpy(&T[o], p, sizeof(Student));
					o++;
				}
				p = p->next;
			}
			do {
				system("cls");
				printf("1.��ѧ������ǰ����\n");
				printf("2.��ѧ�����򣨺�ǰ��\n");
				printf("3.����ѧ�ɼ����ߵ��ͣ�  \n");
				printf("4.����ѧ�ɼ����͵��ߣ�  \n");
				printf("5.��Ӣ��ɼ����ߵ��ͣ�  \n");
				printf("6.��Ӣ��ɼ����͵��ߣ�  \n");
				printf("7.��������ɼ����ߵ��ͣ�\n");
				printf("8.��������ɼ����͵��ߣ�\n");
				printf("9.���ܳɼ����ߵ��ͣ�    \n");
				printf("10.���ܳɼ����͵��ߣ�    \n");
				printf("0.����\n");
				printf("��ѡ��鿴��ʽ��0-10����");
				scanf("%d", &j);
				while (j < 0 || j>10) {
					printf("��������  ���������룺");
					scanf("%d", &j);
				}
				switch (j) {
				case 1://��ѧ������ǰ����
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.stuID > T[h + 1].data.stuID) {
								memcpy(&U[0], &T[h], sizeof(Student));
								memcpy(&T[h], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("ѧ��       \t����\t�༶       \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܷ�\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 2://��ѧ�����򣨺�ǰ��
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.stuID < T[h + 1].data.stuID) {
								memcpy(&U[0], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &T[h], sizeof(Student));
								memcpy(&T[h], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("ѧ��       \t����\t�༶       \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܷ�\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 3://����ѧ�ɼ����ߵ��ͣ�
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.math < T[h + 1].data.score.math) {
								memcpy(&U[0], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &T[h], sizeof(Student));
								memcpy(&T[h], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("ѧ��       \t����\t�༶       \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܷ�\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 4://����ѧ�ɼ����͵��ߣ�
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.math > T[h + 1].data.score.math) {
								memcpy(&U[0], &T[h], sizeof(Student));
								memcpy(&T[h], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("ѧ��       \t����\t�༶       \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܷ�\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 5://��Ӣ��ɼ����ߵ��ͣ�
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.english < T[h + 1].data.score.english) {
								memcpy(&U[0], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &T[h], sizeof(Student));
								memcpy(&T[h], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("ѧ��       \t����\t�༶       \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܷ�\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 6://��Ӣ��ɼ����͵��ߣ�
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.english > T[h + 1].data.score.english) {
								memcpy(&U[0], &T[h], sizeof(Student));
								memcpy(&T[h], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("ѧ��       \t����\t�༶       \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܷ�\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 7://��������ɼ����ߵ��ͣ�
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.compute < T[h + 1].data.score.compute) {
								memcpy(&U[0], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &T[h], sizeof(Student));
								memcpy(&T[h], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("ѧ��       \t����\t�༶       \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܷ�\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 8://��������ɼ����͵��ߣ�
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.compute > T[h + 1].data.score.compute) {
								memcpy(&U[0], &T[h], sizeof(Student));
								memcpy(&T[h], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("ѧ��       \t����\t�༶       \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܷ�\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 9://���ܳɼ����ߵ��ͣ�
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.all < T[h + 1].data.score.all) {
								memcpy(&U[0], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &T[h], sizeof(Student));
								memcpy(&T[h], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("ѧ��       \t����\t�༶       \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܷ�\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 10://���ܳɼ����͵��ߣ�
					for (g = 0;g < o;g++) {
						z = 0;
						for (h = 0;h < o - g - 1;h++) {
							if (T[h].data.score.all > T[h + 1].data.score.all) {
								memcpy(&U[0], &T[h], sizeof(Student));
								memcpy(&T[h], &T[h + 1], sizeof(Student));
								memcpy(&T[h + 1], &U[0], sizeof(Student));
								z = 1;
							}
						}
						if (z == 0)break;
					}
					printf("\n");
					printf("ѧ��       \t����\t�༶       \t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܷ�\n");
					printf("-----------------------------------------------------------------------------------------------------\n");
					for (g = 0;g < o;g++) {
						printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\t%-8d\t%-8d\n", T[g].data.stuID, T[g].data.name, T[g].data.classes, T[g].data.score.math,
							T[g].data.score.english, T[g].data.score.compute, T[g].data.score.all);
					}
					printf("-----------------------------------------------------------------------------------------------------\n");
					break;
				case 0:break;
				}
				printf("�Ƿ�����鿴���ࣨ1.�� 2.�񣩣�");
				scanf("%d", &k);
				while (k < 1 || k>2) {
					printf("��������  ���������룺");
					scanf("%d", &k);
				}
			} while (k == 1);
			printf("�Ƿ�����鿴�����ࣨ1.��  2.�񣩣�");
			scanf("%d", &d);
			while (d < 1 || d>2) {
				printf("��������  ���������룺");
				scanf("%d", &d);
			}
		} while (d == 1);
	}
	return 1;
}

//ƽ����/
int Average(LNode1 *P) {
	LNode1 *p;
	int i, k;
	char a[20];
	do {
		system("cls");
		int j = 0, Allmath = 0, Allenglish = 0, Allcompute = 0;
		p = P->next;
		printf("1.�鿴ĳ�����ƽ����\n");
		printf("2.����\n");
		printf("��ѡ��0-1����");
		scanf("%d", &i);
		while (i < 0 || i>1) {
			printf("��������  ���������룺");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		if (i == 1) {
			printf("������༶��");
			scanf("%s", a);
			while (p != NULL) {
				if (strcmp(p->data.classes, a) == 0) {
					Allmath += p->data.score.math;
					Allenglish += p->data.score.english;
					Allcompute += p->data.score.compute;
					j++;
				}
				p = p->next;
			}
			if (j == 0) {
				printf("�Ҳ����ð࣡\n");
				break;
			}
			printf("\n");
			printf("�༶     \t��ѧƽ����\tӢ��ƽ����\t�����ƽ����\n");
			printf("--------------------------------------------------------------------\n");
			printf("%-10s\t%-8d\t%-8d\t%-8d\n", a, Allmath / j, Allenglish / j, Allcompute / j);
			printf("--------------------------------------------------------------------\n");
		}
		printf("�Ƿ�����鿴��1.��  2.�񣩣�");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("��������  ���������룺");
			scanf("%d", &k);
		}
	} while (k == 1);
	return 1;
}

//�������ѧ��/
int Fail(LNode1 *P) {
	LNode1 *p;

	int i, m;
	char k[20];
	do {
		int j = 0;
		p = P->next;
		system("cls");
		printf("****************************************\n");
		printf("**  1.�鿴��ѧ�������ѧ��            **\n");
		printf("**  2.�鿴Ӣ�ﲻ�����ѧ��            **\n");
		printf("**  3.�鿴������������ѧ��          **\n");
		printf("**  4.�鿴�༶�ﲻ�����ѧ��          **\n");
		printf("**  0.����                            **\n");
		printf("****************************************\n");
		printf("������ѡ��(0-4)��");
		scanf("%d", &i);
		while (i < 0 || i>4) {
			printf("��������  ���������룺");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i) {
		case 1:
			printf("\n");
			printf("ѧ��       \t����\t��ѧ�ɼ�\t�Ƿ񲹿�\n");
			printf("-------------------------------------------------\n");
			while (p != NULL) {
				if (p->data.score.math < 60) {
					printf("%d\t%s\t%-8d\t����\n", p->data.stuID, p->data.name, p->data.score.math);
					j++;
				}
				p = p->next;
			}
			printf("-------------------------------------------------\n");
			printf("������������%d��\n", j);
			break;
		case 2:
			printf("\n");
			printf("ѧ��       \t����\tӢ��ɼ�\t�Ƿ񲹿�\n");
			printf("-------------------------------------------------\n");
			while (p != NULL) {
				if (p->data.score.english < 60) {
					printf("%d\t%s\t%-8d\t����\n", p->data.stuID, p->data.name, p->data.score.english);
					j++;
				}
				p = p->next;
			}
			printf("-------------------------------------------------\n");
			printf("������������%d��\n", j);
			break;
		case 3:
			printf("\n");
			printf("ѧ��       \t����\t������ɼ�\t�Ƿ񲹿�\n");
			printf("-------------------------------------------------\n");
			while (p != NULL) {
				if (p->data.score.compute < 60) {
					printf("%d\t%s\t%-8d\t����\n", p->data.stuID, p->data.name, p->data.score.compute);
					j++;
				}
				p = p->next;
			}
			printf("-------------------------------------------------\n");
			printf("������������%d��\n", j);
			break;
		case 4:
			p = P->next;
			printf("������༶��");
			scanf("%s", k);
			printf("\n");
			printf("ѧ��       \t����\t��ѧ�ɼ�\t�Ƿ񲹿�\n");
			printf("-------------------------------------------------\n");
			while (p != NULL) {
				if (strcmp(p->data.classes, k) == 0) {
					if (p->data.score.math < 60) {
						printf("%d\t%s\t%-8d\t����\n", p->data.stuID, p->data.name, p->data.score.math);
						j++;
					}
				}
				p = p->next;
			}
			printf("-------------------------------------------------\n");
			printf("�ð༶��ѧ������������%d��\n", j);
			printf("\n");
			p = P->next;
			j = 0;
			printf("\n");
			printf("ѧ��       \t����\tӢ��ɼ�\t�Ƿ񲹿�\n");
			printf("-------------------------------------------------\n");
			while (p != NULL) {
				if (strcmp(p->data.classes, k) == 0) {
					if (p->data.score.english < 60) {
						printf("%d\t%s\t%-8d\t����\n", p->data.stuID, p->data.name, p->data.score.english);
						j++;
					}
				}
				p = p->next;
			}
			printf("-------------------------------------------------\n");
			printf("�ð༶Ӣ�ﲻ����������%d��\n", j);
			printf("\n");
			p = P->next;
			j = 0;
			printf("\n");
			printf("ѧ��       \t����\t������ɼ�\t�Ƿ񲹿�\n");
			printf("-------------------------------------------------\n");
			while (p != NULL) {
				if (strcmp(p->data.classes, k) == 0) {
					if (p->data.score.compute < 60) {
						printf("%d\t%s\t%-8d\t����\n", p->data.stuID, p->data.name, p->data.score.compute);
						j++;
					}
				}
				p = p->next;
			}
			printf("-------------------------------------------------\n");
			printf("�ð༶�����������������%d��\n", j);
			break;
		}
		printf("�Ƿ������ѯ��1.��  2.�񣩣�");
		scanf("%d", &m);
		while (m < 1 || m>2) {
			printf("�������󣡡������������룺");
			scanf("%d", &m);
		}
	} while (m == 1);
	return 1;
}

//��ʾ������Ϣ /
int Display(LNode1 *P, LNode2 *Q) {
	LNode1 *p;
	LNode2 *q;
	int i, j;
	do {
		p = P->next;
		q = Q->next;
		system("cls");
		printf("****************************\n");
		printf("**   1.��ʾѧ����Ϣ       **\n");
		printf("**   2.��ʾ��ʦ��Ϣ       **\n");
		printf("**   0.����               **\n");
		printf("****************************\n");
		printf("��ѡ��0-2����\n");
		scanf("%d", &i);
		while (i < 0 || i>2) {
			printf("��������  ���������룺");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i) {
		case 1:
			printf("\n");
			printf("ѧ��         \t����\t�Ա� \t��������    \t���֤��               \t��ѧʱ��     \t������ò   \t��ͥסַ                       \t����  \t��������\t����\t��ҵ֤����\t����Ժϵ\n");
			printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			while (p != NULL) {
				printf("%-10d\t%-5s\t%-2s\t%-10s\t%-10s\t%-10s\t%-10s\t%-30s\t%-5s\t%-10s  \t%-5s \t%-10s\t%-10s\n",
					p->data.stuID, p->data.name, p->data.sex, p->data.date, p->data.ID, p->data.indate,
					p->data.ps, p->data.home, p->data.np, p->data.postalcode, p->data.nation, p->data.graduation, p->data.faculty);
				p = p->next;
			}
			printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			break;
		case 2:
			printf("\n");
			printf("�̹���     \t����\t�Ա�\tְ��    \t����Ժϵ\t�绰\n");
			printf("-----------------------------------------------------------------------------\n");
			while (q != NULL) {
				printf("%-10d\t%-5s\t%-2s\t%-10s\t%-10s\t%-15s\n",
					q->data.ID, q->data.name, q->data.sex, q->data.pt, q->data.faculty, q->data.phone);
				q = q->next;
			}
			printf("-----------------------------------------------------------------------------\n");
			break;
		}
		printf("�Ƿ������ѯ��1. ��   2.�� ����");
		scanf("%d", &j);
		while (j < 1 || j>2) {
			printf("��������  ���������룺");
			scanf("%d", &j);
		}
	} while (j == 1);
	return 1;
}

//�鿴ѧ��/
int Credit(LNode1 *P) {
	LNode1 *p;
	int i, j, k;
	char a[10];

	do {
		p = P->next;
		system("cls");
		printf("************************\n");
		printf("*   1.ѧ�Ų�ѯ         *\n");
		printf("*   2.������ѯ         *\n");
		printf("*   0.����             *\n");
		printf("************************\n");
		printf("��ѡ���ѯ��ʽ��");
		scanf("%d", &i);
		while (i < 0 || i>2) {
			printf("��������  ���������룺");
			scanf("%d", &i);
		}
		if (i == 0)return 1;
		switch (i) {
		case 1:
			printf("������ѧ�ţ�");
			scanf("%d", &j);
			while (p != NULL) {
				if (p->data.stuID == j) {
					printf("\n");
					printf("ѧ��       \t����\t�༶        \t����ѧ��\tδ��ѧ��\n");
					printf("------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.Ccredit, p->data.Rcredit);
					printf("------------------------------------------------------------------------\n");
					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("δ�ҵ�ѧ��Ϊ%d��ѧ����\n", j);
			break;
		case 2:
			printf("������������");
			scanf("%s", &a);
			while (p != NULL) {
				if (strcmp(p->data.name, a) == 0) {
					printf("\n");
					printf("ѧ��       \t����\t�༶        \t����ѧ��\tδ��ѧ��\n");
					printf("------------------------------------------------------------------------\n");
					printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.Ccredit, p->data.Rcredit);
					printf("------------------------------------------------------------------------\n");
					break;
				}
				p = p->next;
			}
			if (p == NULL)printf("δ�ҵ�����Ϊ%s��ѧ����\n", a);
			break;
		}
		printf("�Ƿ������ѯ��1.��  2.�񣩣�");
		scanf("%d", &k);
		while (k < 1 || k>2) {
			printf("��������  ���������룺");
			scanf("%d", &k);
		}
	} while (k == 1);

	return 1;
}

//�鿴����ѧ��ѧ��/
int Allcredit(LNode1 *P) {
	LNode1 *p;
	p = P->next;
	system("cls");
	printf("ѧ��       \t����\t�༶    \t����ѧ��\tδ��ѧ��\n");
	printf("------------------------------------------------------------------------\n");
	while (p != NULL) {
		printf("%-10d\t%-5s\t%-10s\t%-8d\t%-8d\n", p->data.stuID, p->data.name, p->data.classes, p->data.Ccredit, p->data.Rcredit);
		p = p->next;
	}
	printf("------------------------------------------------------------------------\n");
	return 1;
}

//������Ϣ����
void BIM(LNode1 *P, LNode2 *Q) {
	int select, k, j, l;

	do {
		do {
			system("cls");
			printf("*********************\n");
			printf("* 1.�����Ϣ        *\n");
			printf("* 2.�޸���Ϣ        *\n");
			printf("* 3.ɾ����Ϣ        *\n");
			printf("* 0.�������˵�      *\n");
			printf("*********************\n");
			printf("��ѡ��Ҫ���������(0-3)��");
			scanf("%d", &select);
			switch (select) {
			case 1://�����Ϣ
				k = InsertList(P, Q);
				if (k == 0)printf("���ʧ�ܣ�");
				else printf("��ӳɹ���");
				printf("�Ƿ񷵻ػ�����Ϣ����˵���1. ��   2.��");
				scanf("%d", &l);
				while (l < 1 || l>2) {
					printf("��������  ���������룺");
					scanf("%d", &l);
				}
				break;
			case 2://�޸���Ϣ
				k = Modify(P, Q);
				if (k == 0)printf("�޸�ʧ�ܣ�");
				else printf("�޸ĳɹ���");
				printf("�Ƿ񷵻ػ�����Ϣ����˵���1. ��   2.��");
				scanf("%d", &l);
				while (l < 1 || l>2) {
					printf("��������  ���������룺");
					scanf("%d", &l);
				}
				break;
			case 3://ɾ����Ϣ
				Delete(P, Q);
				printf("�Ƿ񷵻ػ�����Ϣ����˵���1. ��   2.��");
				scanf("%d", &l);
				while (l < 1 || l>2) {
					printf("��������  ���������룺");
					scanf("%d", &l);
				}
				break;
			case 0://�������˵�	
				return;
			default:
				printf("��������");
				system("pause"); break;
			}
		} while (select < 0 || select>3);

	} while (l == 1);

}

//ѧ���ɼ�����
void SPM(LNode1 *P) {
	int select, k, j, l;
	char i;
	do {
		do {
			system("cls");
			printf("*********************\n");
			printf("* 1.��ӳɼ�        *\n");
			printf("* 2.�޸ĳɼ�        *\n");
			printf("* 3.ɾ���ɼ�        *\n");
			printf("* 4.��ѯ�ɼ�        *\n");
			printf("* 0.�������˵�      *\n");
			printf("*********************\n");
			printf("��ѡ��Ҫ���������(0-4)��");
			scanf("%d", &select);
			switch (select) {
			case 1://��ӳɼ�
				Insertscores(P);
				printf("�Ƿ񷵻�ѧ���ɼ�����˵���1. ��   2.��");
				scanf("%d", &l);
				while (l < 1 || l>2) {
					printf("��������  ���������룺");
					scanf("%d", &l);
				}
				break;
			case 2://�޸ĳɼ�
				Modifyscores(P);
				printf("�Ƿ񷵻�ѧ���ɼ�����˵���1. ��   2.��");
				scanf("%d", &l);
				while (l < 1 || l>2) {
					printf("��������  ���������룺");
					scanf("%d", &l);
				}
				break;
			case 3://ɾ���ɼ�
				Deletescores(P);
				printf("�Ƿ񷵻�ѧ���ɼ�����˵���1. ��   2.��");
				scanf("%d", &l);
				while (l < 1 || l>2) {
					printf("��������  ���������룺");
					scanf("%d", &l);
				}
				break;
			case 4://��ѯ�ɼ�
				Locatescores(P);
				printf("�Ƿ񷵻�ѧ���ɼ�����˵���1. ��   2.��");
				scanf("%d", &l);
				while (l < 1 || l>2) {
					printf("��������  ���������룺");
					scanf("%d", &l);
				}
				break;
			case 0://�������˵�
				return;
			default:printf("��������");
				system("pause"); break;
			}
		} while (select < 0 || select>4);
	} while (l == 1);
}

//��Ϣ��ѯͳ��
void IQS(LNode1 *P, LNode2 *Q) {
	int select;
	int j;
	do {
		do {
			system("cls");
			printf("****************************\n");
			printf("* 1.��ѯѧ��������Ϣ       *\n");
			printf("* 2.��ѯ�ɼ�               *\n");
			printf("* 3.��ѯ��ʦ������Ϣ       *\n");
			printf("* 4.�ڿ���Ϣ               *\n");
			printf("* 5.�鿴�ܳɼ�             *\n");
			printf("* 6.�鿴ƽ����             *\n");
			printf("* 7.�������ѧ��           *\n");
			printf("* 8.��ʾ���л�����Ϣ       *\n");
			printf("* 0.�������˵�             *\n");
			printf("*********************\n");
			printf("��ѡ��Ҫ���������(0-8)��");
			scanf("%d", &select);
			switch (select) {
			case 1://��ѯѧ��������Ϣ
				Locate1(P);
				printf("�Ƿ񷵻���Ϣ��ѯͳ�Ʋ˵���1.��  2.�񣩣�");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("��������  ���������룺");
					scanf("%d", &j);
				}
				break;
			case 2://��ѯ�ɼ�
				Locatescores(P);
				printf("�Ƿ񷵻���Ϣ��ѯͳ�Ʋ˵���1.��  2.�񣩣�");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("��������  ���������룺");
					scanf("%d", &j);
				}
				break;
			case 3://��ѯ��ʦ������Ϣ
				Locate2(Q);
				printf("�Ƿ񷵻���Ϣ��ѯͳ�Ʋ˵���1.��  2.�񣩣�");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("��������  ���������룺");
					scanf("%d", &j);
				}
				break;
			case 4://�ڿ���Ϣ
				School(Q);
				printf("�Ƿ񷵻���Ϣ��ѯͳ�Ʋ˵���1.��  2.�񣩣�");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("��������  ���������룺");
					scanf("%d", &j);
				}
				break;
			case 5://�鿴�ܳɼ�
				All(P);
				printf("�Ƿ񷵻���Ϣ��ѯͳ�Ʋ˵���1.��  2.�񣩣�");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("��������  ���������룺");
					scanf("%d", &j);
				}
				break;
			case 6://�鿴ƽ����
				Average(P);
				printf("�Ƿ񷵻���Ϣ��ѯͳ�Ʋ˵���1.��  2.�񣩣�");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("��������  ���������룺");
					scanf("%d", &j);
				}
				break;
			case 7://�������ѧ��
				Fail(P);
				printf("�Ƿ񷵻���Ϣ��ѯͳ�Ʋ˵���1.��  2.�񣩣�");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("��������  ���������룺");
					scanf("%d", &j);
				}
				break;
			case 8://��ʾ���л�����Ϣ
				Display(P, Q);
				printf("�Ƿ񷵻���Ϣ��ѯͳ�Ʋ˵���1.��  2.�񣩣�");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("��������  ���������룺");
					scanf("%d", &j);
				}
				break;
			case 0://�������˵�
				return;
			default:printf("��������");
				system("pause"); break;
			}
		} while (select < 0 || select>8);
	} while (j == 1);
}

//��ҵ����Ϣ����
void GIM(LNode1 *P) {
	int select;
	char i;
	int j;
	do {
		do {
			system("cls");
			printf("*************************\n");
			printf("* 1.�鿴ѧ��            *\n");
			printf("* 2.�鿴����ѧ��ѧ��    *\n");
			printf("* 0.�������˵�          *\n");
			printf("*************************\n");
			printf("��ѡ��Ҫ���������(0-2)��");
			scanf("%d", &select);
			switch (select) {
			case 1://�鿴ѧ�� 
				Credit(P);
				printf("�Ƿ񷵻ر�ҵ����Ϣ����˵���1.��  2.�񣩣�");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("��������  ���������룺");
					scanf("%d", &j);
				}
				break;
			case 2://�鿴����ѧ��ѧ��
				Allcredit(P);
				printf("�Ƿ񷵻ر�ҵ����Ϣ����˵���1.��  2.�񣩣�");
				scanf("%d", &j);
				while (j < 1 || j>2) {
					printf("��������  ���������룺");
					scanf("%d", &j);
				}
				break;
			case 0://�������˵�
				return;
			default:printf("��������");
				system("pause");
				break;
			}
		} while (select < 0 || select>2);
	} while (j == 1);
}
//��ʽ������ѧ����Ϣ
void savefile1(LNode1 *P)//Pѧ�� 
{
	FILE *fp;
	if ((fp = fopen("Student.txt", "w")) != NULL)
	{
		LNode1 *p = P->next;
		while (p != NULL)
		{
			fwrite(&p->data, sizeof(p->data), 1, fp);
			p = p->next;
		}
		fclose(fp);
	}
	else
	{
		printf("��ʽ������ѧ����Ϣʧ�ܣ�");
	}
}
//��ʽ�������ʦ��Ϣ
void savefile2(LNode2 *Q)// Q��ʦ
{
	FILE *fp;
	if ((fp = fopen("Teacher.txt", "w")) != NULL)
	{
		LNode2 *q = Q->next;
		while (q != NULL)
		{
			fwrite(&q->data, sizeof(q->data), 1, fp);
			q = q->next;
		}
		fclose(fp);
	}
	else
	{
		printf("��ʽ�������ʦ��Ϣʧ�ܣ�");
	}
}
//��ȡѧ����Ϣ
void readfile1(LNode1 *P)
{
	LNode1 *p = P;
	LNode1 *p1;
	FILE *fp;
	if ((fp = fopen("Student.txt", "r")) != NULL)
	{
		p->next = NULL;
		while (!feof(fp))
		{
			p1 = (LNode1*)malloc(sizeof(LNode1));
			p1->next = NULL;
			fread(&p1->data, sizeof(p->data), 1, fp);
			if (strlen(p1->data.home) < 100) {
				p1->next = p->next;
				p->next = p1;
			}
			else {
				free(p1);
			}
		}
		fclose(fp);
	}
	else
	{
		printf("��ȡѧ����Ϣʧ��!");
	}

}
//��ȡ��ʦ��Ϣ
void readfile2(LNode2 *Q)
{
	LNode2 *q = Q;
	LNode2 *q1;
	FILE *fp;
	if ((fp = fopen("Teacher.txt", "r")) != NULL)
	{
		q->next = NULL;
		while (!feof(fp))
		{
			q1 = (LNode2*)malloc(sizeof(LNode2));
			q1->next = NULL;
			fread(&q1->data, sizeof(q1->data), 1, fp);
			if (strlen(q1->data.faculty) < 20) {
				q1->next = q->next;
				q->next = q1;
			}
			else free(q1);
		}
		fclose(fp);
	}
	else
	{
		printf("��ȡ��ʦ��Ϣʧ��!");
	}
}
//׷�ӱ���ѧ����Ϣ
void appendfile1(LNode1 *P) {
	FILE *fp;
	if ((fp = fopen("Student.txt", "a")) != NULL)
	{
		LNode1 *p = P->next;
		while (p != NULL)
		{
			fwrite(&p->data, sizeof(p->data), 1, fp);
			p = p->next;
		}
		fclose(fp);
	}
	else
	{
		printf("׷�ӱ���ѧ����Ϣʧ�ܣ�");
	}
}
//׷�ӱ����ʦ��Ϣ
void appendfile2(LNode2 *Q) {
	FILE *fp;
	if ((fp = fopen("Teacher.txt", "a")) != NULL)
	{
		LNode2 *q = Q->next;
		while (q != NULL)
		{
			fwrite(&q->data, sizeof(q->data), 1, fp);
			q = q->next;
		}
		fclose(fp);
	}
	else
	{
		printf("׷�ӱ����ʦ��Ϣʧ�ܣ�");
	}
}
void nume(LNode1 *P, LNode2 *Q) {
	int select;
	int i, j;
	do {
		system("cls");//����
		printf("*********************\n");
		printf("* 1.�ļ�����        *\n");
		printf("* 2.������Ϣ����    *\n");
		printf("* 3.ѧ���ɼ�����    *\n");
		printf("* 4.��Ϣ��ѯͳ��    *\n");
		printf("* 5.��ҵ����Ϣ����  *\n");
		printf("* 0.�˳�ϵͳ        *\n");
		printf("*********************\n");
		printf("���������֣�0--5����");
		scanf("%d", &select);
		switch (select) {
		case 1://���ļ�
			printf("  1.��ʽ��������Ϣ \n  2.׷�ӱ�����Ϣ\n  3.��ȡ��Ϣ\n  0.����\n");
			printf("��ѡ��");
			scanf("%d", &i);
			while (i < 0 || i>3) {
				printf("��������  ���������룺");
				scanf("%d", &i);
			}
			switch (i) {
			case 1:
				printf("1.��ʽ������ѧ����Ϣ\n2.��ʽ�������ʦ��Ϣ\n0.����\n");
				printf("��ѡ��");
				scanf("%d", &j);
				while (j< 0 || j>2) {
					printf("��������  ���������룺");
					scanf("%d", &j);
				}
				switch (j) {
				case 1:
					savefile1(P);break;
				case 2:
					savefile2(Q);break;
				case 0:
					break;
				}
				break;
			case 2:
				printf("1.׷�ӱ���ѧ����Ϣ\n2.׷�ӱ����ʦ��Ϣ\n0.����\n");
				printf("��ѡ��");
				scanf("%d", &j);
				while (j < 0 || j>2) {
					printf("��������  ���������룺");
					scanf("%d", &j);
				}
				switch (j) {
				case 1:
					appendfile1(P);break;
				case 2:
					appendfile2(Q);break;
				case 0:
					break;
				}
				break;
			case 3:
				printf("1.��ȡѧ����Ϣ\n2.��ȡ��ʦ��Ϣ\n0.����\n");
				printf("��ѡ��");
				scanf("%d", &j);
				while (j < 0 || j>2) {
					printf("��������  ���������룺");
					scanf("%d", &j);
				}
				switch (j) {
				case 1:
					readfile1(P);break;
				case 2:
					readfile2(Q);break;
				case 0:
					break;
				}
				break;
			case 0:
				break;
			}
			system("pause");
			break;
		case 2://������Ϣ����
			BIM(P, Q);
			system("pause");
			break;
		case 3://ѧ���ɼ�����
			SPM(P);
			system("pause");
			break;
		case 4://��Ϣ��ѯͳ��
			IQS(P, Q);
			system("pause");
			break;
		case 5://��ҵ����Ϣ����
			GIM(P);
			system("pause");
			break;
		case 0://�˳�
			exit(0);
			break;
		default:printf("��������");
			system("pause");
			break;
		}
	} while (select < 0 || select>4);
}
int main() {
	LNode1 S;
	LNode2 T;
	while (1) {
		nume(&S, &T);
	}
}