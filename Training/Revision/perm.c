#include <stdio.h>
#include <string.h>

int n, alph[26], ans = 0;
char l[510];
int dfs(int k) {
	if (k == n) {
		ans++;
		for (int i = 0; i < n; i++)
			printf("%c", l[i]);
			puts("");
			return 0;
	}
	for (int i = 0; i < 26; i++)
		if (alph[i]) {
			l[k] = i + 'a';
			alph[i]--;
			dfs(k + 1);
			alph[i]++;
		}
	return 0;
}
int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	while (getchar() != '\n') getchar();
	for (int i = 0; i < n; i++) {
		char ch;
		ch = getchar();
		alph[ch - 'a']++;
	}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}