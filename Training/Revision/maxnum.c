#include <stdio.h>
#include <string.h>

int small(char s1[], char s2[], int n1, int n2) {
	int p = 0;
	while (p < n1 && p < n2) {
		if (s1[p] < s2[p])
			return 1;
		else 
			if(s1[p] > s2[p])
				return 0;
			else p++;
	}
	if (n1 > n2) {
		if (s1[p] < s2[0]) return 1;
		else 
			return 0;
	}
	else {
		if (s2[p] > s1[0]) return 1;
		else
			return 0;
	}
}
int main(int argc, char const *argv[])
{
	int n;
	char s[25][260];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (small(s[i], s[j], strlen(s[i]), strlen(s[j]))) {
				char tmp[260];
				strcpy(tmp, s[i]);
				strcpy(s[i], s[j]);
				strcpy(s[j], tmp);
			}
	for (int i = 0; i < n; i++)
		printf("%s", s[i]);
	printf("\n");
	return 0;
}