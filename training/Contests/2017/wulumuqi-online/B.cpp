// written at 13:41 on 09 Sep 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};
template <typename T>
void dprint(T begin, T end) {for (auto i = begin; i != end; i++) cerr << (*i) << " "; cerr << "\n";};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const ld EPS = 1e-6;
int sgn(ld x) { return x < -EPS ? -1 : x > EPS ? 1 : 0;}
inline ld add(ld a, ld b) {
    if (abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
    return a + b;
};
struct Point {
    ld x, y;
    Point(ld x = 0, double y = 0) : x(x), y(y) {}
    Point operator + (Point p) { return Point(x + p.x, y + p.y); }
    Point operator - (Point p) { return Point(x - p.x, y - p.y); }
    Point operator * (ld d) { return Point(x * d, y * d); }
    bool operator < (Point p) {
        return x != p.x? x < p.x : y < p.y;
    }
    ld dot(Point p) { return add(x * p.x, y * p.y); }// 内积
    ld det(Point p) { return add(x * p.y, -y * p.x);}// 外积
};
bool on_seg(Point p1, Point p2, Point q) {
    return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}
Point intersection(Point p1, Point p2, Point q1, Point q2) {
    return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

int t;
Point car0[3], car1[3];
Point dir[2];

bool in() {
    ld sum, area;
    area = abs((car1[0] - car1[1]).det(car1[2] - car1[1]));
    for (int i = 0; i < 3; i++) {
        sum = 0;
        for (int j = 0; j < 3; j++) {
            int k = (j + 1) % 3;
            sum += abs((car1[j] - car0[i]).det(car1[k] - car0[i]));
        }
        if (sgn(sum - area) == 0) return true;
    }

    area = abs((car0[0] - car0[1]).det(car0[2] - car0[1]));
    for (int i = 0; i < 3; i++) {
        sum = 0;
        for (int j = 0; j < 3; j++) {
            int k = (j + 1) % 3;
            sum += abs((car0[j] - car1[i]).det(car0[k] - car1[i]));
        }
        if (sgn(sum - area) == 0) return true;
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            int k = (i + 1) % 3, l = (j + 1) % 3;
            Point p = intersection(car0[i], car0[k], car1[j], car1[l]);
            if (on_seg(car0[i], car0[k], p) && on_seg(car1[j], car1[l], p)) return true;
        }
    return false;
}

bool check(Point q, Point p1, Point p2, Point d, Point dd) {
    ld dx1 = p1.x - q.x, dx2 = p2.x - q.x;
    ld dy1 = p1.y - q.y, dy2 = p2.y - q.y;
    ld dirx = dd.x - d.x, diry = dd.y - d.y;
    if (sgn(dirx * (dy1 - dy2) + diry * (dx2 - dx1)) == 0) return false;
    ld t = (dx1 * dy2 - dx2 * dy1) / (dirx * (dy1 - dy2) + diry * (dx2 - dx1));
    if (sgn(t) < 0) return false;
    q = q + d * t; p1 = p1 + dd * t; p2 = p2 + dd * t;
    return (p1 - q).dot(p2 - q) < 0;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        static int cs = 0;
        printf("Case #%d: ", ++cs);
        for (int i = 0; i < 3; i++) scanf("%Lf%Lf", &car0[i].x, &car0[i].y); scanf("%Lf%Lf", &dir[0].x, &dir[0].y);
        for (int i = 0; i < 3; i++) scanf("%Lf%Lf", &car1[i].x, &car1[i].y); scanf("%Lf%Lf", &dir[1].x, &dir[1].y);
        if (in()) puts("YES");
        else if (dir[0].x == dir[1].x && dir[0].y == dir[1].y) {
            puts("NO");
        } else {
            bool flag = false;
            for (int i = 0; i < 3 && !flag; i++)
                for (int j = 0; j < 3 && !flag; j++) {
                    int k = (j + 1) % 3;
                    flag |= check(car0[i], car1[j], car1[k], dir[0], dir[1]);
                    flag |= check(car1[i], car0[j], car0[k], dir[1], dir[0]);
                }
            puts(flag? "YES" : "NO");
        }
    }
    return 0;
}
