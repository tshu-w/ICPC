// written at 20:15 on 8 Mar 2017 
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
const int MAX_W = 10;
const int MAX_S = MAX_W * MAX_W;

typedef bitset<MAX_S> bit;

bit mask;
int W, H, best;
int board[MAX_W][MAX_W], accum[MAX_W + 1][MAX_W + 1];

bool included(const bit &a, const bit &b) {
    return (a & b) == a;
}

bool init() {
    scanf("%d%d", &W, &H);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            scanf("%d", board[i] + j);
    return H > 0;
}

void dfs(int score, bit brd, vector<bit> bs) {
    for (int i = 0; i < W * H; i++) if (!brd[i]) {
        int cnt = 0, key = -1;
        for (int j = 0; j < (int)bs.size(); j++)
            if (bs[j][i]) {
                ++cnt; key = j;
            }
        if (cnt == 1) {
            ++score;
            brd |= bs[key];
        }
    }

    if (brd == mask) {
        best = min(best, score);
        return ;
    }

    if (score >= best - 1) return;

    for (int i = 0; i < (int)bs.size(); i++)
        bs[i] &= mask & (~brd);

    vector<bit> ts;
    for (int i = 0; i < (int)bs.size(); i++) if (bs[i].any()) {
        for (int j = i + 1; j < (int)bs.size(); j++)
            if (bs[i] == bs[j]) bs[j].reset();
    }

    for (int i = 0; i < (int)bs.size(); i++) {
        bool ok = true;
        for (int j = 0; j < (int)bs.size(); j++) if (i != j)
            ok &= !included(bs[i], bs[j]);
        if (ok) ts.push_back(bs[i]);
    }

    for (int i = 0; i < (int)ts.size(); i++) {
        bit t = ts[i];
        ts[i].reset();
        dfs(score + 1, brd | t, ts);
        ts[i] = t;
    }
}

int solve() {
    mask.reset();
    for (int i = 0; i < H * W; i++) mask.set(i, true);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            accum[i + 1][j + 1] = accum[i + 1][j] + accum[i][j + 1] - accum[i][j] + (1 - board[i][j]);

    bit brd;
    vector<bit> bs;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (board[i][j] == 0) {
                brd.set(i * W + j);
            } else {
                int sz = 0;
                for (int k = 1; i + k <= H && j + k <= W; k++) 
                    if (accum[i + k][j + k] - accum[i][j + k] - accum[i + k][j] + accum[i][j] == 0)
                        sz = k;
                    // else break;
                bit bt;
                for (int a = 0; a < sz; a++)
                    for (int b = 0; b < sz; b++)
                        bt.set((i + a) * W + (j + b), true);
                bs.push_back(bt);
            }

    vector<bit> ts;
    for (int i = 0; i < (int)bs.size(); i++) {
        bool ok = true;
        for (int j = 0; j < (int)bs.size(); j++) if (i != j)
            ok &= !included(bs[i], bs[j]);
        if (ok) ts.push_back(bs[i]);
    }

    best = MAX_S;
    dfs(0, brd, ts);

    return best;
}

int main(int argc, char const *argv[])
{
    for(;init();) printf("%d\n", solve());
    return 0;
}