#include<stdio.h>
#define N 100

void Convert(int num, int base) {
	int s[N], e;
	int top = 0;
	if (base == 2 || base == 8 || base == 16) {
		while (top<N&&num>0) {
			s[top++] = num%base;
			num = num / base;
		}
		while (top>0) {
			e = s[--top];
			if (e<10)printf("%d", e);
			else printf("%c", e - 10 + 'A');
		}
		printf("\n");
	}
	else {
		printf("�޴˽��Ƶ�����\n");
	}
}
int main() {
	int n, r;
	printf("������ʮ��������");
	scanf("%d", &n);
	printf("������Ҫת���Ľ��ƣ�2��8��16����");
	scanf("%d", &r);
	Convert(n, r);
}