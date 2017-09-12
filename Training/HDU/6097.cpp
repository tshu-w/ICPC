// written at 18:53 on 10 Aug 2017
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

int t;
double R, x[5], y[5], k, ans, r, d0, d1;

double dis(double x1, double x2, double y1, double y2) {
    return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

bool intersection() {
    return abs(x[2] * y[3] - x[3] * y[2]) / d1 <= R;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lf", &R);
        for (int i = 0; i < 2; i++) {
            scanf("%lf%lf", x + i, y + i);
            k = sqr(R) / (sqr(x[i]) + sqr(y[i]));
            x[i + 2] = k * x[i];
            y[i + 2] = k * y[i];
        }
        r = sqrt(sqr(x[0]) + sqr(y[0]));
        d0 = dis(x[0], x[1], y[0], y[1]);
        d1 = dis(x[2], x[3], y[2], y[3]);
        if (intersection()) ans = d1 / sqrt(k);
        else ans = 2 * sqrt(sqr(R - sqrt(sqr(r) - sqr(d0 / 2))) + sqr(d0 / 2));
        printf("%.10lf\n", ans);
    }
    return 0;
}
