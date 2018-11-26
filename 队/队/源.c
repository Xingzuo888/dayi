#include<stdio.h>
//循环队列的顺序存储
/*#define QUEUESIZE 100                               //队列允许的最大长度
typedef int ElemType;                               //队列的存储类型
typedef struct SqQueue {
	ElemType *data;                                 //队列存储空间的首地址
	int front;                                      //队列位置：指向当前队头元素
	int rear;                                       //队列位置：指向当前队尾元素的下一个位置
}SqQueue;                                           //循环队列
//构造空队
int InitQueue(SqQueue *Q) {
	Q->data = (ElemType *)malloc(QUEUESIZE * sizeof(SqQueue));
	if (Q->data == NULL)return 0;                   //存储分配失败
	Q->front = Q->rear = 0;
	return 1;
}
//求队列的长度
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + QUEUESIZE) % QUEUESIZE;
}
//获取队头元素
int GetFront(SqQueue Q, ElemType *e) {
	if (Q.front == Q.rear)return 0;                 //队列为空
	*e = Q.data[Q.front];
	return 1;
}
//进队
int EnQueue(SqQueue *Q, ElemType e) {
	if ((Q->rear + 1) % QUEUESIZE == Q->front)return 0;     //队列满
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % QUEUESIZE;                    //队尾后移一位
	return 1;
}
//出队
int DeQueue(SqQueue *Q, ElemType *e) {
	if (Q->front == Q->rear)return 0;                     //队列为空
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % QUEUESIZE;                //队头后移一位
	return 1;
}
int main() {
	SqQueue q;
	ElemType e;
	InitQueue(&q);                                        //初始化队列
	EnQueue(&q, 3);EnQueue(&q, 4);EnQueue(&q, 5);EnQueue(&q, 6);   //进队
	DeQueue(&q, &e);printf("出队的元素为：%d\n", e);       //出队并打印队头
	EnQueue(&q, 7);
	DeQueue(&q, &e);
	EnQueue(&q, 8);
	printf("列队中的元素依次出队：");
	while ((DeQueue(&q, &e)) != 0)
		printf("%3d", e);
	printf("\n");
	return 0;
}*/
//链队
typedef int ElemType;
typedef struct QNode {
	ElemType data;
	struct QNode *next;
}QNode;
typedef struct {
	QNode *front;            //队头指针
	QNode *rear;             //队尾指针
}LinkQueue;
//初始化链队列
int InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (QNode *)malloc(sizeof(QNode));
	if (Q->front == NULL)return 0;
	Q->front->next = NULL;
	return 1;
}
//取队头元素
int GetFront(LinkQueue Q, ElemType *e) {
	if (Q.front == Q.rear)return 0;           //队列为空
	*e = Q.front->next->data;
	return 1;
}
//进队
int EnQueue(LinkQueue *Q, ElemType e) {
	QNode *p = (QNode *)malloc(sizeof(QNode));
	if (p == NULL)return 0;
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;           //把p插入到队尾
	Q->rear = p;                //队尾为p
	return 1;
}
//出队
int DeQueue(LinkQueue *Q, ElemType *e) {
	QNode *p;
	if (Q->front == Q->rear)return 0;        //队列为空
	p = Q->front->next;                      //p指向队头结点
	*e = p->data;
	Q->front->next = p->next;                //front的next域指向队头的后一个结点
	if (Q->rear == p)
		Q->rear = Q->front;                  //如果队列中只有一个结点，则删除后，队列为空
	free(p);
	return 1;
}
//判队空
int QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear)return 1;         //队列为空
	else return 0;                          //队列非空
}
int main() {
	LinkQueue q;
	ElemType e;
	InitQueue(&q);                                        //初始化队列
	EnQueue(&q, 3);EnQueue(&q, 4);EnQueue(&q, 5);EnQueue(&q, 6);   //进队
	DeQueue(&q, &e);printf("出队的元素为：%d\n", e);       //出队并打印队头
	EnQueue(&q, 7);
	DeQueue(&q, &e);
	EnQueue(&q, 8);
	if (QueueEmpty(q) != 0)return 0;
	printf("列队中的元素依次出队：");
	while ((DeQueue(&q, &e)) != 0)
		printf("%3d", e);
	printf("\n");
	return 0;
}