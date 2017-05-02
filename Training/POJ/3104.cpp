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
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N;
ll K, A[MAX_N];

bool C(ll times) {
    ll cnt = 0;
    for (int i = 0; i < N; ++i) {
        ll t = 0;
        if (K == 1) {
            if (A[i] > times) return false;
        } else {
            if (A[i] > times)
                t = (A[i] - times) / (K - 1) + ((A[i] - times) % (K - 1)? 1 : 0);
        }
        cnt += t;
    }
    return cnt <= times;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%lld", A + i);
    scanf("%lld", &K);
    ll lb = 0, ub = INF;
    while (ub - lb > 1) {
        // cout << lb << " " << ub << endl;
        ll mid = (ub - lb) / 2 + lb;
        if (C(mid)) ub = mid;
        else lb = mid;
    }
    printf("%lld\n", ub);
    return 0;
}