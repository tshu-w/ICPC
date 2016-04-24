//位移范围是 int 
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int n;
	char s[100];
	unsigned long long ans = 0;
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'B')
			ans += pow(2, i);
	};
	printf("%I64d\n", ans);
	return 0;
}