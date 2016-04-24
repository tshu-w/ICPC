#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char s[260], ss[260];
	int n, p;
	scanf("%s%d", s, &n);
	while (n) {
		p = 0;//未每次更新导致出错
		while (p + 1 < strlen(s) && s[p] <= s[p + 1]) 
			p++;
		strcpy(ss, s + p + 1);
		strcpy(s + p, ss);
		//printf("ss: %s s : %s; %d\n", ss, s, p);
		n--;
	}
	p = 0;
	while (p + 1 < strlen(s) && s[p] == '0') p++;
	printf("%s\n", s + p);
	return 0;
}