#include<stdio.h>
typedef struct {
	int Math;      //��ѧ
	int English;   //Ӣ��
	int Computer;  //�����
	int sum;      //�ܷ�
}score;
typedef struct {
	int ID;//ѧ��
	char name[20];//����
	score scores;
}student;
typedef student ElemType;
typedef struct LNode {
	student data;
	struct LNode *next;
}LNode;
void menu(LNode *L) {
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
			break;
		case 2:
			//�������ѧ����Ϣ
			break;
		case 3:
			//��ѧ�Ų���ĳ��ѧ����Ϣ
			break;
		case 4:
			//����������ĳ��ѧ����Ϣ
			break;
		case 5:
			//��ѧ�Ŷ�ѧ������
			break;
		case 6:
			//���ܳɼ���ѧ������
			break;
		case 7:
			//��ѧ���޸�ĳ��ѧ����Ϣ
			break;
		case 8:
			//�������޸�ĳ��ѧ����Ϣ
			break;
		case 9:
			//��ѧ��ɾ��ĳ��ѧ����Ϣ
			break;
		case 10:
			//������ɾ��ĳ��ѧ����Ϣ
			break;
		default:
			printf("����Ĳ˵����������������룡\n");
		case 0:
			printf("\t�����Ƿ�ȷ��Ҫ�˳�����(Y/N)");
			//�����û������ѡ��ִ���Ƿ�Ҫ�˳��Ĺ���
			exit(0);
			printf("���������ллʹ�ã�\n");

		}
	} while (select < 0 || select>10);
}

int main() {
	LNode H;
	while (1) {
		menu(&H);
	}
}