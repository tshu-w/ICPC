#include <stdio.h>
#include <string.h>

const int maxn = 105;
int max(int a, int b) {
 	return (a > b)? a : b;
}
int main(int argc, char const *argv[])
{
	int n, V, f[10010], w[maxn], c[maxn];
	scanf("%d%d", &n, &V);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &w[i], &c[i]);
	}
	memset(f, 0, sizeof(f));
	for (int i = 0; i < n; ++i)
		for (int v = V; v >= w[i]; v--)
			f[v] = max(f[v], f[v- w[i]] + c[i]);
	printf("%d\n", f[V]);
	return 0;
}