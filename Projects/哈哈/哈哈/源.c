#include<stdio.h>
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode;
int InsertList(LNode *L, int i, ElemType e)
{
	int j;
	LNode *p, *q;
	//初始化，指向头结点，并初始化计数器j=0
	p = L;j = 0;
	//循环：将指针指向第i-1个结点
	while (p != NULL&&j<i - 1)
	{
		p = p->next;
		j++;
	}
	//检果i是否正确(1<=i<=n+1)    j>i-1时，i<1
	if (p == NULL || j>i - 1)return 0;//p==NULL时，i>n+1
									  //分配空间并插入
	q = (LNode*)malloc(sizeof(LNode));
	if (q == NULL)return 0;
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}
void display(LNode *L)
{
	LNode *p;
	p = L->next;
	while (p != NULL)
	{
		printf("%3d", p->data);
		p = p->next;
	}
	printf("\n");
}
void mergeList(LNode *La, LNode *Lb)
{
	LNode *pa, *pb, *pc;
	pa = La->next;
	pb = Lb->next;
	pc = La;
	while (pa!=NULL&&pb!=NULL) {
		if (pa->data > pb->data) {
			pc->next = pb;pb = pb->next;pc = pc->next;
		}
		else {
			pc->next = pa;pa = pa->next;pc = pc->next;
		}
	}
	if (pa != NULL)pc->next = pa;
	else pc->next = pb;
	
}
void deleteElem(LNode *L) {
	LNode *p, *q,*r;
	p = L->next;
	if (p != NULL)q = p->next;
	
	while (p->next!=NULL) {
		r = L->next;
		while (r!=q&&r->data != q->data)r = r->next;
		if (r==q){
			p = p->next;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}
}
int main()
{
	LNode Ha, Hb;
	Ha.next = NULL;
	Hb.next = NULL;
	InsertList(&Ha, 1, 16);
	InsertList(&Ha, 2, 25);
	InsertList(&Ha, 3, 17);
	InsertList(&Ha, 4, 45);
	InsertList(&Ha, 5, 25);
	InsertList(&Ha, 6, 59);
	InsertList(&Ha, 7, 45);
	InsertList(&Ha, 8, 65);
	//显示所有元素
	display(&Ha);

	/*InsertList(&Hb, 1, 12);
	InsertList(&Hb, 2, 21);
	InsertList(&Hb, 3, 39);
	InsertList(&Hb, 4, 55);
	InsertList(&Hb, 5, 62);
	display(&Hb);

	mergeList(&Ha, &Hb);
	*/
	deleteElem(&Ha);
	display(&Ha);


}