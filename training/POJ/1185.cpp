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

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_S = 100;

template <typename T>
inline T sqr(T a) { return a * a;};

string s;
int N, M, dp[2][MAX_S][MAX_S];
vector<int > legal;

int main(int argc, char const *argv[])
{
    while (~scanf("%d%d", &N, &M)) {
        for (int i = 0; i < 1 << M; ++i) {
            bool flag = true;
            for (int j = 0; j < M && flag; ++j)
                if ((i >> j & 1) && (i >> (j + 1) & 1 || (i >> (j + 2) & 1)))
                    flag = false;
            if (flag) legal.push_back(i);
        }
        memset(dp[0], 0, sizeof dp[0]);
        int tot = legal.size(), res = 0;
        for (int i = 0; i < N; ++i) {
            memset(dp[(i + 1) & 1], 0, sizeof dp[(i + 1) & 1]);
            cin >> s;
            int S = 0;
            for (int j = 0; j < M; ++j)
                if (s[j] == 'H') S |= 1 << j;
            for (int j = 0; j < tot; ++j)
                if (!(S & legal[j]))
                    for (int k = 0; k < tot; ++k)
                        if (!(legal[j] & legal[k]))
                            for (int x = 0; x < tot; ++x)
                                if (!(legal[j] & legal[x]) && !(legal[k] & legal[x])) {
                                    dp[(i + 1) & 1][j][k] = max(dp[(i + 1) & 1][j][k], dp[i & 1][k][x] + __builtin_popcount(legal[j]));
                                    res = max(res, dp[(i + 1) & 1][j][k]);
                                }
        }
        cout << res << endl;
    }
    return 0;
}
