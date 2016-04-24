#include <stdio.h>
#include <string.h>

int l[105], f[105], graph[10010][2], n, m, k, gn, ans;
int insert(int u, int v) {
	graph[gn][0] = v;
	graph[gn][1] = f[u];
	f[u] = gn++;

	return 0;
}
int find(int pnt) {
	if (pnt > n)
		ans++;
	else {
		int c[10], p;
		memset(c, 0, sizeof(c));
		p = f[pnt];
		while (p != 0) {
			if (pnt == 1) printf("%d ", p);
			c[ l[ graph[p][0]]] = 1;
			p = graph[p][1];
		}
		for (int i = 0; i < k; i++)
			if (!c[i]) {
				l[pnt] = i;
				find(pnt + 1);
			}
	}

	return 0;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &n, &m, &k);
	ans = 0;
	gn = 1;
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		(u < v)? insert(v, u) : insert(u, v);
	}

	find(1);

	printf("\n%d\n", ans);
	return 0;
}
