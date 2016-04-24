#include <stdio.h>
#include <string.h>

unsigned long long max(unsigned long long a, unsigned long long b) {
	return (a > b)? a : b;
}
int main(int argc, char const *argv[])
{
	unsigned long long n, m, f[100][100], a[100], ans = 0;
	scanf("%llu%llu", &n, &m);
	for (int r = 0; r < n; ++r) {
		memset(f, 0, sizeof(f));
		for (int i = 0; i < m; ++i)
			scanf("%lld", &a[i]);
		for (int i = m - 1; i >= 0; --i)
			for (int j = i; j < m; ++j) {
				f[i][j] = max(a[i] + 2 * f[i + 1][j], a[j] + 2 * f[i][j - 1]);
				//printf("f[%d][%d] = %llu\n", i, j, f[i][j]);
			}
		ans += f[0][m - 1];
	}	
	printf("%llu\n", ans * 2);
	return 0;
}