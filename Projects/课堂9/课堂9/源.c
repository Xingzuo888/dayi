#include<stdio.h>
/*int main()
{
	int yz = 100, zhangsan = 200;
	//int * const p = &yz;
	const int *p = &yz;
	//����ͨ��pȥ�ı�pָ��ĵ�ַ
	//p = &zhangsan;
	//int const *p = &yz;
	p = 300;
	//yz = 400;
	printf("%d\n", yz);
	return 0;
}*/
/*int main()
{
	int a[3] = { 0 };
	int i, *p;
	p = &a[0];
	//p = a;//C�����У����������������׵�ַ
	i = 0;
	while (i < 3)
	{
		*(p+i) = i;
		//*(a++) = i; �����д���Ϊ�������ǳ���
		//*(p++) = i;
		//p[i] = i;//C�����У����Խ�����Ӧ����ָ����
		i++;
	}
	for (i = 0;i < 3;i++)
		printf("%d\n", a[i]);
	return 0;
}*/
/*int main()
{
	//char str1[] = { 'h','e','l','l','o','\0' };
	//char str1[] = "hello";
	char *str1 = "hello";
	//C�����У����ǽ��ַ�����hello����ֵ��str1��
	//���Ǳ�ʾ���ַ�����hello�����׵�ַ��ֵ��str1
	printf("%s\n", str1);
	return 0;
}
/*int main()
{
	int a = 10, b = 20, c = 30;
	int *test[3];
	test[0] = &a;
	test[1] = &b;
	test[2] = &c;
	printf("%d\n", *test[0]);
	printf("%d\n", *test[1]);
	printf("%d\n", *test[2]);

	return 0;
}*/
/*int main()
{
	int a = 10, b = 20, c = 30;
	int *test[3];//ָ������
	int(*p)[3];//����ָ��
	// p�Ǳ������� *p����p��ָ���ͣ�p�Ļ�������int ��3��
	return 0;
}*/
/*int main()
{
	int *p[5];//ָ������
	//int (*p)[5];  //  ����ָ��
	printf("%x\n", p[0]);
	printf("%x\n", p[0] + 1);

	return 0;
}
/*int main()
{
	int *p[5];
	//int (*p)[5];
	printf("%x\n", &p);
	printf("%x\n", &p + 1);
	return 0;
}*/
/*int main()
{
	//int *test[5];   ����ָ������
	//char *test[5];  �ַ�ָ������
	char *test[3] = { "yang","zhu" };//�ַ�ָ������ĳ�ʼ��
	printf("%s\n", test[0]);
	return 0;
}*/