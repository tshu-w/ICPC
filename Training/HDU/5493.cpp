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
const int MAX_N = 1e5 + 5;

template <typename T>
inline T sqr(T a) { return a * a;};

Pii p[MAX_N];
int C[MAX_N];
int n;

void modify(int p,int delta) {
    while (p <= n) {
        C[p] += delta;
        p += p & -p;//lowbit(p);
    }
}
int sum(int p) {
    int res = 0;
    while (p) {
        res += C[p];
        p -= p & -p;//lowbit(p);
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int t, tt = 0, ans[MAX_N];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &p[i].first, &p[i].second);
        memset(C, 0, sizeof C);
        sort(p + 1, p + n + 1);
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            int k = min(p[i].second, n - i - p[i].second);
            if (n - i - p[i].second < 0) {
                flag = false;
                break;
            }
            ++k;
            int l = 1, r = n, mid;
            while (l < r) {
                mid = (l + r) / 2;
                if (mid - sum(mid) >= k) 
                    r = mid;
                else l = mid + 1;
            }
            modify(l, 1);
            ans[l] = p[i].first;
        }
        printf("Case #%d:", ++tt);
        if (flag) {
            for (int i = 1; i <= n; ++i)
                printf(" %d", ans[i]);
            printf("\n");
        } else 
            printf(" impossible\n");
    }
    return 0;
}