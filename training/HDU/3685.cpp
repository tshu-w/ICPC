#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif    
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50000 + 5;
double eps = 1e-9;

template <typename T>
inline T sqr(T a) { return a * a;};

double add(double a, double b) {
    if (abs(a + b) < eps * (abs(a) + abs(b))) return 0;
    return a + b;
}

struct P {
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y) {}    
    P operator + (P p) {
        return P(add(x, p.x), add(y, p.y));
    }
    P operator - (P p) {
        return P(add(x, -p.x), add(y, -p.y));
    }
    P operator * (double d) {
        return P(x * d, y * d);
    }
    double dot(P p) { // 内积
        return add(x * p.x, y * p.y);
    }
    double det(P p) { // 外积
        return add(x * p.y, -y * p.x);
    }
};

// 字典序比较
bool cmp_x(P a, P b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
// 求凸包
vector<P> convex_hull(P *ps, int n) {
    sort(ps, ps + n, cmp_x);
    int k = 0;    // 凸包的顶点数
    vector<P> qs(n * 2);    // 构造中的凸包
    // 构造凸包的下侧
    for (int i = 0; i < n; ++i)
    {
        while (k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) --k;
        qs[k++] = ps[i];
    }
    // 构造凸包的上侧
    for (int i = n - 2, t = k; i >= 0; --i)
    {
        while (k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) --k;
        qs[k++] = ps[i];
    }
    qs.resize(k - 1);
    return qs;
}
 
// 距离的平方
double dist(P p, P q) {
    return sqrt((double)(p - q).dot(p - q));
}

P getG(P *ps, int n) {
    P g(0, 0);
    double area = 0., cur;
    for (int i = 0; i < n; ++i) {
        cur = ps[i].det(ps[(i + 1) % n]) * 0.5;
        g = g + (ps[i] + ps[(i + 1) % n]) * (1. / 3.) * cur;
        area += cur;
    }
    return g * (1. / area);
}

int t, N;
P ps[MAX_N], G;

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            scanf("%lf%lf", &ps[i].x, &ps[i].y);
        G = getG(ps, N);
        // cout << G.x << " " << G.y << endl;
        vector<P> qs = convex_hull(ps, N);
        int ans = 0;
        for (int i = 0; i < qs.size(); ++i) {
            // cout << qs[i].x << " " << qs[i].y << endl;
            int j = (i + 1) % N;
            if ((G - qs[i]).dot(qs[j] - qs[i]) > eps && (G - qs[j]).dot(qs[i] - qs[j]) > eps)
                ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}