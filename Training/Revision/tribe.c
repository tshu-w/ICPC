#include <stdio.h>
#include <string.h>

int l[105], n, m, f[105], graph[10010][2], gn, max, ans[105];

int insert(int u, int v) {
	graph[gn][0] = v;
	graph[gn][1] = f[u];
	f[u] = gn++;

	return 0;
}
int find(int p, int num) {
	if (p > n) {
		if (num > max) {
			for (int i = 1; i <= n; i++) {
				ans[i] = l[i];
				//printf("%d ", l[i]);
			}
			//printf("	%d\n", num);
			max = num;
		}
		return 0;
	}
	if (l[p]) {
		int k = f[p];
		while (k != 0) {
			l[ graph[k][0]] = 0;
			k = graph[k][1];
			//printf("%d %d\n", p, graph[k][0]);
		}
		find(p + 1, num + 1);
		k = f[p];
		while (k != 0) {
			l[ graph[k][0]] = 1;
			k = graph[k][1];
		}
	}
	l[p] = 0;
	find(p + 1, num);
	return 0;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &m);
	gn = 1;
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		(u < v)? insert(u, v) : insert(v ,u);
	}
	max = 0;
	for (int i = 1; i <= n; i++)
		l[i] = 1;
	find(1, 0);
	printf("%d\n", max);

	for (int i = 1; i <=n; i++)
		printf("%d ", ans[i]);
	return 0;
}