// written at 14:12 on 26 Jul 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

namespace fastIO {
#define BUF_SIZE 100000
    //fread -> read
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline void read(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror)
            return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
#undef BUF_SIZE
};
using namespace fastIO;

const int MAX_N = 1e6 + 10;
const ll MOD = 1e9 + 7;

struct SEG {
    int l, r, m;
} seg[MAX_N];
int n, it;
ll fact[MAX_N], iact[MAX_N];
map<ll, ll> inv;

void init() {
    iact[1] = 1ll;
    for (int i = 2; i < MAX_N; i++)
        iact[i] = MOD - (MOD / i) * iact[MOD % i] % MOD;

    fact[0] = iact[0] = 1ll;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = i * fact[i - 1] % MOD;
        iact[i] = iact[i - 1] * iact[i] % MOD;
    }
}

bool cmp(const SEG &a, const SEG &b) {
    return a.l != b.l? a.l < b.l : a.r > b.r;
}

ll C(int a, int b) {
    return fact[a] * iact[b] % MOD * iact[a - b] % MOD;
}

ll solve(int l, int r) {
    if (seg[it].l != l || seg[it].r != r) return 0;
    int a = seg[it].m - seg[it].l, b = seg[it].r - seg[it].m, cur = it;
    ll res = C(a + b, a);
    if (seg[cur].m != seg[cur].l) ++it, res = res * solve(l, seg[cur].m - 1) % MOD;
    if (seg[cur].m != seg[cur].r) ++it, res = res * solve(seg[cur].m + 1, r) % MOD;
    return res;
}

int main() {
    int cs = 0;
    init();
    while (read(n), !fastIO::IOerror) {
        for (int i = 0; i < n; i++)
            read(seg[i].l);
        for (int i = 0; i < n; i++)
            read(seg[i].r);
        for (int i = 0; i < n; i++)
            seg[i].m = i + 1;
        sort(seg, seg + n, cmp);
        it = 0;
        printf("Case #%d: %lld\n", ++cs, solve(1, n));
    }
    return 0;
}
