#include<stdio.h>
void display(int x[], int n) {
	int i;
	for (i = 0;i < n;i++)printf("%3d", x[i]);
	printf("\n");
}
void change(int x[], int n) {
	int i, j,c;
	int k;
	i = 0, j = n - 1;
	while(i<j){
		while (i<j&&x[i] < 0)i++;
		while (i<j&&x[j] > 0)j--;
		
		if (i<j) {
			k = x[i];x[i] = x[j];x[j] = k;
		}
		
	}

}
int main() {
	int a[] = { 5,14,-6,8,-7,9,6,13,-2,-1,0,-4 };
	display(a, 12);
	change(a, 12);
	display(a, 12);
}