#define N 10
#include<stdio.h>
int a[N];//���Ա�
int len = 0;//����
void Display(int x[], int n)
{
	int i;
	for (i = 0;i<n;i++)
	{
		printf("%3d", x[i]);
	}
	printf("\n");
}
//���룺�����Ա�x�ĵ�loc��λ�ò���Ԫ��e,�ɹ���1,ʧ��:0
int InsertList(int x[], int loc, int e)
{
	int j;
	//����λ���Ƿ���ȷ  1<=loc<=len+1
	if (loc<1 || loc>len + 1)return 0;
	//�ռ��Ƿ���
	if (len >= N)
	{
		return 0;
	}
	//�����һ��Ԫ�ص���loc��Ԫ�أ����κ���
	for (j = len;j >= loc;j--)
	{
		x[j] = x[j - 1];
	}
	x[loc - 1] = e;//�ڵ�loc��λ�ã�����e
	len++;//���Ա�ĳ��ȼ�1
	return 1;
}
//ɾ��:�����Ա�x�ĵ�loc��Ԫ��ɾ��������ɾ�����ֵ����*e
//�ɹ���1,ʧ��:0
int DeleteList(int x[], int loc, int *e)
{
	//���ɾ��λ���Ƿ���ȷ 1<=loc<=len
	//�ѵ�loc��Ԫ�ص�ֵ����*e
	//�ӵ�loc+1��Ԫ�ص���len��Ԫ�أ�����ǰ��
	//���ȼ�1
}
//���ң������Ա�x�в��Һ�Ԫ��e��ȵĵ�һ��Ԫ��
//������λ��,��������ڣ��򷵻�0
int LocateList(int x[], int e)
{

}
//�˵�
void menu()
{

	int select, result;
	int e;
	int loc;

	do
	{
		system("cls");//����
		printf("\t****************************\n");
		printf("\t*1.����һ��Ԫ����ָ��λ��  *\n");
		printf("\t*2.ɾ��ָ��λ�õ�Ԫ�ط���  *\n");
		printf("\t*3.����ָ��Ԫ�ص�λ��      *\n");
		printf("\t*4.��ʾ���е�Ԫ��          *\n");
		printf("\t*0.�˳�                    *\n");
		printf("\t****************************\n");
		printf("\t������ٺʹ��룺");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			//����һ��Ԫ����ָ��λ��
			printf("\t������Ҫ�����Ԫ��:");
			scanf("%d", &e);
			printf("\t������Ҫ�����λ��:");
			scanf("%d", &loc);
			result = InsertList(a, loc, e);
			if (result == 0)printf("\t����Ԫ��%dʧ��!\n", e);
			else printf("\t����Ԫ��%d�ɹ�!\n", e);
			system("pause");
			break;
		case 2:
			//ɾ��ָ��λ�õ�Ԫ�ط���
			printf("ɾ��\n");
			system("pause");
			break;
		case 3:
			//����ָ��Ԫ�ص�λ��
			printf("����\n");
			system("pause");
			break;
		case 4:
			//��ʾ���е�Ԫ��
			printf("\t");
			Display(a, len);
			system("pause");
			break;
		case 0:
			//�˳�
			printf("\t�����Ƿ�ȷ��Ҫ�˳�����(Y/N)");
			//�����û������ѡ��ִ���Ƿ�Ҫ�˳��Ĺ���
			exit(0);
			break;
		}
	} while (select<0 || select>4);
}
int main()
{

	while (1)
	{
		menu();
	}
}
