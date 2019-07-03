// written at 19:41 on 01 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename "1004"
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";
};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 5e5 + 10;
const int MAX_M = 32;

int idx(int num, int k) {return num >> k & 1;}

int t, n, A[MAX_N];
int cnt[MAX_M][2];
// Trie
int ch[MAX_N * MAX_M][2];
int size[MAX_N * MAX_M];
ll sum[MAX_N * MAX_M];
int sz;

void Trie() { sz = 1; memset(ch[0], 0, sizeof(ch[0])); }

int newnode() {
    memset(ch[sz], 0, sizeof(ch[sz]));
    sum[sz] = 0; size[sz] = 0;
    return sz++;
}

void insert(int num, int x) {
    int u = 0;
    for (int i = 30; i >= 0; i--) {
        int bt = idx(num, i);
        if (!ch[u][bt]) ch[u][bt] = newnode();
        cnt[i][bt]++;
        u = ch[u][bt];
        size[u] += x;
        sum[u] += x * cnt[i][bt ^ 1];
    }
}

ll count(int num) {
    ll res = 0;
    int u = 0, v;
    for (int i = 30; i >= 0; i--) {
        int bt = idx(num, i);
        v = ch[u][bt ^ 1];
        u = ch[u][bt];
        if (v) res += sum[v] - (ll)size[v] * cnt[i][bt];
    }
    return res;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        Trie();
        for (int i = 0; i < n; i++) {
            scanf("%d", A + i);
            insert(A[i], 1);
        }
        memset(cnt, 0, sizeof(cnt));
        ll ans = 0;
        for (int i = 0; i + 1 < n; i++) {
            insert(A[i], -1);
            ans += count(A[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
