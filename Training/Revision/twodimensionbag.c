#include <stdio.h>
#include <string.h>

const int maxn = 1000;
int max(int a, int b) {
 	return (a > b)? a : b;
}
int main(int argc, char const *argv[])
{
	int n, V, U, f[1000][1000], a[maxn], b[maxn], c[maxn];
	scanf("%d%d%d", &n, &V, &U);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
	memset(f, 0, sizeof(f));
	for (int i = 0; i < n; ++i)
		for (int j = V; j >= a[i]; --j) 
			for (int k = U; k >= b[i]; --k) 
				f[j][k] = max(f[j][k], f[j - a[i]][k - b[i]] + c[i]);
	printf("%d\n", f[V][U]);
	return 0;
}