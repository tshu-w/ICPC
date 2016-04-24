#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int priority(char ch) {
	switch(ch) {
		case '(' : 
		case ')' : return 0;
		case '+' : return 1;
		case '-' : return 2;
		case '*' : return 3;
		case '/' : return 4;
		case '^' : return 5;
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int num[1010], len, num_len = 0, opt_len = 0;
	char opt[1010], s[1010];
	s[0] = '(';
	scanf("%s", &s[1]);
	len = strlen(s);
	s[len] = ')';
	s[++len] = 0;
	int i = 0;
	while (i < len) {
		if ('0' <= s[i] && s[i] <= '9') {
			char tmp[20];
			int tmp_len = 0, j;
			while ('0' <= s[i] && s[i] <= '9') {
				tmp[tmp_len++] = s[i++]; 
			}
			tmp[tmp_len] = 0;
			j = atoi(tmp);
			num[num_len++] = j;
		}
		if (s[i] == ')') {
			while (opt[opt_len - 1] != '(') {
				switch(opt[opt_len - 1]) {
					case '+' :	num[num_len - 2] += num[num_len - 1];break;
					case '-' :	num[num_len - 2] -= num[num_len - 1];break;
					case '*' :	num[num_len - 2] *= num[num_len - 1];break;
					case '/' :	num[num_len - 2] /= num[num_len - 1];break;
					case '^' :	num[num_len - 2] = (int)pow(num[num_len - 2], num[num_len - 1]);
				}
				num_len--;
				opt_len--;
			}
			opt_len--;
		}
		else if (i == 0 || priority(s[i]) == 0||priority(s[i]) >= priority(opt[opt_len - 1])) {
			opt[opt_len++] = s[i];
		}
		else {
			switch(opt[opt_len - 1]) {
				case '+' :	num[num_len - 2] += num[num_len - 1];break;
				case '-' :	num[num_len - 2] -= num[num_len - 1];break;
				case '*' :	num[num_len - 2] *= num[num_len - 1];break;
				case '/' :	num[num_len - 2] /= num[num_len - 1];break;
				case '^' :	num[num_len - 2] = (int)pow(num[num_len - 2], num[num_len - 1]);
			}
			num_len--;
			//opt[opt_len - 1] = s[i];
			opt_len--;
			i--;
		}
		i++;
		// for (int j = 0; j < num_len; ++j)
		// 	printf("%d ", num[j]);
		// printf("\n");
		// for (int j = 0; j < opt_len; ++j)
		// 	printf("%c", opt[j]);
		// printf("\n");
	}
	printf("%d\n", num[0]);
	return 0;
}