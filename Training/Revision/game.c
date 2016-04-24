#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn = 55;
int min(int a, int b) {
    return (a < b)? a : b;
}
int max(int a, int b) {
    return (a > b)? a : b;
}
int main(int argc, char const *argv[])
{
	int n, m, num[maxn], sum[maxn], max_ans, min_ans, f[maxn][maxn];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num[i]);
	}
	for (int st = 0; st < n; ++st) {
		for (int i = 0; i < n; i++) {
			int cur = (i + st) % n;
			sum[i] = (i)? sum[i - 1] + num[cur] : num[cur];
			//printf("%d\n", cur);
			//printf("sum[%d] = %d\n", i, sum[i]);
		}
		for (int i = 0; i < n ; ++i) {
			int cur = (i + st) / n;
			int s = sum[i];
			if (s < 0)
				s += 1000000;
			f[i][1] = s % 10;
			for (int j = 2; j <= min(m, i + 1); ++j) {
				for (int k = j - 2; k < i; ++k) {
					int s = sum[i] - sum[k];
					if (s < 0)
						s += 1000000;
					if (k != j - 2) 
						f[i][j] = max(f[k][j - 1] * (s % 10), f[i][j]);
					else
						f[i][j] = f[k][j - 1] * (s % 10);
				}
			}
		}
		if (st)
			max_ans = max(f[n - 1][m], max_ans);
		else
			max_ans = f[n - 1][m];


			for (int i = 0; i < n ; ++i) {
			int cur = (i + st) / n;
			int s = sum[i];
			if (s < 0)
				s += 1000000;
			f[i][1] = s % 10;
			//printf("f[%d][1] = %d\n", i, f[i][1]);
			for (int j = 2; j <= min(m, i + 1); ++j) {
				for (int k = j - 2; k < i; ++k) {
					int s = sum[i] - sum[k];
					if (s < 0)
						s += 1000000;
					if (k != j - 2) 
						f[i][j] = min(f[k][j - 1] * (s % 10), f[i][j]);
					else
						f[i][j] = f[k][j - 1] * (s % 10);
					//printf("f[%d][%d] = %d : %d\n", i, j, f[i][j], f[k][j - 1] * (s % 10));
				}
			}
		}
		if (st)
			min_ans = min(f[n - 1][m], min_ans);
		else
			min_ans = f[n - 1][m];


	}
	printf("%d\n%d\n", min_ans, max_ans);
	return 0;
}