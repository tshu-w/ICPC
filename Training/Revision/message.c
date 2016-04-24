#include <stdio.h>
#include <string.h>

const int maxn = 55;
int max(int a, int b) {
	return (a > b)? a : b;
}
int main(int argc, char const *argv[])
{
	int m, n, a[maxn][maxn], f[2 * maxn][maxn][maxn];
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	memset(f, 0, sizeof(f));
	for (int i = 0; i <= m + n - 2; ++i)
		for (int j = 0; j < n && j <= i; ++j)
			for (int k = 0; k <= j; ++k) 
				if (i - j < m && i - k < m)
					if (j != k || (j == k && j == n - 1 && i == m + n - 2)) {
						f[i][j][k] = max(f[i - 1][j][k], f[i][j][k]);
						if (j - 1 >= 0)
							f[i][j][k] = max(f[i - 1][j - 1][k], f[i][j][k]);
						if (k - 1 >= 0)
							f[i][j][k] = max(f[i - 1][j][k - 1], f[i][j][k]);
						if (j - 1 >= 0 && k - 1 >= 0)
							f[i][j][k] = max(f[i - 1][j - 1][k - 1], f[i][j][k]);
						f[i][j][k] += a[i - j][j] + a[i - k][k];
					}
	printf("%d\n", f[m + n - 2][n - 1][n - 1]);
	return 0;
}