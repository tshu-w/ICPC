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
const int MAX_N = 1e5;

template <typename T>
inline T sqr(T a) { return a * a;};

int main(int argc, char const *argv[])
{
    int rlis[MAX_N], t, tt = 0, n, l, a[MAX_N], lis[MAX_N];
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        fill(lis, lis + n, INF);
        for (int i = n - 1, p; i >= l; --i) {
            p = lower_bound(lis, lis + n, -a[i]) - lis;
            lis[p] = -a[i];
            rlis[i] = p + 1;
        }
        int ans = 0;
        fill(lis, lis + n, INF);
        for (int i = l, p; i < n; ++i) {
            p = lower_bound(lis, lis + n, a[i]) - lis;
            ans = max(ans, p + rlis[i]);
            *lower_bound(lis, lis + n, a[i - l]) = a[i - l];
        }
        ans = max(ans, (int)(lower_bound(lis, lis + n, INF) - lis));
        printf("Case #%d: %d\n", ++tt, ans);
    }
    return 0;
}