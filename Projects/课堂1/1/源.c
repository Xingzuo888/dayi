#include<stdio.h>
#include<string.h>
int main()
{
	int a[10] = {0};
	int *p ,*o,*u;
	p = &a[1];o = &a[2];
	printf("%d\n", o-p);
	/*p = &a[3];//p=100
	*(p + 1) = 400;//p+1=104,*(p+1)���Ǳ�ʾa[4]
	printf("%d\n", a[4]);
	printf("%x\n", p);
	printf("%x\n", p+1);//q-p=4�ֽ�=1����Ԫ
	/*ָ�������������������ֽ������������ĵ�Ԫ����
	��Ԫ�Ĵ�С��ָ��Ļ����;���
	  �˹���Ҳ������ ָ��ӷ�*/
	return 0;
}