//#include <bits/stdc++.h>
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

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 500 + 5;
const int tab[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

ll MOD;
ll dp[MAX_N][2][8];

template <typename T>
inline T sqr(T a) { return a * a;};

void init() {
    for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 8; ++k)
                dp[i][j][k] = -1ll;
}
void add(ll &a, ll b) {
    a = (a + b) % MOD;
}
ll dfs(int res, int crr, int s) {
    // cout << res << " " << crr << " " << s << endl;
    if (dp[res][crr][s] + 1)
        return dp[res][crr][s];
    if (!(res + crr + s))
        return dp[res][crr][s] = 1ll;
    if (s == 0 && crr == 1 && res == tab[1])
        return dp[res][crr][s] = 1ll;
    if (res == 0)
        return dp[res][crr][s] = 0ll;
    dp[res][crr][s] = 0ll;
    int a, tot, nxtcrr;
    if (s == 1) {
        for (int b = 0; b < 10; ++b) {
            a = b + 0 + crr;
            if (a >= 10) {
                a = a - 10;
                nxtcrr = 1;
            } else nxtcrr = 0;
            tot = tab[a] + tab[b];
            if (res >= tot) {
                add(dp[res][crr][s], dfs(res - tot, nxtcrr, s));
                if (b)
                    add(dp[res][crr][s], dfs(res - tot, nxtcrr, 0));
            }
        }
        // return dp[res][crr][s];
    } else if (s == 2) {
        for (int c = 0; c < 10; ++c) {
            a = 0 + c + crr;
            if (a >= 10) {
                a = a - 10;
                nxtcrr = 1;
            } else nxtcrr = 0;
            tot = tab[a] + tab[c];
            if (res >= tot) {
                add(dp[res][crr][s], dfs(res - tot, nxtcrr, s));
                if (c)
                    add(dp[res][crr][s], dfs(res - tot, nxtcrr, 0));
            }
        }
    } else if (s == 3) {
        for (int b = 0; b < 10; ++b)
            for (int c = 0; c < 10; ++c) {
                a = b + c + crr;
                if (a >= 10) {
                    a = a - 10;
                    nxtcrr = 1;
                } else nxtcrr = 0;
                tot = tab[a] + tab[b] + tab[c];
                if (res >= tot) {
                    add(dp[res][crr][s], dfs(res - tot, nxtcrr, s));
                    if (b)
                        add(dp[res][crr][s], dfs(res - tot, nxtcrr, 2));
                    if (c)
                        add(dp[res][crr][s], dfs(res - tot, nxtcrr, 1));
                    if (b && c)
                        add(dp[res][crr][s], dfs(res - tot, nxtcrr, 0));
                }
            }
    }
    return dp[res][crr][s];
}
int main(int argc, char const *argv[])
{
    int t, tt = 0, n;
    cin >> t;
    while (t--) {
        init();
        cin >> n >> MOD;
        cout << "Case #" << ++tt << ": " << dfs(n - 3, 0, 3) << endl;
    }
    return 0;
}