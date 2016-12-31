#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int k, tm[15];
	char s[10];
	memset(tm, 0, sizeof(tm));
	scanf("%d", &k);
	for (int i = 0; i < 4; ++i) { 
		scanf("%s", s);
		for (int j = 0; j < 4; ++j) {
			if (s[j] != '.')
				tm[s[j] - '0']++;
		}
	}
	int flag = 1;
	for (int i = 1; i <= 9; ++i) {
		if (tm[i] > 2 * k) {
			flag = 0;
			break;
		}
	}
	if (flag) 
		printf("YES\n");
	else 
		printf("NO\n");
	return 0;
}