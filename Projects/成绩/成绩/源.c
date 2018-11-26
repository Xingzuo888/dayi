#include<stdio.h>
typedef struct {
	int Math;      //��ѧ
	int English;   //Ӣ��
	int Computer;  //�����

}Score;
typedef struct {
	int ID;//ѧ��
	char name[20];//����
	Score scores;
}Student;
typedef Student ElemType;
typedef struct LNode {
	Student data;
	struct LNode *next;
}LNode;
//����ѧ����Ϣ
int InserstList(LNode *L, ElemType e) {

	LNode *p, *q;
	p = L;

	q = (LNode*)malloc(sizeof(LNode));
	if (q == NULL)return 0;
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}
//���ѧ���ɼ�
int Display(LNode *L) {
	LNode *p;
	int sum, i, j, k;
	p = L->next;
	printf("\tѧ��\t����\t��ѧ\tӢ��\t�����\t�ܳɼ�\n");
	while (p != NULL) {
		i = p->data.scores.Math;
		j = p->data.scores.English;
		k = p->data.scores.Computer;
		sum = i + j + k;
		printf("\t%d\t%s\t%d\t%d\t%d\t%d\n"
			, p->data.ID, p->data.name, p->data.scores.Math
			, p->data.scores.English, p->data.scores.Computer
			, sum);
		p = p->next;
	}
}
//��ѧ�Ų���ĳ��ѧ����Ϣ
int IdLocateList(LNode *L, int i) {
	int a, b, c, sum, k;
	LNode *p;
	p = L->next;
	while (p != NULL) {
		k = p->data.ID;
		if (k == i) {
			printf("\tѧ��\t����\t��ѧ\tӢ��\t�����\t�ܳɼ�\n");
			a = p->data.scores.Math;
			b = p->data.scores.English;
			c = p->data.scores.Computer;
			sum = a + b + c;
			printf("\t%d\t%s\t%d\t%d\t%d\t%d\n"
				, p->data.ID, p->data.name, p->data.scores.Math
				, p->data.scores.English, p->data.scores.Computer
				, sum);
			return 1;
		}
		p = p->next;
	}
	if (p == NULL)return 0;
}
void menu(LNode *L) {
	int i, result, a, b, c, d;
	char name[20];
	ElemType e;
	char choice;
	int select;
	do {
		system("cls");//����
					  //��ʾ�˵�
		printf("*************************************\n");
		printf("��ӭʹ��ѧ���ɼ�����ϵͳ\n");
		printf("[1] ��������ѧ����Ϣ\n");
		printf("[2] �������ѧ���ɼ�\n");
		printf("[3] ��ѧ�Ų���ĳ��ѧ����Ϣ\n");
		printf("[4] ����������ĳ��ѧ����Ϣ\n");
		printf("[5] ��ѧ�Ŷ�ѧ������\n");
		printf("[6] ���ܳɼ���ѧ������\n");
		printf("[7] ��ѧ���޸�ĳ��ѧ����Ϣ\n");
		printf("[8] �������޸�ĳ��ѧ����Ϣ\n");
		printf("[9] ��ѧ��ɾ��ĳ��ѧ����Ϣ\n");
		printf("[10] ������ɾ��ĳ��ѧ����Ϣ\n");
		printf("[0] �˳�����\n");
		printf("����������ѡ��0 - 9����\n");
		printf("**************************************)\n");

		//�����û�������		
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			//��������ѧ����Ϣ
			printf("������ѧ����Ϣ��");

			printf("������ѧ�ţ�");
			scanf("%d", &a);e.ID = a;
			printf("������������");
			scanf("%s", name);
			strcpy(e.name, name);
			printf("��������ѧ�ɼ���");
			scanf("%d", &b);e.scores.Math = b;
			printf("������Ӣ��ɼ���");
			scanf("%d", &c);e.scores.English = c;
			printf("�����������ɼ���");
			scanf("%d", &d);e.scores.Computer = d;
			result = InserstList(L, e);
			if (result == 0)printf("����ʧ�ܣ�");
			else printf("����ɹ���");
			system("pause");
			break;
		case 2:
			//�������ѧ����Ϣ
			Display(L);
			system("pause");
			break;
		case 3:
			//��ѧ�Ų���ĳ��ѧ����Ϣ
			printf("������ѧ�Ų���ĳ��ѧ����Ϣ��");
			scanf("%d", &a);
			result = IdLocateList(L, &a);
			if (result == 0)printf("����ʧ�ܣ�");
			else printf("���ҳɹ���");
			system("pause");
			break;
		case 4:
			//����������ĳ��ѧ����Ϣ
			system("pause");
			break;
		case 5:
			//��ѧ�Ŷ�ѧ������
			system("pause");
			break;
		case 6:
			//���ܳɼ���ѧ������
			system("pause");
			break;
		case 7:
			//��ѧ���޸�ĳ��ѧ����Ϣ
			system("pause");
			break;
		case 8:
			//�������޸�ĳ��ѧ����Ϣ
			system("pause");
			break;
		case 9:
			//��ѧ��ɾ��ĳ��ѧ����Ϣ
			system("pause");
			break;
		case 10:
			//������ɾ��ĳ��ѧ����Ϣ
			system("pause");
			break;
		default:
			printf("����Ĳ˵����������������룡\n");
			system("pause");
			break;
		case 0:

			printf("���������ллʹ�ã�\n");
			exit(0);

			break;
		}
	} while (select < 0 || select>10);
}
int main() {
	LNode H;
	Student student1 = { 1640610901,"��һ",{ 51,23,65 } };
	Student student2 = { 1640610902,"����",{ 51,23,65 } };
	Student student3 = { 1640610903,"����",{ 51,23,65 } };
	Student student4 = { 1640610904,"����",{ 51,23,65 } };
	Student student5 = { 1640610905,"����",{ 51,23,65 } };
	H.next = NULL;
	InserstList(&H, student1);
	InserstList(&H, student2);
	InserstList(&H, student3);
	InserstList(&H, student4);
	InserstList(&H, student5);
	while (1) {
		menu(&H);
	}
}