// written at 15:21 on 6 Mar 2017 
// 我能怎么办，我也很绝望
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int SIZE = 4;
const int WIDTH = SIZE * SIZE;

char sudoku[WIDTH][WIDTH + 1];
int block[WIDTH][WIDTH];

inline int cb(int x) {
    return x * x * x;
}
void init() {
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < WIDTH; j++)
            block[i][j] = i / SIZE * SIZE + j / SIZE;
}
bool read() {
    for (int i = 0; i < WIDTH; i++)
        if (scanf("%s", sudoku[i]) == EOF)
            return false;
    return true;
}

bool dfs(int cur[WIDTH][WIDTH]) {
    int row[WIDTH] = {}, col[WIDTH] = {}, bk[WIDTH] = {}, tmp[WIDTH][WIDTH];
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < WIDTH; j++)
            if (cur[i][j]) {
                row[i] |= 1 << cur[i][j];
                col[j] |= 1 << cur[i][j];
                bk[block[i][j]] |= 1 << cur[i][j];
            }

    for(;;) {
        bool found = false;
        int x = -1, y = -1, imin = WIDTH + 1, sub = 0, mask = 0;
        for (int i = 0; i < WIDTH; i++)
            for (int j = 0; j < WIDTH; j++) if (!cur[i][j]) {
                int S = ((1 << WIDTH) - 1) << 1;
                S &= ~row[i]; S &= ~col[j]; S &= ~bk[block[i][j]];
                if (S == 0) return false;
                int cnt = __builtin_popcount(S);
                if (cnt == 1) {
                    found = true;
                    cur[i][j] = __builtin_ctz(S);
                    row[i] |= 1 << cur[i][j];
                    col[j] |= 1 << cur[i][j];
                    bk[block[i][j]] |= 1 << cur[i][j];
                } else if (cnt <= imin) {
                    int a = cb(__builtin_popcount(row[i])) + cb(__builtin_popcount(col[j])) + cb(__builtin_popcount(bk[block[i][j]]));
                    if (cnt < imin || a > sub) {
                        sub = a;
                        imin = cnt;
                        x = i;
                        y = j;
                        mask = S;
                    }
                }
            }

        for (int i = 0; i < WIDTH; i++) {
            int S = 0;
            for (int j = 0; j < WIDTH; j++) if (cur[i][j])
                S |= 1 << j;
            for (int k = 1; k <= WIDTH; k++) if (!(row[i] >> k & 1)) {
                int cnt = 0, y = -1;
                for (int j = 0; j < WIDTH; j++) 
                    if (!cur[i][j] && !((col[j] | bk[block[i][j]]) >> k & 1)) {
                        S |= 1 << j;
                        cnt++;
                        y = j;
                    }
                if (cnt == 0) return false;
                if (cnt == 1) {
                    int j = y;
                    found = true;
                    cur[i][j] = k;
                    row[i] |= 1 << cur[i][j];
                    col[j] |= 1 << cur[i][j];
                    bk[block[i][j]] |= 1 << cur[i][j];
                }
            }
            if (__builtin_popcount(S) < WIDTH) return false;
        }

        for (int j = 0; j < WIDTH; j++) {
            int S = 0;
            for (int i = 0; i < WIDTH; i++) if (cur[i][j])
                S |= 1 << i;
            for (int k = 1; k <= WIDTH; k++) if (!(col[j] >> k & 1)) {
                int cnt = 0, x = -1;
                for (int i = 0; i < WIDTH; i++)
                    if (!cur[i][j] && !((row[i] | bk[block[i][j]]) >> k & 1)) {
                        S |= 1 << i;
                        cnt++;
                        x = i;
                    }
                if (cnt == 0) return false;
                if (cnt == 1) {
                    int i = x;
                    found = true;
                    cur[i][j] = k;
                    row[i] |= 1 << cur[i][j];
                    col[j] |= 1 << cur[i][j];
                    bk[block[i][j]] |= 1 << cur[i][j];
                }
            }
            if (__builtin_popcount(S) < WIDTH) return false;
        }

        for (int l = 0; l < WIDTH; l++) {
            for (int k = 1; k <= WIDTH; k++) if (!(bk[l] >> k & 1)) {
                int cnt = 0, x = -1, y = -1;
                int xx = (l / SIZE) * SIZE, yy = (l % SIZE) * SIZE;
                for (int i = 0; i < SIZE; i++)
                    for (int j = 0; j < SIZE; j++)
                        if (!cur[i + xx][j + yy] && !((row[i + xx] | col[j + yy]) >> k & 1)) {
                            cnt++;
                            x = i + xx;
                            y = j + yy;
                        }
                if (cnt == 0) return false;
                if (cnt == 1) {
                    int i = x, j = y;
                    found = true;
                    cur[i][j] = k;
                    row[i] |= 1 << cur[i][j];
                    col[j] |= 1 << cur[i][j];
                    bk[block[i][j]] |= 1 << cur[i][j];
                }
            }
        }

        if (!found) {
            if (imin == WIDTH + 1) {
                for (int i = 0; i < WIDTH; i++) {
                    for (int j = 0; j < WIDTH; j++)
                        printf("%c", cur[i][j] - 1 + 'A');
                    printf("\n");
                }
                return true;
            }
            for (int k = 1; k <= WIDTH; k++) if (mask >> k & 1) {
                memcpy(tmp, cur, sizeof tmp);
                tmp[x][y] = k;
                if (dfs(tmp)) return true;
            }
            return false;
        }
    }

    return false;
}

void solve() {
    int sd[WIDTH][WIDTH];
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < WIDTH; j++)
            if (sudoku[i][j] == '-') sd[i][j] = 0;
            else sd[i][j] = sudoku[i][j] - 'A' + 1;
    dfs(sd);
}

int main(int argc, char const *argv[])
{
    init();
    for(int c = 0; read(); c++) {
        if (c) puts("");
        solve();
    } 
    return 0;
}