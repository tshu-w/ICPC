#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pii;

const int maxn = 1e6 + 10;

int n, m, k, s[maxn], a[maxn], pre[maxn];
bool flag[maxn];

int main(int argc, char const *argv[]) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) scanf("%d", s + i), flag[s[i]] = true;
    for (int i = 0; i < k; i++) scanf("%d", a + i);
    pre[0] = 0;
    for (int i = 1; i <= n; i++) 
        if (!flag[i-1]) pre[i] = i-1;
        else pre[i] = pre[i-1];
    ll ans = LLONG_MAX;
    for (int i = 0; i < k; i++) {
        bool ff = false;
        int j = 0, tmp = 0, lst;
        while (j < n) {
            while (flag[j] && pre[j] > lst) j = pre[j];
            if (flag[j]) { ff = true; break; }
            tmp++;
            lst = j;
            j += i+1;
        }
        if (ff) continue;
        ans = min(ans, 1ll * tmp * a[i]);
    }
    if (ans == LLONG_MAX) printf("-1\n");
    else printf("%lld\n", ans);
    return 0;
}