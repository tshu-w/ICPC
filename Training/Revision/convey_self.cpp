#include <cstdio>

using namespace std;
const int maxn = 1010;

double min(double a, double b) {
	return (a < b)? a: b;
}
int main(int argc, char const *argv[])
{
	int W, len, n, cur_minv, w[maxn], v[maxn];
	long long pre_sum[maxn];
	double f[maxn];

	scanf("%d%d%d", &W, &len, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &w[i], &v[i]);
		if (i)
			pre_sum[i] = w[i] + pre_sum[i - 1];
		else
			pre_sum[i] = w[i];
		//printf("pre_sum[%d] = %d\n", i, pre_sum[i]);
	} 
	for (int i = 0; i < n; ++i) {
		cur_minv = v[i];
		f[i] = (double)len / (double)cur_minv + f[i - 1];
		//printf("%lf : ", f[i]);
		for (int k = i - 1; k >= 0; --k) {
			if (v[k] < cur_minv)
				cur_minv = v[k];
			if (k) {
				if (pre_sum[i] - pre_sum[k - 1] <= W) 
					f[i] = min(f[k - 1] + (double)len / (double)cur_minv, f[i]);
			} else {
				if (pre_sum[i] <= W)
					f[i] = min((double)len / (double)cur_minv, f[i]);
			}
		}
		//printf("%lf\n", f[i]);
	}
	printf("%.1lf\n", f[n - 1] * 60);
	return 0;
}