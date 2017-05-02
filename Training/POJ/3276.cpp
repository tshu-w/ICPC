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
#define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif    
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 5000 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int n, K, M;
int dir[MAX_N], f[MAX_N];

int cal(int k) {
    memset(f, 0, sizeof f);
    int sum = 0, res = 0;

    for (int i = 0; i + k <= n; ++i) {
        if ((dir[i] + sum) % 2 != 0) {
            ++res;
            f[i] = 1;
        }
        sum += f[i];
        if (i - k + 1 >= 0) 
            sum -= f[i - k + 1];
    }    

    for (int i = n - k + 1; i < n; ++i) {
        if ((dir[i] + sum) % 2 != 0) {
            return -1;
        }
        if (i - k + 1 >= 0) 
            sum -= f[i - k + 1];
    }

    return res;
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s[0] == 'F')
            dir[i] = 0;
        else dir[i] = 1;
    }

     K = 1, M = n;
    for (int k = 1; k <= n; ++k) {
        int m = cal(k);
        if (~m && M > m) {
            K = k;
            M = m;
        }
    }
    cout << K << " " << M << endl;
    return 0;
}