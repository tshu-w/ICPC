#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int n, p, s[100010][2];
	memset(s, 0, sizeof(s));
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		s[i][0] = r / p - l / p;
		if (l % p == 0) s[i][0]++;
		s[i][1] = r - l + 1;
		s[i][0] = s[i][1] - s[i][0];
		//printf("%d %d\n", s[i][0], s[i][1]);
	}
	printf("\n");
	double total = 0.0;
	for (int i = 0; i < n - 1; i++) {
		total += 1 - (double)s[i][0] / (double)s[i][1] * (double)s[i+1][0] / (double)s[i+1][1];
	}
	total += 1 - (double)s[n-1][0] / (double)s[n-1][1] * (double)s[0][0] / (double)s[0][1];
	printf("%lf\n", total * 2000);
	return 0;
}