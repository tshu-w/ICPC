// written at 22:18 on 28 Dec 2017
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

int k[4], cnt[1510];

int main() {
  for (int i = 0; i < 3; i++) {
    cin >> k[i];
    cnt[k[i]]++;
  }
  if (cnt[1] == 1 || cnt[2] == 2 || cnt[3] == 3) {
    cout << "YES\n";
    return 0;
  }
  if (cnt[2] == 1 && cnt[4] == 2) {
    cout << "YES\n";
    return 0;
  }
  cout << "NO\n";
  return 0;
}
