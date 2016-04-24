#include <stdio.h>
#include <string.h>

const int maxt = 300010;
int main(int argc, char const *argv[])
{
	int m, s, t, maxs, f[maxt];
	scanf("%d%d%d", &m, &s, &t);
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= t; ++i)
		if (m > 9) {
			f[i] = f[i - 1] + 60;
			m -= 10;
		}
		else {
			f[i] = f[i - 1];
			m += 4;
		}
	for (int i = 1; i <= t; ++i) {
		if (f[i] < f[i - 1] + 17)
			f[i] = f[i - 1] + 17;
		if (f[i] >= s) {
			printf("Yes\n%d\n", i);
			return 0;
		}
	}
	printf("No\n%d\n", f[t]);
	return 0;
}