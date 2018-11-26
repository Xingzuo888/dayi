#include<stdio.h>
#include <string.h>
#define N 5  //�ռ������
typedef struct
{
	int year;
	int month;
	int day;
}Date;
typedef struct
{
	int id; //ͼ����
	char name[20];//ͼ����
	int price;//�۸�
	Date pubDate;//��������
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
	L->length = N;
	return 1;

}
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
			for (i = L->length;i >= len - 1;i--)
			{
				memcpy(&L->elem[i], &L->elem[i - 1], sizeof L->elem[i]);
				L->elem[i].id++;
			}
		}
		printf("\t������������");
		scanf("%s", L->elem[len - 1].name);
		L->elem[len - 1].id = len;
		printf("\t������۸�");
		scanf("%d", &L->elem[len - 1].price);
		printf("\t������������ڣ�����2017 11 11����");
		scanf("%d%d%d", &L->elem[len - 1].pubDate.year, &L->elem[len - 1].pubDate.month, &L->elem[len - 1].pubDate.day);
		return len;
	}


}
int Delete(sqList *L, char name[])
{
	int i;
	for (i = 0;i<L->length;i++)
	{
		if (strcmp(name, L->elem[i].name) == 0)
		{
			while (i<L->length && L->length != 1)
			{
				memcpy(&L->elem[i], &L->elem[i + 1], sizeof L->elem[i - 1]);
				L->elem[i].id--;
				i++;
			}
			L->length--;
			return 1;
		}
	}
	return 0;
}
void Locate(sqList *L, char name[])
{
	int i;;
	for (i = 0;i<L->length;i++)
		if (strcmp(name, L->elem[i].name) == 0)
		{
			printf("\t������%s�ڵ�%dλ��\n", name, L->elem[i].id);
			return;
		}
	printf("\t������û��%s�Ȿ��\n", name);
	return;
}
void Display(sqList *L)
{
	int i;
	for (i = 0;i<L->length;i++)
	{
		printf("\t��ţ�%d\n", L->elem[i].id);
		printf("\t������");
		puts(L->elem[i].name);
		printf("\t�۸�%d\n", L->elem[i].price);
		printf("\t�������ڣ�%d-%d-%d\n", L->elem[i].pubDate.year, L->elem[i].pubDate.month, L->elem[i].pubDate.day);
		printf("\n");
	}
	return;
}
//�˵�
void menu(sqList *pbook)
{
	//pbook->elem[i].pubData.day

	int select, len, result;
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
			//����һ��Ԫ����ָ��λ��
			printf("\t��������%d���飬������Ч��Χ�����\n", pbook->length);
			printf("\t���������λ��");
			scanf("%d", &len);
			result = Insert(pbook, len);
			if (result == 0)
				printf("\t���ʧ��\n");
			else
				printf("\t�ѳɹ���ӵ�%dλ��\n", result);
			system("pause");
			break;
		case 2:
			//ɾ��ָ��λ�õ�Ԫ�ط���
			printf("\t������ɾ����������");
			scanf("%s", name);
			result = Delete(pbook, name);
			if (result == 0)
				printf("\tɾ��ʧ��\n");
			else
			{
				printf("\t�ѳɹ�ɾ��");
				puts(name);
			}
			system("pause");
			break;
		case 3:
			//����ָ��Ԫ�ص�λ��
			printf("\t��������ҵ�������");
			scanf("%s", name);
			Locate(pbook, name);
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
	//��ʼ��
	books.elem[0].id = 1;
	books.elem[1].id = 2;
	books.elem[2].id = 3;
	books.elem[3].id = 4;
	books.elem[4].id = 5;

	strcpy(books.elem[0].name, "Datestructure");
	strcpy(books.elem[1].name, "Math");
	strcpy(books.elem[2].name, "Chinese");
	strcpy(books.elem[3].name, "English");
	strcpy(books.elem[4].name, "Numberlogic");


	books.elem[0].price = 50;
	books.elem[1].price = 50;
	books.elem[2].price = 50;
	books.elem[3].price = 50;
	books.elem[4].price = 50;


	books.elem[0].pubDate.year = 2017;
	books.elem[1].pubDate.year = 2017;
	books.elem[2].pubDate.year = 2017;
	books.elem[3].pubDate.year = 2017;
	books.elem[4].pubDate.year = 2017;


	books.elem[0].pubDate.month = 11;
	books.elem[1].pubDate.month = 11;
	books.elem[2].pubDate.month = 11;
	books.elem[3].pubDate.month = 11;
	books.elem[4].pubDate.month = 11;


	books.elem[0].pubDate.day = 11;
	books.elem[1].pubDate.day = 11;
	books.elem[2].pubDate.day = 11;
	books.elem[3].pubDate.day = 11;
	books.elem[4].pubDate.day = 11;

	//������ʼ��
	while (1)
	{
		menu(&books);
	}

}