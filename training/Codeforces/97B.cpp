// written at 16:25 on 12 Mar 2017 
#include <bits/stdc++.h>

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
const int MAX_N = 1e4 + 10;

int n;
Pii A[MAX_N];
set<Pii> s;

void dfs(int l, int r) {
    int mid = (l + r) >> 1, x = A[mid].first;
    for (int i = l; i < r; i++)
        s.emplace(x, A[i].second);
    if (l + 1 >= r) return;
    if (l < mid) dfs(l, mid);
    if (mid < r) dfs(mid, r);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &A[i].first, &A[i].second);
    sort(A, A + n);
    dfs(0, n);
    printf("%d\n", (int)s.size());
    for (auto x : s)
        printf("%d %d\n", x.first, x.second);
    return 0;
}