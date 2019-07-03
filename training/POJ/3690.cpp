// written at 17:45 on 16 Mar 2017
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
const int MAX_N = 1e3 + 10;
const int MAX_T = 100 + 10;
const int MAX_Q = 50 + 10;

int N, M, T, P, Q, _;
char field[MAX_N][MAX_N];
char patterns[MAX_T][MAX_N][MAX_N];

ull hsh[MAX_N][MAX_N], tmp[MAX_N][MAX_N];

void compute_hash(char a[MAX_N][MAX_N], int n, int m) {
    const ull B1 = 9973;
    const ull B2 = 100000007;
    ull t1 = 1;
    for (int j = 0; j < Q; j++) t1 *= B1;
    for (int i = 0; i < n; i++) {
        ull e = 0;
        for (int j = 0; j < Q; j++) e = e * B1 + a[i][j];

        for (int j = 0; j + Q <= m; j++) {
            tmp[i][j] = e;
            if (j + Q < m) e = e * B1 + a[i][j + Q] - t1 * a[i][j];
        }
    }

    ull t2 = 1;
    for (int i = 0; i < P; i++) t2 *= B2;
    for (int j = 0; j + Q <= m; j++) {
        ull e = 0;
        for (int i = 0; i < P; i++) e = e * B2 + tmp[i][j];
        
        for (int i = 0; i + P <= n; i++) {
            hsh[i][j] = e;
            if (i + P < n) e = e * B2 + tmp[i + P][j] - t2 * tmp[i][j];
        }
    }    
}

void solve() {
    multiset<ull> unseen;
    for (int k = 0; k < T; k++) {
        compute_hash(patterns[k], P, Q);
        unseen.insert(hsh[0][0]);
    }

    compute_hash(field, N, M);
    for (int i = 0; i + P <= N; i++)
        for (int j = 0; j + Q <= M; j++)
            unseen.erase(hsh[i][j]);
    
    int ans = T - unseen.size();
    printf("Case %d: %d\n", ++_, ans);
}

int main(int argc, char const *argv[])
{
    while(scanf("%d%d%d%d%d", &N, &M, &T, &P, &Q), N + M + T + P + Q) {
        for (int i = 0; i < N; i++)
            scanf("%s", field[i]);
        for (int t = 0; t < T; t++)
            for (int i = 0; i < P; i++)
                scanf("%s", patterns[t][i]);
        solve();
    }
    return 0;
}