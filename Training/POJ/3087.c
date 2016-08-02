#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int n, c, s1[105], s2[105], s[210];
	char st[210];
	scanf("%d", &n);
	for (int cases = 1; cases <= n; cases++){
		scanf("%d", &c);
		while (getchar() != '\n') 
			;
		scanf("%s", st);
		for (int i = 0; i < c; i++) {
			s1[i] = st[i] - 'A';
		}
		scanf("%s", st);
		for (int i = 0; i < c; i++) {
			s2[i] = st[i] - 'A';
		}
		scanf("%s", st);
		int flag = 1;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < c; j++) {
				s[2 * j] = s2[j];
				s[2 * j + 1] = s1[j];
			}
			int equal = 1;
			for (int j = 0; j < 2 * c; j++) {
				if (st[j] - 'A' != s[j]) 
					equal = 0;
				//printf("%d ", s[j]);
			}
			//printf("\n");
			for (int j = 0; j < c; j++) {
				s1[j] = s[j];
				s2[j] = s[j + c];
			}
			if (equal) {
				printf("%d %d\n", cases, i + 1);
				flag = 0;
				break;
			}
		}
		if (flag) 
			printf("%d -1\n", cases);
	}
	return 0;
}