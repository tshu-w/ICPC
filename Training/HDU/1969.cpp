#include <bits/stdc++.h>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double Pi = acos(-1.0);
const double eps = 1e-6;
const int INF = INT_MAX;
const int MAX_N = 1e4 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, n, f;
double sum = 0, a[MAX_N];
bool cal(double x) {
    int num = 0;
    for (int i = 0; i < n; ++i) {
        num += (int)(a[i] / x);
        if (num >= f)
            return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    cin >> t;
    while (t--) {
        cin >> n >> f;
        ++f;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] = Pi * sqr(a[i]);
            sum += a[i];
        }
        double l = 0, r = sum, mid;
        while (fabs(r - l) > eps) {
            mid = (l + r) / 2;
            if (!cal(mid)) r = mid; 
            else l = mid;
        }
        printf("%.4f\n", l);
    }
    return 0;
}