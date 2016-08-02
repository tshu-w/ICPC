#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const line[] = "+---+---+---+---+---+---+---+---+"

int main(int argc, char const *argv[])
{
	char s[200], ss[200], board[10][10], st[200];
	int len_s;
	scanf("While: %s", s);
	len_s = strlen(s);
	int last = -1, cur, x, y;
	for (int i = len_s - 1; i >= 0; i++) 
		if (s[i] == ',' || i == len_s - 1) {
			if (s[i] == ',') {
				cur = i ;
			}
			if (i == len_s - 1) {
				cur = len_s;
			}
			if (cur - last == 4) {
				x = s[cur - 1] - '0';
				y = s[cur - 2] - 'a';
				graph[x][y] = s[cur - 3];
			}
			else {
				x = s[cur - 1] - '0';
				y = s[cur - 2] - 'a';
				graph[x][y] = 'P';
			}
			last = cur;
		}
	scanf("Black: %s", s);
	len_s = strlen(s);
	int last = -1, cur, x, y;
	for (int i = len_s - 1; i >= 0; i++) 
		if (s[i] == ',' || i == len_s - 1) {
			if (s[i] == ',') {
				cur = i ;
			}
			if (i == len_s - 1) {
				cur = len_s;
			}
			if (cur - last == 4) {
				x = s[cur - 1] - '0';
				y = s[cur - 2] - 'a';
				graph[x][y] = s[cur - 3];
			}
			else {
				x = s[cur - 1] - '0';
				y = s[cur - 2] - 'a';
				graph[x][y] = 'P';
			}
			last = cur;
		}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) 
			printf("%c ", graph[i][j]);
		printf("\n");
	}
	return 0;
}