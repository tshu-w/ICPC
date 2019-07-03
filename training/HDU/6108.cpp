// written at 14:02 on 12 Aug 2017
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

int t, n;

int cnt(int n) {
    int res = 0;
    for (int i = 1; (ll)i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i != i) res += 2;
            else res++;
        }
    }
    return res;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", cnt(n - 1));
    }
    return 0;
}
