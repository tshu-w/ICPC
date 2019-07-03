// written at 22:05 on 28 Dec 2017
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

const int maxn = 1e5 + 10;

int n, A[maxn], imin, ans, last;

int main() {
  scanf("%d", &n);
  ans = imin = INT_MAX;
  for (int i = 0; i < n; i++) {
    scanf("%d", A + i);
    imin = min(A[i], imin);
  }
  last = -1;
  for (int i = 0; i < n; i++)
    if (A[i] == imin) {
      if (last != -1) ans = min(ans, i - last);
      last = i;
    }
  printf("%d\n", ans);
  return 0;
}
