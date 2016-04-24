//奖学金
#include "stdio.h"

int main(int argc, char const *argv[])
{
	int n, score[500][4];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		score[i][3] = i + 1;
		for (int j = 0; j < 3; j++) {
			scanf("%d", &score[i][j]);
			if (j == 2) {
				score[i][j] += score[i][0] + score[i][1];
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (score[j][2] < score[j+1][2] || (score[j][2] == score[j+1][2] && score[j][0] < score[j+1][0])) {
				for (int k = 0; k < 4; k++) {
					int tmp = score[j][k];
					score[j][k] = score[j+1][k];
					score[j+1][k] = tmp;
				}
			}
	for (int i = 0; i < 5; i++)
		printf("%d %d\n", score[i][3], score[i][2]);

	return 0;
}