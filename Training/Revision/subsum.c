#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


int mmin[7010], pstsum[7010], a[7010], l[7010];
int c, n, ln;

int min(int a, int b) {
	return (a < b)? a : b;
}
int dfs(int k, int sum) {
	if (sum == c) {
		for (int i = 0; i < ln; i++)
			printf("%d ", l[i]);
		printf("\n");
		return 0;
	}
	if (k < n && sum + mmin[k] <= c && sum + pstsum[k] >= c) {
		if (sum + a[k] <= c) {
			l[ln++] = a[k];
			dfs(k + 1, sum  + a[k]);
			ln--; 
		}
		dfs(k + 1, sum);
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pstsum[i] = 0;
	}
	pstsum[n - 1] = a[n - 1];
	mmin[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		pstsum[i] = pstsum[i + 1] + a[i];
		mmin[i] = min(a[i], mmin[i + 1]);
	}
	ln = 0;
	dfs(0, 0);
	return 0;
}