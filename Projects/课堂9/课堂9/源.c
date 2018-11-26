#include<stdio.h>
/*int main()
{
	int yz = 100, zhangsan = 200;
	//int * const p = &yz;
	const int *p = &yz;
	//不能通过p去改变p指向的地址
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
	//p = a;//C语言中，数组名代表数组首地址
	i = 0;
	while (i < 3)
	{
		*(p+i) = i;
		//*(a++) = i; 此行有错，因为数组名是常量
		//*(p++) = i;
		//p[i] = i;//C语言中，可以将数组应用在指针上
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
	//C语言中，不是将字符串“hello”赋值给str1。
	//而是表示将字符串“hello”的首地址赋值给str1
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
	int *test[3];//指针数组
	int(*p)[3];//数组指针
	// p是变量名， *p表明p是指针型，p的基类型是int 【3】
	return 0;
}*/
/*int main()
{
	int *p[5];//指针数组
	//int (*p)[5];  //  数组指针
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
	//int *test[5];   整形指针数组
	//char *test[5];  字符指针数组
	char *test[3] = { "yang","zhu" };//字符指针数组的初始化
	printf("%s\n", test[0]);
	return 0;
}*/