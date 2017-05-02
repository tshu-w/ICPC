#include <stdio.h>
#include <string.h>

const int dir_lft[4][2] = { {-1, 0}, {0,  1}, {1, 0}, {0, -1} };
const int dir_rgh[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0,  1} };

struct Point
{
    int x, y;
    int step;
} S, E, l[4096], lt;
int t, r, c, vis[50][50];
char maze[50][50];

int dfs(int x, int y, int opt, const int dir[][2]) {
    if (maze[x][y] == 'E') 
        return 1;
    int xx, yy, opt2, step = 0;
    for (int i = 0; i < 4; i++) {
        opt2 = (opt + i + 3) % 4;
        xx = x + dir[opt2][0];
        yy = y + dir[opt2][1];
        if (0 <= xx && xx < r && 0 <= yy && yy < c &&
            (maze[xx][yy] == 'E' || maze[xx][yy] == '.')) {
            return step = dfs(xx, yy, opt2, dir) + 1;
        }
    }
    return step;
}
int bfs() {
    memset(vis, 0, sizeof(vis));
    int head = 0, tail = 1;
    l[0].x = S.x;
    l[0].y = S.y;
    l[0].step = 1;
    vis[S.x][S.y] = 1;
    while (head < tail) {
        for (int i = 0; i < 4; i++) {
            lt = l[head];
            lt.x += dir_lft[i][0];
            lt.y += dir_lft[i][1];
            lt.step++;;
            if (0 <= lt.x && lt.x < r && 0 <= lt.y && lt.y < c)
                if (!vis[lt.x][lt.y] && (maze[lt.x][lt.y] == 'E' || maze[lt.x][lt.y] == '.')) {
                    vis[lt.x][lt.y] = 1;
                    l[tail++] = lt;
                    if (maze[lt.x][lt.y] == 'E') 
                        return lt.step;
                }
        }
        head++;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &c, &r);
        for (int i = 0; i < r; i++) {
            scanf("%s", maze[i]);
            for (int j = 0; j < c; j++)
                if (maze[i][j] == 'S') {
                    maze[i][j] = 1;
                    S.x = i;
                    S.y = j;
                }
        }
        printf("%d %d %d\n", dfs(S.x, S.y, 0, dir_lft), dfs(S.x, S.y, 0, dir_rgh), bfs());
    }
    return 0;
}