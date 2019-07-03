#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = INT_MAX;
const int MAX_N = 505;

const double PI = acos(-1.0);
ll sum;
std::vector<int> v;
int l, n, m, s, a[MAX_N], b[MAX_N], cases = 0;

int main(int argc, char const *argv[]) {
    while (~scanf("%d%d%d", &l, &n, &m)) {
        for (int i = 0; i < l; ++i)
            scanf("%d", &a[i]);

        for (int i = 0; i < n; ++i)
            scanf("%d", &b[i]);
        v.resize(0);
        for (int i = 0; i < l; ++i)
            for (int j = 0; j < n; ++j)
                v.push_back(a[i] + b[j]);
        for (int i = 0; i < m; ++i)
            scanf("%d", &a[i]);

        sort(v.begin(), v.end());
        scanf("%d", &s);
        printf("Case %d:\n", ++cases);
        for (int i = 0; i < s; ++i) {
            bool flag = false;
            scanf("%lld", &sum);
            for (int i = 0; i < m; ++i)
                if (v[lower_bound(v.begin(), v.end(), sum - a[i]) - v.begin()] == sum - a[i]) {
                    flag = true;
                    break;
                }
            if (flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}