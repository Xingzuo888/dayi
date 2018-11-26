#include<stdio.h>
#define N 100
#define M 100
#define MAXSIZE 100
typedef struct {
	char data;          //结点值
	int weight;         //权值
	int parent;         //双亲结点
	int lchild;         //左孩子结点
	int rchild;         //右孩子结点
} HTNode;
typedef struct {
	char cd[N];         //存放哈夫曼编码
	int start;          //从start开始读cd中的哈夫曼编码
}HCode;

//显示对应编码
void CreateHT(HTNode ht[], int n) {       //调用输入的数组和他【】和结点数n
	int i, k, lnode, rnode;
	int min1, min2;
	for (i = 0;i < 2 * n - 1;i++) {       //所有结点的相关域置初值-1
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	}
	for (i = n;i < 2 * n - 1;i++) {       //构造哈夫曼树
		min1 = min2 = 32767;              //设int的最大值是32767
		lnode = rnode = -1;               //lnode和rnode记录最小权值的两个结点位置
		for (k = 0;k <= i - 1;k++) {
			if (ht[k].parent == -1) {    //只在尚未构造二叉树的结点中查找
				if (ht[k].weight < min1) {   //若权值小于最小的左结点的权值
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else if (ht[k].weight < min2) {
					min2 = ht[k].weight;
					rnode = k;
				}
			}
		}
		//两个最小结点的父结点是1
		ht[lnode].parent = i;
		ht[rnode].parent = i;
		//两个最小结点的父结点权值为两个最小结点权值之和
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;
		//父结点的左结点和右结点
		ht[i].lchild = lnode;
		ht[i].rchild = rnode;
	}
}

//编码
void editHCode(HTNode ht[], HCode hcd[], int n) {    //编码函数
	char string[MAXSIZE];
	int i, j, k;
	scanf("%s", string);          //把要进行编码的字符串存入string数组中
	printf("\n输出编码结果：\n");
	for (i = 0;string[i] != '#';i++) {     //#为终止标志
		for (j = 0;j < n;j++) {
			//循环查找与输入字符相同的编号，相同的就输出这个字符的编码
			if (string[i] == ht[j].data) {
				for (k = hcd[j].start;k <= n;k++) {
					printf("%c", hcd[j].cd[k]);
					break;           //输出完成后跳出当前for循环
				}
			}
		}
	}
}

//译码
void deHCode(HTNode ht[], HCode hcd[], int n) {     //译码函数
	char code[MAXSIZE];
	int i, j, l, k, m, x;
	scanf("%s", code);       //把要进行译码的字符串存入code数组中
	printf("\n输出译码结果：\n");
	while (code[0] != '#')
	for (i = 0;i < n;i++) {
		m = 0;         //m为相同编码个数的计数器
		//j为记录所存储字符的编码个数
		for (k = hcd[i].start, j = 0;k <= n;k++, j++) {
			if (code[j] == hcd[i].cd[k])      //当有相同编码时，m值加1
				m++;
		}
		//当输入的字符串与所存储的编码字符串个数相等时，则输出data数据
		if (m == j) {
			printf("%c", ht[i].data);
			//把已经使用过的code数组里的字符串删除
			for (x = 0;code[x - 1] != '#';x++)
				code[x] = code[x + j];
		}
	}
}
void main() {
	int n = 26, i;
	char orz, back, flag = 1;
	char str[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };    //初始化
	int fnum[] = { 186,64,13,22,32,103,21,15,47,57,1,2,32,20,57,63,15,1,48,51,80,23,8,18,1,16 };                                 //初始化
	HTNode ht[M];          //建立结构体
	HCode hcd[N];          //建立结构体
	for (i = 0;i < n;i++) {
		ht[i].data = str[i];
		ht[i].weight = fnum[i];
	}
	while (flag) {
		printf("\n");
		printf("       　**********哈夫曼编译器***********\n\n");
		printf("        ************************************");
		printf("\n           *  A----------------显示对应编译器 *");
		printf("\n           *  B----------------进行编码       *");
		printf("\n           *  C----------------进行译码       *");
		printf("\n           *  D----------------退出           *\n");
		printf("         ***********************************");
		printf("\n");
		printf("        请输入选择的编号：");
		scanf("%c", &orz);
		switch (orz) {
		case 'a':
		case 'A':
			system("cls");
			CreateHT(ht, n);             //创建哈夫曼树
			//CreateHCode(ht, hcd, n);     //创建哈夫曼编码
			//DispHCode(ht, hcd, n);       //显示哈夫曼编码
			printf("\n按任意键返回...");
			getch();
			system("cls");
			break;
		case 'b':
		case 'B':
			system("cls");
			printf("请输入要进行编码的字符串（以#结束）：\n");
			editHCode(ht, hcd, n);       //对输入的字符进行编码
			printf("\n按任意键返回...");
			getch();
			system("cls");
			break;
		case 'c':
		case 'C':
			system("cls");
			DispHCode(ht, hcd, n);
			printf("请输入编码（以#结束）：\n");
			deHCode(ht, hcd, n);         //对输入的字符进行译码
			printf("\n按任意键返回...");
			getch();
			system("cls");
			break;
		case 'd':
		case 'D':
			flag = 0;break;
		defautlt:
			system("cls");
		}
	}
}