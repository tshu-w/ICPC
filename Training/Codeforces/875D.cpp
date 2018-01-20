// written at 20:02 on 16 Oct 2017
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 2e5 + 10;

int n, h[maxn], fst[maxn], lst[maxn], L[maxn], R[maxn], bit[60];
int st[maxn];

inline ll cal(int m) {
    return 1ll * (m - 1) * m / 2;
}
void solve() {
    fill(bit, bit + 33, -1);
    for (int i = 0; i < n; i++) {
        fst[i] = -1;
        for (int j = 0; j <= 32; j++)
            if ((h[i] >> j & 1) == 0) fst[i] = max(fst[i], bit[j]);
        for (int j = 0; j <= 32; j++)
            if (h[i] >> j & 1) bit[j] = i;
    }
    fill(bit, bit + 33, n);
    for (int i = n - 1; i >= 0; i--) {
        lst[i] = n;
        for (int j = 0; j <= 32; j++)
            if ((h[i] >> j & 1) == 0) lst[i] = min(lst[i], bit[j]);
        for (int j = 0; j <= 32; j++)
            if (h[i] >> j & 1) bit[j] = i;
    }

    int t = 0;
    for (int i = 0; i < n; i++) {
        while (t > 0 && h[st[t - 1]] < h[i]) t--;
        L[i] = t == 0 ? -1 : st[t - 1];
        st[t++] = i;
    }

    t = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (t > 0 && h[st[t - 1]] <= h[i]) t--;
        R[i] = t == 0 ? n : st[t - 1];
        st[t++] = i;
    }

    // dprint(L, L + n);
    // dprint(R, R + n);
    // dprint(fst, fst + n);
    // dprint(lst, lst + n);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        int l = max(L[i], fst[i]), r = min(R[i], lst[i]);
        // cerr << l << " " << r << endl;
        res += cal(r - l - 1) - cal(i - l - 1) - cal(r - i - 1);
    }
    cout << cal(n) - res << endl;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", h + i);
    solve();
    return 0;
}
