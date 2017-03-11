// written at 10:56 on 6 Mar 2017 
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector> 
#include <utility>
#include <bitset>
#include <numeric>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;

int sudoku[15][15], s, t, one[100], block[15][15];
char str[100];
int row[9], col[9], grid[9];

void init() {
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    memset(grid, 0, sizeof grid);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            block[i][j] = i / 3 * 3 + j / 3;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) if (sudoku[i][j]) {
            row[i] |= 1 << sudoku[i][j];
            col[j] |= 1 << sudoku[i][j];
            grid[block[i][j]] |= 1 << sudoku[i][j];
        }
    s = t = 0;
}

bool dfs() {
    // for (int i = 0; i < 9; i++)
    //     for (int j = 0; j < 9; j++)
    //         printf("%d%c", sudoku[i][j], " \n"[j == 8]);printf("\n");

    if (s < t) {
        int x = one[s] / 9, y = one[s] % 9;
        int mask = row[x] | col[y] | grid[block[x][y]];
        ++s;
        if (__builtin_popcount(mask) == 9) {
            --s;
            return false;
        }
        int k = __builtin_ffs((1 << 10) - 2 - mask) - 1;
        row[x] ^= 1 << k;
        col[y] ^= 1 << k;
        grid[block[x][y]] ^= 1 << k;
        sudoku[x][y] = k;
        if (dfs()) return true;
        sudoku[x][y] = 0;
        row[x] ^= 1 << k;
        col[y] ^= 1 << k;
        grid[block[x][y]] ^= 1 << k;
        --s;
        return false;
    }
    int tmp = t;
    int imax = 0, x = -1, y = -1, flag = -1;
    bool success = true;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) if (!sudoku[i][j]) {
            success = false;
            int mask = row[i] | col[j] | grid[block[i][j]];
            int cnt = __builtin_popcount(mask);
            if (cnt == 9) return false;
            if (imax < cnt) {
                imax = cnt;
                x = i, y = j;
                flag = mask;
            } else if (cnt == 8) 
                one[t++] = i * 9 + j;
        }
    if (success) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                printf("%d", sudoku[i][j]);
        printf("\n");
        return true;
    }
    for (int k = 1; k <= 9; k++)
        if ((flag >> k & 1) == 0) {
            row[x] ^= 1 << k;
            col[y] ^= 1 << k;
            grid[block[x][y]] ^= 1 << k;
            sudoku[x][y] = k;
            if (dfs()) return true;
            sudoku[x][y] = 0;
            row[x] ^= 1 << k;
            col[y] ^= 1 << k;
            grid[block[x][y]] ^= 1 << k;
        }
    t = tmp;
    return false;
}

int main(int argc, char const *argv[])
{
    while (scanf("%s", str) && str[0] != 'e') {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (str[i * 9 + j] != '.')
                    sudoku[i][j] = str[i * 9 + j] - '0';
                else sudoku[i][j] = 0;
        init();
        dfs();
    }
    return 0;
}