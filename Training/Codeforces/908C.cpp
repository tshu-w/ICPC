// written at 23:13 on 29 Dec 2017
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

int n, R, X[maxn], l[maxn], r[maxn];
double Y[maxn];

int main() {
  scanf("%d%d", &n, &R);
  for (int i = 0; i < n; i++) scanf("%d", X + i), l[i] = X[i] - R, r[i] = X[i] + R;
  for (int i = 0; i < n; i++) {
    double iy = R;
    for (int j = 0; j < i; j++)
      if ((X[i] - R <= l[j] && l[j] <= X[i] + R)||
          (X[i] - R <= r[j] && r[j] <= X[i] + R)) {
        iy = max(iy, Y[j] + sqrt(sqr(2 * R) - sqr(X[i] - X[j])));
      }
    Y[i] = iy;
  }
  for (int i = 0; i < n; i++)
    printf("%.8f%c", Y[i], " \n"[i + 1 == n]);
  return 0;
}
