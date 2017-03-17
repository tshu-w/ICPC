// written at 15:37 on 16 Mar 2017
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
const int INF = INT_MAX / 3;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e3 + 10;
const int MAX_M = 20 * 50 + 10;

const char *AGCT = "AGCT";

int N, cs;
string S, P[MAX_N];
int nxt[MAX_M][4];
bool ng[MAX_M];

int dp[MAX_N][MAX_M];

void solve() {
    vector<string> pfx;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= P[i].length(); j++)
            pfx.push_back(P[i].substr(0, j));
    sort(pfx.begin(), pfx.end());
    pfx.erase(unique(pfx.begin(), pfx.end()), pfx.end());
    int K = pfx.size();

    for (int i = 0; i < K; i++) {
        ng[i] = false;
        for (int j = 0; j < N; j++) {
            ng[i] |= P[j].length() <= pfx[i].length()
                && pfx[i].substr(pfx[i].length() - P[j].length(), P[j].length()) == P[j];
        }
        for (int j = 0; j < 4; j++) {
            string s = pfx[i] + AGCT[j];
            int k;
            for(;;) {
                k = lower_bound(pfx.begin(), pfx.end(), s) - pfx.begin();
                if (k < K && pfx[k] == s) break;
                s = s.substr(1);
            }
            nxt[i][j] = k;
        }
    }

    dp[0][0] = 1;
    for (int i = 1; i < K; i++) dp[0][i] = 0;
    for (int t = 0; t < S.length(); t++) {
        for (int i = 0; i < K; i++) dp[t + 1][i] = INF;
        for (int i = 0; i < K; i++) {
            if (ng[i]) continue;
            for (int j = 0; j < 4; j++) {
                int k = nxt[i][j];
                dp[t + 1][k] = min(dp[t + 1][k], dp[t][i] + (S[t] == AGCT[j]? 0 : 1));
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < K; i++) {
        if (ng[i]) continue;
        ans = min(ans, dp[S.length()][i]);
    }
    printf("Case %d: ", ++cs);
    if (ans == INF) printf("%d\n", -1);
    else printf("%d\n", ans);
}

int main(void) {
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++)
            cin >> P[i];
        cin >> S;
        solve(); 
    }
    return 0;
}