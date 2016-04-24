#include <stdio.h>

int main(int argc, char const *argv[])
{
	long long int ans = 0;
	int odd = 0, n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &j);
		ans += j;
		if ( j % 2 && (odd > j || odd == 0) )
		//错：if ( (j % 2 && odd > j) || odd == 0)
			odd = j;
	}
	if (ans % 2)
		printf("%I64d\n", ans - odd);
	else 
		printf("%I64d\n", ans);
	return 0;
}