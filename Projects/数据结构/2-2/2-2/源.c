#include<stdio.h>
typedef struct LNode {
	char data;
	struct LNode *next;
}LNode;
void display(LNode *L) {
	LNode *p = L->next;
	while (p != NULL) {
		printf("%3c", p->data);
		p = p->next;
	}
	printf("\n");
}
void reverseLink(LNode *L) {
	LNode *p, *q;
	p = L->next;
	L->next = NULL;

	while (p != NULL) {
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;

	}
}
int main() {
	LNode H, na, nb, nc, nd, ne, nf;
	na.data = 'A';nb.data = 'B';nc.data = 'C';
	nd.data = 'D';ne.data = 'E';nf.data = 'F';
	H.next = &na;na.next = &nb;nb.next = &nc;
	nc.next = &nd;nd.next = &ne;ne.next = &nf;nf.next = NULL;
	display(&H);
	reverseLink(&H);
	display(&H);
}