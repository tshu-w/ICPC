#include <stdio.h>

//#define max(a,b) (a > b)? a : b;
int max(int a, int b) {
	return (a > b)? a : b;
}
int main(int argc, char const *argv[])
{
	int up[105], down[105], height[105], n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &height[i]);
		up[i] = down[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
			if (height[i] > height[j]) {
				up[i] = max(up[i], up[j] + 1);
			}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j > i; --j)
			if (height[i] > height[j]) {
				down[i] = max(down[i], down[j] + 1);
			}
	}
	for (int i = 0; i < n; ++i)
		ans = max(ans, up[i] + down[i] - 1);
	printf("%d\n", n - ans);
	return 0;
}