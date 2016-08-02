#include <stdio.h>
#include <string.h>

const int dir[4][2] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};
struct Pnt
{
    int x, y;
    int step;
}S, lt;
int r, c, board[25][25], min;
int find(int x, int y, int k) {
    //printf("%d %d %d\n", x, y, k);
    if (k > 10)
        return 0;
    int flag = 1;
    for (int i = 0; i < 4; i++) {
        int xx, yy, cnt = 0;
        xx = x + dir[i][0];
        yy = y + dir[i][1];
        while (0 <= xx && xx < r && 0 <= yy && yy < c &&
               (board[xx][yy] == 0 || board[xx][yy] == 3)) {
            if (board[xx][yy] == 3) {
                if (min > k) min = k;
                return 1;
            }
            xx += dir[i][0];
            yy += dir[i][1];
            cnt++;
        }
        if (xx < 0 || xx == r || yy < 0 || yy == c)
            continue;
        if (board[xx][yy] == 1 && cnt) {
            board[xx][yy] = 0;
            xx -= dir[i][0];
            yy -= dir[i][1];
            if (find(xx, yy, k + 1))
                flag = 0;
            board[xx + dir[i][0]][yy + dir[i][1]] = 1;
        }
    }
    if (flag)
        return 0;
    return 1;
}
int main(int argc, char const *argv[])
{
    while(scanf("%d%d", &c, &r) && r && c) {
        min = 20;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                scanf("%d", &board[i][j]);
                if (board[i][j] == 2) {
                    S.x = i;
                    S.y = j;
                    board[i][j] = 0;
                }
            }
        printf("%d\n", find(S.x, S.y, 1)? min : -1);
    }
    return 0;
}