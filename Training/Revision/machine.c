#include <stdio.h>
#include <limits.h>
#define oo INT_MAX

int time[30], l[30], n, k, ans = oo;
int find(int step, int curtime) {
	if (curtime < ans) {
		if (step == n) 
			ans = curtime;
		else {
			for (int i = 0; i < k; i++) {
				l[i] += time[step];
				find(step + 1, (l[i] > curtime)? l[i] : curtime);
				l[i] -= time[step];
			}
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &time[i]);
	}
	find(0, 0);
	printf("%d\n", ans);
	return 0;
}