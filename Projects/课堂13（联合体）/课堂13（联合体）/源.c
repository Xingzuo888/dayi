#include<stdio.h>
/*struct test {
	int a;
	int b;
};*/
union test {
	int a;
	int b;
};
//结构体的各个成员占有各自独立的内存空间
//联合体的所有成员共享同一个内存空间
int main()
{
	//struct test yz;
	union test yz;
	yz.a = 10;
	yz.b = 20;
	printf("%d\n", yz.a);
	printf("%d\n", yz.b);
	printf("%d\n", sizeof(yz));
	return 0;
}