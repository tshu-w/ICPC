#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int n, max, high[1010], l[1010], down[1010], nl = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &high[i]);
		down[i] = 1;
	}
	memset(l, 0, sizeof(l));
	down[0] = 1;l[0] = high[0];nl++;
	max = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (high[j] > high[i] && down[j] + 1 > down[i])
				down[i] = down[j] + 1;
			if (down[i] > max) 
				max = down[i];
		}
		int flag = 0, p;
		for (int j = 0; j < nl; j++)
			if (l[j] > high[i]) {
				if (!flag) {
					p = j;
					flag = 1;
				}
				else 
					if (l[j] < l[p]) 
						p = j;
			}
			if (!flag) 
				l[nl++] = high[i];
			else l[p] = high[i];
	}
	printf("%d %d\n", max, nl);
	return 0;
}