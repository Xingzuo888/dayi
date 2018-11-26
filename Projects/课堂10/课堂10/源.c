#include<stdio.h>
#include<stdlib.h>
/*int main()
{
	int NUM;
	int *p, i;
	printf("请输入人数：");
	scanf("%d", &NUM);
	p = (int *)malloc(sizeof(int)*NUM);
	if (p == NULL)     //NULL  假
	{
		printf("分配内存不成功\n");
		exit(1);//结束程序
	}
	for (i = 0;i < NUM;i++)
		scanf("%d", &p[i]);//p[1]   *(p+i)
	for (i = 0;i < NUM;i++)
		printf("%d\n", p[i]);
	free(p);
	return 0;
}*/
/*int Strcmp(const char *s1, const char *s2);
int main()
{
	char *s1 = "hello", *s2 = "hello!";
	printf(Strcmp(s1, s2) ? "Identical" : "Different");
	return 0;
}
int Strcmp(const char *s1,const  char *s2)
{
	for (;*s1 != '\0'&&*s2 != '\0';++s1, ++s2)
		if (*s1 != *s2)return 0;
	if (*s1 + *s2 == 0)return 1;
	return 0;
}*/
/*int stoi(const char *s)
{
	int  d = 0;
	char *p = (char *)s;
	for (;*p != '\0';++p)
		d = d * 10 + (*p - '0');
	return d;
}
int sigma(int n)
{
	int i, sum;
	for (i = 1, sum = 0;i <= n;++i)sum += i;
	return sum;
}
int main(int argc, char *argv[1])
{
	if (argc < 2) {
		printf("Usage:8-19 n\ne.g. 8-19 100");
		return -1;
	}
	printf("1+2+...+%d", argv[1], sigma(stoi(argv[1])));
	return 0;
}*/
/*char * Strchr(char ch, const char *s) {
	for (;*s != '\0';++s)
		if (*s == ch)return (char *)s;
	return NULL;
}
int main() {
	char *s = "The quick fox jumps over a lazy dog";
	printf(Strchr('x', s) != NULL ? "Found" : "Not found");
	return 0;
}*/
double inc(double e)
{
	return ++e;
}
double square(double e)
{
	return e*e;
}
double negative(double e)
{
	return -e;
}
double out(double e)
{
	printf("%7.lf", e);
	return e;
}
void traverse(double a[], int len, double(*f)(double))
{
	int i;
	for (i = 0;i < len;i++) a[i] = f(a[i]);
}
/*int main()
{
	#define N 10
	double a[10] = { 0.9,-1.1,2.2,3.3,-4.4,5.5,6.6,7.7,8.8,-9.9 };
	
	printf("original:\n");
	traverse(a, N, out);
	putchar('\n');
	
	printf("increased:\n");
	traverse(a, N, inc);
	traverse(a, N, out);
	putchar('\n');
	
	printf("squared:\n");
	traverse(a, N, square);
	traverse(a, N, out);
	putchar('\n');

	printf("negatived:\n");
	traverse(a, N, negative);
	traverse(a, N, out);
	
	return 0;
}*/
double copy(double e)
{
	return e;
}
typedef double(*FUNCTION)(double);
typedef char * STRING;
int main()
{
	#define N 10
	double a[10] = { 0.9,-1.1,2.2,3.3,-4.4,5.5,6.6,7.7,8.8,-9.9 };
	FUNCTION f[] = { copy,inc,square,negative };
	STRING title[] = { "original","increased","squared","negatived" };
	int i;
	for (i = 0;i < 4;++i) {
		printf("%s:\n", title[i]);
		traverse(a, N, f[i]);
		traverse(a, N, out);
		putchar('\n');
	}
	return 0;
}