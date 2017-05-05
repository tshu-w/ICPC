// written at 16:10 on 03 May 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 100 + 10;

struct Building {
    double x1, x2, y, h;
    int id;
    Building(double _x1 = 0, double _x2 = 0, double _y = 0, double _h = 0, int _id = 0) {
        x1 = _x1; x2 = _x2; y = _y; h = _h; id = _id;
    }
};

bool cmp(const Building &a, const Building &b) {
    return a.x1 < b.x1 || (a.x1 == b.x1 && a.y < b.y);
}

int main(void) {
    int n, t = 0;
    Building b[MAX_N];
    double x, y, w, d, h, xs[MAX_N * 2];
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf%lf%lf%lf", &x, &y, &w, &d, &h);
            b[i] = Building(x, x + w, y, h, i);
            xs[2 * i] = x;
            xs[2 * i + 1] = x + w;
        }
        sort(b, b + n, cmp);
        sort(xs, xs + 2 * n);
        int m = unique(xs, xs + 2 * n) - xs;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j + 1 < m; j++) {
                double x = ( xs[j] + xs[j + 1] ) / 2;
                bool flag = b[i].x1 <= x && x <= b[i].x2;
                for (int k = 0; flag && k < n; k++)
                    if (b[k].x1 <= x && x <= b[k].x2 && b[k].y < b[i].y && b[k].h >= b[i].h)
                        flag = false;
                if (flag) {
                    ans.push_back(b[i].id + 1);
                    break;
                }
            }
        }
        if (t++) puts("");
        printf("For map #%d, the visible buildings are numbered as follows:\n", t);
        for (int i = 0; i < (int)ans.size(); i++)
            printf("%d%c", ans[i], i + 1 == (int)ans.size()? '\n' : ' ');
    }
    return 0;
}
