//˳��ջ
/*#include<stdio.h>
#define STACKSIZE 100         //ջ�������󳤶�
#define STACKINCREMENT 20     //�洢�ռ��������
typedef  int ElemType;        //ջ�Ĵ洢����
typedef struct SqStack {
ElemType *base;
int *top;
int stacksize;
}SqStack;
//ջ�ĳ�ʼ��
int InitStack(SqStack *S) {
S->base = (ElemType *)malloc(STACKSIZE * sizeof(ElemType));
if (S->base == NULL) return 0;
S->top = S->base;
S->stacksize = STACKSIZE;
return 1;
}
//��ջ��
int StackEmpty(SqStack S) {
if (S.top == S.base)return 1;
else return 0;
}
//��ȡջ��Ԫ��
int GetTop(SqStack S, ElemType *e) {
if (S.top == S.base)return 0;   //ջ��
else {
*e = *(S.top - 1);         //��ջ��Ԫ�ص�֮��ֵ��e
return 1;
}
}
//��ջ
int Push(SqStack *S, ElemType e) {
if (S->top - S->base >= S->stacksize) {       //ջ����׷�Ӵ洢�ռ�
S->base = (ElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType));
if (S->base == NULL)return 0;            //�洢����ʧ��
S->top = S->base + S->stacksize;
S->stacksize += STACKINCREMENT;
}
*S->top++ = e;                              //�Ȳ���Ԫ�أ�Ȼ��ջ��ָ������һλ
return 1;
}
//��ջ
int Pop(SqStack *S, ElemType *e) {
if (S->top == S->base)return 0;             //ջ��
*e = *--S->top;                             //�Ƚ�ջ��ָ������һλ��Ȼ��ȡ��Ԫ��ֵ��ֵ��e
return 1;
}
//��ȡջ�е�Ԫ�ظ���
int StackLength(SqStack S) {
return S.top - S.base;
}
int main() {
int i, n;
ElemType e;
SqStack s;                                                           //����һ��ջ
InitStack(&s);                                                       //��ʼ��ջ
Push(&s, 3);Push(&s, 4);Push(&s, 5);Push(&s, 6);                     //3��4��5��6��ջ
Pop(&s, &e);printf("��ջ��Ԫ��Ϊ%d\n", e);                           //��ջ����ӡջ��Ԫ��
Push(&s, 7);                                                         //7��ջ
Pop(&s, &e);                                                         //��ջ
Push(&s, 8);                                                         //8��ջ
n = StackLength(s);                                                  //��ȡջ�ĳ���
printf("ջ�е�Ԫ�����γ�ջ��");
for (i = 0;i < n;i++) {                                              //ջ��Ԫ�����γ�ջ����ӡ
Pop(&s, &e);
printf("%3d", e);
}
printf("\n");
return 0;
}*/
//��ջ
#include<stdio.h>
typedef int ElemType;                          //ջ�Ĵ洢����
typedef struct LNode {                         //��ջ���
	ElemType data;                             //������
	struct Node *next;                         //ָ����
}LNode;
typedef struct LinkStack {                     //��ջ
	LNode *top;                                //ջ��ָ��
}LinkStack;
//�����ջ
void InitStack(LinkStack *S) {
	S->top = NULL;                             //��ʼ����ջ
}
//��ȡջ��Ԫ��
int GetTop(LinkStack S, ElemType *e) {
	if (S.top == NULL)return 0;                //ջ��
	else {
		*e = S.top->data;                      //��ջ��Ԫ�ص�ֵ��ֵ��e
		return 1;
	}
}
//��ջ
int Push(LinkStack *S, ElemType e) {
	LNode *p;
	p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL)return 0;
	p->data = e;
	p->next = S->top;                         //��p��ָ�����Ϊջ�����
	S->top = p;                    //ջ��ָ��p
	free(p);
	return 1;
}
//��ջ
int Pop(LinkStack *S, ElemType *e) {
	LinkStack *p;
	if (S->top == NULL)return 0;              //ջ��
	*e = S->top->data;                        //ȡ��ջ��Ԫ�ص�ֵ
	p = S->top;
	S->top = S->top->next;                    //�µ�ջ��Ϊ��ǰջ������һ�����
	free(p);
	return 1;
}
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(LinkStack S) {
	if (S.top == NULL)return 1;               //ջ��
	else return 0;                            //ջ�ǿ�
}
int main() {
	int i, n;
	ElemType e;
	LinkStack s;                               //����һ��ջ
	InitStack(&s);                             //��ʼ��ջ
	system("title  ��3��  ��ջ");
	Push(&s, 3);Push(&s, 4);Push(&s, 5);Push(&s, 6);   //3��4��5��6��ջ
	Pop(&s, &e);printf("��ջ��Ԫ��Ϊ%d\n", e);         //��ջ����ӡջ��Ԫ��
	Push(&s, 7);
	Pop(&s, &e);
	Push(&s, 8);
	printf("ջ��Ԫ�����γ�ջ��");
	while (s.top != NULL) {                   //ջ��Ԫ�����γ�ջ����ӡ
		Pop(&s, &e);
		printf("%3d", e);
	}
	printf("\n");
	return 0;
}