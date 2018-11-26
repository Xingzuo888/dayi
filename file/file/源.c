#include<stdio.h>
//文件的读写
/*int main() {
	FILE *fp;
	char ch;
	if ((fp = fopen("string", "w+")) == NULL) {
		printf("Cannot open file!");
		return -1;
	}
	printf("input a string:\n");
	ch = getchar();
	while (ch != '\n') {
		fputc(ch, fp);
		ch = getchar();
	}
	fclose(fp);
	fp = fopen("string", "r");
	ch = fgetc(fp);
	while (ch != EOF) {
		putchar(ch);
		ch = fgetc(fp);
	}
	fclose(fp);
	return 0;
}*/
//格式化读写
/*int main() {
	FILE *fp;
	int a = 11;
	float b = 22.22;
	char c = 'A';
	fp = fopen("test", "w");
	fprintf(fp, "%d,%f,%c", a, b, c);
	fclose(fp);
	fopen("test", "r");
	fscanf(fp, "%d,%f,%c", &a, &b, &c);
	fclose(fp);
	printf("a=%d,b=%f,c=%c\n", a, b, c);
	return 0;
}*/
//读字符串函数fgets（）
/*int main() {
	FILE *fp;
	char str[32];
	if ((fp = fopen("test","r")) == NULL) {
		printf("Cannot open file!");
		return -1;
	}
	fgets(str, 16, fp);
	printf("%s\n", str);
	fclose(fp);
	return 0;
}*/
//写字符串函数fputs()
/*int main() {
	FILE *fp;
	char s[32];
	if ((fp = fopen("test", "a+")) == NULL) {
		printf("Cannot open file!");
		return -1;
	}
	fputc("\n", fp);
	fputs(s, fp);
	fclose(fp);
	fp = fopen("test", "r");
	while (fgets(s, 15, fp))puts(s);
	fclose(fp);
	return 0;
}*/
//数据块的读写
/*int main() {
	FILE *fp;
	char buf1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
#define bufsize 10
	char buf2[bufsize + 1];
	int line, len;
	fp = fopen("abcd", "wb");
	fwrite(buf1, sizeof(char), sizeof(buf1) - 1, fp);
	fclose(fp);
	line = 1;
	fp = fopen("abcd", "rb");
	while (!feof(fp)) {
		len = fread(buf2, sizeof(char), bufsize, fp);
		buf2[len] = '\0';
		printf("%3d:%s\n", line++, buf2);
	}
	fclose(fp);
	return 0;
}*/
//rewind()函数的使用
/*int main() {
	FILE *fp;
	char ch;
	int i;
	fp = fopen("teat", "r");
	for (i = 0;i < 25;++i)putchar(fgetc(fp));
	printf("\n************\n");
	rewind(fp);
	for (i = 0, ch = fgetc(fp);i < 15;ch = fgetc(fp), ++i)putchar(ch);
	fclose(fp);
	return 0;
}*/
//fseek()函数的使用
/*int maim() {
	FILE *fp;
	char ch;
	fp = fopen("teat", "r");
	fseek(fp, 15L, SEEK_SET);
	for (ch = fgetc(fp);ch!EOF;ch = fgetc(fp))putchar(ch);
	fclose(fp);
	return 0;
}*/
//ftell()函数的使用
int main() {
	FILE *fp;
	long size;
	fp = fopen("teat", "rb");fseek(fp, 0L, SEEK_END);
	printf("The size of this file is %1d\n", ftell(fp));
	fclose(fp);
	return 0;
}