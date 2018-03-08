// written at 13:59 on 22 Feb 2018
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

const int maxn = 1e6 + 10;

int n, a, b, A[maxn];

int main() {
    scanf("%d%d%d", &n, &a, &b);
    if (a > b) swap(a, b);
    if (a == 1) {
        for (int i = 0; i < n; i++)
            printf("%d%c", i + 1, " \n"[i + 1 == n]);
        return 0;
    }
    for (int i = 0; i * a <= n; i++)
        if ((n - i * a) % b == 0) {
            int x = i, y = (n - i * a) / b, cur = 1;
            for (int j = 0; j < x; j++) {
                printf("%d ", cur + a - 1);
                for (int k = 0; k < a - 1; k++)
                    printf("%d ", cur + k);
                cur = cur + a;
            }
            for (int j = 0; j < y; j++) {
                printf("%d ", cur + b - 1);
                for (int k = 0; k < b - 1; k++)
                    printf("%d ", cur + k);
                cur = cur + b;
            }
            printf("\n");
            return 0;
        }
    printf("-1\n");
    return 0;
}
