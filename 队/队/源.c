#include<stdio.h>
//ѭ�����е�˳��洢
/*#define QUEUESIZE 100                               //�����������󳤶�
typedef int ElemType;                               //���еĴ洢����
typedef struct SqQueue {
	ElemType *data;                                 //���д洢�ռ���׵�ַ
	int front;                                      //����λ�ã�ָ��ǰ��ͷԪ��
	int rear;                                       //����λ�ã�ָ��ǰ��βԪ�ص���һ��λ��
}SqQueue;                                           //ѭ������
//����ն�
int InitQueue(SqQueue *Q) {
	Q->data = (ElemType *)malloc(QUEUESIZE * sizeof(SqQueue));
	if (Q->data == NULL)return 0;                   //�洢����ʧ��
	Q->front = Q->rear = 0;
	return 1;
}
//����еĳ���
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + QUEUESIZE) % QUEUESIZE;
}
//��ȡ��ͷԪ��
int GetFront(SqQueue Q, ElemType *e) {
	if (Q.front == Q.rear)return 0;                 //����Ϊ��
	*e = Q.data[Q.front];
	return 1;
}
//����
int EnQueue(SqQueue *Q, ElemType e) {
	if ((Q->rear + 1) % QUEUESIZE == Q->front)return 0;     //������
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % QUEUESIZE;                    //��β����һλ
	return 1;
}
//����
int DeQueue(SqQueue *Q, ElemType *e) {
	if (Q->front == Q->rear)return 0;                     //����Ϊ��
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % QUEUESIZE;                //��ͷ����һλ
	return 1;
}
int main() {
	SqQueue q;
	ElemType e;
	InitQueue(&q);                                        //��ʼ������
	EnQueue(&q, 3);EnQueue(&q, 4);EnQueue(&q, 5);EnQueue(&q, 6);   //����
	DeQueue(&q, &e);printf("���ӵ�Ԫ��Ϊ��%d\n", e);       //���Ӳ���ӡ��ͷ
	EnQueue(&q, 7);
	DeQueue(&q, &e);
	EnQueue(&q, 8);
	printf("�ж��е�Ԫ�����γ��ӣ�");
	while ((DeQueue(&q, &e)) != 0)
		printf("%3d", e);
	printf("\n");
	return 0;
}*/
//����
typedef int ElemType;
typedef struct QNode {
	ElemType data;
	struct QNode *next;
}QNode;
typedef struct {
	QNode *front;            //��ͷָ��
	QNode *rear;             //��βָ��
}LinkQueue;
//��ʼ��������
int InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (QNode *)malloc(sizeof(QNode));
	if (Q->front == NULL)return 0;
	Q->front->next = NULL;
	return 1;
}
//ȡ��ͷԪ��
int GetFront(LinkQueue Q, ElemType *e) {
	if (Q.front == Q.rear)return 0;           //����Ϊ��
	*e = Q.front->next->data;
	return 1;
}
//����
int EnQueue(LinkQueue *Q, ElemType e) {
	QNode *p = (QNode *)malloc(sizeof(QNode));
	if (p == NULL)return 0;
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;           //��p���뵽��β
	Q->rear = p;                //��βΪp
	return 1;
}
//����
int DeQueue(LinkQueue *Q, ElemType *e) {
	QNode *p;
	if (Q->front == Q->rear)return 0;        //����Ϊ��
	p = Q->front->next;                      //pָ���ͷ���
	*e = p->data;
	Q->front->next = p->next;                //front��next��ָ���ͷ�ĺ�һ�����
	if (Q->rear == p)
		Q->rear = Q->front;                  //���������ֻ��һ����㣬��ɾ���󣬶���Ϊ��
	free(p);
	return 1;
}
//�жӿ�
int QueueEmpty(LinkQueue Q) {
	if (Q.front == Q.rear)return 1;         //����Ϊ��
	else return 0;                          //���зǿ�
}
int main() {
	LinkQueue q;
	ElemType e;
	InitQueue(&q);                                        //��ʼ������
	EnQueue(&q, 3);EnQueue(&q, 4);EnQueue(&q, 5);EnQueue(&q, 6);   //����
	DeQueue(&q, &e);printf("���ӵ�Ԫ��Ϊ��%d\n", e);       //���Ӳ���ӡ��ͷ
	EnQueue(&q, 7);
	DeQueue(&q, &e);
	EnQueue(&q, 8);
	if (QueueEmpty(q) != 0)return 0;
	printf("�ж��е�Ԫ�����γ��ӣ�");
	while ((DeQueue(&q, &e)) != 0)
		printf("%3d", e);
	printf("\n");
	return 0;
}