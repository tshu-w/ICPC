// written at 16:23 on 10 Oct 2017
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef pair<double, double> Pdd;
const int maxn = 10;

double r;
int t, n, w[maxn];
vector<Pdd> v[1 << maxn];
bool vis[1 << maxn];

double wght(int s) {
    double res = 0.;
    for (int i = 0; i < n; i++)
        if (s >> i & 1) res += w[i];
    return res;
}

void len(int sup) {
    if (vis[sup]) return;
    vis[sup] = true;
    if (__builtin_popcount(sup) == 1) { v[sup].push_back(Pdd(0, 0)); return; }
    int sub = sup;
    do {
        sub = (sub - 1) & sup;
        if (sub && sup ^ sub) {
            double w1 = wght(sub), w2 = wght(sup ^ sub);
            double len1 = w2 / (w1 + w2), len2 = w1 / (w1 + w2);
            len(sub); len(sup ^ sub);
            for (Pdd p1 : v[sub])
                for (Pdd p2 : v[sub ^ sup])
                    v[sup].push_back(Pdd(max(p1.first, p2.first - 1) + len1, max(p2.second, p1.second - 1) + len2));
        }
    } while (sub != sup);
    sort(all(v[sup]));
    v[sup].erase(unique(all(v[sup])), v[sup].end());
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lf%d", &r, &n);
        for (int i = 0; i < n; i++) scanf("%d", w + i);
        for (int i = 0; i < 1 << n; i++) v[i].clear(), vis[i] = false;
        int S = (1 << n) - 1;
        len(S);
        double ans = -1.;
        for (auto x : v[S]) {
            if (x.first + x.second <= r) ans = max(ans, x.first + x.second);
            // cerr << x.first << ", " << x.second << endl;
        }
        printf("%.10f\n", ans);
    }
    return 0;
}
