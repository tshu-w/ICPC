#include <stdio.h>
#include <limits.h>

double min(double a, double b) {
	return (a > b)? b : a;
}
int main(int argc, char const *argv[])
{
	double f[1005];
	long long w[1005], v[1005], max_weight, len, n, maxcv, maxdv, sum, tata;
	scanf("%lld%lld%lld", &max_weight, &len, &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld%lld", &w[i], &v[i]);
		f[i] = (double)LLONG_MAX;
	}
	maxcv = LLONG_MAX;
	sum = tata = 0;
	f[tata] = 0.0;
	for (int i = 1; i <= n; ++i) {
		sum += w[i];
		if (sum <= max_weight) {
			if (v[i] < maxcv) 
				maxcv = v[i];
			f[i] = (double)len/(double)maxcv + f[tata];
		}
		else {
			maxcv = LLONG_MAX;
			maxdv = LLONG_MAX;
			int tak = 0;
			tata = i;
			for (int j = i; j >= 1; --j) {
				tak += w[j];
				if (tak > max_weight) 
					break;
				if (v[j] < maxdv) maxdv = v[j];
				f[i] = min(f[i], f[j - 1] + (double)len / (double)maxdv);
			}
		}
	} 
	printf("%.1f\n", f[n] * 60);
	return 0;
}