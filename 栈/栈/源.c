//顺序栈
/*#include<stdio.h>
#define STACKSIZE 100         //栈允许的最大长度
#define STACKINCREMENT 20     //存储空间分配增量
typedef  int ElemType;        //栈的存储类型
typedef struct SqStack {
ElemType *base;
int *top;
int stacksize;
}SqStack;
//栈的初始化
int InitStack(SqStack *S) {
S->base = (ElemType *)malloc(STACKSIZE * sizeof(ElemType));
if (S->base == NULL) return 0;
S->top = S->base;
S->stacksize = STACKSIZE;
return 1;
}
//判栈空
int StackEmpty(SqStack S) {
if (S.top == S.base)return 1;
else return 0;
}
//获取栈顶元素
int GetTop(SqStack S, ElemType *e) {
if (S.top == S.base)return 0;   //栈空
else {
*e = *(S.top - 1);         //将栈顶元素的之赋值给e
return 1;
}
}
//进栈
int Push(SqStack *S, ElemType e) {
if (S->top - S->base >= S->stacksize) {       //栈满，追加存储空间
S->base = (ElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType));
if (S->base == NULL)return 0;            //存储分配失败
S->top = S->base + S->stacksize;
S->stacksize += STACKINCREMENT;
}
*S->top++ = e;                              //先插入元素，然后将栈顶指针上移一位
return 1;
}
//出栈
int Pop(SqStack *S, ElemType *e) {
if (S->top == S->base)return 0;             //栈空
*e = *--S->top;                             //先将栈顶指针下移一位，然后取出元素值赋值给e
return 1;
}
//获取栈中的元素个数
int StackLength(SqStack S) {
return S.top - S.base;
}
int main() {
int i, n;
ElemType e;
SqStack s;                                                           //声明一个栈
InitStack(&s);                                                       //初始化栈
Push(&s, 3);Push(&s, 4);Push(&s, 5);Push(&s, 6);                     //3、4、5、6进栈
Pop(&s, &e);printf("出栈的元素为%d\n", e);                           //出栈并打印栈顶元素
Push(&s, 7);                                                         //7进栈
Pop(&s, &e);                                                         //出栈
Push(&s, 8);                                                         //8进栈
n = StackLength(s);                                                  //获取栈的长度
printf("栈中的元素依次出栈：");
for (i = 0;i < n;i++) {                                              //栈中元素依次出栈并打印
Pop(&s, &e);
printf("%3d", e);
}
printf("\n");
return 0;
}*/
//链栈
#include<stdio.h>
typedef int ElemType;                          //栈的存储类型
typedef struct LNode {                         //链栈结点
	ElemType data;                             //数据域
	struct Node *next;                         //指针域
}LNode;
typedef struct LinkStack {                     //链栈
	LNode *top;                                //栈顶指针
}LinkStack;
//构造空栈
void InitStack(LinkStack *S) {
	S->top = NULL;                             //初始化空栈
}
//获取栈顶元素
int GetTop(LinkStack S, ElemType *e) {
	if (S.top == NULL)return 0;                //栈空
	else {
		*e = S.top->data;                      //将栈顶元素的值赋值给e
		return 1;
	}
}
//进栈
int Push(LinkStack *S, ElemType e) {
	LNode *p;
	p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL)return 0;
	p->data = e;
	p->next = S->top;                         //把p所指结点作为栈顶结点
	S->top = p;                    //栈顶指向p
	free(p);
	return 1;
}
//出栈
int Pop(LinkStack *S, ElemType *e) {
	LinkStack *p;
	if (S->top == NULL)return 0;              //栈空
	*e = S->top->data;                        //取出栈顶元素的值
	p = S->top;
	S->top = S->top->next;                    //新的栈顶为当前栈顶的下一个结点
	free(p);
	return 1;
}
//判断栈是否为空
int StackEmpty(LinkStack S) {
	if (S.top == NULL)return 1;               //栈空
	else return 0;                            //栈非空
}
int main() {
	int i, n;
	ElemType e;
	LinkStack s;                               //声明一个栈
	InitStack(&s);                             //初始化栈
	system("title  第3章  链栈");
	Push(&s, 3);Push(&s, 4);Push(&s, 5);Push(&s, 6);   //3，4，5，6进栈
	Pop(&s, &e);printf("出栈的元素为%d\n", e);         //出栈并打印栈顶元素
	Push(&s, 7);
	Pop(&s, &e);
	Push(&s, 8);
	printf("栈中元素依次出栈：");
	while (s.top != NULL) {                   //栈中元素依次出栈并打印
		Pop(&s, &e);
		printf("%3d", e);
	}
	printf("\n");
	return 0;
}