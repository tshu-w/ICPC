// written at 15:35 on 02 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename "test"
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

const int MAX_N = 1e5 + 10;

int n, m, lft[MAX_N], rgh[MAX_N];

void link(int l, int r) { rgh[l] = r; lft[r] = l;}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        memset(lft, 0, sizeof lft);
        memset(rgh, 0, sizeof rgh);
        for (int i = 0; i + 1 <= n; i++) link(i, i + 1);
        bool inv = false;
        for (int i = 0; i < m; i++) {
            int opt, a, b;
            scanf("%d", &opt);
            if (opt == 4) {inv = !inv; continue;}
            scanf("%d%d", &a, &b);
            int &la = lft[a], &ra = rgh[a], &lb = lft[b], &rb = rgh[b];
            if (inv && opt != 3) opt = 3 - opt;
            switch (opt) {
                case 1: {
                    rgh[la] = ra; lft[ra] = la;
                    rgh[lb] = a;
                    la = lb;
                    lb = a;
                    ra = b;
                    break;
                }
                case 2: {
                    rgh[la] = ra; lft[ra] = la;
                    lft[rb] = a;
                    ra = rb;
                    rb = a;
                    la = b;
                    break;
                }
                case 3: {
                    if (la == b) {
                        rgh[lb] = a; lft[ra] = b;
                        la = lb; rb = ra;
                        lb = a; ra = b;
                    } else if (ra == b) {
                        rgh[la] = b; lft[rb] = a;
                        lb = la; ra = rb;
                        la = b; rb = a;
                    } else {
                        swap(la, lb); swap(ra, rb);
                        rgh[la] = a; lft[ra] = a;
                        rgh[lb] = b; lft[rb] = b;
                    }
                    break;
                }
            }
        }
        ll sum = 0;
        for (int i = 1, j = rgh[0]; i <= n; i += 2) {
            if (i & 1) sum += j;
            j = rgh[rgh[j]];
        }
        static int cs = 0;
        printf("Case %d: %lld\n", ++cs, !inv || n & 1? sum : (ll) n * (n + 1) / 2 - sum);
    }
    return 0;
}
