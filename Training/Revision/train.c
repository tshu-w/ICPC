#include <stdio.h>

int main(int argc, char const *argv[])
{
	int stack[10010], n, a[10010], pop, l, k;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	l = 1;
	stack[k = 0] = 1;
	for (int i = 0; i < n; ++i) {
		while (stack[k] != a[i] && k < n)
			stack[++k] = l++;
		k--;
	}
	if (k == 0)
		printf("YES\n");
	else 
		printf("NO\n");
	return 0;
}