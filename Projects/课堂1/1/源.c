#include<stdio.h>
#include<string.h>
int main()
{
	int a[10] = {0};
	int *p ,*o,*u;
	p = &a[1];o = &a[2];
	printf("%d\n", o-p);
	/*p = &a[3];//p=100
	*(p + 1) = 400;//p+1=104,*(p+1)就是表示a[4]
	printf("%d\n", a[4]);
	printf("%x\n", p);
	printf("%x\n", p+1);//q-p=4字节=1个单元
	/*指针相减，结果不是相差的字节数，而是相差的单元数。
	单元的大小由指针的基类型决定
	  此规则，也是用于 指针加法*/
	return 0;
}