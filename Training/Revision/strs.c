#include <stdio.h>
#include <string.h>

int tran(char ch) {
	switch(ch) {
		case '<' : return 1;
		case '>' : return 2;
		case '(' : return 3;
		case ')' : return 4;
		case '[' : return 5;
		case ']' : return 6;
		case '{' : return 7;
		case '}' : return 8;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int n, stack[300], pop;
	char s[300];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		memset(stack, 0, sizeof(stack));
		int len = strlen(s);
		pop = 0;
		stack[pop++] = tran(s[0]);
		for (int i = 1; i < len; ++i) {
			int trans = tran(s[i]);
			if (trans == stack[pop - 1] + 1)
				pop--;
			else if (trans > stack[pop - 1] || trans % 2 == 0)
					break;
			else stack[pop++] = trans;
		}
		//printf("%d\n", pop);
		if (!pop) 
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}