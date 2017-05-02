// written at 20:37 on 25 Dec 2016 
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
const int MAX_N = 1e5 + 10;
const int a[4][4] = {
    {1, 5, 1, -1},
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
};
const int b[4] = {36, 11, 5, 1};
int N, MOD;

typedef vector<int> vec;
typedef vector<vec> mat;
mat mat_mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    rep(i, 0, A.size())
        rep(k, 0, B.size())
            rep(j, 0, B[0].size())
                C[i][j] = (C[i][j] + (A[i][k] + MOD) % MOD * (B[k][j] + MOD) % MOD + MOD) % MOD;
    return C;
}
mat mat_pow(mat &A, int n) {
    mat B(A.size(), vec(A.size()));
    rep(i, 0, A.size()) B[i][i] = 1;
    while (n) {
        if (n & 1) B = mat_mul(B, A);
        A = mat_mul(A, A);
        n >>= 1;
    }    
    return B;
}

int main(int argc, char const *argv[])
{
    while (scanf("%d%d", &N, &MOD) && N + MOD) {
        mat A(4, vec(4));
        rep(i, 0, 4) rep(j, 0, 4) A[i][j] = a[i][j];
        if (N > 4) {
            A = mat_pow(A, N - 4);
            int ans = 0;
            rep (i, 0, 4) ans = (ans + A[0][i] % MOD * b[i] % MOD + MOD) % MOD;
            printf("%d\n", ans);
        }
        else printf("%d\n", b[4 - N] % MOD);

    }    
    return 0;
}