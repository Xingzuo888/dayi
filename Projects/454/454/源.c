#include<stdio.h>
#include <string.h>
#define N 5  //�ռ������
typedef struct
{
	int year;
	int month;
	int day;
}Data;
typedef struct
{
	int id; //ͼ����
	char name[20];//ͼ����
	int price;//�۸�
	Data pubData;//��������
}Book;

typedef Book ElemType;
typedef struct
{
	ElemType *elem;//�׵�ַ
	int length;//Ԫ�ظ���
	int listSize;//����
}sqList;
//��ʼ���߱�L,����Ϊsize,�ɹ�����1,ʧ�ܷ���0
int InitiList(sqList *L, int size)
{

	L->elem = (ElemType*)malloc(size * sizeof(ElemType));
	if (L->elem == NULL)return 0;
	L->listSize = size;
	L->length = 3;
	return 1;

}
//����һ��ͼ��
int Insert(sqList *L, int len)
{
	int i;
	if (len<1 || len>L->length + 1)
		return 0;
	else
	{
		L->length++;
		if (L->length>1)
		{
			for (i = L->length;i >= len;i--)
			{
				L->elem[i] = L->elem[i - 1];
				L->elem[i].id++;
			}
		}
		printf("\t������������");
		scanf("%s", L->elem[len - 1].name);
		L->elem[len - 1].id = len;
		printf("\t������۸�");
		scanf("%d", &L->elem[len - 1].price);
		printf("\t������������ڣ�����2008 10 16����");
		scanf("%d%d%d", &L->elem[len - 1].pubData.year, &L->elem[len - 1].pubData.month, &L->elem[len - 1].pubData.day);
		return len;
	}


}
//����һ��ͼ�飬������� �������� ��������ڣ�����0
int LocateList(sqList *L)
{
	char name[20];
	int i;
	printf("\t������Ҫ���ҵ�������");
	scanf("%s", name);
	for (i = 0;i<L->length;i++)
	{
		if (strcmp(name, L->elem[i].name) == 0)
			printf("\t%s������Ϊ%d\n", name, L->elem[i].id);
		else
			printf("\t�����ҵ��鲻����\n");
		break;
	}
}//��ӡ���Ѵ��ڵ�������
void Display(sqList *L)
{
	int i;
	for (i = 0;i<L->length;i++)
	{
		printf("\t��ţ�%d\n", L->elem[i].id);
		printf("\t������");
		puts(L->elem[i].name);
		printf("\t�۸�%d\n", L->elem[i].price);
		printf("\t�������ڣ�%d-%d-%d\n", L->elem[i].pubData.year, L->elem[i].pubData.month, L->elem[i].pubData.day);
		printf("\n");
	}
	return;
}
//ɾ��һ��ͼ��
int Delete(sqList *L, char name[])
{
	int i;
	printf("\t������Ҫɾ��ͼ������֣�");
	scanf("%s", name);
	for (i = 0;i<L->length;i++)
	{
		if (strcmp(name, L->elem[i].name) == 0)
			while (i<L->length&&L->length != 1)
			{
				memcpy(&L->elem[i], &L->elem[i + 1], sizeof L->elem[i]);
				L->elem[i].id--;
				i++;
			}
		L->length--;
		return 1;
	}

	return 0;
}
//�˵�
void menu(sqList *pbook)
{
	//pbook->elem[i].pubData.day

	int select, len;
	int result;
	char name[20];
	do
	{
		system("cls");//����
		printf("\t****************************\n");
		printf("\t*1.����µ�ͼ��            *\n");
		printf("\t*2.ɾ��ָ��ͼ��            *\n");
		printf("\t*3.����ָ��ͼ��(����)      *\n");
		printf("\t*4.��ʾ���е�ͼ��          *\n");
		printf("\t*0.�˳�                    *\n");
		printf("\t****************************\n");
		printf("\t������ٺʹ��룺");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			//����һ��ͼ��
			printf("\t�������%d���飬������Ч�ķ�Χ������ͼ�顣\n", pbook->length);
			printf("\t����������ͼ���λ�ã�");
			scanf("%d", &len);
			result = Insert(pbook, len);
			if (result == 0)
				printf("\t����ͼ��ʧ�ܣ��������ȷ������");
			else
				printf("\t����ͼ��ɹ������к�Ϊ%d\n", result);
			system("pause");
			break;
		case 2:
			//ɾ��ָ��λ�õ�Ԫ�ط���
			result = Delete(pbook, name);
			if (result == 0)
				printf("\tɾ��ͼ��ʧ�ܣ�����ȷ����");
			else
				printf("\tɾ��ͼ��%s�ɹ�", name);
			system("pause");
			break;
		case 3:
			//����ָ��Ԫ�ص�λ��
			LocateList(pbook);
			system("pause");
			break;
		case 4:
			//��ʾ���е�Ԫ��
			Display(pbook);
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
	sqList books;
	InitiList(&books, 100);
	books.elem[0].id = 1;
	books.elem[1].id = 2;
	books.elem[2].id = 3;

	strcpy(books.elem[0].name, "����ѧ");
	strcpy(books.elem[1].name, "����");
	strcpy(books.elem[2].name, "������ѧ");


	books.elem[0].price = 36;
	books.elem[1].price = 80;
	books.elem[2].price = 66;


	books.elem[0].pubData.year = 2008;
	books.elem[1].pubData.year = 2012;
	books.elem[2].pubData.year = 2010;


	books.elem[0].pubData.month = 11;
	books.elem[1].pubData.month = 10;
	books.elem[2].pubData.month = 8;

	books.elem[0].pubData.day = 11;
	books.elem[1].pubData.day = 12;
	books.elem[2].pubData.day = 16;
	while (1)
	{
		menu(&books);
	}

}