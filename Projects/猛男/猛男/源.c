#include<stdio.h>
/*
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
*/
int main() {
	unsigned long n, x = 1, d1 = 0;
	int t, i;
	scanf("%d", &n);
	while (n != 0) {
		t = n % 10;
		if (t % 2 == 0) {
			d1 = t*x + d1;
			x *= 10;
		}
		n = (n-t)/10;
	}
	printf("%d\n", d1);
}