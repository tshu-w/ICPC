#include <stdio.h>
#include <string.h>

const int maxh = 110;
const int maxn = 110;
struct gabage
{
	int t, f, h;
} g[maxn], tmp;
int max(int a, int b) {
	return (a > b)? a : b;
}
int main(int argc, char const *argv[])
{
	int d, n, f[maxh][maxn], flag = 1, maxt;
	scanf("%d%d", &d, &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &g[i].t, &g[i].f, &g[i].h);
	}
	memset(f, 0, sizeof(f));
	maxt = f[0][0] = 10;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (g[i].t > g[j].t) {
				tmp = g[i];
				g[i] = g[j];
				g[j] = tmp;
			}
	for (int i = 1; i <= n && flag; ++i) {
		for (int h = 0; h <= d; ++h) {
			if (f[h][i - 1] >= g[i].t) {
				f[h + g[i].h][i] = max(f[h][i - 1], f[h + g[i].h][i]);
				f[h][i] = max(f[h][i - 1] + g[i].f, f[h][i]);
				maxt = max(f[h][i], maxt);
				if (h + g[i].h >= d) {
					printf("%d\n", g[i].t);
					flag = 0;
					break;
				}
			}				
		}
	}
	if (flag)
		printf("%d\n", maxt);
	return 0;
}