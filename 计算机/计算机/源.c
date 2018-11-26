#include<stdio.h>
#define N 30
char tr[] = "#()+-*/";

char pre[7][8] = {//#()+-*/
	{ "=<*<<<<" },//#
	{ "*<=<<<<" },//(
	{ "*******" },//)
	{ "><>>><<" },//+
	{ "><>>><<" },//-
	{ "><>>>>>" },//*
	{ "><>>>>>" } };///
int In(char op)
{
	int i = 0;
	while (tr[i] != '\0')
	{
		if (op == tr[i])return 1;
		i++;
	}
	return 0;
}
char Precede(char stackop, char op)
{
	int i, j, k = 0;
	while (tr[k] != '\0')
	{
		if (stackop == tr[k])i = k;
		if (op == tr[k])j = k;
		k++;
	}

	return pre[i][j];
}
double Operate(double a, char theta, double b)
{
	double result;
	switch (theta)
	{
	case '+':
		result = a + b;break;
	case '-':
		result = a - b;break;
	case '*':
		result = a*b;break;
	case '/':
		result = a / b;break;
	}
	return result;
}
double EvaluateExpression(char exp[])
{
	int i = 0;
	char optr[N];
	double opnd[N];//设optr和opnd分别为运算符栈和运算数栈
	int top[2] = { 0 };//top[0]为optr的栈顶，top[1]为opnd的栈顶，都指向栈顶元素的下一位置
	double a, b, r;
	char op;
	optr[top[0]++] = '#';
	while (exp[i] != '\0')
	{
		i++;
	}
	exp[i] = '#';exp[i + 1] = '\0';
	i = 0;
	while (exp[i] != '\0' && (exp[i] != '#' || optr[top[0] - 1] != '#'))
	{
		if (0 == In(exp[i]))
		{
			int temp;//存放数字的临时变量
			temp = exp[i] - '0';//将字符转换为十进制数
			i++;
			//逐个读入操作数的各位数码，并转化为十进制数
			while (0 == In(exp[i]))//将逐个读入的操作数各位转化为十进制数
			{
				temp = temp * 10 + exp[i] - '0'; i++;
			}
			opnd[top[1]++] = temp; //不是运算符进栈

		}
		else
		{

			switch (Precede(optr[top[0] - 1], exp[i]))
			{
			case '<': //栈顶元素优先权低
				optr[top[0]++] = exp[i]; i++;break;
			case '=':  //脱括号并接收下一字符
				top[0]--;i++; break;
			case '>': //退栈并将运算结果入栈
				op = optr[--top[0]];
				b = opnd[--top[1]];
				a = opnd[--top[1]];
				r = Operate(a, op, b);
				opnd[top[1]++] = r;
				break;
			}
		}

	}
	return opnd[top[1] - 1];
}
int main()
{
	char str[30];
	char ch;
	do
	{
		printf("请输入一个表达式：");
		fflush(stdin);
		gets(str);
		printf("%s=", str);
		printf("%.2lf\n", EvaluateExpression(str));
		printf("继续？(Y/N)");
		fflush(stdin);
		ch = getchar();
	} while (ch != 'N'&&ch != 'n');
}
