#include<stdio.h>
/*struct test {
	int a;
	int b;
};*/
union test {
	int a;
	int b;
};
//�ṹ��ĸ�����Առ�и��Զ������ڴ�ռ�
//����������г�Ա����ͬһ���ڴ�ռ�
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