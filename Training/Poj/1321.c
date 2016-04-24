#include <stdio.h>
#include <string.h>

int column[10], n, k;
char board[10][10];

int find(int num, int line) {
	if (num > k) {
		return 1;
	}
	if (line > n)
		return 0;
	int sum = 0;
			for (int j = 0; j < n; j++)
				if (!column[j] && board[line][j] == '#') {
						column[j] = 1;
						sum += find(num + 1, line + 1);
						column[j] = 0;
					}
	sum += find(num, line + 1);
	return sum;
};
int main(int argc, char const *argv[])
 {
 	while(scanf("%d%d", &n, &k) && n != -1 && k != -1) {
 		memset(column, 0, sizeof(column));
 		memset(board, 0, sizeof(board));
 		for (int i = 0; i < n; i++)
 			scanf("%s", board[i]);
 		printf("%d\n", find(1, 0));
 	}
 	return 0;
} 
