#include <stdio.h>
#include <string.h>

const int maxn = 6000;
int max(int a, int b) {
 	return (a > b)? a : b;
}
int main(int argc, char const *argv[])
{
	int N, V, f[10000], w[maxn], c[maxn], n[maxn];
	scanf("%d%d", &N, &V);
	for (int i = 0; i < N; ++i) {
		scanf("%d%d%d", &n[i], &w[i], &c[i]);
	}
	memset(f, 0, sizeof(f));
	for (int i = 0; i < N; ++i) {
		int k;
		for (k = 1 << 0; k <= n[i] && w[i] * k <= V; n[i]-= k, k <<= 1) {
			for (int v = V; v >= w[i] * k; --v) 
				f[v] = max(f[v], f[v- w[i] * k] + c[i] * k);
		}
		k = n[i];
		if ( k > 0 && w[i] * k <= V) {
			for (int v = V; v >= w[i] * k; --v) 
				f[v] = max(f[v], f[v- w[i] * k] + c[i] * k);
		}
	}
	printf("%d\n", f[V]);
	return 0;
}