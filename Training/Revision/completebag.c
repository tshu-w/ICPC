#include <stdio.h>
#include <string.h>

const int maxn = 1000;
int max(int a, int b) {
 	return (a > b)? a : b;
}
int main(int argc, char const *argv[])
{
	int n, V, f[10000], w[maxn], c[maxn];
	scanf("%d%d", &n, &V);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &w[i], &c[i]);
	}
	memset(f, 0, sizeof(f));
	for (int i = 0; i < n; ++i)
		for (int v = w[i]; v <= V; ++v)
			f[v] = max(f[v], f[v- w[i]] + c[i]);
	printf("%d\n", f[V]);
	return 0;
}
// 转化为 01 背包
// #include <stdio.h>
// #include <string.h>

// const int maxn = 1000;
// int max(int a, int b) {
//  	return (a > b)? a : b;
// }
// int main(int argc, char const *argv[])
// {
// 	int N, V, f[maxn], w[maxn], c[maxn], n[maxn];
// 	scanf("%d%d", &N, &V);
// 	for (int i = 0; i < N; ++i) {
// 		scanf("%d%d%d", &w[i], &c[i], &n[i]);
// 	}
// 	memset(f, 0, sizeof(f));
// 	for (int i = 0; i < N; ++i)
// 		for (int j = 0; w[i] * (1<<j) <= V; ++j) 
// 			for (int v = V; v >= w[i] * (1<<j); --v)
// 				f[v] = max(f[v], f[v- w[i] * (1<<j)] + c[i] * (1<<j));
// 	printf("%d\n", f[V]);
// 	return 0;
// }