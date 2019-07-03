#include <bits/stdc++.h>

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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 15;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, A[MAX_N], ans[MAX_N];

bool ok(int x, int y) {
    for (int i = 0; i < x; ++i)
        if (A[i] == y || x + y == i + A[i] || y - x == A[i] - i)    
            return false;
    return true;
}
int dfs(int k, int n) {
    if (k == n)
        return 1;
    int res = 0;
    for (int i = 0; i < n; ++i) 
        if (ok(k, i)) {
            A[k] = i;
            res += dfs(k + 1, n);
        }    
    return res;
}
int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 10; ++i)
        ans[i] = dfs(0, i);
    while (scanf("%d", &N) && N) {
        printf("%d\n", ans[N]);
    }    
    return 0;
}