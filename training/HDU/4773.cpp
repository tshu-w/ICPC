#include <bits/stdc++.h>
using namespace std;
#define ass(condition) if (!(condition)) { int x = 1, y = 0; cout << x / y << endl; }

const double pi = acos(-1.);
const double eps = 1e-8;

inline int sgn(double x) { return x < -eps ? -1 : x > eps ? 1 : 0;}
inline double sqr(double x) { return x * x;}

struct Point {
  double x, y;
  Point (double x = 0, double y = 0): x(x), y(y) {}
  void read() { scanf("%lf%lf", &x, &y);} 
  void write() { printf("(%f, %f)\n", x, y);}

  Point operator + (const Point& u) { return Point(x + u.x, y + u.y); }
  Point operator - (const Point& u) { return Point(x - u.x, y - u.y); }
  Point operator * (const double u) { return Point(x * u, y * u); }
  Point operator / (const double u) { return Point(x / u, y / u); }
  double dot(Point p) { return x * p.x + y * p.y; }
  double crs(Point p) { return x * p.y - y * p.x; }
};
typedef Point Vector;

double getDistance(Point a, Point b) { double x=a.x-b.x, y=a.y-b.y; return sqrt(x*x + y*y); }
double getAngle(Vector u) { return atan2(u.y, u.x); }

struct Circle {
  Point o; double r;
  Circle() {} 
  Circle (Point o, double r = 0): o(o), r(r) {}
  void read() { o.read(), scanf("%lf", &r);}
  void write() { printf("%.10f %.10f %.10f\n", o.x, o.y, r);}
  Point point(double rad) { return Point(o.x + cos(rad) * r, o.y + sin(rad) * r); }
};

int getTangents(Circle o1, Circle o2, Point* a, Point* b) {
  int cnt = 0;
  if (sgn(o1.r - o2.r) < 0) { swap(o1, o2); swap(a, b); }
  double d = getDistance(o1.o, o2.o);
  double rdif = o1.r - o2.r, rsum = o1.r + o2.r;
  if (sgn(d - rdif) < 0) return 0;
  if (sgn(d) == 0 && sgn(rdif) == 0) return -1;

  double base = getAngle(o2.o - o1.o);
  if (sgn(d - rdif) == 0) {
    a[cnt] = o1.point(base); b[cnt] = o2.point(base); cnt++;
    return cnt;
  }

  double ang = acos(rdif / d);
  a[cnt] = o1.point(base+ang); b[cnt] = o2.point(base+ang); cnt++;
  a[cnt] = o1.point(base-ang); b[cnt] = o2.point(base-ang); cnt++;

  if (sgn(d - rsum) == 0) {
    a[cnt] = o1.point(base); b[cnt] = o2.point(pi+base); cnt++;
  } else if (sgn(d - rsum) > 0) {
    double ang = acos(rsum / d);
    a[cnt] = o1.point(base+ang); b[cnt] = o2.point(pi+base+ang); cnt++;
    a[cnt] = o1.point(base-ang); b[cnt] = o2.point(pi+base-ang); cnt++;
  }
  return cnt;
}

Circle inv(Circle O, Point p, double r2 = 25.0) {
  double d = getDistance(O.o, p);
  double a = 1 / (d - O.r);
  double b = 1 / (d + O.r);
  O.r = (a - b) / 2 * r2;
  O.o = p + (O.o - p) * (a + b) * r2 / 2 / d;
  return O;
}

bool getIntersection(Point p, Vector v, Point q, Vector w, Point& o) {
  if (sgn(v.crs(w)) == 0) return false;
  Vector u = p - q;
  double k = w.crs(u) / v.crs(w);
  o = p + v * k;
  return true;
}

Circle inv(Point a, Point b, Point p, double r2 = 25.0) {
  Vector v = Vector(b.y - a.y, a.x - b.x);
  Point x;
  getIntersection(p, v, a, b - a, x);
  double d = getDistance(x, p);
  if (sgn(d) == 0) return Circle(Point(0, 0), 0);
  double r = r2 / d / 2;
  Point o = p + (x - p) * (r / d);
  return Circle(o, r);
}

int t;
Point p, a[20], b[20];
Circle c1, c2, C1, C2;
vector<Circle> ans;

bool check(Circle c) {
  bool flag = true;
  flag &= sgn(getDistance(c.o, c1.o) - c.r - c1.r) == 0;
  flag &= sgn(getDistance(c.o, c2.o) - c.r - c2.r) == 0;
  flag &= sgn(getDistance(p, c.o) - c.r) == 0;
  return flag;
}

int main() {
  for (scanf("%d", &t); t--; ) {
    c1.read(); c2.read(); p.read();
    C1 = inv(c1, p); C2 = inv(c2, p);
    int n = getTangents(C1, C2, a, b);
    ans.clear();
    for (int i = 0; i < n; i++) {
      Circle c = inv(a[i], b[i], p);
      if (check(c)) ans.push_back(c);
    }
    printf("%d\n", (int)ans.size());
    for (auto c : ans) c.write();
  } 
  return 0;
}