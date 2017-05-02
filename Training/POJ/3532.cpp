// written at 10:50 on 13 Feb 2017 
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector> 
#include <utility>
#include <bitset>

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
const int MAX_N = 1e2 + 10;
const double eps = 1e-8;
typedef vector<double> vec;
typedef vector<vec> mat;

int N, M, u, v, r;

void gauss_joedan(const mat& A, const vec& b) {
    int n = A.size();
    mat B(n, vec(n + 1));
    rep(i, 0, n) rep(j, 0, n) B[i][j] = A[i][j];
    rep(i, 0, n) B[i][n] = b[i];

    rep(i, 1, n) {
        int pivot = i;
        rep(j, i, n) if (abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
        if (i != pivot) swap(B[i], B[pivot]);
        if (abs(B[i][i]) < eps) return;
        rep(j, i + 1, n) B[i][j] /= B[i][i];
        rep(j, 0, n) if (i != j)
            rep(k, i + 1, n) B[j][k] -= B[j][i] * B[i][k];
    }
    printf("%.2f\n", B[n - 1][n] / B[n - 1][n - 1]);
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &N, &M);
    mat A(N, vec(N, 0));
    vec b(N, 0); b[0] = b[N - 1] = 1;
    rep(i, 0, M) {
        scanf("%d%d%d", &u, &v, &r); --u, --v;
        double g = 1. / r;
        A[u][u] += g; A[v][v] += g;
        A[v][u] -= g; A[u][v] -= g;
    }
    rep(i, 0, N) A[i][0] = 0;
    gauss_joedan(A, b);
    return 0;
}