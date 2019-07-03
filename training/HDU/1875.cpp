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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 10000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;}

int t, C, X[MAX_N], Y[MAX_N];
vector<pair<int, Pii>> v;

int par[MAX_N];
int rnk[MAX_N];
void init(int n) {
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        rnk[i] = 0;
    }
}
int find(int x) {
    return par[x] == x? x : par[x] = find(par[x]);
}
bool same(int x, int y) {
    return find(x) == find(y);
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
    }
}

inline bool in(int x) {
    return (100 <= x && x <= 1000000);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &C);
        for (int i = 0; i < C; ++i)
            scanf("%d%d", X + i, Y + i);
        v.clear();
        for (int i = 0; i < C; ++i)
            for (int j = i + 1; j < C; ++j)
                if (in(sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]))) 
                    v.push_back(make_pair(sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]), Pii(i, j)));
        sort(v.begin(), v.end());
        init(C);
        int cnt = 0;
        double res = 0;
        for (int i = 0; i < v.size(); ++i) {
            pair<int, Pii> e = v[i];
            if (!same(e.second.first, e.second.second)) {
                unite(e.second.first, e.second.second);
                res += sqrt(e.first);
                ++cnt;
            }
        }
        if (cnt == C - 1)
            printf("%.1lf\n", res * 100);
        else printf("oh!\n");
    }
    return 0;
}