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
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, Pii> Piii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, A[MAX_N];

void solve() {
    vector<Piii > v;
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            v.push_back(Piii(A[i] + A[j], Pii(i, j)));
    sort(v.begin(), v.end());
    bool flag = false;
    int ans = -INF;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) if (i != j) {
            int res = A[j] - A[i], l, r;
            l = lower_bound(v.begin(), v.end(), Piii(res, Pii(0, 0))) - v.begin();
            r = upper_bound(v.begin(), v.end(), Piii(res, Pii(INF, INF))) - v.begin();
            for (int k = l; k < r; ++k)
                if (i != v[k].second.first && i != v[k].second.second)
                    if (j != v[k].second.first && j != v[k].second.second) {
                        flag = true;
                        ans = max(ans, A[j]);
                    }
        }
    if (flag)
        printf("%d\n", ans);
    else printf("no solution\n");
}

int main(int argc, char const *argv[])
{
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; ++i)
            scanf("%d", A + i);
        solve();
    }        
    return 0;
}