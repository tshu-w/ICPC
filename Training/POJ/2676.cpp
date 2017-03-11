// written at 11:38 on 5 Mar 2017 
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

int t, sudoku[15][15];
char mp[15][15];
int flag[15][3];

void init() {
    memset(flag, 0, sizeof flag);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) if (sudoku[i][j]) {
            flag[i][0] |= 1 << sudoku[i][j];
            flag[j][1] |= 1 << sudoku[i][j];
            flag[i / 3 * 3 + j / 3][2] |= 1 << sudoku[i][j];
        }
}
bool dfs(int x, int y) {
    for (int i = 1; i <= 9; i++) {
        if ((flag[x][0] >> i & 1) || (flag[y][1] >> i & 1) || (flag[x / 3 * 3 + y / 3][2] >> i & 1)) continue;
        sudoku[x][y] = i;
        flag[x][0] |= 1 << sudoku[x][y];
        flag[y][1] |= 1 << sudoku[x][y];
        flag[x / 3 * 3 + y / 3][2] |= 1 << sudoku[x][y];

        bool f = true; 
        for (int j = 0; j < 9 && f; j++)
            for (int k = 0; k < 9 && f; k++)
                if (!sudoku[j][k]) f = dfs(j, k);
        if (f) return true;

        flag[x][0] &= ~(1 << sudoku[x][y]);
        flag[y][1] &= ~(1 << sudoku[x][y]);
        flag[x / 3 * 3 + y / 3][2] &= ~(1 << sudoku[x][y]);
        sudoku[x][y] = 0;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 9; i++) {
            scanf("%s", mp[i]);
            for (int j = 0; j < 9; j++)
                sudoku[i][j] = mp[i][j] - '0';
        }
        init();
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (!sudoku[i][j]) {
                    dfs(i, j);
                    break;
                }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) 
                printf("%d", sudoku[i][j]);
            printf("\n");
        }
    } 
    return 0;
}