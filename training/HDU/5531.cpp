#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
const double pi = acos(-1.0);
const double eps = 1e-8;
template <typename T>
inline T sqr(T a) { return a * a;};
int sgn(double x) { return x < -eps ? -1 : x > eps ? 1 : 0;}
int t, n;
double d[maxn], r[maxn], x[maxn], y[maxn];

void init() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lf%lf", x + i, y + i);
    x[n] = x[0], y[n] = y[0];
    for (int i = 0; i < n; i++) d[i] = sqrt(sqr(x[i+1] - x[i]) + sqr(y[i+1] - y[i]));
}
double r1[maxn];
double C(double k) {
    r1[0] = k;
    for (int i = 0; i + 1 < n; i++) r1[i + 1] = d[i] - r1[i];
    double ans = 0.;
    for (int i = 0; i < n; i++) ans += sqr(r1[i]) * pi;
    return ans;
}

int work() {
    double res = 0.0;
    for (int i = 0; i + 1 < n; i++)
        if (i & 1) res -= d[i];
        else res += d[i];
    if (n & 1) {
        r[0] = (res + d[n - 1]) / 2;
    } else {
        if (sgn(res - d[n - 1]) != 0) return puts("IMPOSSIBLE");
        double lb = 0, ub = DBL_MAX, tmp = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1) tmp -= d[i], lb = max(lb, tmp);
            else tmp += d[i], ub = min(ub, tmp);
        }
        if (ub < lb) return puts("IMPOSSIBLE");
        while (lb + eps < ub) {
            double lm = (lb * 2 + ub) / 3, um = (lb + ub * 2) / 3;
            if (C(lm) >= C(um)) lb = lm;
            else ub = um;
        }
        r[0] = lb;
    }
    for (int i = 0; i + 1 < n; i++) r[i + 1] = d[i] - r[i];
    for (int i = 0; i < n; i++) if (r[i] < 0) return puts("IMPOSSIBLE");
    double ans = 0.;
    for (int i = 0; i < n; i++) ans += sqr(r[i]) * pi;
    printf("%.2f\n", ans);
    for (int i = 0; i < n; i++) printf("%.2f\n", r[i]);
    return 0;
}

int main() {
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++) {
        init(); work();
    }
    return 0;
}
