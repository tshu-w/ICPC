// written at 16:47 on 30 Apr 2017
#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif
#define filename "A-large"
#define setfile() freopen(filename".in.txt", "r", stdin); freopen(filename".ans.txt", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans.txt");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const int MAX_N = 1000 + 10;
const double pi = acos(-1.0);

int t, n, k;
Pii C[MAX_N];
int main(void)
{
    setfile();
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int r, h;
            cin >> r >> h;
            C[i] = make_pair(r, h);
        }
        sort(C, C + n);
        double ans = 0;
        double sum = 0;
        priority_queue<double, vector<double>, greater<double> > que;
        for (int i = 0; i < n; i++) {
            double area = 2 * pi * C[i].first * C[i].second;
            sum += area;
            que.push(area);
            if (i >= k - 1) {
                ans = max(ans, sum + pi * C[i].first * C[i].first);
                area = que.top(); que.pop();
                sum -= area;
            }
        }
        printf("Case #%d: %f\n", _ + 1, ans);
    }
    resetfile();
    return 0;
}
