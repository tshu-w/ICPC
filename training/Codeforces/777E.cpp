// written at 12:25 on 25 Feb 2017 
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
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = 1e5 + 10;

struct T {
    int a, b, h;
    T(int a = 0, int b = 0, int h = 0): a(a), b(b), h(h) { }
};

T t[MAX_N];

int N;
stack<T> st;
ll res, ans;

bool cmp(T t1, T t2) {
    return t1.b == t2.b ? t1.a > t2.a : t1.b > t2.b;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    rep(i, 0, N)
        scanf("%d%d%d", &t[i].a, &t[i].b, &t[i].h);
    sort(t, t + N, cmp);
    st.push(T(0, INF, 0));
    int it = 0;
    while (it < N) {
        while (st.size() && t[it].b <= st.top().a) {
            res -= st.top().h; st.pop();
        }
        st.push(t[it]); res += t[it].h;++it;
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}