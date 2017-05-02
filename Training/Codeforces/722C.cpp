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
const int MAX_N = 1e5;

template <typename T>
inline T sqr(T a) { return a * a;};

int n;
ll A[MAX_N], s, ps[MAX_N];
set<Pii> qu;
multiset<ll> sum;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", A + i);
        s += A[i];
        ps[i + 1] = ps[i] + A[i];
    }
    sum.insert(s);
    qu.insert(Pii(n, 0));
    for (int i = 0, p; i < n; ++i) {
        scanf("%d", &p); --p;
        auto it = qu.upper_bound(Pii(p, 0));
        // cout << it->second << " " << it->first << endl;
        ll tmp = ps[it->first] - ps[it->second];
        // cout << "tmp " << tmp << endl;
        sum.erase(sum.lower_bound(tmp));

        tmp = ps[p] - ps[it->second];
        // cout << "tmp " << tmp << endl;
        sum.insert(tmp); qu.insert(Pii(p, it->second));

        tmp = ps[it->first] - ps[p + 1];
        // cout << "tmp " << tmp << endl;
        sum.insert(tmp); qu.insert(Pii(it->first, p + 1));

        qu.erase(it);
        printf("%I64d\n", *sum.rbegin());
    }
    return 0;
}