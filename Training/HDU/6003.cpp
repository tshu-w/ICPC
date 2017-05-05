// written at 10:11 on 03 May 2017
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

const int MAX_N = 1e5 + 10;

int t, n, m, C[MAX_N];
Pii seg[MAX_N];

int main(void)
{
    scanf("%d", &t);
    for (int _ = 0; _ < t; _++) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &seg[i].first, &seg[i].second);
        for (int i = 0; i < m; i++)
            scanf("%d", C + i);
        sort(seg, seg + n);
        sort(C, C + m);
        int ans = 0;
        priority_queue<int, vector<int>, greater<int> > que;
        for (int i = 0, it = 0; i < m; i++) {
            while (it < n && seg[it].first <= C[i]) que.push(seg[it++].second);
            while (!que.empty() && que.top() < C[i]) que.pop();
            if (que.size() == 0) {ans = -1; break;}
            ans = max(ans, n - (int)que.size());
            que.pop();
        }
        if (~ans) printf("Case #%d: %d\n", _ + 1, ans + 1);
        else printf("Case #%d: IMPOSSIBLE!\n", _ + 1);
    }
    return 0;
}
