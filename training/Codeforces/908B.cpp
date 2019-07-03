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

const int maxn = 50 + 10;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, a[5], ans = 0, sx, sy;
string s, mz[maxn];

int id(int k) {
  for (int i = 0; i < 4; i++)
    if (a[i] == k) return i;
  return -1;
}

bool dfs(int x, int y, int st) {
  int xx = x + dx[id(s[st] - '0')], yy = y + dy[id(s[st] - '0')];
  // if (xx < 0 || xx >= n || yy < 0 || yy >= m) return false;
  if (mz[xx][yy] == '#') return false;
  if (mz[xx][yy] == 'E') return true;
  if (st + 1 < SZ(s)) return dfs(xx, yy, st + 1);
  return false;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> mz[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mz[i][j] == 'S') sx = i, sy = j;
  cin >> s;
  for (int i = 0; i < 4; i++) a[i] = i;
  do {
    if (dfs(sx, sy, 0)) ans++;
  } while (next_permutation(a, a + 4));
  cout << ans << endl;
  return 0;
}
