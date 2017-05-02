// written at 11:51 on 15 Feb 2017 
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
typedef pair<Pii, int > Piii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;
const int MAX_M = 3e5 + 10;

struct node
{
    set<int> s;
    int m;    
}dat[MAX_N * 4];

int N, M, A[MAX_N], ans[MAX_M];
Piii q[MAX_M];

void init(int k, int l, int r) {
    dat[k].m = INF;
    rep(i, l, r) dat[k].s.insert(A[i]);
    if (l + 1 == r) return;
    init(2 * k + 1, l, (l + r) / 2);
    init(2 * k + 2, (l + r) / 2, r);
}
int query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l) return INF;
    if (a <= l && r <= b) return dat[k].m;
    int lm = query(a, b, 2 * k + 1, l, (l + r) / 2);
    int rm = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return min(lm, rm);
}
void update(int a, int b, int k, int l, int r, int x, int &mi) {
    if (a >= r || b <= l) return;
    if (l + 1 == r) {
        dat[k].m = min(dat[k].m, abs(x - A[l]));
        mi = min(mi, dat[k].m);
        return;
    }
    set<int> &s = dat[k].s;
    auto p = s.lower_bound(x);
    if ((p == s.end() || (*p - x) >= mi) && (p == s.begin() || (x - *(--p) >= mi))) {
        mi = min(mi, query(a, b, k, l, r));
        return;
    }
    update(a, b, 2 * k + 1, l, (l + r) / 2, x, mi);
    update(a, b, 2 * k + 2, (l + r) / 2, r, x, mi);
    dat[k].m = min(dat[2 * k + 1].m, dat[2 * k + 2].m);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    rep(i, 0, N) scanf("%d", A + i);
    scanf("%d", &M);
    rep(i, 0, M) {
        scanf("%d%d", &q[i].first.first, &q[i].first.second);
        --q[i].first.first; --q[i].first.second;
        q[i].second = i; 
    }
    sort(q, q + M);
    init(0, 0, N);
    int l = N - 1;
    irep(i, M, 0) {
        while (l >= q[i].first.first) {
            int mi = INF;
            update(l + 1, N, 0, 0, N, A[l], mi);
            --l;
        }
        ans[q[i].second] = query(q[i].first.first, q[i].first.second + 1, 0, 0, N);
    }
    rep(i, 0, M) printf("%d\n", ans[i]);
    return 0;
}