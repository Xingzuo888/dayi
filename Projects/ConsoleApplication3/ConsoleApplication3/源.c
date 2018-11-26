#include <stdio.h>
# define NUMP 100
int main(void)
{
	int i,k,m;
	int people[NUMP];
	for (i = 0;i < NUMP;i++)
		people[i] = i;
	i = 0, k = 0, m = NUMP;
	while (1) {
		if (people[i] != -1)
			k = k + 1;
		if (k == 3) {
			people[i] = -1;
			m--;
			if (m == 1)
				break;
			k = 0;
		}
		i++;
		if (i = NUMP)
			i = 0;
	}
	for (i = 0;i < NUMP;i++)
		if (people[i] != -1)
			printf("最后剩下的编号为%d的人\n", people[i]);
	return 0;
}