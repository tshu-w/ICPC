#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, a[105], sum = 0, avg, step = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	avg = sum / n;
	for (int i = 0 ; i < n; i++)
		a[i] -= avg;
	int l = 0, r = n - 1;
	while (a[l] == 0) l++;
	while (a[r] == 0) r--;
	while (l <= r) {
		a[l + 1] += a[l];
		a[l] = 0;
		step++;
		l++;
		while (a[l] == 0 && l <= r) l++;
	}	
	printf("%d\n", step);
	return 0;
}