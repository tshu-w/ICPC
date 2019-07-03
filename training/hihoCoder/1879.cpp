#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 10;
const __int128 inv3 = 332748118;
const __int128 mod = 998244353;

template<typename T> T mod_inv(T x, T mod) {
  return x == 1 ? 1 : (mod - (mod / x)) * mod_inv(mod % x, mod) % mod;
}

template<typename T> int quad(T x, T y) {
  if (x <= 0 && y < 0) return 0;
  if (x > 0 && y <= 0) return 1;
  if (x >= 0 && y > 0) return 2;
  if (x < 0 && y >= 0) return 3;
  return 2;
}

struct Point {
  __int128 x, y;
  double ang;
  Point(__int128 x = 0, __int128 y = 0): x(x), y(y) { ang = atan2((ll)y, (ll)x); }
  bool operator < (const Point& p) const {
    // if (quad(x, y) == quad(p.x, p.y)) {
    //   if (x * p.y == y * p.x) return x * x + y * y < p.x * p.x + p.y * p.y;
    //   else return x * p.y - y * p.x > 0;
    // }
    // return quad(x, y) < quad(p.x, p.y);
    // return atan2((ll)y, (ll)x) < atan2((ll)u.y, (ll)u.x);
    return ang < p.ang;
  }
  Point operator - (const Point& u) const { return Point(x - u.x, y - u.y); }
  __int128 det(Point p) { return x * p.y - y * p.x; }
  __int128 dot(Point p) { return x * p.x + y * p.y; }
};

int t, n;
vector<Point> ps, qs;
__int128 sumx[2 * maxn], sumy[2 * maxn];

bool check2(int a, int b) {
  return qs[b].det(qs[a]) < 0 || (qs[b].det(qs[a]) == 0 && qs[b].dot(qs[a]) > 0 && qs[a] < qs[b]);
}

bool check1(int a, int b) {
  return qs[b].det(qs[a]) <= 0 && qs[b].dot(qs[a]) > 0;
}

int main() {
  int t, n;
  for (scanf("%d", &t); t--; ) {
    scanf("%d", &n); ps.clear();
    for (int i = 0; i < n; i++) {
      ll x, y; scanf("%lld%lld", &x, &y);
      ps.push_back(Point(x, y));
    }
    __int128 sumall = 0, sumexc = 0;
    for (int i = 0; i < n; i++) {
      qs.clear();
      for (int j = 0; j < n; j++) if (i != j) qs.push_back(ps[j] - ps[i]);
      int m = qs.size();
      sort(qs.begin(), qs.end()); 
      for (int j = 0; j < m; j++) qs.push_back(qs[j]);

      sumx[0] = sumy[0] = 0;
      for (int j = 0; j < 2 * m; j++) {
        sumx[j + 1] = (sumx[j] + qs[j].x);
        sumy[j + 1] = (sumy[j] + qs[j].y);
      }

      int r1 = 0, r2 = 0;
      for (int j = 0; j < m; j++) {
        r1 = max(r1, j + 1); r2 = max(r2, j + 1);
        while (r2 - j < m && check2(j, r2)) r2++;
        while (r1 < r2 && check1(j, r1)) r1++;
        sumall = ( sumall + ((sumy[r2] - sumy[j]) % mod * qs[j].x - (sumx[r2] - sumx[j]) % mod * qs[j].y)) % mod;
        sumexc = ( sumexc + ((sumy[r2] - sumy[r1]) % mod * qs[j].x - (sumx[r2] - sumx[r1]) % mod * qs[j].y) ) % mod;
      }
    }
    sumall = (sumall * inv3) % mod;
    printf("%lld\n", ll(((sumall - sumexc) % mod + mod) % mod));
  }
  return 0;
}