// written at 22:19 on 30 Jul 2017
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

int n;
ll a, b;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a, &b);
        ll mul = a * b;
        ll lb = 0, ub = 1e6;
        while (lb + 1 < ub) {
            ll mid = (lb + ub) / 2;
            if (mid * mid * mid < mul) lb = mid;
            else ub = mid;
        }
        if (ub * ub * ub != mul) {
            printf("No\n");
            continue;
        }
        if (a % ub || b % ub) {
            printf("No\n");
            continue;
        }
        a /= ub; b /= ub;
        if (a * b == ub) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
