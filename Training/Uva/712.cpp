// written at 14:45 on 11 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int maxn = 1024;
const int maxm = 10;

char x[maxm][2], s[maxn];
int m, n;
int a[maxn], b[maxm];

int main() {
    while (scanf("%d", &m) && m) {
        for (int i = 0; i < m; i++) scanf("%s", x[i]);
        scanf("%s", s);
        for (int i = 0; i < 1 << m; i++) a[i] = s[i] - '0';
        static int cs = 0;
        printf("S-Tree #%d:\n", ++cs);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            int u = 1;
            for (int j = 0; j < m; j++) {
                b[j] = s[x[j][1] - '1'] - '0';
                u = 2 * u + b[j];
            }
            printf("%d", a[u - (1 << m)]);
        }
        printf("\n\n");
    }
    return 0;
}
