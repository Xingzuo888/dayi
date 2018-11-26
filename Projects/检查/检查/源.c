#include<stdio.h>
#define N 20
int matching(char exp[]) {
	int i = 0;int s[N];
	int top = 0;
	int state = 1;
	while (exp[i]!= '\0'&&state==1) {
		switch (exp[i]) {
		case '[':
		case '{':
		case '<':
		case '(':s[top++] = exp[i];i++;break;
		case ')':
		case '>':
		case '}':
		case ']':
			if (top > 0) {
				if (s[top - 1] == '('&&exp[i] == ')' || s[top - 1] == '<'&&exp[i] == '>' ||
					s[top - 1] == '{'&&exp[i] == '}' || s[top - 1] == '['&&exp[i] == ']') {
					--top;
					i++;
				}
			}
			else state = 0;
			break;
		default:i++;
		}
	}
	if (0==top&&state==1)return 1;
	else return 0;
}
int main() {
	int i;
	char str[80];
	printf("输入表达式：");
	scanf(str);
	i=matching(str);
	if (i==0)printf("失败！");
	else printf("成功！");

}