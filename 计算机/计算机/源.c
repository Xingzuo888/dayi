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
	double opnd[N];//��optr��opnd�ֱ�Ϊ�����ջ��������ջ
	int top[2] = { 0 };//top[0]Ϊoptr��ջ����top[1]Ϊopnd��ջ������ָ��ջ��Ԫ�ص���һλ��
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
			int temp;//������ֵ���ʱ����
			temp = exp[i] - '0';//���ַ�ת��Ϊʮ������
			i++;
			//�������������ĸ�λ���룬��ת��Ϊʮ������
			while (0 == In(exp[i]))//���������Ĳ�������λת��Ϊʮ������
			{
				temp = temp * 10 + exp[i] - '0'; i++;
			}
			opnd[top[1]++] = temp; //�����������ջ

		}
		else
		{

			switch (Precede(optr[top[0] - 1], exp[i]))
			{
			case '<': //ջ��Ԫ������Ȩ��
				optr[top[0]++] = exp[i]; i++;break;
			case '=':  //�����Ų�������һ�ַ�
				top[0]--;i++; break;
			case '>': //��ջ������������ջ
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
		printf("������һ�����ʽ��");
		fflush(stdin);
		gets(str);
		printf("%s=", str);
		printf("%.2lf\n", EvaluateExpression(str));
		printf("������(Y/N)");
		fflush(stdin);
		ch = getchar();
	} while (ch != 'N'&&ch != 'n');
}
