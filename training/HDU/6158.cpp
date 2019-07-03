#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
const double pi = acos(-1.);
const double eps = 1e-15;

int t, n;
double r1, r2;

int main() {
  for (scanf("%d", &t); t--; ) {
    scanf("%lf%lf%d", &r1, &r2, &n); if (r1 < r2) swap(r1, r2);
    double x1 = 2 * r1, x2 = sqr(x1) / (2 * r2);
    double r = (x2 - x1) / 2.;
    double ans = 0;
    for (int i = 1; i <= n; i++) {
      double lst = ans;
      double d = sqrt(sqr(x1 + r) + sqr(i / 2 * 2 * r));
      double a = sqr(x1) / (d - r), b = sqr(x1) / (d + r);
      double rr = (a - b) / 2;
      ans += sqr(rr); 
      if ((ans - lst) < eps) break;
    }
    printf("%.5f\n", ans * pi);
  }
  return 0;
}