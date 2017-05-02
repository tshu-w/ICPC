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
const int MAX_N = 100000 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};


int main(int argc, char const *argv[])
{
    int n, p, a[MAX_N], cnt, h, k, res = 0;
    ll t = 0;
    cin >> n >> h >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    while (p < n) {
        while (p < n && res + a[p] <= h) 
            res += a[p++];
        if (p == n) break;
        cnt = (res - h + a[p] + k - 1) / k;
        t += cnt;
        res -= cnt * k;
        if (res < 0) res = 0;
    }
    if (res)
        t += (res + k - 1) / k;
    cout << t << endl;
    return 0;
}