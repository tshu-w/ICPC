#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100 + 5;
const int MAX_M = 100 + 5;

int N, M;
char field[MAX_N][MAX_M];

void dfs(int x, int y) {
    field[x][y] = '.';

    for (int dx = -1; dx <= 1; ++dx)
        for (int dy = -1; dy <= 1; ++dy) {
            int xx, yy;
            xx = x + dx; yy = y + dy;
            if (0 <= xx && xx < N && 0 <= yy && yy < M && field[xx][yy] == 'W')
                dfs(xx, yy);
        }
    return ;
}
void sovle() {
    int res = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (field[i][j] == 'W') {
                dfs(i, j);
                ++res;
            }
    cout << res << endl;
}
int main(int argc, char const *argv[])
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            do field[i][j] = getchar(); while (field[i][j] == '\n');
    }
    sovle();
    return 0;
}