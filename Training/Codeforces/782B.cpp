// written at 20:57 on 5 Mar 2017
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
const double EPS = 1e-6;

int N;
double X[MAX_N], V[MAX_N];

double C(double x) {
    double res = 0;
    for (int i = 0; i < N; i++)
        res = max(abs(X[i] - x) / V[i], res);
    return res;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    double lb = 1e9, ub = 1;
    for (int i = 0; i < N; i++) {
        scanf("%lf", X + i);
        lb = min(X[i], lb);
        ub = max(X[i], ub);
    }
    for (int i = 0; i < N; i++)
        scanf("%lf", V + i);
    while (lb + EPS < ub) {
        double ll = (2. * lb + ub) / 3.;
        double rr = (lb + 2. * ub) / 3.;
        if (C(ll) <= C(rr)) ub = rr;
        else lb = ll;
    }
    printf("%.10f\n", C(lb));
    return 0;
}
