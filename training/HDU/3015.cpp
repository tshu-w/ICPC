#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif    
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N;
Pii T[MAX_N];

struct BIT
{
    ll bit[MAX_N];
    BIT() {
        memset(bit, 0, sizeof bit);
    }
    ll sum(int i) {
        ll s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int i, int x) {
        while (i <= N) {
            bit[i] += x;
            i += i & -i;
        }
    }    
};


void compress(Pii *a) {
    vector<int> v, vv;
    for (int i = 0; i < N; ++i)
        v.push_back(T[i].first);
    
    sort(v.begin(), v.end());
    // v.erase(unique(v.begin(), v.end()), v.end());
    
    for (int i = 0; i < N; ++i)
        T[i].first = lower_bound(v.begin(), v.end(), T[i].first) - v.begin() + 1;


    for (int i = 0; i < N; ++i)
        vv.push_back(T[i].second);
    
    sort(vv.begin(), vv.end());
    // vv.erase(unique(vv.begin(), vv.end()), vv.end());
    
    for (int i = 0; i < N; ++i)
        T[i].second = lower_bound(vv.begin(), vv.end(), T[i].second) - vv.begin() + 1;

}

int main(int argc, char const *argv[])
{
    while (~scanf("%d", &N)) {
        BIT cnt, sm;
        for (int i = 0; i < N; ++i)
            scanf("%d%d", &T[i].second, &T[i].first);
        compress(T);
        sort(T, T + N, greater<Pii>());
        ll ans = 0, sumX = 0;
        for (int i = 0; i < N; ++i) {
            ans += T[i].first * (cnt.sum(T[i].second) * T[i].second - sm.sum(T[i].second));
            ans += T[i].first * (sumX - sm.sum(T[i].second) - (i - cnt.sum(T[i].second)) * T[i].second);
            sm.add(T[i].second, T[i].second);
            cnt.add(T[i].second, 1);
            sumX += T[i].second;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}