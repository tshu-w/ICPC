// written at 14:23 on 13 Feb 2017 
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
const int MAX_N = 20 + 5;
const double eps = 1e-8;
typedef vector<double> vec;
typedef vector<vec> mat;

int N, M, X, Y;
ll C[MAX_N][MAX_N];

void init() {
    rep(i, 0, MAX_N) {
        C[i][0] = C[i][i] = 1;
        rep(j, 1, i) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
}
inline int index(int n, int m) {
    return n * M + m + 1;
}
vec gauss_joedan(const mat& A, const vec& b) {
    int n = A.size();
    mat B(n, vec(n + 1));
    rep(i, 0, n) rep(j, 0, n) B[i][j] = A[i][j];
    rep(i, 0, n) B[i][n] = b[i];

    rep(i, 0, n) {
        int pivot = i;
        rep(j, i, n) if (abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
        if (i != pivot) swap(B[i], B[pivot]);

        if (abs(B[i][i]) < eps) return vec();

        rep(j, i + 1, n + 1) B[i][j] /= B[i][i];
        rep(j, 0, n) if (i != j)
            rep(k, i + 1, n + 1) B[j][k] -= B[j][i] * B[i][k];
    }

    vec x(n);
    rep(i, 0, n) x[i] = B[i][n];
    return x;
}
void solve() {
    int n = N * M + 1;
    mat A(n, vec(n, 0)); vec b(n, 0);
    A[0][0] = 1; b[0] = 1;
    rep(m, 0, n) rep(k, 0, m + 1) {
        double a = C[m][k] * pow((double)X, k / N) * pow((double)Y, (m - k) / M);
        A[index(k % N, (m - k) % M)][m < N * M? m + 1 : 0] += a;
    }
    vec x = gauss_joedan(A, b);
    reverse(x.begin() + 1, x.end());
    rep(i, 0, n) printf("%d%c", (int)round(x[i]), " \n"[i + 1 == n]);
}

int main(int argc, char const *argv[])
{
    init();
    while (scanf("%d%d%d%d", &X, &N, &Y, &M), X) solve();
    return 0;
}