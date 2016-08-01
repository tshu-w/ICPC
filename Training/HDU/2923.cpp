//#include <bits/stdc++.h>
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

typedef long l;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 50;
const int MAX_M = 500 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int t, N, M, A[MAX_N], dp[MAX_N][MAX_M];

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; ++i)
            scanf("%d", A + i);
        sort(A, A + N);
        int sum, cnt;
        for (cnt = sum = 0; cnt < N && sum + A[cnt] <= M; ++cnt)
            sum += A[cnt];
        
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 0; i < N; ++i)
            for (int j = cnt; j > 0; --j)
                for (int k = M; k >= A[i]; --k)
                    dp[j][k] += dp[j - 1][k - A[i]];
        
        int ans = 0;
        for (int i = 0; i <= M; ++i)
            ans += dp[cnt][i];
        if (cnt)
	        printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n", ans, cnt);
	    else 
	    	printf("Sorry, you can't buy anything.\n");
    }
    return 0;
}