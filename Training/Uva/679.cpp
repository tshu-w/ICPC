// written at 11:11 on 03 Aug 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
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

int t, d, n;

int solve(int n) {
    int dd = 1, p = 1;
    while (dd < d) {
        p = 2 * p + (n & 1);
        n >>= 1;
        dd++;
    }
    return p;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &d, &n);
        printf("%d\n", solve(n - 1));
    }
    scanf("%d", &t);
    return 0;
}
