#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 30;
const int MAX_M = 30;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int N, M;
char room[MAX_N][MAX_M];
bool vis[MAX_N][MAX_M];

int dfs(int x, int y) {
	int res = 1;
	for (int i = 0; i < 4; ++i) {
		int xx = dx[i] + x, yy = dy[i] + y;
		if (0 <= xx && xx < N && 0 <= yy && yy < M && !vis[xx][yy] && room[xx][yy] == '.') {
			vis[xx][yy] = true;
			res += dfs(xx, yy);
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d%d", &M, &N) && N && M) {
		int x, y;
		for (int i = 0; i < N; ++i) {
			scanf("%s", room[i]);
			for (int j = 0; j < M; ++j) {
				if (room[i][j] == '@')
					x = i, y = j;
			}
		}
		memset(vis, false, sizeof vis);	
		printf("%d\n", dfs(x, y));
	}
	return 0;
}