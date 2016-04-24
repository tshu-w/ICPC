#include "stdio.h"
#include "string.h"

int a[30], n;
int dfs(int k, int r) {
	if (r == n) {
		for (int i = 0; i < k; i++)
			printf("%d ", a[i]);
		printf("\n");
		return 0;
	}
	for (int i = (k) ? a[k - 1] : 1; r + i <= n; i++)
		{
			a[k] = i;
			dfs(k + 1, r + i);
		}
	return 0;
}
int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	dfs(0, 0);
	return 0;
}