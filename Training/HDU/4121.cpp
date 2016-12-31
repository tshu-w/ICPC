#include <stdio.h>
#include <string.h>

char chessboard[12][12];
int flag[12][12];
int b_r, b_c;
int house_pace[8][2] = {
    { 1, 2}, { 1, -2}, {-1, 2}, {-1, -2},
    { 2, 1}, { 2, -1}, {-2, 1}, {-2, -1},
};
int house_block[8][2] = {
    { 0, 1}, { 0, -1}, { 0, 1}, { 0, -1},
    { 1, 0}, { 1,  0}, {-1, 0}, {-1,  0},
};
int udlr[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int General(int r, int c) {
    for (int i = r; i <= 10; i++)
        if (chessboard[i][c]) {
            if (chessboard[i][c] == 'G') return 1;
            else return 0;
        }
    return 0;
};
int Chariot(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int cases = 0;
        int dr = r + udlr[i][0], dc = c+ udlr[i][1];
        while (dr >= 1 && dr <= 10 && dc >= 1 && dc <= 9 && cases < 1) {
            if (cases < 1) flag[dr][dc] = 0;
            if (chessboard[dr][dc]) cases++;
            dr += udlr[i][0];
            dc += udlr[i][1];
        }
    }
    return 0;
};
int Horse(int r, int c) {
    for (int i = 0; i < 8; i++)
        if (!chessboard[r+house_block[i][0]][c+house_block[i][1]])
            flag[r+house_pace[i][0]][c+house_pace[i][1]] = 0;
    return 0;
};
int Cannon(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int cases = 0;
        int dr = r + udlr[i][0], dc = c + udlr[i][1];
        while (dr >= 1 && dr <= 10 && dc >= 1 && dc <= 9 && cases <= 1) {
            if (cases == 1) flag[dr][dc] = 0;
            if (chessboard[dr][dc]) cases++;
            dr += udlr[i][0];
            dc += udlr[i][1];
        }
    }
    return 0;
};
int main(int argc, const char * argv[]) {
    int n;
    while (scanf("%d%d%d", &n, &b_r, &b_c) == 3 && n) {
        memset(chessboard, 0, sizeof(chessboard));
        char s[5];
        int r0, c0;
        for (int i = 0; i < n; i++) {
            scanf("%s%d%d", s, &r0, &c0);
            chessboard[r0][c0] = s[0];
        }
        memset(flag, 0, sizeof(flag));
        for (int i = 1; i <= 3; i++)
            for (int j = 4; j <= 6; j++)
                flag[i][j] = 1;
        for (int i = 8; i <= 10; i++)
            for (int j = 4; j <= 6; j++)
                flag[i][j] = 1;
        for (int i = 1; i <= 10; i++)
            for (int j = 1; j <= 9; j++)
                if (chessboard[i][j])
                    switch (chessboard[i][j]) {
                        case 'G':
                        case 'R':   Chariot(i, j);break;
                        case 'H':   Horse(i, j);break;
                        case 'C':   Cannon(i, j);break;
                    }
        int checkmate = 1;
        for (int i = 0; i < 4; i++)
            if (flag[b_r+udlr[i][0]][b_c+udlr[i][1]]) checkmate = 0;
        printf((checkmate)? "YES\n" : "NO\n");
    }
    return 0;
}
