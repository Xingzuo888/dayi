#include<stdio.h>
int swep(char x[], int start, int end) {
	int i, j;
	char t;
	for (i = start, j = end;i < j;i++, j--) {
		t = x[i];x[i] = x[j];x[j] = t;
	}
}
void change(char x[],int m,int n){
	
	swep(x, 0, m + n - 1);
	swep(x, 0, n - 1);
	swep(x, n, m + n - 1);
}
int main() {
	char str[] = "1234567ABCD";
	change(str, 7, 4);
	printf("互换后的序列是：%s\n", str);
}