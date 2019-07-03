#include <stdio.h>
#include <string.h>

const int step[8][2] = {
    { -2, -1}, { -2, 1}, { -1, -2}, { -1, 2},
    {  1, -2}, {  1, 2}, {  2, -1}, {  2, 1},
};

int board[30][30], l[1010][2], p, q, t, cases ,flag;
int find(int k) {
    if (flag) return 0;
    if (k == p * q) {
        printf("Scenario #%d:\n", cases);
        for (int i = 0; i < p * q; i++)
            printf("%c%d", l[i][0] + 'A' - 1, l[i][1]);
        printf("\n");
        flag = 1;
        return 0;
    }
    for (int i = 0; i < 8; i++) {
        int xx, yy;
        xx = l[k - 1][0] + step[i][0];
        yy = l[k - 1][1] + step[i][1];
        if (xx > 0 && yy > 0 && xx <= q && yy <= p && !board[xx][yy]) {
            board[xx][yy] = 1;
            l[k][0] = xx;
            l[k][1] = yy; 
            find(k + 1);
            board[xx][yy] = 0;
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    for (cases = 1; cases <= t; cases++) {
        scanf("%d%d", &p, &q);
        memset(board, 0, sizeof(board));
        memset(l, 0, sizeof(l));
        flag = 0;
        l[0][0] = 1;    l[0][1] = 1;
        board[1][1] = 1;
        find(1);
        if (!flag) 
            printf("Scenario #%d:\nimpossible\n", cases);
        if (cases != t) 
            printf("\n");
    }
    return 0;
}