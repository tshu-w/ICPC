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
    int n, t, cnt = 0;
    double a[15][15];
    cin >> n >> t;
    memset(a, 0, sizeof a);
    a[0][0] = t;
    for (int j = 0; j < n; ++j)
        for (int k = 0; k <= j; ++k) {
            if (a[j][k] > 1. - 1e-6) {
                a[j + 1][k] += (a[j][k] - 1) / 2.0;
                a[j + 1][k + 1] += (a[j][k] - 1) / 2.0;
            }
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            if (a[i][j] > 1. - 1e-6)
                ++cnt;
    cout << cnt << endl;
    return 0;
}