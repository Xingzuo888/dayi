#include<stdio.h>
#include<string.h>
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
	L->length = 5;
	return 1;

}
//����
int InsertList(sqList *L, int loc) {
	int i;
	if (loc<1 || loc>L->length)
		return 0;
	else
	{
		L->length++;
		
		for (i = L->length;i > loc - 1;i--) {
			L->elem[i] = L->elem[i - 1];
			L->elem[i].id++;
		}
		
		L->elem[loc - 1].id = loc;
		printf("\t������Ҫ��ӵ�������");
		scanf("%s", &L->elem[loc-1].name);
		printf("\t�������鱾�ļ۸�");
		scanf("%d", &L->elem[loc-1].price);
		printf("\t�������������(��2008 08 08)��");
		scanf("%d%d%d", &L->elem[loc-1].pubData.year, &L->elem[loc-1].pubData.month, &L->elem[loc-1].pubData.day);
		
		return 1;
	}
}
//ɾ��
int DeleteList(sqList *L,char name[]) {
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
//����
int LocateList(sqList *L, char name[])
{
	int i;
	for (i = 0;i < L->length;i++) {
		if (strcmp(name, L->elem[i].name) == 0) {
			
			printf("\t�鱾���Ϊ��%d\n",L->elem[i].id);
			printf("\t�鱾�ļ۸�Ϊ��%d\n",L->elem[i].price);
			printf("\t��������Ϊ��%d/%d/%d\n"
				,L->elem[i].pubData.year, L->elem[i].pubData.month, L->elem[i].pubData.day);
			return 1;
		}
	}
	return 0;
}
//��ʾ
int DispList(sqList *L) {
	int i;
	for (i = 0;i < L->length;i++) {
		printf("\t�鱾���Ϊ��%d\n", L->elem[i].id);
		printf("\t����Ϊ��%s\n", L->elem[i].name);
		printf("\t�鱾�ļ۸�Ϊ��%d\n", L->elem[i].price);
		printf("\t��������Ϊ��%d/%d/%d\n"
			, L->elem[i].pubData.year, L->elem[i].pubData.month, L->elem[i].pubData.day);
		printf("\n");
	}
}
//�˵�
void menu(sqList *pbook)
{
	//pbook->elem[i].pubData.day

	int select, loc, result;
	
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
			
			printf("\t��������ӵ�λ�ã�"); 
			scanf("%d", &loc);
			result = InsertList(pbook, loc);
			if (result == 0)printf("\t���ʧ�ܣ�\n");
			else printf("\t��ӳɹ���\n");
			system("pause");
			break;
		case 2:
			result = DeleteList(pbook, name);
			if (result == 0)
				printf("\tɾ��ͼ��ʧ�ܣ�����ȷ����");
			else
				printf("\tɾ��ͼ��%s�ɹ�", name);
			system("pause");
			break;
		case 3:
			
			printf("\t��������ҵ�������");
			scanf("%s",name);
			result = LocateList(pbook, &name);
			if (result == 0)printf("\t����ʧ�ܣ�\n");
			else {
				printf("\t���ҳɹ���\n");
				
				
			}
			system("pause");
			break;
		case 4:
			//��ʾ���е��鼮
			DispList(pbook);
			
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
	books.elem[3].id = 4;
	books.elem[4].id = 5;

	strcpy(books.elem[0].name, "����");
	strcpy(books.elem[1].name, "��ѧ");
	strcpy(books.elem[2].name, "Ӣ��");
	strcpy(books.elem[3].name, "���ݽṹ");
	strcpy(books.elem[4].name, "C����");

	books.elem[0].price = 20;
	books.elem[1].price = 20;
	books.elem[2].price = 20;
	books.elem[3].price = 30;
	books.elem[4].price = 30;

	books.elem[0].pubData.year = 2004;
	books.elem[1].pubData.year = 2004;
	books.elem[2].pubData.year = 2004;
	books.elem[3].pubData.year = 2004;
	books.elem[4].pubData.year = 2004;

	books.elem[0].pubData.month = 11;
	books.elem[1].pubData.month = 11;
	books.elem[2].pubData.month = 11;
	books.elem[3].pubData.month = 11;
	books.elem[4].pubData.month = 11;

	books.elem[0].pubData.day = 12;
	books.elem[1].pubData.day = 12;
	books.elem[2].pubData.day = 12;
	books.elem[3].pubData.day = 12;
	books.elem[4].pubData.day = 12;

	while (1)
	{
		menu(&books);
	}

}