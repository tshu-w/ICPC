//车厢重组
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, a[10010], ans = 0;
	scanf("%d", &n)；
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j]) 
				ans++;
	printf("%d\n", ans);
	return 0;
}