// written at 22:20 on 30 Jul 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T> inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";
};


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 1e5 + 10;
const int MAX_K = 50 + 10;
const int INF = INT_MAX / 3;


int n, k, A[MAX_N], dp[2][MAX_K];
int rmq[MAX_N * 4], dat[MAX_N * 4];
int *cur, *nxt;
int lst[MAX_N], pre[MAX_N];

void build(int k, int l, int r) {
    dat[k] = 0;
    if (l + 1 == r) {
        rmq[k] = cur[l];
        return;
    }
    build(2 * k + 1, l, (l + r) / 2);
    build(2 * k + 2, (l + r) / 2, r);
    rmq[k] = max(rmq[k * 2 + 1], rmq[k * 2 + 2]);
}

void add(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l) return;
    if (a <= l && r <= b) {
        rmq[k]++, dat[k]++;
        return;
    }
    add(a, b, 2 * k + 1, l, (l + r) / 2);
    add(a, b, 2 * k + 2, (l + r) / 2, r);
    rmq[k] = max(rmq[k * 2 + 1], rmq[k * 2 + 2]) + dat[k];
}

int query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l) return -INF;
    if (a <= l && r <= b) return rmq[k];
    return max(query(a, b, 2 * k + 1, l, (l + r) / 2), query(a, b, 2 * k + 2, (l + r) / 2, r)) + dat[k];
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", A + i), --A[i];
    memset(lst, -1, sizeof lst);
    int cnt = 0;
    cur = dp[0], nxt = dp[1];
    for (int i = 0; i < n; i++) {
        pre[i] = lst[A[i]];
        lst[A[i]] = i;
        if (pre[i] == -1) ++cnt;
        cur[i] = cnt;
    }
    for (int i = 2; i <= k; i++) {
        build(0, 0, n);
        for (int j = 0; j < i - 1; j++) nxt[j] = -INF;
        for (int j = i - 1; j < n; j++) {
            add(max(0, pre[j]), j, 0, 0, n);
            nxt[j] = query(0, j, 0, 0, n);
        }
        swap(cur, nxt);
    }
    cout << cur[n - 1] << endl;
    return 0;
}
