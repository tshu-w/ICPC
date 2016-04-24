#include "stdio.h"
#include "string.h"

int a[30], n, r;
int dfs(int k) {
	if (k == r) {
		for (int i = 0; i < r; i++)
			printf("%d ", a[i]);
		printf("\n");
		return 0;
	}
	for (int i = (k) ? a[k - 1] + 1 : 1; i <= n; i++) {
			a[k] = i;
			dfs(k + 1);
		}
	return 0;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &r);
	dfs(0);
	return 0;
}