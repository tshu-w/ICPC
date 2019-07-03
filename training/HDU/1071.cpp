#include <bits/stdc++.h>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;

template <typename T>
inline T sqr(T a) { return a * a;};
int main(int argc, char const *argv[])
{
    int n;
    double a, k, area, x1, x2, x3, y1, y2, y3;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        a = (y2 - y1) / sqr(x2 - x1);
        k = (y3 - y2) / (x3 - x2);
        area = a * (x3 * x3 * x3 - x2 * x2 * x2) / 3 - a * x1 * (sqr(x3) - sqr(x2)) + (a * sqr(x1) + y1 - y2 + k * x2) * (x3 - x2) -
        k * (sqr(x3) - sqr(x2)) / 2;
        printf("%.2lf\n", area);
    }
    return 0;
}