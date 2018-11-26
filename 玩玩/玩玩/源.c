#include<stdio.h>
void sort1(int a[],int N) {   //小到大排序
	int temp, i,j,z;
	printf("小到大排序:");
	for (i = 0;i < N;i++) {
		z = 0;
		for (j = 0;j < N - i - 1;j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				z = 1;
			}
		}
		if (z = 0)break;
	}
}

void sort2(int a[], int N) {   //大到小排序
	int temp, i, j, z;
	printf("大到小排序:");
	for (i = 0;i < N;i++) {
		z = 0;
		for (j = 0;j < N - i - 1;j++) {
			if (a[j] < a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				z = 1;
			}
		}
		if (z = 0)break;
	}
}

void play(int a[],int N) {   //打印输出
	int i;
	for (i = 0;i < N;i++) {
		printf("%3d", a[i]);
	}
	printf("\n");
}
int main() {
	int a[10], num;
	for (num = 0;num < 10;num++) {
		printf("请输入第%d个数字：", num + 1);
		scanf("%d", &a[num]);
	}
	sort1(&a, 10);
	play(&a, 10);
	sort2(&a, 10);
	play(&a, 10);
	
	return 0;
}