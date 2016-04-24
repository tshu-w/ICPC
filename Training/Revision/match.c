#include <stdio.h>
#include <string.h>

int n, a[1 << 8][1 << 8];
int make(int i, int j, int l, int r) {
	if (l == r)
		a[i][j] = l;
	else {
		make(i, j, l, (l + r) / 2);
		make(i, j + (r - l + 1) / 2, (l + r) / 2 + 1, r);
		make(i + (r - l + 1) / 2, j, (l + r) / 2 + 1, r);
		make(i + (r - l + 1) / 2, j + (r - l + 1) / 2 , l, (l + r) / 2);
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	make(0, 0, 1, 1 << n);
	for (int i = 0; i < 1 << n; i++) {
		for (int j = 0; j < 1 << n; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
	return 0;
}