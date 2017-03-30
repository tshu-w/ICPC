// written at 12:37 on 30 Mar 2017
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
const int MAX_N = 1e6 + 10;
const int GAP = 1000;

int n, k, A[MAX_N];
set<int> s, flag;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", A + i);
        s.insert(A[i] - n);
    }
    queue<Pii> que;
    que.emplace(0, 0);
    while (que.size()) {
        Pii p = que.front(); que.pop();
        if (p.first == 0 && p.second != 0)
            return printf("%d\n", p.second), 0;
        for (auto x : s)
            if (-1000 <= x + p.first && x + p.first <= 1000 && flag.count(x + p.first) == 0) {
                que.emplace(x + p.first, p.second + 1);
                flag.insert(x + p.first);
            }
    }
    printf("-1\n");
    return 0;
}
