#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 10;
const double eps = 1e-10;
int sgn(double x) { return x < -eps ? -1 : x > eps ? 1 : 0;}
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator + (Point p) { return Point(x + p.x, y + p.y); }
    Point operator - (Point p) { return Point(x - p.x, y - p.y); }
    Point operator * (double d) { return Point(x * d, y * d); }
    bool operator == (const Point& u) const { return sgn(x - u.x) == 0 && sgn(y - u.y) == 0; }
    double operator ^ (const Point& u) { return x*u.y - y*u.x; }
    double dot(Point p) { return x * p.x + y * p.y; }
    double det(Point p) { return x * p.y - y * p.x; }
};
typedef Point Vector;

double getAngle (Point p, Point q) {return acos(p.dot(q) / sqrt(p.dot(p)) / sqrt(q.dot(q)));}
double getArea (double a, double b, double c) { double s =(a+b+c)/2; return sqrt(s*(s-a)*(s-b)*(s-c)); }
double getArea (Point a, Point b, Point c) { return abs((b - a).det(c - a)) / 2; }
double getLength (Vector a) { return sqrt(a.dot(a)); }
double getPLength (Vector a) { return a.dot(a); }

struct Circle {
    Point o; double r;
    Circle(Point o = Point(0, 0), double r = 0) : o(o), r(r) {}
    double getArea (double rad) { return rad * r * r / 2; }
};

double getDistanceToSegment (Point p, Point a, Point b) {
    if (a == b) return getLength(p-a);
    Vector v1 = b - a, v2 = p - a, v3 = p - b;
    if (sgn(v1.dot(v2)) < 0) return getLength(v2);
    else if (sgn(v1.dot(v3)) > 0) return getLength(v3);
    else return abs(v1.det(v2) / getLength(v1));
}
double getCross(Vector a, Vector b) { return a.det(b); }
double getDirArea (Point a, Point b, Point c) { return getCross(b - a, c - a) / 2; }

/* 直线和圆的交点 */
int getLineCircleIntersection (Point p, Point q, Circle O, double& t1, double& t2, vector<Point>& sol) {
    Point v = q - p;
    /* 使用前需清空sol */
    sol.clear();
    double a = v.x, b = p.x - O.o.x, c = v.y, d = p.y - O.o.y;
    double e = a*a+c*c, f = 2*(a*b+c*d), g = b*b+d*d-O.r*O.r;
    double delta = f*f - 4*e*g;
    if (sgn(delta) < 0) return 0;
    if (sgn(delta) == 0) {
        t1 = t2 = -f / (2 * e);
        sol.push_back(p + v * t1);
        return 1;
    }

    t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(p + v * t1);
    t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(p + v * t2);
    return 2;
}

/* 三角形一顶点为圆心 */
double getPublicAreaToTriangle (Circle O, Point a, Point b) {
    if (sgn((a-O.o)^(b-O.o)) == 0) return 0;
    int sig = 1;
    double da = getPLength(O.o-a), db = getPLength(O.o-b);
    if (sgn(da-db) > 0) {
        swap(da, db); swap(a, b); sig = -1;
    }

    double t1, t2;
    vector<Point> sol;
    int n = getLineCircleIntersection(a, b, O, t1, t2, sol);

    if (sgn(da-O.r*O.r) <= 0) {
        if (sgn(db-O.r*O.r) <= 0) return getDirArea(O.o, a, b) * sig;

        int k = 0;
        if (n == 2 && getPLength(sol[0]-b) > getPLength(sol[1]-b)) k = 1;

        double ret = getArea(O.o, a, sol[k]) + O.getArea(getAngle(sol[k]-O.o, b-O.o));
        double tmp = (a-O.o)^(b-O.o);
        return ret * sig * sgn(tmp);
    }

    double d = getDistanceToSegment(O.o, a, b);
    if (sgn(d-O.r) >= 0) {
        double ret = O.getArea(getAngle(a-O.o, b-O.o));
        double tmp = (a-O.o)^(b-O.o);
        return ret * sig * sgn(tmp);
    }

    double ret1 = O.getArea(getAngle(a-O.o, b-O.o));
    double ret2 = O.getArea(getAngle(sol[0]-O.o, sol[1]-O.o)) - getArea(O.o, sol[0], sol[1]);
    double ret = (ret1 - ret2), tmp = (a-O.o)^(b-O.o);
    return ret * sig * sgn(tmp);
}

double getPublicAreaToPolygon(Circle O, Point* p, int n) {
    if (sgn(O.r) == 0) return 0;
    double area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += getPublicAreaToTriangle(O, p[i], p[j]);
    }
    return abs(area);
}

int n, m;
Point ps[maxn];
double area;

double getArea(Point* p, int n) {
    double ret = 0;
    for (int i = 0; i < n-1; i++)
        ret += (p[i] - p[0]).det(p[i + 1] - p[0]);
    return ret / 2;
}

bool check(Circle O, double p, double q) {
    return sgn(getPublicAreaToPolygon(O, ps, n) - area * p / q) > 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lf%lf", &ps[i].x, &ps[i].y);
    area = getArea(ps, n);
    scanf("%d", &m);
    for (int i = 0, x, y, p, q; i < m; i++) {
        scanf("%d%d%d%d", &x, &y, &p, &q);
        p = q - p;
        double lb = 0, ub = 1e4;
        while(ub - lb > eps) {
            double r = (lb + ub) / 2;
            Circle O(Point(x, y), r);
            if (check(O, p, q)) ub = r;
            else lb = r;
        }
        printf("%.12f\n", lb);
    }
    return 0;
}
