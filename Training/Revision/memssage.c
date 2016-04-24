#include <stdio.h>
#include <string.h>

const int maxn = 220;
long long max(long long a, long long b) {
	return (a > b)? a : b;
}
int main(int argc, char const *argv[])
{
	int n, m[maxn];
	long long f[maxn][maxn], ans;
	scanf("%d", &n);
	memset(f, 0, sizeof(f));
	memset(m, 0, sizeof(m));
	for (int i = 0; i < n; ++i) {
		scanf("%d", &m[i]);
		m[i + n] = m[i];
	}
	ans = 0;
	for (int i = 2 * n - 2; i >= 0; --i)
		for (int j = i + 1; j < 2 * n; ++j) {
			for (int k = i; k < j; ++k) {
				f[i][j] = max(f[i][k] + f[k + 1][j] + m[i] * m[k + 1] * m[j + 1], f[i][j]);
			}
			if (j + 1 == i + n)
				ans = max(ans, f[i][j]);
		}
	printf("%lld\n", ans);
	return 0;
}