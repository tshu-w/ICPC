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
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50005;
const double eps = 1e-8;
const int dx[] = {0, 1, 0, 0, -1};
const int dy[] = {0, 0, 1, -1, 0};

template <typename T>
inline T sqr(T a) { return a * a;};

typedef vector<int> vec;
typedef vector<vec> mat;

int n = 5, m = 6;

mat A(n * m, vec(n * m));
vec b(n * m);

vec gauss_joedan(const mat& A, const vec& b) {
    int n = A.size();
    mat B(n, vec(n + 1));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) B[i][j] = A[i][j];
    for (int i = 0; i < n; ++i) B[i][n] = b[i];

    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i; j < n; ++j)
            if (B[j][i]) { 
                pivot = j;
                break;
            }
        if (pivot != i) swap(B[i], B[pivot]);

        for (int j = 0; j < n; ++j) if (i != j && B[j][i]) {
                for (int k = i; k <= n; ++k) B[j][k] ^= B[i][k];
            }
    }

    vec x(n);
    for (int i = 0; i < n; ++i) x[i] = B[i][n];
    return x;
}

int main(int argc, char const *argv[])
{
    int t, cs = 0;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < n; ++i)
            for (int j = 0, a; j < m; ++j) {
                scanf("%d", &a);
                b[i * m + j] = a & 1;
                for (int d = 0; d < 5; ++d) {
                    int x = i + dx[d], y = j + dy[d];
                    if (0 <= x && x < n && 0 <= y && y < m) 
                        A[i * m + j][x * m + y] = 1;    
                }
            }
        printf("PUZZLE #%d\n", ++cs);
        vec ans = gauss_joedan(A, b);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                printf("%d%c", ans[i * m + j], j == m - 1? '\n' : ' ');
    }
    return 0;
}