#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char line[] = "+---+---+---+---+---+---+---+---+";

int main(int argc, char const *argv[])
{
	char s[200], ss[200], board[10][10], st[200];
	int len_s;
	memset(board, 0, sizeof(board));
	scanf("White: %s", s);
	len_s = strlen(s);
	int last = -1, cur, x, y;
	for (int i = 0; i < len_s; i++) 
		if (s[i] == ',' || i == len_s - 1) {
			if (s[i] == ',') {
				cur = i ;
			}
			if (i == len_s - 1) {
				cur = len_s;
			}
			if (cur - last == 4) {
				x = 8 - s[cur - 1] + '0';
				y = s[cur - 2] - 'a';
				board[x][y] = s[cur - 3];
			}
			else {
				x = 8 - s[cur - 1] + '0';
				y = s[cur - 2] - 'a';
				board[x][y] = 'P';
			}
			//printf("%d %d\n", cur, last);
			last = cur;
		}
	getchar();
	scanf("Black: %s", s);
	len_s = strlen(s);
	last = -1;
	for (int i = 0; i < len_s; i++) 
		if (s[i] == ',' || i == len_s - 1) {
			if (s[i] == ',') {
				cur = i ;
			}
			if (i == len_s - 1) {
				cur = len_s;
			}
			if (cur - last == 4) {
				x = 8 - s[cur - 1] + '0';
				y = s[cur - 2] - 'a';
				board[x][y] = s[cur - 3] + 32;
			}
			else {
				x = 8 - s[cur - 1] + '0';
				y = s[cur - 2] - 'a';
				board[x][y] = 'P' + 32;
			}
			//printf("%d %d\n", cur, last);
			last = cur;
		}
	for (int i = 0; i < 8; i++) {
		puts(line);
		for (int j = 0; j < 8; j++)
			if ((i + j) % 2) {
				if (board[i][j]) printf("|:%c:", board[i][j]);
				else printf("|:::");
			}
			else {
				if (board[i][j]) printf("|.%c.", board[i][j]);
				else printf("|...");
			}
		puts("|");
	}
	puts(line);
	return 0;
}