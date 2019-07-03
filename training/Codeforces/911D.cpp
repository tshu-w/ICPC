// written at 22:29 on 28 Dec 2017
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

const int maxn = 1510;

int n, A[maxn], m;
int bit[maxn];

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}
void add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}

int cal(int l, int r) {
  int ans = 0;
  memset(bit, 0, sizeof bit);
  for (int j = l; j < r; j++) {
    ans += (j - l) - sum(A[j]);
    add(A[j], 1);
  }
  return ans;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", A + i);
  int tot = cal(0, n) & 1;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    tot ^= (r - l + 1) / 2 & 1;
    if (tot) puts("odd");
    else puts("even");
  }
  return 0;
}
