#include<stdio.h>
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
typedef struct LNode
{
	Book data;
	struct LNode *next;
}LNode;
int InsertList(LNode *L,int i,ElemType e)
{
	int j;
	LNode *p,*q;
	//��ʼ����ָ��ͷ��㣬����ʼ��������j=0
	p=L;j=0;
	//ѭ������ָ��ָ���i-1�����
	while(p!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	//���i�Ƿ���ȷ(1<=i<=n+1)    j>i-1ʱ��i<1
	if(p==NULL||j>i-1)return 0;//p==NULLʱ��i>n+1
	//����ռ䲢����
	q=(LNode*)malloc(sizeof(LNode));
	if(q==NULL)return 0;
	q->data=e;
	q->next=p->next;
	p->next=q;
	return 1;
}
int DeleteList(LNode *L,char a[]) {
	
	LNode *p, *q;
	p = L;
	
	while (p->next!=NULL) {
		q = p->next;
		if (strcmp(q->data.name,a)==0) {
			
			p->next = q->next;
			free(q);
			return 1;
			
		}
		p = p->next;
	}
	if(p->next==NULL) return 0;
	p = L;
	
	
}
int LocateList(LNode *L, char a[]) {
	LNode *p;
	p = L->next;
	while (p!=NULL) {
		if (strcmp(p->data.name,a)==0) {
			printf("\t���\t%-16s�۸�\t��������\n", "����");
			printf("\t%d\t%-16s%d\t%d-%d-%d\n"
				, p->data.id, p->data.name, p->data.price
				, p->data.pubData.year
				, p->data.pubData.month
				, p->data.pubData.day);
			return 1;
		}
		p = p->next;
		
	}
	
	if (p==NULL) return 0;
}
int ChangeList(LNode *L, char a[]) {
	LNode *p;
	int i, j, k, g;
	p = L;
	while (p!=NULL) {
		if (strcmp(a, p->data.name)==0) {
			printf("\tԭ���ļ۸��ǣ�%d\n", p->data.price);
			printf("\t�������޸ļ۸�");
			scanf("%d",&i);
			p->data.price = i;
			printf("\tԭ���ĳ��������ǣ�%d-%d-%d\n"
				, p->data.pubData.year, p->data.pubData.month, p->data.pubData.day);
			printf("\t�������޸ĳ�������(��2008 08 08)��");
			scanf("%d%d%d",&j,&k,&g);
			p->data.pubData.year = j;
			p->data.pubData.month = k;
			p->data.pubData.day = g;
			return 1;
		}
		p = p->next;
	}
	if(p==NULL) return 0;
}
void display(LNode *L)
{
	LNode *p;
	int i = 0;
	p=L->next;
	printf("\t���\t%-16s�۸�\t��������\n","����");
	while(p!=NULL)
	{
		i++;
		p->data.id = i;
		printf("\t%d\t%-16s%d\t%d-%d-%d\n"
			,p->data.id,p->data.name,p->data.price
			,p->data.pubData.year
			,p->data.pubData.month
			,p->data.pubData.day);
		p=p->next;
	}
}
//�˵�
void menu(LNode *L)
{	
	ElemType e;
	
	int i,result;
	int a,b,c,d;
	int select;	
	char n[30];
	do
	{
		system("cls");//����
		printf("\t****************************\n");
		printf("\t*1.����µ�ͼ��            *\n");
		printf("\t*2.ɾ��ָ��ͼ��(����)      *\n");
		printf("\t*3.����ָ��ͼ��(����)      *\n");
		printf("\t*4.�޸�ͼ����Ϣ            *\n");
		printf("\t*5.��ʾ���е�ͼ��          *\n");
		printf("\t*0.�˳�                    *\n");
		printf("\t****************************\n");
		printf("\t������ٺʹ��룺");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			//����һ��Ԫ����ָ��λ��
			printf("\t����������λ�ã�");
			scanf("%d", &i);
			e.id = i;
			printf("\t������������");
			scanf("%s", n);
			strcpy(e.name, n);
			printf("\t��������ļ۸�");
			scanf("%d", &a);
			e.price = a;
			printf("\t��������ĳ�������(��2008 08 08)��");
			scanf("%d%d%d",&b,&c,&d);
			e.pubData.year = b;
			e.pubData.month = c;
			e.pubData.day = d;
			result = InsertList(L, i, e);
			if (result == 0)printf("����ʧ�ܣ�");
			else printf("����ɹ���");
			system("pause");
			break;
		case 2:
			//ɾ��ָ��λ�õ�Ԫ�ط���
			printf("\t������ɾ����������");
			scanf("%s", n);
			
			result = DeleteList(L, &n);
			if (result == 0)printf("ɾ��ʧ�ܣ�");
			else printf("ɾ���ɹ���");
			system("pause");
			break;
		case 3:
			//����ָ��Ԫ�ص�λ��
			printf("\t��������ҵ�������");
			scanf("%s", n);
			
			result = LocateList(L, &n);
			if (result == 0)printf("����ʧ�ܣ�");
			else {
				printf("���ҳɹ���");
				
			}
				system("pause");
			break;
		case 4:
			//�޸�ͼ����Ϣ
			printf("\t������Ҫ�޸ĵ��飺");
			scanf("%s", n);
			result = ChangeList(L, &n);
			if (result == 0)printf("�޸�ʧ�ܣ�");
			else printf("�޸ĳɹ���");
			system("pause");
			break;
		case 5:
			//��ʾ���е�Ԫ��
			display(L);
		
			system("pause");
			break;
		case 0:
			//�˳�
			printf("\t�����Ƿ�ȷ��Ҫ�˳�����(Y/N)");
			//�����û������ѡ��ִ���Ƿ�Ҫ�˳��Ĺ���
			exit(0);
			break;
		}
	}while(select<0||select>5);
}
int main()
{
	LNode H;
	Book book1={1,"���ݽṹ",34,{2014,1,25}};
	Book book2={2,"C���Գ������",31,{2013,11,12}};
	Book book3={3,"Java�������",42,{2015,8,1}};
	Book book4={4,"WebӦ�ÿ���",68,{2016,10,18}};
	Book book5={5,"Android��������",75,{2017,3,30}};
	H.next=NULL;
	InsertList(&H,1,book1);
	InsertList(&H,2,book2);
	InsertList(&H,3,book3);
	InsertList(&H,4,book4);
	InsertList(&H,5,book5);
	
	while(1)
	{
		menu(&H);
	}

}