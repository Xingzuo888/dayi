#include<stdio.h>
#define N 100
#define M 100
#define MAXSIZE 100
typedef struct {
	char data;          //���ֵ
	int weight;         //Ȩֵ
	int parent;         //˫�׽��
	int lchild;         //���ӽ��
	int rchild;         //�Һ��ӽ��
} HTNode;
typedef struct {
	char cd[N];         //��Ź���������
	int start;          //��start��ʼ��cd�еĹ���������
}HCode;

//��ʾ��Ӧ����
void CreateHT(HTNode ht[], int n) {       //���������������������ͽ����n
	int i, k, lnode, rnode;
	int min1, min2;
	for (i = 0;i < 2 * n - 1;i++) {       //���н���������ó�ֵ-1
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	}
	for (i = n;i < 2 * n - 1;i++) {       //�����������
		min1 = min2 = 32767;              //��int�����ֵ��32767
		lnode = rnode = -1;               //lnode��rnode��¼��СȨֵ���������λ��
		for (k = 0;k <= i - 1;k++) {
			if (ht[k].parent == -1) {    //ֻ����δ����������Ľ���в���
				if (ht[k].weight < min1) {   //��ȨֵС����С�������Ȩֵ
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else if (ht[k].weight < min2) {
					min2 = ht[k].weight;
					rnode = k;
				}
			}
		}
		//������С���ĸ������1
		ht[lnode].parent = i;
		ht[rnode].parent = i;
		//������С���ĸ����ȨֵΪ������С���Ȩֵ֮��
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		//������������ҽ��
		ht[i].lchild = lnode;
		ht[i].rchild = rnode;
	}
}

//����
void editHCode(HTNode ht[], HCode hcd[], int n) {    //���뺯��
	char string[MAXSIZE];
	int i, j, k;
	scanf("%s", string);          //��Ҫ���б�����ַ�������string������
	printf("\n�����������\n");
	for (i = 0;string[i] != '#';i++) {     //#Ϊ��ֹ��־
		for (j = 0;j < n;j++) {
			//ѭ�������������ַ���ͬ�ı�ţ���ͬ�ľ��������ַ��ı���
			if (string[i] == ht[j].data) {
				for (k = hcd[j].start;k <= n;k++) {
					printf("%c", hcd[j].cd[k]);
					break;           //�����ɺ�������ǰforѭ��
				}
			}
		}
	}
}

//����
void deHCode(HTNode ht[], HCode hcd[], int n) {     //���뺯��
	char code[MAXSIZE];
	int i, j, l, k, m, x;
	scanf("%s", code);       //��Ҫ����������ַ�������code������
	printf("\n�����������\n");
	while (code[0] != '#')
	for (i = 0;i < n;i++) {
		m = 0;         //mΪ��ͬ��������ļ�����
		//jΪ��¼���洢�ַ��ı������
		for (k = hcd[i].start, j = 0;k <= n;k++, j++) {
			if (code[j] == hcd[i].cd[k])      //������ͬ����ʱ��mֵ��1
				m++;
		}
		//��������ַ��������洢�ı����ַ����������ʱ�������data����
		if (m == j) {
			printf("%c", ht[i].data);
			//���Ѿ�ʹ�ù���code��������ַ���ɾ��
			for (x = 0;code[x - 1] != '#';x++)
				code[x] = code[x + j];
		}
	}
}
void main() {
	int n = 26, i;
	char orz, back, flag = 1;
	char str[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };    //��ʼ��
	int fnum[] = { 186,64,13,22,32,103,21,15,47,57,1,2,32,20,57,63,15,1,48,51,80,23,8,18,1,16 };                                 //��ʼ��
	HTNode ht[M];          //�����ṹ��
	HCode hcd[N];          //�����ṹ��
	for (i = 0;i < n;i++) {
		ht[i].data = str[i];
		ht[i].weight = fnum[i];
	}
	while (flag) {
		printf("\n");
		printf("       ��**********������������***********\n\n");
		printf("        ************************************");
		printf("\n           *  A----------------��ʾ��Ӧ������ *");
		printf("\n           *  B----------------���б���       *");
		printf("\n           *  C----------------��������       *");
		printf("\n           *  D----------------�˳�           *\n");
		printf("         ***********************************");
		printf("\n");
		printf("        ������ѡ��ı�ţ�");
		scanf("%c", &orz);
		switch (orz) {
		case 'a':
		case 'A':
			system("cls");
			CreateHT(ht, n);             //������������
			//CreateHCode(ht, hcd, n);     //��������������
			//DispHCode(ht, hcd, n);       //��ʾ����������
			printf("\n�����������...");
			getch();
			system("cls");
			break;
		case 'b':
		case 'B':
			system("cls");
			printf("������Ҫ���б�����ַ�������#��������\n");
			editHCode(ht, hcd, n);       //��������ַ����б���
			printf("\n�����������...");
			getch();
			system("cls");
			break;
		case 'c':
		case 'C':
			system("cls");
			DispHCode(ht, hcd, n);
			printf("��������루��#��������\n");
			deHCode(ht, hcd, n);         //��������ַ���������
			printf("\n�����������...");
			getch();
			system("cls");
			break;
		case 'd':
		case 'D':
			flag = 0;break;
		defautlt:
			system("cls");
		}
	}
}