// written at 11:37 on 02 Oct 2017
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

const int maxn = 1e3 + 10;
const int maxm = 5e6 + 10;

int n, m;
bitset<maxn> bst[10], D;
char s[maxm];

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < 10; i++) bst[i].reset(); D.reset();
        for (int i = 0, k; i < n; i++) {
            scanf("%d", &k);
            for (int j = 0, x; j < k; j++) {
                scanf("%d", &x);
                bst[x].set(i);
            }
        }
        getchar(); fgets(s, sizeof(s), stdin);
        m = strlen(s);
        for (int i = 0; i < m; i++) {
            D <<= 1; D.set(0);
            D &= bst[s[i] - '0'];
            if (D[n - 1] == 1) {
                char tmp = s[i + 1];
                s[i + 1] = '\0';
                puts(s + (i - n + 1));
                s[i + 1] = tmp;
            }
        }
    }
    return 0;
}
