#include "stdio.h"
#include "string.h"

int flag[30], a[30], n;
int dfs(int k) {
	if (k == n) {
		for (int i = 0; i < n; i++)
			printf("%d ", a[i]);
		printf("\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		if (!flag[i]) {
			flag[i] = 1;
			a[k] = i;
			dfs(k + 1);
			flag[i] = 0;
		}
	return 0;
}
int main(int argc, char const *argv[])
{
	memset(flag, 0, sizeof(flag));
	scanf("%d", &n);
	dfs(0);
	return 0;
}